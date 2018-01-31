// counting_sort_vector.cpp
// Glenn G. Chappell
// 28 Oct 2015
//
// For CS 411/611 Fall 2015
// Counting Sorts on a vector

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <algorithm>
using std::minmax_element;


// comparisonCountingSort
// Sort a vector, using Comparison Counting Sort
// Requirements on Types:
//     operator< is a total order on type T.
//     Type T has a copy ctor & copy assignment.
// Pre:
//     Difference between largest & smallest items in v is a feasible
//      array index.
// Post:
//     v contains the same items as it did initially, but now sorted by
//      < (in a stable manner).
template <typename Val>
void comparisonCountingSort(vector<Val> & data)
{
    vector<Val> buffer(data.size());
    for (size_t i = 0; i < data.size(); ++i)
    {
        // Interation i puts data[i] in proper place in buffer

        // Count # of items that should come before data[i]
        size_t countbefore = 0;
        for (size_t k = 0; k < i; ++k)
        {
            if (!(data[i] < data[k]))
                ++countbefore;
        }
        for (size_t k = i+1; k < data.size(); ++k)
        {
            if (data[k] < data[i])
                ++countbefore;
        }

        // Put data[i] in its place
        buffer[countbefore] = data[i];
    }

    // Copy back to original storage
    data = buffer;
}


// distributionCountingSort
// Sort a vector, using Distribution Counting Sort
void distributionCountingSort(vector<int> & data)
{
    // FInd min, max elements of data
    auto p = minmax_element(data.begin(), data.end());
    auto minelt = *(p.first);
    auto maxelt = *(p.second);

    // Initialize frequencies
    vector<size_t> freqs(maxelt-minelt+1, 0);
    for (size_t i = 0; i < data.size(); ++i)
    {
        ++freqs[data[i]-minelt];
    }

    // freqs[k-minval] is now the number of times k occurs in v.

    // Replace freqs[k] with sum of freqs[0]..freqs[k-1]
    size_t runtotal = 0;
    for (size_t i = 0; i < freqs.size(); ++i)
    {
        size_t save = freqs[i];
        freqs[i] = runtotal;
        runtotal += save;
    }

    // freqs[k-minval] is now the index, in sorted version of v, of 1st
    //  item equal to k (if any).

    // Make sorted list
    vector<int> buffer(data.size());
    for (size_t i = 0; i < data.size(); ++i)
    {
        buffer[freqs[data[i]-minelt]] = data[i];
        ++freqs[data[i]-minelt];  // Update index for next w/ same value
    }

    // Copy back to original storage
    data = buffer;
}


// Main program
// Demonstrates use of Counting Sort functions.
int main()
{
    // Set up data to sort
    vector<int> v { 5, 3, 2, 8, 8, 8, 8, 5, 9, 10, 4, 8, 6, 1, -4 };

    // Print unaltered data
    cout << "Before:" << endl;
    for (const auto & val : v)
        cout << val << " ";
    cout << endl;
    cout << endl;

    // Call one of the Counting Sort functions
    //comparisonCountingSort(v);
    distributionCountingSort(v);

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

