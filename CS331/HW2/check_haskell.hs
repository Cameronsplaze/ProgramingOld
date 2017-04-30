-- check_haskell.hs
-- Glenn G. Chappell
-- 2 Feb 2017
--
-- For CS F331 / CSCE A331 Spring 2017
-- A Haskell Program to Run
-- Used in Assignment 2, Exercise A

module Main where


-- main
-- Print second secret message.
main = do
    putStrLn "Secret message #2:"
    putStrLn ""
    putStrLn secret_message


-- secret_message
-- A mysterious String.
secret_message = map ordToC ords where
    d1 = [76,45,-59,93,12,7,-3,-59]
    d2 = [94,5,-69,78,24,1,15,7]
    d3 = [-65,99,0,16,7,-72,57,49]
    d4 = [-11,21,18,-1,15,1,-58]
    diffs = map (+ offset) $ concat [d1, d2, d3, d4]
    thisAndAdd x xs = x : map (+ x) xs
    ords = foldr thisAndAdd [] diffs
    ordToC n = toEnum n `asTypeOf` '@'
    offset = -10

