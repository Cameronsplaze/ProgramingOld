//MSArray.h

//Cameron Showalter
//22 September, 2016
//Template class MSArray, manages a moderate smart array
#ifndef MSARRAY_H_INCLUDED
#define MSARRAY_H_INCLUDED
#include <iostream>
#include <cstddef>

using std::swap;


// class MSArray
// Holds a dynamic array and adds simple usablity to it
// Invariants:
//     0 <= size
template <typename T>
class MSArray{
public:
    using value_type = T;       //Type of array
    using size_type = size_t;   //size of array, unsigned
    //default Ctor
    //makes array, sets size to 10
    //pre: n/a
    //post: created array of size 10
    MSArray()
    {
        arrayPtr_ = new T[10];
        size_=10;
    }
    //one-par ctor(size)
    //Makes an array with size
    //pre: Size >=0, type must be defined
    //post: creates array of your size
    MSArray(size_t s)
    {
        arrayPtr_ =  new T[s];
        size_ = s;
    }
    //two-par ctor(size, value)
    //Makes an array with size, and fills it with value
    //pre: Size >=0, type must be defined
    //post: creates array of your size
    MSArray(size_t s, T d)
    {
        arrayPtr_ = new T[s];
        size_ = s;
        for(int i=0; i<s; i++)
        {
            arrayPtr_[i]=d;
        }
    }
    // const size()
    //pre: n/a
    //post: return size of array
    const size_t size() const
    {
        return size_;
    }
    // begin()
    //pre: n/a
    //post: return pointer to the start of the array
    T* begin()
    {
        return arrayPtr_;
    }
    //const begin()
    //pre: n/a
    //post: return pointer to the start of the array
    const T* begin() const
    {
        return arrayPtr_;
    }
    // end()
    //pre: n/a
    //post: return pointer to the end of the array +1
    T* end()
    {
        return (arrayPtr_+size_);
    }
    //const end()
    //pre: n/a
    //post: return pointer to the end of the array +1
    const T* end() const
    {
        return (arrayPtr_+size_);
    }

    //op[]
    //pre: idx >=0
    //post: return value by reference at idx
    T& operator[](size_t idx)
    {
        return *(arrayPtr_ + idx);
    }
    //const op[]
    //pre: idx >=0
    //post: return value by reference at idx
    const T& operator[](size_t idx) const
    {
        return *(arrayPtr_ + idx);
    }

    //**************
    //---BIG FIVE---
    //**************

	// dtor
	// deletes array
	// Pre: n/a
	// Post: deletes dynamic array
    ~MSArray()
    {
        if(size_)
        {
            delete[] arrayPtr_;
            size_=0;
        }
    }
    //copy assign
    //pre: n/a
    //post: copy class through assignment
    MSArray & operator=(const MSArray & rhs)
    {
        MSArray copy(rhs);
        mswap(copy);
        return *this;
    }
    //copy ctor
    //pre: n/a
    //post: copy class
    MSArray(const MSArray & other) //74
    {
        size_ = other.size_;
        arrayPtr_ = new T [size_];
        for(int i=0; i<size_; i++)
        {
            *(arrayPtr_+i) = *(other.arrayPtr_ + i);
        }
    }
    //move ctor
    //pre: n/a
    //post: move class
    MSArray(MSArray && other) noexcept
    {
        swap(size_, other.size_);
        arrayPtr_ = new T [size_];
        swap(arrayPtr_, other.arrayPtr_);

    }
    //move assignment
    //pre: n/a
    //post: move class through assignment
    MSArray & operator=(MSArray && rhs) noexcept
    {
        mswap(rhs);
        return *this;
    }

private:
    int size_; //size of array
    value_type * arrayPtr_; // pointer to the array
    //mswap(other)
    //pre: n/a
    //post: swaps other with class
    void mswap(MSArray & other) noexcept
    {
        swap(arrayPtr_, other.arrayPtr_);
        swap(size_, other.size_);
    }
};
//END OF CLASS MSArray


//op==
//pre: MSArray must have data types
//post: returns lhs==rhs
template <typename T>
bool operator== (const MSArray<T> &lhs, const MSArray<T> &rhs)
{
    bool returnMe = true;
    if(lhs.size()==rhs.size())
    {
        for(int i=0; i<lhs.size(); i++)
        {
            if(lhs[i] != rhs[i])
            {
                returnMe = false;
            }
        }
    }
    else
    {
        returnMe=false;
    }
    return returnMe;
}
//op!=
//pre: MSArray must have data types
//post: returns lhs!=rhs
template <typename T>
bool operator!= (const MSArray<T> &lhs, const MSArray<T> &rhs)
{
    return !(lhs == rhs);
}
//op<
//pre: MSArray must have data types
//post: returns lhs<rhs
template <typename T>
bool operator< (const MSArray<T> &lhs, const MSArray<T> &rhs)
{
    int sizeA;
    if(lhs.size() < rhs.size())
    {
        sizeA = lhs.size();
    }
    else
    {
        sizeA = rhs.size();
    }
    for(int i=0; i<sizeA; i++)
    {
        if(lhs[i] < rhs[i])
        {
            return true;
        }
        if(rhs[i] < lhs[i])
        {
            return false;
        }
    }
    if(lhs.size() < rhs.size())
    {
        return true;
    }
    return false;
}
//op>
//pre: MSArray must have data types
//post: returns lhs>rhs
template <typename T>
bool operator> (const MSArray<T> &lhs, const MSArray<T> &rhs)
{
    if(lhs<rhs)
    {
        return false;
    }
    if(lhs == rhs)
    {
        return false;
    }
    return true;
}
//op<=
//pre: MSArray must have data types
//post: returns lhs<=rhs
template <typename T>
bool operator<= (const MSArray<T> &lhs, const MSArray<T> &rhs)
{
    return !(lhs > rhs);
}
//op>=
//pre: MSArray must have data types
//post: returns lhs>=rhs
template <typename T>
bool operator>= (const MSArray<T> &lhs, const MSArray<T> &rhs)
{
    return !(lhs < rhs);
}


#endif // MSARRAY_H_INCLUDED

