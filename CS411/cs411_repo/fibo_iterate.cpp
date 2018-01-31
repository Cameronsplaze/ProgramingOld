// fibo_iterate.cpp
// Glenn G. Chappell
// 16 Sep 2015
//
// For CS 411/611 Fall 2015
// Computing Fibonacci Numbers
// Iterative

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <cstdint>
using std::uint_fast64_t;


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
    // Two variables to hold consecutive Fibonacci numbers:
    unum prev = static_cast<unum>(1);  // F(-1)
    unum curr = static_cast<unum>(0);  // F(0)

    for (int k = 0; k < n; ++k)
    {
        // prev == F(k-1)
        // curr == F(k)

        // Slide prev & curr to the right
        unum next = prev + curr;  // Next Fibonacci number after curr
        prev = curr;
        curr = next;

        // prev == F(k)
        // curr == F(k+1)
    }

    // curr == F(n)
    return curr;
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

