// fibo_recurse.cpp
// Glenn G. Chappell
// 16 Sep 2015
//
// For CS 411/611 Fall 2015
// Computing Fibonacci Numbers
// Recursive (return 2, with wrapper)

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstdint>
using std::uint_fast64_t;
#include <utility>
using std::pair;


// Type unum
// Type of values used for large-ish integer computation.
// Should be an unsigned integer type.
using unum = uint_fast64_t;  // >= 64 bits, fast, unsigned


// Type upair: pair of unum values. For function fibo_recurse.
using upair = pair<unum, unum>;

// fibo_recurse
// Given n, returns F(n-1), F(n) ((n-1)th and nth Fibonacci numbers).
// F(-1) = 1. F(0) = 0. F(1) = 1. For n >= 2, F(n) = F(n-2) + F(n-1).
// Recursive.
// Pre:
//     n >= 0.
//     F(n) is a valid unum value.
// For 64-bit unsigned, preconditions hold if 0 <= n <= 93.
// Post:
//     Return is pair<int, int>(F(n-1), F(n)).
// Does not throw.
upair fibo_recurse(int n)
{
    // BASE CASE
    if (n == 0)
        return upair(1, 0);

    // RECURSIVE CASE
    upair oldPair = fibo_recurse(n-1);
    return upair(oldPair.second, oldPair.first + oldPair.second);
}


// fibo
// Given n, returns F(n) (the nth Fibonacci number).
// F(0) = 0. F(1) = 1. For n >= 2, F(n) = F(n-2) + F(n-1).
// Uses fibo_recurse.
// Pre:
//     n >= 0.
//     F(n) is a valid unum value.
// For 64-bit unsigned, preconditions hold if 0 <= n <= 93.
// Post:
//     Return is F(n).
// Does not throw.
unum fibo(int n)
{
    return fibo_recurse(n).second;
}


// main
// Prints i, F(i) for i = 0, 1, 2, ... through the greatest legal
// value for our function.
// Uses fibo.
int main()
{
    cout << "Fibonacci Numbers" << endl;
    cout << endl;
    for (int i = 0; i <= 93; ++i)
    {
        cout << i << ": " << fibo(i) << endl;
    }
    cout << endl;

    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

