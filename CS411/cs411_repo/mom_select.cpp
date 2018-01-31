// mom_select.cpp
// Glenn G. Chappell
// 7 Oct 2015
//
// For CS 411/611 Fall 2015
// Median-of-Medians Selection
// (a.k.a. Blum-Floyd-Pratt-Rivest-Tarjan Selection)

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


// Forward declarations:

// momSelect
// Selection using Median-of-Medians Selection algorithm.
template <typename RAIter>
RAIter momSelect(RAIter first, RAIter last,  // Range: [first, last)
                 size_t index);              // Selection index


// lpartition
// Partitions a sequence about a given pivot. Uses Lomuto Algorithm.
// Returns the new pivot position via a reference parameter.
//
// Requirements on Types:
//     FDIter must be a forward iterator type.
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


// medianOf5
// Given 5 iterators, finds the median of the values they reference and
//  returns an iterator to it. Values are not altered; return value is
//  always equal to one of the parameters.
// Performs at most 6 comparisons.
// NOT stable (in the non-mutating selection-algorithm sense).
// Based on http://stackoverflow.com/a/2117018 by user DRBlaise.
template <typename Iter>
Iter medianOf5(Iter ai, Iter bi, Iter ci, Iter di, Iter ei)
{
    auto & a(*ai);
    auto & b(*bi);
    auto & c(*ci);
    auto & d(*di);
    auto & e(*ei);

    return b < a ? d < c ? b < d ? a < e ? a < d ? e < d ? ei : di
                                                 : c < a ? ci : ai
                                         : e < d ? a < d ? ai : di
                                                 : c < e ? ci : ei
                                 : c < e ? b < c ? a < c ? ai : ci
                                                 : e < b ? ei : bi
                                         : b < e ? a < e ? ai : ei
                                                 : c < b ? ci : bi
                         : b < c ? a < e ? a < c ? e < c ? ei : ci
                                                 : d < a ? di : ai
                                         : e < c ? a < c ? ai : ci
                                                 : d < e ? di : ei
                                 : d < e ? b < d ? a < d ? ai : di
                                                 : e < b ? ei : bi
                                         : b < e ? a < e ? ai : ei
                                                 : d < b ? di : bi
                 : d < c ? a < d ? b < e ? b < d ? e < d ? ei : di
                                                 : c < b ? ci : bi
                                         : e < d ? b < d ? bi : di
                                                 : c < e ? ci : ei
                                 : c < e ? a < c ? b < c ? bi : ci
                                                 : e < a ? ei : ai
                                         : a < e ? b < e ? bi : ei
                                                 : c < a ? ci : ai
                         : a < c ? b < e ? b < c ? e < c ? ei : ci
                                                 : d < b ? di : bi
                                         : e < c ? b < c ? bi : ci
                                                 : d < e ? di : ei
                                 : d < e ? a < d ? b < d ? bi : di
                                                 : e < a ? ei : ai
                                         : a < e ? b < e ? bi : ei
                                                 : d < a ? di : ai;
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


// momPivot
// Does Median-of-Medians pivot choice.
// Returns iterator to pivot.
template <typename RAIter>
RAIter momPivot(RAIter first, RAIter last)
{
    assert (last != first);
    if (last-first == 1)
        return first;

    RAIter spot = first;
    for (RAIter five = first; five < last; five += 5)
    {
        RAIter median;
        if (last-five < 5)
        {
            if (last-five >= 3)
                // A median of a,b,c is a median of a,b,c,d
                median = medianOf3(five, five+1, five+2);
            else
                // A median of a or of a,b is just a
                median = five;
        }
        else
            median = medianOf5(five, five+1, five+2, five+3, five+4);

        iter_swap(median, spot);
        ++spot;
    }

    // Pivot is median of our list of medians; find with momSelect
    return momSelect(first, spot, (spot-first)/2);
}


// momSelect
// Selection using Median-of-Medians Selection algorithm. [first, last)
//  specifies a nonempty range. index is an index in this range
//  (0 .. size-1). Return value is an iterator to the item in this range
//  that would be at the given index, if the range were sorted (not
//  necessarily in a stable manner). The range is modified, but not
//  sorted.
// Uses lpartition, momPivot
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
RAIter momSelect(RAIter first, RAIter last,  // Range: [first, last)
                 size_t index)               // Selection index
{
    assert (last != first);
    while (true)  // For tail-recursion elimination
    {
        // Find median-of-medians pivot & point pivotiter at it
        RAIter pivotiter = momPivot(first, last);
                                             // Indirect recursion!

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
        // return momSelect(first, last, index);
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
// Demonstrates function momSelect.
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
    pos = momSelect(data.begin(), data.end(), index);
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
    pos = momSelect(data.begin(), data.end(), index);
    cout << "DONE" << endl;
    cout << endl;

    // 3: Big Sorted Data
    cout << "***** Try #3: big sorted data" << endl;

    data = makeSortedData(BIGSIZE);
    cout << "Data size: " << data.size() << endl;
    index = data.size()*2/3;
    cout << "Doing selection ... ";
    cout.flush();
    pos = momSelect(data.begin(), data.end(), index);
    cout << "DONE" << endl;
    cout << endl;

    // 4: Big Median-of-3 Killer Data
    cout << "***** Try #4: big median-of-3 killer data" << endl;

    data = makeMo3KillerData(BIGSIZE);
    cout << "Data size: " << data.size() << endl;
    index = data.size()*2/3;
    cout << "Doing selection ... ";
    cout.flush();
    pos = momSelect(data.begin(), data.end(), index);
    cout << "DONE" << endl;
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

