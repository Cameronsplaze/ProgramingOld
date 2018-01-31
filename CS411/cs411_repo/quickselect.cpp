// quickselect.cpp
// Glenn G. Chappell
// 7 Oct 2015
//
// For CS 411/611 Fall 2015
// Lomuto Partition & Quickselect

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <algorithm>
using std::iter_swap;
using std::swap;
#include <vector>
using std::vector;
#include <cstdlib>
using std::size_t;
#include <cassert>
// For assert


// lpartition
// Partitions a sequence about a given pivot. Uses Lomuto Algorithm.
// Returns the new pivot position via a reference parameter.
//
// Requirements on Types:
//     FDIter must be a forward iterator type.
//     The value type of FDIter must have copy=, operator<.
//     operator< must be a total order on the value type of FDIter.
// Pre:
//     [first, last) is a valid nonempty range.
//     pivotiter is an iterator in the range [first, last).
// Post:
//     [first, last) contains the same items as it did initially,
//      but now each ITEM before pivotiter has ITEM < *pivotiter,
//      and each ITEM after pivotiter has !(ITEM < *pivotiter).
//     pivotiter lies in [first, last) and references an item with
//      the same value as *pivotiter before the function call.
template <typename FDIter>
void lpartition(FDIter first, FDIter last,  // Range to partition
                FDIter & pivotiter)         // Iterator to pivot
{
    // Put the pivot at the start of the list
    iter_swap(first, pivotiter);

    // Now "first" points to the pivot

    // Make the "left list": list of items less than pivot
    FDIter leftFinal = first;  // points to final item in left list
    FDIter check = first;      // item to check
    for (++check;              // start after pivot, iterate thru list
         check != last;
         ++check)
    {
        if (*check < *first)              // if item < PIVOT
        {
            ++leftFinal;                  // move up end mark
            iter_swap(leftFinal, check);  // and put item in left list
        }
    }

    // Note new pivot position, for caller, and put pivot there
    pivotiter = leftFinal;
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


// quickselect
// Selection using Quickselect algorithm. [first, last) specifies a
//  nonempty range. index is an index in this range (0 .. size-1).
//  Return value is an iterator to the item in this range that would be
//  at the given index, if the range were sorted (not necessarily in a
//  stable manner). The range is modified, but not sorted.
// Uses lpartition, medianOf3
// Pre:
//     [first, last) is a nonempty valid range.
//     0 <= index < (last-first).
// Post:
//     Return is iterator to the item that would be at position given by
//      index, if the data were sorted (not necessarily in a stable
//      manner).
//     Data in [first, last) are same items as initially, but possibly
//      in a different order.
template <typename RAIter>
RAIter quickselect(RAIter first, RAIter last,  // Range: [first, last)
                   size_t index)               // Selection index
{
    while (true)  // For tail-recursion elimination
    {
        // Find median-of-three pivot & point pivotiter at it
        size_t size = last - first;
        assert (size != 0);
        RAIter pivotiter = medianOf3(first, first+size/2, last-1);

        // Do partition
        lpartition(first, last, pivotiter);
        size_t pivotindex = pivotiter - first;

        // BASE CASE of former recursive function
        // If the pivot is our item, then return it
        if (index == pivotindex)
            return pivotiter;

        // RECURSIVE CASE of former recursive function
        if (index < pivotindex)
        {   // Recurse on range of items preceding the pivot
            last = pivotiter;
        }
        else
        {   // Recurse on range of items following the pivot
            index -= pivotindex+1;
            first = pivotiter+1;
        }
        // Tail call is gone, replaced by loop
        // return quickselect(first, last, index);
    }
}


// makeSortedData
// Generate presorted data of the given size in the returned vector.
vector<int> makeSortedData(size_t size)
{
    vector<int> v(size);

    // Create sorted data
    for (size_t i = 0; i < size; ++i)
    {
        v[i] = int(i);
    }

    return v;
}


// makeMessyData
// Generate "messy" data of the given size in the returned vector.
// Values are in the range [0, maxv).
// Calling function quickselect on this data should result in typical
// behavior (average case, more or less).
vector<int> makeMessyData(size_t size, int maxv=1000000000)
{
    vector<int> v(size);

    // Create messy data
    const double phi = 1.6180339887498948482;
    for (size_t i = 0; i < size; ++i)
    {
        double x = double(i+1)*phi;
        double fracpart = x - int(x);
        v[i] = int(fracpart * maxv);
    }

    return v;
}


// makeMo3KillerData
// Generate median-of-3 killer data of the given size in the returned
// vector. This is the killer sequence for our optimized Quickselect.
// Calling function quickselect on this data should result in worst-case
// behavior.
vector<int> makeMo3KillerData(size_t size)
{
    vector<int> v(size);

    // Create killer data
    for (size_t i = 0; i < size; ++i)
        v[i] = int(i);
    if (size >= 2)
    {
        size_t esize = size - (size % 2);  // Greatest even num <= size
        for (size_t i = esize-2; ; i -= 2)
        {
            size_t m = i+(esize-i)/2;
            swap(v[i+1], v[m]);

            if (i == 0)
                break;
        }
    }

    return v;
}


// Main program
// Demonstrates function quickselect.
int main()
{
    // Variables
    vector<int> data;
    size_t index;
    vector<int>::const_iterator pos;
    const size_t SMALLSIZE = 12;
    const size_t BIGSIZE = 100000;

    // 1: Small Data
    // Prints data and results
    cout << "***** Try #1: small data" << endl;

    data = makeMessyData(SMALLSIZE, int(SMALLSIZE*2));
    cout << "Data size: " << data.size() << endl;
    index = data.size()*2/3;

    cout << endl;
    cout << "Before:" << endl;
    for (auto i : data)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << endl;
    cout << "Doing selection ... ";
    cout.flush();
    pos = quickselect(data.begin(), data.end(), index);
    cout << "DONE" << endl;

    cout << endl;
    cout << "After:" << endl;
    for (auto i : data)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << "Result of selection (index = " << index << "): "
         << *pos << endl;
    cout << endl;

    // 2: Big Messy Data
    cout << "***** Try #2: big messy data" << endl;

    data = makeMessyData(BIGSIZE);
    cout << "Data size: " << data.size() << endl;
    index = data.size()*2/3;
    cout << "Doing selection ... ";
    cout.flush();
    pos = quickselect(data.begin(), data.end(), index);
    cout << "DONE" << endl;
    cout << endl;

    // 3: Big Sorted Data
    cout << "***** Try #3: big sorted data" << endl;

    data = makeSortedData(BIGSIZE);
    cout << "Data size: " << data.size() << endl;
    index = data.size()*2/3;
    cout << "Doing selection ... ";
    cout.flush();
    pos = quickselect(data.begin(), data.end(), index);
    cout << "DONE" << endl;
    cout << endl;

    // 4: Big Median-of-3 Killer Data
    cout << "***** Try #4: big median-of-3 killer data" << endl;

    data = makeMo3KillerData(BIGSIZE);
    cout << "Data size: " << data.size() << endl;
    index = data.size()*2/3;
    cout << "Doing selection ... ";
    cout.flush();
    pos = quickselect(data.begin(), data.end(), index);
    cout << "DONE" << endl;
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

