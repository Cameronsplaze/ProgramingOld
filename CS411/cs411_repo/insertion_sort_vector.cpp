// insertion_sort_vector.cpp
// Glenn G. Chappell
// 14 Sep 2015
//
// For CS 411/611 Fall 2015
// Insertion Sort on a vector

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;


// insertionSortVector
// Sort a vector using Insertion Sort.
// Requirements on Types:
//     operator< is a total order on type T.
//     Type T has a copy ctor & copy assignment.
// Pre:
//     None.
// Post:
//     v contains the same items as it did initially,
//      but now sorted by < -- in a stable manner.
template <typename T>
void insertionSortVector(vector<T> & v)
{
    // Get size of vector
    size_t size = v.size();
    if (size <= 1)
        return;

    // Iterate through items, inserting each into earlier items
    for (size_t i = 1; i != size; ++i)
    {
        // Insert item i into sorted list of items 0 .. i-1

        // First find the spot to insert item i
        size_t k;  // We use k after the loop, so declare it outside
        for (k = i; k != 0; --k)
            // Be careful! Backwards loop with unsigned counter
        {
            if (!(v[i] < v[k-1]))
                break;
        }

        // k is now the subscript of the spot item i should be in
        // So put item i there
        T insertme = v[i];
        for (size_t m = i; m != k; --m)
            // Be careful! Backwards loop with unsigned counter
        {
            v[m] = v[m-1];
        }
        v[k] = insertme;
    }
}


// Main program
// Demonstrates use of function insertionSortVector.
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
    insertionSortVector(v);

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

