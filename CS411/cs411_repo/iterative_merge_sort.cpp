// iterative_merge_sort.cpp
// Glenn G. Chappell
// 9 Oct 2015
//
// For CS 411/611 Fall 2015
// Iterative Merge Sort using Random-Access Iterators

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
#include <type_traits>
using std::remove_reference;


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
void stableMerge(FDIter first, FDIter middle, FDIter last)
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
            *out++ = *in2++;
        else
            *out++ = *in1++;
    }

    // Copy remainder of original sequence to buffer.
    // Only one of the following two copy calls will do anything, since
    //  the other is given an empty source range.
    copy(in1, middle, out);
    copy(in2, last, out);

    // Copy buffer contents back to original sequence location.
    copy(buffer.begin(), buffer.end(), first);
}


// iterativeMergeSort
// Sorts a sequence, using iterative variant of Merge Sort.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of RAIter.
// Pre:
//     [first, last) is a valid range.
// Post:
//     [first, last) contains the same items as it did initially,
//      but now sorted by < (in a stable manner).
// NOTE. We could make this iterative version of Merge Sort work with
// forward iterators, but it would be messy.
template <typename RAIter>
void iterativeMergeSort(RAIter first, RAIter last)
{
    // Compute size of entire range
    size_t size = last - first;

    // We merge ranges of size 1 into ranges of size 2. Then we merge
    // ranges of size 2 into ranges of size 4. This continues until
    // the entire range is sorted.
    //
    // The outer loop goes through sizes: 1, 2, 4, 8, etc. The inner
    // loop goes through pairs of ranges of the current size. Each pair
    // is merged into a single sorted range of twice that size. The last
    // subrange to be merged may need to be shorter.

    size_t partsize = 1;    // Size of two subranges to be merged
    while (partsize < size)
    {
        RAIter lo = first;  // Start of 1st subrange to be merged
        while (lo + partsize < last)
        {
            RAIter hi = lo + partsize * 2;
                            // Past end of 2nd subrange to be merged
            if (last < hi)
                hi = last;
            stableMerge(lo, lo + partsize, hi);

            lo = hi;        // Onward to the next pair of subranges
        }
        partsize *= 2;      // All ranges of current size have been
                            //  merged. Proceed to the next size
    }
}


// Main program
// Demonstrates use of function iterativeMergeSort.
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
    iterativeMergeSort(v.begin(), v.end());

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

