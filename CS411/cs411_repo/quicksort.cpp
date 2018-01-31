// quicksort.cpp
// Glenn G. Chappell
// 12 Oct 2015
//
// For CS 411/611 Fall 2015
// Hoare Partition & Quicksort

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <algorithm>
using std::iter_swap;
#include <cassert>
// For assert


// hpartition
// Partitions a sequence about a given pivot. Uses Hoare Algorithm.
// Returns the new pivot position via a reference parameter.
//
// Requirements on Types:
//     RAIter must be a random-access iterator type.
//     The value type of RAIter must have copy=, operator<.
//     operator< must be a total order on the value type of RAIter.
// Pre:
//     [first, last) is a valid nonempty range.
//     pivotiter is an iterator in the range [first, last).
// Post:
//     [first, last) contains the same items as it did initially, but
//      now each ITEM before pivotiter has !(*pivotiter < ITEM), and
//      each ITEM after pivotiter has !(ITEM < *pivotiter).
//     pivotiter lies in [first, last) and references an item with the
//      same value as *pivotiter before the function call.
// NOTE. We could make Hoare Partition work with bidirectional
// iterators, but it would be messy.
template <typename RAIter>
void hpartition(RAIter first, RAIter last, RAIter & pivotiter)
{
    // Put the pivot at the start of the list
    iter_swap(first, pivotiter);

    // Now "first" points to the pivot

    // Iterator left: all items before it have !(PIVOT < ITEM)
    RAIter left = first+1;
    // Iterator right: all items after it have !(ITEM < PIVOT)
    RAIter right = last-1;
    // In the loop below, we stop when items before left + items
    //  after right are the entire list.

    while (left <= right)
    {
        // Move left & right in as far as we can
        if (!(*first < *left))        // if *left <= PIVOT
            ++left;
        else if (!(*right < *first))  // if *right >= PIVOT
            --right;
        // If we can move neither left nor right, then swap their items
        else
        {
            iter_swap(left, right);
            ++left;
            --right;
        }
    }

    // Note new pivot position, for caller, and put pivot there
    pivotiter = right;
    iter_swap(first, pivotiter);
}


// medianOf3
// Given 3 iterators, finds the median of the values they reference and
//  returns an iterator to it. Values are not altered; return value is
//  always equal to one of the parameters.
// Performs at most 3 comparisons.
// Stable (in the non-mutating selection-algorithm sense).
template <typename Iter>
Iter medianOf3(Iter ai, Iter bi, Iter ci)
{
    auto & a(*ai);
    auto & b(*bi);
    auto & c(*ci);

    return b < a ? c < a ? c < b ? bi : ci
                         : ai
                 : c < b ? c < a ? ai : ci
                         : bi;
}


// quicksort
// Sorts a sequence, using Quicksort. Includes following optimizations:
// - Median-of-3 pivot selection
// - Tail-recursion elimination on larger recursive call
// Does NOT include final Insertion Sort pass or switch to Heap Sort
//  when recursion depth is large.
// Recursive.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     operator< is a total order on the value type of RAIter.
// Pre:
//     [first, last) is a valid range.
// Post:
//     [first, last) contains the same items as it did initially,
//      but now sorted by <.
template <typename RAIter>
void quicksort(RAIter first, RAIter last)
{
    while (true)  // For tail-recursion elimination
    {
        size_t size = last - first;

        // BASE CASE
        if (size <= 1)
            return;

        // RECURSIVE CASE

        // Find median-of-three pivot & point pivotiter at it
        assert (size != 0);
        RAIter pivotiter = medianOf3(first, first+size/2, last-1);

        // Do partition
        hpartition(first, last, pivotiter);

        // Do actual recursive call on smaller of two parts;
        //  tail-recursion elimination on the other
        if (pivotiter-first < last-pivotiter-1)
        {
            quicksort(first, pivotiter);
            //quicksort(pivotiter+1, last);
            first = pivotiter+1;
        }
        else
        {
            quicksort(pivotiter+1, last);
            //quicksort(first, pivotiter);
            last = pivotiter;
        }
        // Tail call is gone, replaced by loop
        //quicksort(first, last);
    }
}


// Main program
// Demonstrates use of function quicksort.
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
    quicksort(v.begin(), v.end());

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

