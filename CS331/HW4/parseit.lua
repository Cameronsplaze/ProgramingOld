-- parseit.lua
-- Cameron Showalter
-- 15 Feb 2017
--
-- For CS F331 / CSCE A331 Spring 2017
-- Recursive-Descent Parser #4: Expressions + Better ASTs
-- Requires lexit.lua

local parseit = {}  -- Our module

lexit = require "lexit"


-- Variables

-- For lexit iteration
local iter          -- Iterator returned by lexit.lex
local state         -- State for above iterator (maybe not used)
local lexit_out_s   -- Return value #1 from above iterator
local lexit_out_c   -- Return value #2 from above iterator

-- For current lexeme
local lexstr = ""   -- String form of current lexeme
local lexcat = 0    -- Category of current lexeme:
                    --  one of categories below, or 0 for past the end


-- Symbolic Constants for AST

STMT_LIST   = 1
CR_STMT     = 2
PRINT_STMT  = 3
INPUT_STMT  = 4
SET_STMT    = 5
SUB_STMT    = 6
CALL_STMT   = 7
IF_STMT     = 8
WHILE_STMT  = 9
BIN_OP      = 10
UN_OP       = 11
NUMLIT_VAL  = 12
STRLIT_VAL  = 13
BOOLLIT_VAL = 14
VARID_VAL   = 15
ARRAY_REF   = 16



-- Utility Functions

-- advance
-- Go to next lexeme and load it into lexstr, lexcat.
-- Should be called once before any parsing is done.
-- Function init must be called before this function is called.
local function advance()
    lexit_out_s, lexit_out_c = iter(state, lexit_out_s)
    if lexit_out_s ~= nil then
        lexstr, lexcat = lexit_out_s, lexit_out_c
    else
        lexstr, lexcat = "", 0
    end
end


-- init
-- Initial call. Sets input for parsing functions.
local function init(prog)
    iter, state, lexit_out_s = lexit.lex(prog)
    advance()
end


-- atEnd
-- Return true if pos has reached end of input.
-- Function init must be called before this function is called.
local function atEnd()
    return lexcat == 0
end


-- matchString
-- Given string, see if current lexeme string form is equal to it. If
-- so, then advance to next lexeme & return true. If not, then do not
-- advance, return false.
-- Function init must be called before this function is called.
local function matchString(s)
    if lexstr == s then
        if lexstr == ")" or lexstr == "]" or
          lexstr == "true" or lexstr == "false" then
          lexit.preferOp()
        end
        advance()
        return true
    else
        return false
    end
end


-- matchCat
-- Given lexeme category (integer), see if current lexeme category is
-- equal to it. If so, then advance to next lexeme & return true. If
-- not, then do not advance, return false.
-- Function init must be called before this function is called.
local function matchCat(c)
    if lexcat == c then
        if lexcat == lexit.VARID or lexcat == lexit.NUMLIT then
          lexit.preferOp()
        end
        advance()
        return true
    else
        return false
    end
end


-- Primary Function for Client Code

-- parse
-- Given program, initialize parser and call parsing function for start
-- symbol. Returns pair of booleans & AST. First boolean indicates
-- successful parse or not. Second boolean indicates whether the parser
-- reached the end of the input or not. AST is only valid if first
-- boolean is true.
function parseit.parse(prog)
    init(prog)
    local good, ast = parse_stmt_list()  -- Parse start symbol
    local done = atEnd()
    return good, done, ast
end


-- Parsing Functions

--(2)         stmt_list     →     { statement }
function parse_stmt_list()
    local good, ast, newast
    ast = { STMT_LIST }
    while true do
        if lexstr ~= "cr" and lexstr ~= "print" and lexstr ~= "input" and lexstr ~= "set" 
            and lexstr ~= "sub" and lexstr ~= "call" and lexstr ~= "if" and lexstr ~= "while" 
            then break
        end
        good, newast = parse_stmt()
        if not good then
            return false, nil
        end
    table.insert(ast,newast)
    end
    return true, ast
end


--[[
(3)         statement     →     “cr”
(4)             |       “print” ( STRLIT | expr )
(5)             |       “input” lvalue
(6)             |       “set” lvalue “:” expr
(7)             |       “sub” SUBID stmt_list “end”
(8)             |       “call” SUBID
(9)             |       “if” expr stmt_list { “elseif” expr stmt_list } [ “else” stmt_list ] “end”
(10)            |       “while” expr stmt_list “end”
]]--
function parse_stmt()
    local oldlexstr, good, ast, newast
    --====================================================
    if matchString("cr") then
        return true, { CR_STMT }
    --====================================================
    elseif matchString("print") then
        oldlexstr = lexstr
        if matchCat(lexit.STRLIT) then
            return true, { PRINT_STMT, {STRLIT_VAL, oldlexstr} }
        else
            good,ast = parse_expr()
            if not good then
                return false,nil
            end
            ast = { PRINT_STMT, ast }
        end
    --====================================================
    elseif matchString("input") then
        good,ast = parse_lvalue()
        if not good then
            return false,nil
        end
        ast = { INPUT_STMT, ast }
    --====================================================
    elseif matchString("set") then
        good,ast = parse_lvalue()
        if not good or not matchString(":") then
            return false,nil
        end
        good,newast = parse_expr()
        if not good then
            return false,nil
        end
        ast = {SET_STMT, ast, newast}
    --====================================================
    elseif matchString("sub") then
        local subid = lexstr
        if not matchCat(lexit.SUBID) then
            return false,nil
        end
        good,ast = parse_stmt_list()
        if not good or not matchString("end") then
            return false,nil
        end
        ast = { SUB_STMT, subid, ast }
    --====================================================
    elseif matchString("call") then
        oldlexstr = lexstr
        if not matchCat(lexit.SUBID) then
            return false,nil
        end
            ast = { CALL_STMT, oldlexstr }
        return true,ast
    --====================================================
    elseif matchString("if") then
        local expr,stmt_list
        good,expr = parse_expr()
        if not good then
            return false,nil
        end
        good,stmt_list = parse_stmt_list()
        if not good then
            return false,nil
        end
        ast = { IF_STMT, expr, stmt_list }
        while true do
            oldlexstr = lexstr
            if not matchString("elseif") then
                break
            end
            good,expr = parse_expr()
            if not good then
                return false,nil
            end
            good,stmt_list = parse_stmt_list()
            if not good then
                return false,nil
            end
            table.insert(ast,expr)
            table.insert(ast,stmt_list)
        end
        if matchString("else") then
            good,stmt_list = parse_stmt_list()
            if not good then
                return false,nil
            end
            table.insert(ast,stmt_list)
        end
        if not matchString("end") then
            return false,nil
        end
    --====================================================
    elseif matchString("while") then
        local expr,stmt_list
        good,expr = parse_expr()
        if not good then 
            return false,nil
        end
        good,stmt_list = parse_stmt_list()
        if not good or not matchString("end") then
            return false,nil
        end
        ast = { WHILE_STMT, expr, stmt_list }
    --====================================================
    else
        return false,nil
    end
    return true,ast
end



--(11)        expr      →     comp_expr { ( “&&” | “||” ) comp_expr }
-- parse_expr
-- Parsing function for nonterminal "expr".
-- Function init must be called before this function is called.
function parse_expr()
    local oldlexstr, good, ast, newast
        good,ast = parse_comp_expr()
        if not good then
            return false,nil
        end
        while true do
            oldlexstr = lexstr
            if not matchString("&&") and not matchString("||") then
                break
            end
            good, newast = parse_comp_expr()
            if not good then
                return false, nil
            end
            ast = { { BIN_OP, oldlexstr }, ast, newast }
        end
    return true,ast
end



--[[
(12)        comp_expr     →     “!” comp_expr
(13)            |       arith_expr { ( “==” | “!=” | “<” | “<=” | “>” | “>=” ) arith_expr }
]]--
function parse_comp_expr()
    local oldlexstr, good, ast, newast
    if matchString("!") then
        good,ast = parse_comp_expr()
        if not good then
            return false,nil
        end
        ast = { {UN_OP, "!"}, ast }
        return true,ast
    end
    good,ast = parse_arith_expr()
    if not good then
        return false,nil
    end
    while true do
        oldlexstr = lexstr
        if not matchString("==") and not matchString("!=") and not 
                matchString("<") and not matchString("<=") and not 
                matchString(">") and not matchString(">=") then
            break
        end
        good, newast = parse_arith_expr()
        if not good then
            return false, nil
        end
        ast = { { BIN_OP, oldlexstr }, ast, newast }
    end
    return true,ast
end



--(14)        arith_expr    →     term { ( “+” | “-” ) term }
function parse_arith_expr()
    local oldlexstr, good, ast, newast
    good,ast = parse_term()
    if not good then
        return false,nil
    end
    while true do
        oldlexstr = lexstr
        if not matchString("+") and not matchString("-") then
            break
        end
        good,newast = parse_term()
        if not good then
            return false,nil
        end
        ast = { {BIN_OP, oldlexstr}, ast, newast }
    end
    return true,ast
end



--(15)        term      →     factor { ( “*” | “/” | “%” ) factor }
function parse_term()
    local oldlexstr, good, ast, newast
    good,ast = parse_factor()
    if not good then
        return false,nil
    end
    while true do
        oldlexstr = lexstr
        if not matchString("*") and not matchString("/") and not matchString("%") then
            break
        end
        good,newast = parse_factor()
        if not good then
            return false,nil
        end
        ast = { {BIN_OP, oldlexstr}, ast, newast }
    end
    return true,ast
end



--[[
(16)        factor    →     ( “+” | “-” ) factor
(17)            |       “(” expr “)”
(18)            |       NUMLIT
(19)            |       ( “true” | “false” )
(20)            |       lvalue
]]--

-- parse_factor
-- Parsing function for nonterminal "factor".
-- Function init must be called before this function is called.
function parse_factor()
    local oldlexstr, good, ast, newast
    oldlexstr = lexstr
    if matchString("+") or matchString("-") then
        good,newast = parse_factor()
        if not good then
            return false,nil
        end
        ast = { {UN_OP, oldlexstr}, newast }
    elseif matchString("(") then
        good,ast = parse_expr()
        if not good or not matchString(")") then
            return false,nil
        end
    elseif matchCat(lexit.NUMLIT) then
        ast = { NUMLIT_VAL, oldlexstr }
    elseif matchString("true") or matchString("false") then
        ast = { BOOLLIT_VAL, oldlexstr }
    else
        good,ast = parse_lvalue() 
        if not good then
            return false,nil
        end
    end
    return true,ast
end



--(21)        lvalue    →     VARID [ “[” expr “]” ]
function parse_lvalue()
    local oldlexstr, good, ast, newast
    oldlexstr = lexstr
    if matchCat(lexit.VARID) then
        ast = { VARID_VAL, oldlexstr }
    else
        return false,nil
    end
    if matchString("[") then
        good,newast = parse_expr()
        if not good or not matchString("]") then
            return false,nil
        end
        ast = { ARRAY_REF, { VARID_VAL, oldlexstr }, newast }
    end
    return true,ast
end





return parseit
--[[
    (1)         program       →     stmt_list
    (2)         stmt_list     →     { statement }
    (3)         statement     →     “cr”
    (4)             |       “print” ( STRLIT | expr )
    (5)             |       “input” lvalue
    (6)             |       “set” lvalue “:” expr
    (7)             |       “sub” SUBID stmt_list “end”
    (8)             |       “call” SUBID
    (9)             |       “if” expr stmt_list { “elseif” expr stmt_list } [ “else” stmt_list ] “end”
    (10)            |       “while” expr stmt_list “end”
    (11)        expr      →     comp_expr { ( “&&” | “||” ) comp_expr }
    (12)        comp_expr     →     “!” comp_expr
    (13)            |       arith_expr { ( “==” | “!=” | “<” | “<=” | “>” | “>=” ) arith_expr }
    (14)        arith_expr    →     term { ( “+” | “-” ) term }
    (15)        term      →     factor { ( “*” | “/” | “%” ) factor }
    (16)        factor    →     ( “+” | “-” ) factor
    (17)            |       “(” expr “)”
    (18)            |       NUMLIT
    (19)            |       ( “true” | “false” )
    (20)            |       lvalue
    (21)        lvalue    →     VARID [ “[” expr “]” ]
]]--