//da3.h
//Cameron Showalter
//Assignment 3
//9-29-16
//Used with da3.cpp

#ifndef FILE_DA3_H_INCLUDED
#define FILE_DA3_H_INCLUDED

#include <cstddef>
#include <functional>
#include <stdexcept>
#include <vector>

//using namespace std;
using std::size_t;
using std::function;
using std::out_of_range;
using std::vector;


// **************************************************************** // *
// Begin DO-NOT-CHANGE section                                      // *
// Do not alter the lines below                                     // *
// **************************************************************** // *
                                                                    // *
                                                                    // *
// struct LLNode                                                    // *
// Linked List node, with client-specified value type               // *
// Intended Invariants (breakable, as data members are public):     // *
//     Either _next is nullptr, or _next points to an LLNode,       // *
//      allocated with new, owned by *this.                         // *
// Requirements on Types:                                           // *
//     ValueType must have a copy ctor and a dctor.                 // *
template <typename ValueType>                                       // *
struct LLNode {                                                     // *
    ValueType _data;  // Data for this node                         // *
    LLNode *  _next;   // Ptr to next node, or nullptr if none      // *
                                                                    // *
    // The following simplify creation & destruction                // *
                                                                    // *
    // 1- & 2-param ctor                                            // *
    // Pre:                                                         // *
    //     theNext, if passed, is either nullptr, or else it        // *
    //      points to an LLNode, allocated with new, with           // *
    //      ownership transferred to *this.                         // *
    // Post:                                                        // *
    //     _data == data.                                           // *
    //     _next == next.                                           // *
    explicit LLNode(const ValueType & data,                         // *
                    LLNode * next = nullptr)                        // *
        :_data(data),                                               // *
         _next(next)                                                // *
    {}                                                              // *
                                                                    // *
    // dctor                                                        // *
    // Pre: None.                                                   // *
    // Post:                                                        // *
    //     Previous value of _next has been delete'd                // *
    ~LLNode()                                                       // *
    { delete _next; }                                               // *
};  // End struct LLNode                                            // *
                                                                    // *
                                                                    // *
// **************************************************************** // *
// End DO-NOT-CHANGE section                                        // *
// Do not alter the lines above                                     // *
// **************************************************************** // *


// lookUp function.
// Pre:
//      None.
// Post:
//      out_of_range exception thrown for index that is negative or out of
//      range of linked list.
//
//      If no exception thrown, _data is returned at given index.
template <typename ValueType>
ValueType lookUp(const LLNode<ValueType> * head, size_t index)
{
    auto p = head;
    if (p==nullptr)
    {
        throw out_of_range("out_of_range(list size == 0)");
    }
    for(size_t i = 0; i < index; ++i)
    {
        if (p->_next == nullptr)
        {
            throw out_of_range("index is > list size");
        }
        p = p->_next;
    }
    return p->_data;
}


// callBetween function.
// Pre:
//      None.
// Post:
//      None.
void callBetween(const std::function<void()> & start,
                 const std::function<void()> & middle,
                 const std::function<void()> & finish);


// uniqueCount function.
// Pre:
//      None.
// Post:
//      Returns number of unique items inside the vector.
template <typename RAIter>
size_t uniqueCount(RAIter first, RAIter last)
{
    vector<typename RAIter::value_type> myVect;
    while (last != first)
    {
        bool findMe = false;
        for (size_t i = 0; i < myVect.size(); ++i)
        {
            if (myVect[i] == *first)
            {
                findMe = true;
                break;
            }
        }
        if (!findMe)
        {
            myVect.push_back(*first);
        }
        first++;
    }
    return myVect.size();
}


// isPrime function.
// Pre:
//      None.
// Post:
//      Returns true if passed number is prime or false if not prime.
bool isPrime(int n);


#endif  //#ifndef FILE_DA3_H_INCLUDED
