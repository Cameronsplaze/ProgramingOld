-- interpit.lua 
-- Cameron Showalter

-- For CS F331 / CSCE A331 Spring 2017
-- Interpret AST from parseit.parse
-- For Assignment 6, Exercise B


-- *********************************************************************
-- * To run a Kanchil program, use kanchil.lua (which uses this file). *
-- *********************************************************************


local interpit = {}  -- Our module


-- ***** Variables *****


-- Symbolic Constants for AST

local STMT_LIST   = 1
local CR_STMT     = 2
local PRINT_STMT  = 3
local INPUT_STMT  = 4
local SET_STMT    = 5
local SUB_STMT    = 6
local CALL_STMT   = 7
local IF_STMT     = 8
local WHILE_STMT  = 9
local BIN_OP      = 10
local UN_OP       = 11
local NUMLIT_VAL  = 12
local STRLIT_VAL  = 13
local BOOLLIT_VAL = 14
local VARID_VAL   = 15
local ARRAY_REF   = 16


-- ***** Utility Functions *****


-- numToInt
-- Given a number, return the number rounded toward zero.
local function numToInt(n)
    if n >= 0 then
        return math.floor(n)
    else
        return math.ceil(n)
    end
end


-- strToNum
-- Given a string, attempt to interpret it as an integer. If this
-- succeeds, return the integer. Otherwise, return 0.
local function strToNum(s)
    -- Try to do string -> number conversion; make protected call
    -- (pcall), so we can handle errors.
    local success, value = pcall(function() return 0+s end)

    -- Return integer value, or 0 on error.
    if success then
        return numToInt(value)
    else
        return 0
    end
end


-- numToStr
-- Given a number, return its string form.
local function numToStr(n)
    return ""..n
end


-- boolToInt
-- Given a boolean, return 1 if it is true, 0 if it is false.
local function boolToInt(b)
    if b then
        return 1
    else
        return 0
    end
end



-- ***** Primary Function for Client Code *****


-- interp
-- Interpreter, given AST returned by parseit.parse.
-- Parameters:
--   ast     - AST constructed by parseit.parse
--   state   - Table holding values of Zebu integer variables
--             Value of simple variable xyz is in state.s["xyz"]
--             Value of array item xyz[42] is in state.a["xyz"][42]
--   incall  - Function to call for line input
--             incall() inputs line, returns string with no newline
--   outcall - Function to call for string output
--             outcall(str) outputs str with no added newline
--             To print a newline, do outcall("\n")
-- Return Value:
--   state updated with changed variable values
function interpit.interp(ast, state, incall, outcall)
    -- Each local interpretation function is given the AST for the
    -- portion of the code it is interpreting. The function-wide
    -- versions of state, incall, and outcall may be used. The
    -- function-wide version of state may be modified as appropriate.

    local isLHS
    local getLHS
    local intExpression
    local boolExpression
    local interp_stmt_list
    local interp_stmt



    function isLHS(ast)
        if ast[1] == NUMLIT_VAL or ast[1] == VARID_VAL or ast[1] == ARRAY_REF then
            return true
        elseif type(ast[1])=="table" and ast[1][1] == UN_OP and (ast[1][2] == "+" or ast[1][2] == "-") then
            return true
        elseif ast[1][1] == BIN_OP then
            if  ast[1][2] == "+" or ast[1][2] == "-" or ast[1][2] == "%" or
                ast[1][2] == "*" or ast[1][2] == "/" then
                return true
            end
        end
        return false
    end

    function getLHS(ast)
        local returnMe

        if ast[1] == NUMLIT_VAL then 
            returnMe = strToNum(ast[2])
        elseif ast[1] == VARID_VAL then
            returnMe = state.v[ast[2]]
        elseif ast[1] == ARRAY_REF then
            if state.a[ast[2][2]] ~= nil then
                returnMe = state.a[ast[2][2]][intExpression(ast[3])]
            else 
                returnMe = 0
            end
        end
        return returnMe
    end

    function intExpression(ast)

        local returnMe=nil
        local i = 1

        if ast[1] == NUMLIT_VAL or ast[1] == VARID_VAL or ast[1] == ARRAY_REF then
            returnMe = getLHS(ast)
        else
            while ast[i][1] == BIN_OP do
                i=i+1
            end
 
            i=i-1
            for j = i+1, #ast do

                local fooValue
                if ast[j][1] == UN_OP then

                    local  sign = 1
                    if ast[j][2] == "-" then
                        sign = sign*-1
                    end

                    j=j+1
                    if isLHS(ast[j]) then
                        if type(ast[j][1])=="table" then
                            fooValue = sign * intExpression(ast[j])
                        else
                            fooValue = sign * getLHS(ast[j])
                        end
                    else
                        fooValue = sign * boolToInt(boolExpression(ast[j]))
                    end
                else 
                    if isLHS(ast[j]) then
    
                       if type(ast[j][1])=="table" then
                            fooValue = intExpression(ast[j])
                        else
                            fooValue = getLHS(ast[j])
                        end
                    else
                        fooValue = boolToInt(boolExpression(ast[j]))
                    end
                end
                if returnMe == nil then
                    returnMe = fooValue
                elseif i > 0 then 
                    if ast[i][2] == '*' then
                        returnMe = returnMe * fooValue
                    elseif ast[i][2] == '/' then
                        if fooValue == 0 then
                            returnMe = 0
                        else
                            local s = returnMe/fooValue / math.abs(returnMe/fooValue)
                            if s > 0 then
                                returnMe = math.floor(returnMe / fooValue)
                            else
                                returnMe = math.ceil(returnMe / fooValue)
                            end
                        end
                    elseif ast[i][2] == '%' then
                         if fooValue == 0 then
                            returnMe = 0
                        else
                            returnMe = returnMe % fooValue    
                        end
                    elseif ast[i][2] == '+' then 
                        returnMe = returnMe + fooValue  
                    elseif ast[i][2] == '-' then
                        returnMe = returnMe - fooValue    
                    end
                    i=i-1
                end

            end
        end

        if returnMe == nil then
            returnMe = 0
        end

        return returnMe
    end

    function boolExpression(ast)

        local tmpReturn=nil
        local returnBool = nil

        local i = 1

        if ast[1]==BOOLLIT_VAL then
            if ast[2] == "false" then
                returnBool = false
            else
                returnBool = true
            end
        elseif isLHS(ast) then
            if intExpression(ast) == 0 then
                return false
            else
                return true
            end
        else
            while ast[i][1] == BIN_OP do
                i=i+1
            end
            i=i-1
            for j = i+1, #ast do
                local saveExpression
            
                if ast[j][1] == UN_OP then
                    if ast[j][2] == "!" then
                        j=j+1
                        returnBool = not boolExpression(ast[j])
                    end
                end
                if i > 0 then
                    if ast[i][2] == "&&" or ast[i][2] == "||" then
                        if returnBool == nil then
                            returnBool = boolExpression(ast[j])
                        elseif ast[i][2] == "&&" then
                            i=i-1
                            returnBool = returnBool and boolExpression(ast[j])
                        elseif ast[i][2] == "||" then
                            i=i-1
                            returnBool = returnBool or boolExpression(ast[j])
                        end
                    elseif isLHS(ast[j]) then
                        if tmpReturn == nil then
                            tmpReturn = intExpression(ast[j])
                        else
                            saveExpression = intExpression(ast[j])
                            if ast[i][2] == "==" then
                                returnBool = tmpReturn == saveExpression                    
                            elseif ast[i][2] == "!=" then
                                returnBool = tmpReturn ~= saveExpression
                            elseif ast[i][2] == ">" then
                                returnBool = tmpReturn > saveExpression
                            elseif ast[i][2] == "<" then
                                returnBool = tmpReturn < saveExpression
                            elseif ast[i][2] == ">=" then
                                returnBool = tmpReturn >= saveExpression
                            elseif ast[i][2] == "<=" then
                                returnBool = tmpReturn <= saveExpression
                            end
                            tmpReturn = saveExpression
                            i=i-1
                        end
                    end
                end
            end
        end
        return returnBool
    end

    function interp_stmt_list(ast)  -- Already declared local
        for i = 2, #ast do
            interp_stmt(ast[i])
        end
    end

    function interp_stmt(ast)
        local name, body, str

        if ast[1] == CR_STMT then
            outcall("\n")
        elseif ast[1] == PRINT_STMT then
            if ast[2][1] == STRLIT_VAL then
                str = ast[2][2]
                outcall(str:sub(2,str:len()-1))
            ----------------------Print stmt with expression-----------------------------
            elseif isLHS(ast[2]) then 
                body = intExpression(ast[2])
                outcall(numToStr(body))
            elseif boolExpression(ast[2]) == true then
                outcall("1")
            elseif boolExpression(ast[2]) == false then
                outcall("0")
            -----------------------------------------------------------------------------
            end
        elseif ast[1] == INPUT_STMT then
            ---------------------------Input stmt----------------------------------------
            if ast[2][1] == VARID_VAL then
                name = ast[2][2]
                body = incall()
                state.v[name] = strToNum(body)  
            elseif ast[2][1] == ARRAY_REF then
                name = ast[2][2][2]
                body = incall()
                if(state.a[name] == nil) then
                    state.a[name]={}
                end
                state.a[name][intExpression(ast[2][3])] = strToNum(body)
            end
            -----------------------------------------------------------------------------
        elseif ast[1] == SET_STMT then
            ------------------------------Set stmt---------------------------------------
            if ast[2][1] == VARID_VAL then
                name = ast[2][2]
                if isLHS(ast[3]) then
                    body = intExpression(ast[3])
                else
                    body = boolToInt( boolExpression(ast[3]))
                end
                state.v[name] = body
            elseif ast[2][1] == ARRAY_REF then
                name = ast[2][2][2]
                body = ast[3]
                if(state.a[name] == nil) then
                    state.a[name]={}
                end
                if isLHS(ast[3]) then
                    body = intExpression(ast[3])
                else
                    body = boolToInt( boolExpression(ast[3]))
                end
                state.a[name][intExpression(ast[2][3])] = body 
            end
            -----------------------------------------------------------------------------
        elseif ast[1] == SUB_STMT then
            name = ast[2]
            body = ast[3]
            state.s[name] = body
        elseif ast[1] == CALL_STMT then
            name = ast[2]
            body = state.s[name]
            if body == nil then
                body = { STMT_LIST }
            end
            interp_stmt_list(body)
        elseif ast[1] == IF_STMT then
            -------------------------------If stmt---------------------------------------
            local passed = false
            local counter = 2
            for i=2, #ast-1, 2 do
                if boolExpression(ast[i]) and not passed then
                    interp_stmt_list(ast[i+1])
                    passed = true
                end
                counter = i
            end
            if not passed and type(ast[counter+2]) == "table" then
                interp_stmt_list(ast[counter+2])
            end
            -----------------------------------------------------------------------------
        elseif ast[1] == WHILE_STMT then
            ------------------------------While stmt-------------------------------------
            while boolExpression(ast[2])  do
                interp_stmt_list(ast[3])
            end
            -----------------------------------------------------------------------------
        else
        end
    end

    -- Body of function interp
    interp_stmt_list(ast)
    return state
end


-- ***** Module Export *****


return interpit

