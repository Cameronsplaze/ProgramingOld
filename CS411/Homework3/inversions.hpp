// inversions.h
// Cameron Showalter
// 13 Oct 2017

#ifndef INVERSIONS_HPP_INCLUDED
#define INVERSIONS_HPP_INCLUDED

#include <cstddef>      // for std::size_t



#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <algorithm>
using std::copy;
#include <iterator>
using std::distance;
using std::advance;
#include <type_traits>
using std::remove_reference;

//**************************************************************************8
// Unmodified version of code wrote by Dr.Chappel, 9 October 2015
//	https://projects.cs.uaf.edu/cs411_2015_03.git
//**************************************************************************8







// stableMerge
// Merge two halves of a sequence, each sorted, into a single sorted
// sequence in the same location. Merge is done in a stable manner.
// Requirements on Types:
//     FDIter is a forward iterator type.
//     The value type of FDIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, middle) and [middle, last) are valid ranges, each sorted
//      by <.
// Post:
//     [first, last) contains the same items as it did initially, but
//      now sorted by < (in a stable manner).
template <typename FDIter>
void stableMerge(FDIter first, FDIter middle, FDIter last, int &totalSwaps)
{
    // ** C++03:
    //typedef typename iterator_traits<FDIter>::value_type Value;
    // ** C++11:
    using Value = typename remove_reference<decltype(*first)>::type;
    // ** Is this really better?

    vector<Value> buffer(distance(first, last));
                                // Buffer for temporary copy of data
    FDIter in1 = first;         // Read location in 1st half
    FDIter in2 = middle;        // Read location in 2nd half
    auto out = buffer.begin();  // Write location in buffer
    // ** auto! That *is* better than vector<Value>::iterator

    // Merge two sorted lists into a single list in buff.
    while (in1 != middle && in2 != last)
    {
        if (*in2 < *in1)  // Must do comparison this way, to be stable.
        {
            // you have to move the right half over whats left of the left half
            totalSwaps += middle - in1;
            *out++ = *in2++;
        }
        else
        {
            *out++ = *in1++;
        }
    }

    // Copy remainder of original sequence to buffer.
    // Only one of the following two copy calls will do anything, since
    //  the other is given an empty source range.
    copy(in1, middle, out);
    copy(in2, last, out);

    // Copy buffer contents back to original sequence location.
    copy(buffer.begin(), buffer.end(), first);

}


// mergeSort
// Sorts a sequence, using Merge Sort.
// Recursive.
// Requirements on Types:
//     FDIter is a forward iterator type.
//     The value type of FDIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, last) is a valid range.
// Post:
//     [first, last) contains the same items as it did initially,
//      but now sorted by < (in a stable manner).
template <typename FDIter>
void recurse(FDIter first, FDIter last, int &totalSwaps)
{
    // Compute size of sequence
    size_t size = distance(first, last);

    // BASE CASE
    if (size <= 1)
        return;

    // RECURSIVE CASE
    FDIter middle = first;
    advance(middle, size/2);  // middle is iterator to middle of range

    // Recursively sort the two lists
    recurse(first, middle, totalSwaps);
    recurse(middle, last, totalSwaps);

    // And merge them
    stableMerge(first, middle, last, totalSwaps);
    return;
}




//base case
//  pass a referance value that can be changed throughout the recursion

template <typename FDIter>
std::size_t inversions(FDIter first, FDIter last)
{
    int totalSwaps = 0;
    recurse(first, last, totalSwaps);
    return totalSwaps;
}


#endif // INVERSIONS_HPP_INCLUDED

