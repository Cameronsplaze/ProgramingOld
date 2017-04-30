-- lexer.lua
-- Cameron Showalter
-- 21 Feb 2017
-- 
--
-- For CS F331 / CSCE A331 Spring 2017
-- Lexer Module
-- Based on LexerCode.lua
--
-- Usage:
--
--    program = "print a+b;"  -- program to lex
--    for lexstr, cat in lexer.lex(program) do
--        -- lexstr is the string form of a lexeme
--        -- cat is the lexeme category
--        --  It can be used as an index for array lexer.catnames
--    end



local lexit = {}


-- Lexeme Categories
lexit.KEY = 1
lexit.VARID = 2
lexit.SUBID = 3
lexit.NUMLIT = 4
lexit.STRLIT = 5
lexit.OP = 6
lexit.PUNCT = 7
lexit.MAL = 8

-- Lexeme category names
lexit.catnames = 
{
    "Keyword",
    "VariableIdentifier",
    "SubroutineIdentifier",
    "NumericLiteral",
    "StringLiteral",
    "Operator",
    "Punctuation",
    "Malformed" 
}



-- Kind-of-Character Functions

-- isLetter
-- Returns true if string c is a letter character, false otherwise.
local function isLetter(c)
    if c:len() ~= 1 then
        return false
    elseif c >= "A" and c <= "Z" then
        return true
    elseif c >= "a" and c <= "z" then
        return true
    else
        return false
    end
end


-- isDigit
-- Returns true if string c is a digit character, false otherwise.
local function isDigit(c)
    if c:len() ~= 1 then
        return false
    elseif c >= "0" and c <= "9" then
        return true
    else
        return false
    end
end


-- isWhitespace
-- Returns true if string c is a whitespace character, false otherwise.
local function isWhitespace(c)
    if c:len() ~= 1 then
        return false
    elseif c == " " or c == "\t" or c == "\n" or c == "\r"
      or c == "\f" then
        return true
    else
        return false
    end
end


-- isIllegal
-- Returns true if string c is an illegal character, false otherwise.
local function isIllegal(c)
    if c:len() ~= 1 then
        return false
    elseif isWhitespace(c) then
        return false
    elseif c >= " " and c <= "~" then
        return false
    else
        return true
    end
end



-- Flag to determine if operater or longest lexeme is preferred
local preferOpFlag = false

-- preferOp
-- Function that changes preferOpFlag to true
function lexit.preferOp()
    preferOpFlag = true
end


function lexit.lex(prog)
    -- ***** Variables (like class data members) *****

    local pos       -- Index of next character in prog
                    -- INVARIANT: when getLexeme is called, pos is
                    --  EITHER the index of the first character of the
                    --  next lexeme OR len+1
    local state     -- Current state for our state machine
    local ch        -- Current character
    local lexstr    -- The lexeme, so far
    local category  -- Category of lexeme, set when state set to DONE
    local handlers  -- Dispatch table; value created later

    -- ***** States *****
    local DONE = 0
    local START = 1
    local KEYWORD = 2
    local IDENTIFIER = 3
    local NUMLIT = 4
    local OP = 5
    local STRLIT = 6
    local EXP = 7

    local keywords = 
    {
        ["call"] = true,
        ["cr"] = true,
        ["else"] = true,
        ["elseif"] = true,
        ["end"] = true,
        ["false"] = true,
        ["if"] = true,
        ["input"] = true,
        ["print"] = true,
        ["set"] = true,
        ["sub"] = true,
        ["true"] = true,
        ["while"] = true
    }


    local operators =
    {
        ["&"] = true,
        ["|"] = true,
        ["!"] = true,
        ["="] = true,
        ["<"] = true,
        [">"] = true,
        ["+"] = true,
        ["-"] = true,
        ["*"] = true,
        ["/"] = true,
        ["%"] = true,
        ["["] = true,
        ["]"] = true,
        [":"] = true,
    }

    -- ***** Character-Related Functions *****

    -- currChar
    -- Return the current character, at index pos in prog. Return value
    -- is a single-character string, or the empty string if pos is past
    -- the end.
    local function currChar()
        return prog:sub(pos, pos)
    end
    -- nextChar
    -- Return the next character, at index pos+1 in prog. Return value
    -- is a single-character string, or the empty string if pos+1 is
    -- past the end.
    local function nextChar()
        return prog:sub(pos+1, pos+1)
    end
    -- nextCharTwo
    -- returns character i spaces after our current one
    local function nextCharForward(i)
        return prog:sub(pos+i,pos+i)
    end


    -- drop1
    -- Move pos to the next character.
    local function drop1()
        pos = pos+1
    end
    -- add1
    -- Add the current character to the lexeme, moving pos to the next
    -- character.
    local function add1()
        lexstr = lexstr .. currChar()
        drop1()
    end


    -- skipWhitespace
    -- Skip whitespace and comments, moving pos to the beginning of
    -- the next lexeme, or to prog:len()+1.
    local function skipWhitespace()
        while true do
            while isWhitespace(currChar()) do
                drop1()
            end

            if currChar() == "#" then
                while currChar() ~= "\n" and currChar() ~= "" do
                    drop1()
                end
                if currChar() == "" then
                    return
                end
                drop1()
            end

            if isWhitespace(currChar()) == false and currChar() ~= "#" then
                return
            end
        end
    end


    local function handlers_DONE()
        io.write("ERROR: 'DONE' state should not be handled\n")
        assert(0)
    end
    local function handlers_START()
        -- Illegal
        if isIllegal(ch) then
            add1()
            state = DONE
            category = lexit.MAL
        -- Must be a keyword
        elseif isLetter(ch) then
            add1()
            state = KEYWORD
        -- Identifiers
        elseif ch == "%" or ch == "&" then
            if preferOpFlag == true then
                if (ch == "&" and nextChar() == "&") or ch == "%" then
                    state = OP
                    return
                end
            end
            if isLetter(nextChar()) or nextChar() == "_" then
                add1()
                state = IDENTIFIER
                if ch == "%" then
                    category = lexit.VARID
                else
                    category = lexit.SUBID
                end
            else
                state = OP
            end
        -- Numeric Literals
        elseif isDigit(ch) then
            add1()
            state = NUMLIT
        -- Operator or numeric literals
        elseif ch == "+" or ch == "-" then
            if isDigit(nextChar()) and preferOpFlag == false then
                state = NUMLIT
            else
                state = DONE
                category = lexit.OP
            end
            add1()
        -- Operators
        elseif operators[ch] == true then
            state = OP
        -- String literal
        elseif ch == "\'" or ch == "\"" then
            state = STRLIT
        -- Punctuation
        else
            add1()
            state = DONE
            category = lexit.PUNCT
        end
    end
    local function handlers_KEYWORD()
        if isLetter(ch) then
            add1()
        else
            state = DONE
            if keywords[lexstr] == true then
                category = lexit.KEY
            else
                category = lexit.MAL
            end
        end
    end    
    local function handlers_IDENTIFIER()
        if isLetter(ch) or isDigit(ch) or ch == "_" then
            add1()
        else
            state = DONE
        end
    end
    local function handlers_NUMLIT()
        if isDigit(ch) then
            add1()
        elseif ch == "e" or ch == "E" then
            if isDigit(nextChar()) then
                add1()
                state = EXP
            elseif nextChar() == "+" and isDigit(nextCharForward(2)) == true then
                add1()
                add1()
                state = EXP
            else
                state = DONE
                category = lexit.NUMLIT
            end
        else
            state = DONE
            category = lexit.NUMLIT
        end
    end
    local function handlers_OP()
        if ch == "&" or ch == "|" or ch == "=" then
            if ch == nextChar() then
                add1()
            else
                -- Not operators but punctuation
                add1()
                state = DONE
                category = lexit.PUNCT
                return
            end
        elseif ch == "!" or ch == "<" or ch == ">" then
            if nextChar() == "=" then
                add1()
            end
        end
        add1()
        state = DONE
        category = lexit.OP
    end
    local function handlers_STRLIT()
        closing = ch
        add1()
        ch = currChar()
        while ch ~= "" and ch ~= closing do
            add1()
            ch = currChar()
        end
        state = DONE
        if ch == "" then
            -- reached end of input without closing
            category = lexit.MAL
        else
            category = lexit.STRLIT
            add1()
        end
    end
    local function handlers_EXP()
        if isDigit(ch) then
            add1()
        else
            state = DONE
            category = lexit.NUMLIT
        end
    end


    handlers = {
        [DONE]=handlers_DONE,
        [START]=handlers_START,
        [KEYWORD]=handlers_KEYWORD,
        [IDENTIFIER]=handlers_IDENTIFIER,
        [NUMLIT]=handlers_NUMLIT,
        [OP]=handlers_OP,
        [STRLIT]=handlers_STRLIT,
        [EXP]=handlers_EXP,
    }


    -- getLexeme
    -- function for the for-in loop
    -- returns the next lexeme and its category id
    local function getLexeme(dummy1, dummy2)
        if pos > prog:len() then
            preferOpFlag = false
            return nil,nil
        end

        lexstr = ""
        state = START

        while state ~= DONE do
            ch = currChar()
            handlers[state]()
        end

        skipWhitespace()
        preferOpFlag = false
        return lexstr,category
    end

    pos = 1
    skipWhitespace()
    return getLexeme, nil, nil
end


return lexit

