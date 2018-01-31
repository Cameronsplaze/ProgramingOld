// fibo_dp_bottomup.cpp
// Glenn G. Chappell
// 4 Nov 2015
//
// For CS 411/611 Fall 2015
// Computing Fibonacci Numbers
// Dynamic Programming (Bottom-Up)

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstdint>
using std::uint_fast64_t;
#include <vector>
using std::vector;


// Type unum
// Type of values used for large-ish integer computation.
// Should be an unsigned integer type.
using unum = uint_fast64_t;  // >= 64 bits, fast, unsigned


// fibo
// Given n, returns F(n) (the nth Fibonacci number).
// F(0) = 0. F(1) = 1. For n >= 2, F(n) = F(n-2) + F(n-1).
// Pre:
//     n >= 0.
//     F(n) is a valid unum value.
// For 64-bit unsigned, preconditions hold if 0 <= n <= 93.
// Post:
//     Return is F(n).
// Does not throw.
unum fibo(int n)
{
    vector<unum> fibotable(n+1);  // fibotable[i] will be ith Fibonacci

    for (int i = 0; i <= n; ++i)
    {
        if (i <= 1)
            fibotable[i] = unum(i);
        else
            fibotable[i] = fibotable[i-1] + fibotable[i-2];
    }
    return fibotable[n];
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

