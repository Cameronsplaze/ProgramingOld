-- parseit.lua
-- Glenn G. Chappell
-- 15 Feb 2017
--
-- For CS F331 / CSCE A331 Spring 2017
-- Recursive-Descent Parser #4: Expressions + Better ASTs
-- Requires lexit.lua


-- Grammar
-- Start symbol: expr
--
--     expr    ->  term { ("+" | "-") term }
--     term    ->  factor { ("*" | "/") factor }
--     factor  ->  ID
--              |  NUMLIT
--              |  "(" expr ")"
--
-- All operators (+ - * /) are left-associative.
--
-- AST Specification
-- - For a NUMLIT, the AST is { NUMLIT_VAL, SS }, where SS is the string
--   form of the lexeme.
-- - For an ID, the AST is { ID_VAL, SS }, where SS is the string form
--   of the lexeme.
-- - For expr -> term, then AST for the expr is the AST for the term,
--   and similarly for term -> factor.
-- - Let X, Y be expressions with ASTs XT, YT, respectively.
--   - The AST for ( X ) is XT.
--   - The AST for X + Y is { { BIN_OP, "+" }, XT, YT }, and similarly
--     other operators.


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
    -- Advance the iterator
    lexit_out_s, lexit_out_c = iter(state, lexit_out_s)

    -- If we're not past the end, copy current lexeme into vars
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
    -- Initialization
    init(prog)

    -- Get results from parsing
    local good, ast = parse_expr()  -- Parse start symbol
    local done = atEnd()

    -- And return them
    return good, done, ast
end


-- Parsing Functions

-- Each of the following is a parsing function for a nonterminal in the
-- grammar. Each function parses the nonterminal in its name and returns
-- a pair: boolean, AST. On a successul parse, the boolean is true, the
-- AST is valid, and the current lexeme is just past the end of the
-- string the nonterminal expanded into. Otherwise, the boolean is
-- false, the AST is not valid, and no guarantees are made about the
-- current lexeme. See the AST Specification near the beginning of this
-- file for the format of the returned AST.


-- parse_expr
-- Parsing function for nonterminal "expr".
-- Function init must be called before this function is called.
function parse_expr()
    local good, ast, saveop, newast

    good, ast = parse_term()
    if not good then
        return false, nil
    end

    while true do
        saveop = lexstr
        if not matchString("+") and not matchString("-") then
            break
        end

        good, newast = parse_term()
        if not good then
            return false, nil
        end

        ast = { { BIN_OP, saveop }, ast, newast }
    end

    return true, ast
end


-- parse_term
-- Parsing function for nonterminal "term".
-- Function init must be called before this function is called.
function parse_term()
    local good, ast, saveop, newast

    good, ast = parse_factor()
    if not good then
        return false, nil
    end

    while true do
        saveop = lexstr
        if not matchString("*") and not matchString("/") then
            break
        end

        good, newast = parse_factor()
        if not good then
            return false, nil
        end

        ast = { { BIN_OP, saveop }, ast, newast }
    end

    return true, ast
end


-- parse_factor
-- Parsing function for nonterminal "factor".
-- Function init must be called before this function is called.
function parse_factor()
    local savelex, good, ast

    savelex = lexstr
    if matchCat(lexit.ID) then
        return true, { ID_VAL, savelex }
    elseif matchCat(lexit.NUMLIT) then
        return true, { NUMLIT_VAL, savelex }
    elseif matchString("(") then
        good, ast = parse_expr()
        if not good then
            return false, nil
        end

        if not matchString(")") then
            return false, nil
        end

        return true, ast
    else
    	io.write("YOU'RE HITTING THIS ONE\n")
    	return true, {STMT_LIST}
        --return false, nil
    end
end


-- Module Export

return parseit

