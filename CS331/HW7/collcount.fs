\ collcount-fs

\ Cameron Showalter
\ CS 331, Spring 2017
\ Assignment 7, Part B



\ logic to collcount: n/2  if odd, else 3n+1
: collcount_counter ( r l -- r+1 x x==1 )
  dup
  1 2
  */MOD drop
  0 = if 2 / else 3 * 1 + then
  swap 1 + swap
  dup 1 =
;

\ collcount
\ Runs the collez formula and returns the times it took to get to one
: collcount ( l -- r )
  0 swap
  dup
  1 <> if
      begin
          collcount_counter
      until
  then drop
;


