-- Cameron Showalter
-- CS331 Spring 2017
module PA5 where
import Data.List


tuple (_,second) = second

-- FilterAB
filterAB fn list1 list2 = returnMe where 
    pairedList = zip list1 list2
    trueList = filter (fn.fst) pairedList
    returnMe = tuple (unzip trueList)

-- ##operator
(##) :: Eq a => [a] -> [a] -> Int
[] ## _ = 0
_ ## [] = 0
(lhs1:rhs1) ## (lhs2:rhs2)
    | lhs1 == lhs2 = 1 + rhs1 ## rhs2
    | otherwise = rhs1 ## rhs2

-- findList
findList :: Eq a => [a] -> [a] -> Maybe Int
findList list1 list2 = findIndex (isPrefixOf list1) (tails list2)

-- collatzCounts
collatzCounts :: [Integer]
collatzCounts = map collatzTotal [0..]

collatzSum n i
    | n == 1 = i
    | mod n 2 == 0 = collatzSum (div n 2) (i+1)
    | otherwise = collatzSum ((3*n)+1) (i+1)

collatzTotal n = collatzSum (n+1) 0
