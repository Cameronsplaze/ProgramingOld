// rpmult.cpp
// Glenn G. Chappell
// 5 Oct 2015
//
// For CS 411/611 Fall 2015
// Russian Peasant Multiplication

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <algorithm>
using std::swap;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <cstdlib>
using std::exit;


// rpMult
// Compute and return the product of a, b.
// Uses "Russian Peasant Multiplication". Should be able to handle any
// product that operator* can compute.
// Pre: None.
// Post:
//     Return == a * b.
// Note that postcondtions should hold even when a*b produces numeric
// overflow.
int rpMult(int a,
           int b)
{
    // Determine whether product is negative
    bool neg = false;  // Will be true for negative product
    if (a < 0)
    {
        neg = !neg;
        a = -a;
    }
    if (b < 0)
    {
        neg = !neg;
        b = -b;
    }

    // We want a to be the smaller of a, b
    if (b < a)
        swap(a, b);

    // result: sum of right-hand operands whose corresponding left-hand
    //  operand is odd. When we are done, result should hold a * b.
    int result = 0;

    // R-P Multiplication loop
    while (a > 0)
    {
        if (a % 2 != 0)
            result += b;
        a /= 2;
        b *= 2;
    }

    // Fix the sign, and we're finished
    return neg ? -result : result;
}


// getNum
// Prints prompt to cout and then inputs a number of type int on a line
// from cin. Repeats until valid number obtained; returns it to caller
// in reference argument. Return is false if number could not be
// obtained.
bool getNum(const string & prompt,
            int & num)
{
    while (true)
    {
        cout << prompt;
        string line;
        getline(cin, line);
        if (!cin)
        {
            if (cin.eof())
                return false;
            continue;
        }

        istringstream istr(line);
        istr >> num;
        if (!istr)
            continue;
        return true;
    }
}


// Main program
// Use function rpMult to compute the product of user-provided numbers.
int main()
{
    // Get two numbers to multiply
    int a, b;  // Numbers to multiply
    cout << endl;
    cout << "I need two numbers to multiply together" << endl;
    cout << endl;
    if (!getNum("Enter the first number: ", a))
    {
        cout << "Could not do input" << endl;
        exit(1);
    }
    cout << endl;
    if (!getNum("Enter the second number: ", b))
    {
        cout << "Could not do input" << endl;
        exit(1);
    }
    cout << endl;

    // Print divider between user input, results
    cout << "----------------------------------------" << endl;
    cout << endl;

    // Compute & print results
    cout << "Numbers to multiply: " << a << ", " << b << endl;
    int rpmprod = rpMult(a, b);
    int prod = a * b;
    cout << "Russian Peasant Multiplication result: " << rpmprod
         << endl;
    cout << "C++ operator* result: " << prod << endl;
    cout << endl;

    // Check the result
    if (rpmprod == prod)
    {
        cout << "The results are equal." << endl;
        cout << "Awesomely nifty!" << endl;
    }
    else
    {
        cout << "The results differ." << endl;
        cout << "Crud, phooey, and more crud!" << endl;
    }
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

