// bubble_sort_vector.cpp
// Glenn G. Chappell
// 21 Sep 2015
//
// For CS 411/611 Fall 2015
// Bubble Sort on a vector

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <algorithm>
using std::swap;
#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;


// bubbleSortVector
// Sort a vector using Bubble Sort.
// Requirements on Types:
//     operator< is a total order on type T.
//     Type T has a copy ctor & copy assignment.
// Pre:
//     None.
// Post:
//     v contains the same items as it did initially,
//      but now sorted by < -- in a stable manner.
template <typename T>
void bubbleSortVector(vector<T> & v)
{
    // Get size of vector
    size_t n = v.size();

    for (size_t pass = 0; pass <= n-2; ++pass)
        // Passes; exit when sorted
        // (n-pass) is number of items dealt with on the pass
        // That is, we deal with items 0 .. n-pass-1
        // Note: "pass" is called "i" in the Levitin text
    {
        // Do one Bubble Sort pass on v[0 .. n-pass-1],
        //  that is, on pairs from 0,1 up to n-pass-2,n-pass-1
        bool swapped = false;  // True if any swaps during this pass

        for (size_t j = 0; j <= n-pass-2; ++j)
            // v[j], v[j+1] are current pair
        {
            // Compare & maybe swap p[j], p[j+1]
            if (v[j+1] < v[j])  // Out of order?
            {
                swap(v[j], v[j+1]);
                swapped = true;
            }
        }

        // If no swaps, then vector is sorted; we're done
        if (!swapped)
            break;
    }
}


// Main program
// Demonstrates use of function bubbleSortVector.
int main()
{
    // Set up data to sort
    vector<int> v { 5, 3, 2, 8, 5, 9, 10, 4, 6, 1, -4 };

    // Print unaltered data
    cout << "Before:" << endl;
    for (const auto & val : v)
        cout << val << " ";
    cout << endl;
    cout << endl;

    // Do a sort
    bubbleSortVector(v);

    // Print results
    cout << "After:" << endl;
    for (const auto & val : v)
        cout << val << " ";
    cout << endl;
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

