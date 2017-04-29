//da3.cpp
//Cameron Showalter
//Assignment 3
//9-29-16
//Used with da3.h

#include "da3.h"
#include <functional>
using std::function;
//using namespace std;

// callBetween function.
// (See header file for docs.)
void callBetween(const std::function<void()> & start,
                 const std::function<void()> & middle,
                 const std::function<void()> & finish)
{
    start();
    try
    {
        middle();
    }
    catch(...)
    {
        finish();
        throw;
    }
    finish();
}
// primeRecursion function.
// Workhorse for isPrime function.
// Pre:
//      None.
// Post:
//      Returns true if number is prime or false if number is not prime.
bool primeRecursion(int n, int k)
{
    //Base
    if (n > k*k)
    {
        return true;
    }
    if (n%k == 0)
    {
        return false;
    }
    //Recursive
    else
    {
        return primeRecursion(n, k-1);
    }
}

// isPrime function.
// (See header file for docs.)
bool isPrime(int n)
{
    //Base
    if (n<=1)
    {
        return false;
    }
    //Recursive
    else
    {
        return primeRecursion(n, n-1);
    }
}
