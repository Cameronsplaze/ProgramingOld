// insertion_sort.cpp
// Glenn G. Chappell
// 28 Sep 2015
//
// For CS 411/611 Fall 2015
// Insertion Sort using Iterators

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <algorithm>
using std::rotate;


// insertionSortRec
// Sort a sequence using Insertion Sort.
// Recursive version.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     T must have a copy ctor and copy assignment.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, last) is a valid range.
// Post:
//     [first, last) contains the same items as it did initially,
//      but now sorted by < (in a stable manner).
template <typename RAIter>
void insertionSortRec(RAIter first, RAIter last)
{
    // Compute size of sequence
    size_t size = last - first;

    // BASE CASE
    if (size <= 1)
        return;

    // RECURSIVE CASE
    insertionSortRec(first, last-1);

    // Insert final item into earlier items
    size_t k;  // We use k after the loop, so declare it outside
    for (k = size-1; k != 0; --k)
        // Be careful! Backwards loop with unsigned counter
    {
        if (!(first[size-1] < first[k-1]))
            break;
    }
    // Final item should be in spot k - put it there

    rotate(first+k, last-1, last);
}


// insertionSortLoop
// Sort a sequence using Insertion Sort.
// Iterative version.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     T must have a copy ctor and copy assignment.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, last) is a valid range.
// Post:
//     [first, last) contains the same items as it did initially,
//      but now sorted by < (in a stable manner).
template <typename RAIter>
void insertionSortLoop(RAIter first, RAIter last)
{
    // Compute size of sequence
    size_t size = last - first;
    if (size <= 1)
        return;

    // Iterate through items, inserting each into earlier items
    for (size_t i = 1; i != size; ++i)
    {
        // Insert item i into sorted list of items 0 .. i-1
        size_t k;  // We use k after the loop, so declare it outside
        for (k = i; k != 0; --k)
            // Be careful! Backwards loop with unsigned counter
        {
            if (!(first[i] < first[k-1]))
                break;
        }
        // Item i should be in spot k - put it there

        rotate(first+k, first+i, first+(i+1));
    }
}


// Main program
// Demonstrates use of functions insertionSortRec / insertionSortLoop.
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
    insertionSortRec(v.begin(), v.end());   // Recursive version
    //insertionSortLoop(v.begin(), v.end());  // Iterative version

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

