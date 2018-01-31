// heap_sort.cpp
// Glenn G. Chappell
// 26 Oct 2015
//
// For CS 411/611 Fall 2015
// Heap Algorithms & Heap Sort

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <algorithm>
using std::swap;
using std::iter_swap;
#include <cassert>
// For assert


// *********************************************************************
// testHeap & heapInsert are provided for reference purposes. They are
// not used by heapSort.
// *********************************************************************


// testHeap
// Determines whether given random-access range is a Heap.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <.
// Pre:
//     [first, last) is a valid range.
// Post:
//     Return value is true iff given range is a Heap.
template<typename RAIter>
bool testHeap(RAIter first, RAIter last)
{
    size_t size = last - first;
    // Compare each non-root item with its parent
    for (size_t index = 1; index < size; ++index)
    {
        if (first[(index-1)/2] < first[index])
            return false;
    }
    return true;
}


// heapInsert
// Heap insert operation on a random-access range.
// Inserts *(last-1) into Heap [first, last-1).
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid range.
//     [first, last-1) forms a Heap.
// Post:
//     [first, last) contains the same items as it did initially, but
//      now forming a Heap.
template<typename RAIter>
void heapInsert(RAIter first, RAIter last)
{
    assert(last != first);
    size_t curr = (last-first)-1;    // Index of item to "trickle up"
    while (curr != 0)
    {
        size_t parent = (curr-1)/2;  // Index of parent
        if (!(first[parent] < first[curr]))
            break;  // No more trickling; done

        // Trickle up one level
        swap(first[curr], first[parent]);
        curr = parent;
    }
}


// *********************************************************************
// Functions below used by heapSort.
// *********************************************************************


// trickleDown
// Internal-use function for heapDelete, makeHeap.
// Does "trickle down" of item at given location into existing partial
// Heap.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid nonempty range.
//     location lies in [first, last).
//     (location, last) is a partial Heap.
//      That is, !(first[(k-1)/2] < first[k]), whenever both
//      first+(k-1)/2 and first+k lie in (location, last).
// Post:
//     [location, last) is a partial Heap containing the same items as
//      initially.
template<typename RAIter>
void trickleDown(RAIter first, RAIter last, RAIter location)
{
    size_t size = last - first;
    size_t curr = location - first;  // Index of item to "trickle down"
    assert(curr < size);
    while (true)
    {
        size_t lchild = 2*curr+1;    // Index of left child (if any)
        if (lchild >= size)          // Are there any children?
            break;                   // If not, done

        size_t bigchild = lchild;    // Will hold index of bigger child
        if (lchild+1 < size && first[lchild] < first[lchild+1])
            bigchild = lchild+1;

        if (!(first[curr] < first[bigchild]))
            break;  // No more trickling; done

        // Trickle down one level
        swap(first[curr], first[bigchild]);
        curr = bigchild;
    }
}


// heapDelete
// Heap delete operation on a random-access range.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid nonempty range.
//     [first, last) forms a Heap.
// Post:
//     *(last-1) is the former *first.
//     [first, last-1) forms a Heap with the remaining items.
template<typename RAIter>
void heapDelete(RAIter first, RAIter last)
{
    assert(last != first);
    iter_swap(first, last-1);
    trickleDown(first, last-1, first);
}


// makeHeap
// Turns the given random-access range into a Heap using a linear number
// of compare & swap operations.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid range.
// Post:
//     [first, last) contains the same items as it did initially, but
//      now forming a Heap.
template<typename RAIter>
void makeHeap(RAIter first, RAIter last)
{
    // Trickle down every item in the range, in reverse order
    for (auto location = last-1; first <= location; --location)
        trickleDown(first, last, location);

    /*
    // Above is the linear-time method. Below is the more obvious
    //  method, which also works, but requires log-linear time.
    for (auto currentEnd = first+2; currentEnd <= last; ++currentEnd)
        heapInsert(first, currentEnd);
    */
}


// heapToSorted
// Given a Heap; makes it into a sorted list.
// Sorts the given Heap.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid range.
//     [first, last) is a Heap.
// Post:
//     [first, last) contains the same items as it did initially, but
//      now sorted by <.
template<typename RAIter>
void heapToSorted(RAIter first, RAIter last)
{
    while (last-first >= 2)
    {
        heapDelete(first, last);
        --last;
    }
}


// heapSort
// Sorts a sequence, using Heap Sort.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     operator< is a total order on the value type of RAIter.
// Pre:
//     [first, last) is a valid range.
// Post:
//     [first, last) contains the same items as it did initially,
//      but now sorted by <.
template <typename RAIter>
void heapSort(RAIter first, RAIter last)
{
    makeHeap(first, last);
    heapToSorted(first, last);
}


// Main program
// Demonstrates use of function heapSort.
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
    heapSort(v.begin(), v.end());

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

