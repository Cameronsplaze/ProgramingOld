#!/usr/bin/env lua




local pa2 = {}

---------------(First Test)---------------
    local function filterArray(f, inv)
        local ret = {}
        local counter = 1
        for i = 0, #inv, 1 do
            if inv[i] ~= nul then
                if f( inv[i] ) then
                    ret[counter] = inv[i]
                    counter = counter + 1
                end
            end
        end
        return ret
    end
    pa2.filterArray = filterArray

---------------(Second Test)---------------
    local function concatMax(str, num)
        printTimes = math.floor(num/str:len())
        return string.rep( str, printTimes)
    end
    pa2.concatMax = concatMax

---------------(Third Test)---------------

    local function collatz(t)

        while true do
            coroutine.yield(t)
            if t==1 then
                break;
            end
            if t%2==0 then
                t=t/2
            else
               t = (3*t)+1
            end
        end
    end
    pa2.collatz = collatz


return pa2

