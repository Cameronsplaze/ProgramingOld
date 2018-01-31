// selection_sort_vector.cpp
// Glenn G. Chappell
// 21 Sep 2015
//
// For CS 411/611 Fall 2015
// Selection Sort on a vector

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


// selectionSortVector
// Sort a vector using Selection Sort.
// Requirements on Types:
//     operator< is a total order on type T.
//     Type T has a copy ctor & copy assignment.
// Pre:
//     None.
// Post:
//     v contains the same items as it did initially,
//      but now sorted by <.
template <typename T>
void selectionSortVector(vector<T> & v)
{
    size_t n = v.size();  // Size of dataset

    for (size_t pass = 0; pass <= n-2; ++pass)  // Passes
        // Passes
        // We deal with items pass .. n-1
        // Note: "pass" is called "i" in the Levitin text
    {
        // Look in v[pass .. n-1]
        //  and find the item that goes in v[pass].

        size_t indexOfSmallest = pass;  // Index of smallest so far
        for (size_t j = pass+1; j <= n-1; ++j)
        {
            if (v[j] < v[indexOfSmallest])
                indexOfSmallest = j;
        }

        // Now v[indexOfSmallgest] goes in v[pass].
        // Put it there, swapping so that the old v[pass] stays around.
        swap(v[indexOfSmallest], v[pass]);
    }
}


// Main program
// Demonstrates use of function selectionSortVector.
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
    selectionSortVector(v);

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

