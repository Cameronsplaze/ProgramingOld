// binary_search.cpp
// VERSION 2
// Glenn G. Chappell
// 4 Oct 2015
// Updated: 5 Oct 2015
//
// For CS 411/611 Fall 2015
// Binary Search using Iterators

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <iterator>
using std::distance;
using std::advance;


// binarySearch
// Does Binary Search on a range specified with iterators.
// Requirements on types:
//     FDIter is a forward iterator type.
//     ValueType is the value type of FDIter.
//     ValueType has a public operator<.
//     operator< is a total order on ValueType.
// Pre:
//     [first, last) is a valid range.
//     Values in the range are sorted by < (ascending).
// Post:
//     Return is true if findme was found (using equivalence) in range,
//      false otherwise.
template <typename FDIter, typename ValueType>
bool binarySearch(FDIter first, FDIter last,  // Range to search
                  const ValueType & findme)   // Value to find
{
    while (true)  // For tail-recursion elimination
    {
        size_t size = distance(first, last);  // Size of range

        // BASE CASE of former recursive function

        if (size <= 1)
        {
            if (size == 0)
                return false;
            return !(*first < findme) && !(findme < *first);
        }

        // RECURSIVE CASE of former recursive function

        // Get iterator to middle position of range
        FDIter middle = first;
        advance(middle, size/2);

        if (findme < *middle)
        {   // Search first half of range
            last = middle;
        }
        else
        {   // Search second half of range
            first = middle;
        }

        // Tail call is gone, replaced by loop
        //return binarySearch(first, last, findme);
    }
}


// doSearch
// Do a search using function binarySearch with the given data & key.
// Print result.
void doSearch(const vector<int> & data,  // Data to search in
              int key,                   // Key to search for
              bool expect)               // Expected result
{
    // Do search
    cout << "Searching for key: " << key << endl;
    bool success = binarySearch(data.begin(), data.end(), key);

    // Print result
    cout << "Result: " << (success ? "found" : "not found") << endl;
    cout << "Same as expected result: "
         << (success == expect ? "yes" : "NO *************************")
         << endl;
    cout << endl;
}


// Main program
// Do several searches using binarySearch
int main()
{
    // Set up data to search
    vector<int> data;
    const int SIZE = 100000;
    for (auto i = 0; i < SIZE; ++i)
        data.push_back(10*i);

    doSearch(data, 40, true);   // Search for 40, expect to find it
    doSearch(data, 45, false);  // Search for 45, expect not to find it
    doSearch(data, 1000, true);
    doSearch(data, 1001, false);
    doSearch(data, -1, false);

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

