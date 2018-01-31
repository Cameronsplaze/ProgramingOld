// fibo_dp_topdown.cpp
// Glenn G. Chappell
// 6 Nov 2015
//
// For CS 411/611 Fall 2015
// Computing Fibonacci Numbers
// Dynamic Programming (Top-Down)

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstdint>
using std::uint_fast64_t;
#include <vector>
using std::vector;
#include <cassert>
// For assert


// Type unum
// Type of values used for large-ish integer computation.
// Should be an unsigned integer type.
using unum = uint_fast64_t;  // >= 64 bits, fast, unsigned


// Marker for unknown values in table
const unum UNKNOWN = 9999999999999999999ULL;


// fibo_recurse
// Given n, returns F(n) (the nth Fibonacci number).
// F(0) = 0. F(1) = 1. For n >= 2, F(n) = F(n-2) + F(n-1).
// Pre:
//     n >= 0.
//     F(n) is a valid unum value.
// For 64-bit unsigned, above preconditions hold if 0 <= n <= 93.
//     n < fibotable.size().
//     For each i, fibotable[i] is either UNKNOWN or F(i).
// Post:
//     Return is F(n).
// Recursive helper function for fibo.
unum fibo_recurse(vector<unum> & fibotable,
                  int n)
{
    assert (n < int(fibotable.size()));
    unum result;  // For our final result

    // Check if we have already computed this; if so, do not recompute
    if (fibotable[n] != UNKNOWN)
        return fibotable[n];

    if (n <= 1)  // BASE CASE
    {
        result = static_cast<unum>(n);
    }
    else         // RECURSIVE CASE
    {
        result =
            fibo_recurse(fibotable, n-2) + fibo_recurse(fibotable, n-1);
    }

    // Save our result and return it
    fibotable[n] = result;
    return result;
}


// fibo
// Given n, returns F(n) (the nth Fibonacci number).
// F(0) = 0. F(1) = 1. For n >= 2, F(n) = F(n-2) + F(n-1).
// Pre:
//     n >= 0.
//     F(n) is a valid unum value.
// For 64-bit unsigned, preconditions hold if 0 <= n <= 93.
// Post:
//     Return is F(n).
// Uses recursive helper function fibo_recurse.
unum fibo(int n)
{
    vector<unum> fibotable(n+1, UNKNOWN);
                 // fibotable[i] will be ith Fibonacci
                 // UNKNOWN marks values not yet computed
    return fibo_recurse(fibotable, n);
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

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

