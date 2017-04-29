// tvsarray.h

// Cameron Showalter
// 10-28-16
// Assignment 5
// Header file for class TVSArray
// Very smart array class thatat manages its own resource and acts similar to a vector.

#ifndef FILE_TVSARRAY_H_INCLUDED
#define FILE_TVSARRAY_H_INCLUDED

#include <iostream>
#include <cstddef>   //for std::size_t
#include <algorithm> //for std::swap, std::copy, std::rotate, std::distance
using std::copy;

//******************************************************************
// Template class TVSArray - Class definition
//******************************************************************


// class TVSArray
// Simple RAII class holding dynamic array of value_type T.
// Invariants:
//		0 <= size_ <= capacity_
//		data_ points to a template array of value_type T, allocated with new[],
//			owned by *this, holding capacity_ T OR data_ is a null pointer,
//			and capacity_ == 0.
// Requirements on type:
//		Copy ctor.
template <typename T>
class TVSArray {

// ***** TVSArray: types *****
public:
	using size_type = std::size_t;
    using value_type = T;
	using iterator = value_type *;
	using const_iterator = const value_type *;

	static const size_type DEFAULT_CAP = size_type(16);

// ***** TVSAArray Ctors, dctor, op= *****
public:

	// Default ctor
	// Pre:
	//		None.
	// Post:
	//		size_ = 0;
	//		capacity_ = DEFAULT_CAP
	//		data_ = new array of type T
	// Exception Neutral
	// Strong Guarantee
	explicit TVSArray():capacity_(DEFAULT_CAP), size_(size_type(0)), data_(new value_type[DEFAULT_CAP])
	{

	}

	// Ctor from size
	// Pre:
	//		size >= 0
	// Post:
	//		capacity_ == size
	//		size_ == size
	//		data_ = new array of type T
	// Eception Neutral
	// Strong Guarantee
	explicit TVSArray(size_type size):capacity_(size), size_(size), data_(new value_type[size])
	{

	}


	// Copy ctor
	// Pre:
	// 		None.
	// Post:
	//		capacity_ == other.capacity_
	//		size_ == other.size_
	//		data_ == other.data_
	// Exception Neutral
	// Strong Guarantee
	TVSArray(const TVSArray & other):capacity_(other.capacity_), size_(other.size_), data_(new value_type[other.size_])
	{
		try
		{
			copy(other.begin(), other.end(), begin());
		}
		catch(...)
		{
			delete [] data_;
			throw;
		}
	}


	// Move ctor
	// Pre:
	//		None.
	// Post:
	//		capacity_ == other.capacity_
	// 		size_ == other.size_
	//		data_ == other.data_
	//		other TVSArray set to 0 and null
	// Exception Neutral
	// No-Throw Guarantee
	TVSArray(TVSArray && other) noexcept:capacity_(other.capacity_), size_(other.size_), data_(other.data_)
	{
		other.capacity_ = size_type(0);
		other.size_ = size_type(0);
		other.data_ = nullptr;
	}


	// Copy Assignment
	// Pre:
	//		None.
	// Post:
	//		*this == rhs
	// Exception Neutral
	// Strong Guarantee
	TVSArray & operator=(const TVSArray &rhs)
    {
        TVSArray temp(rhs);
        swap(temp);
        return *this;
    }

	// Move Assignment
	// Pre:
	// 		None.
	// Post:
	//		*this == rhs
	// Exception Neutral
	// No-Throw Guarantee
	TVSArray & operator=(TVSArray && rhs) noexcept
	{
        swap(rhs);
        return *this;
	}


	// Dctor
	// Pre:
	//		None.
	// Post:
	//		data_ deallocated
	// Exception Neutral
	// Strong Guarantee
    ~TVSArray()
	{
        delete [] data_;
	}


// ***** TVSArray: op[] *****
public:

	//operator[] const and non const
	// Pre:
	//		0 <= index < size_
	// Post:
	//		data_[index] is returned
	// Exception Neutral
	// No-throw Guarantee
	const value_type & operator[](size_type index) const
	{
		return data_[index];
	}
	value_type & operator[](size_type index)
	{
		return data_[index];
	}

// ***** TVSrray: general public functions *****
public:

	// Size const
	// Pre:
	//		None.
	// Post:
	//		size_ returned
	// Exception Neutral
	// No-Throw Guarantee
	size_type size() const
	{
	    return size_;
    }

	// Empty
	// Pre:
	//		None.
	// Post:
	//		returns a bool on if array is empty
	// Exception Neutral
	// No-Throw Guarantee
	bool empty() const
	{
	    return size_==0;
    }

	// Begin (const and non const)
	// Pre:
	//		None.
	// Post:
	//		returns beginning of data_
	// Exception Neutral
	// No-Throw Guarantee
	const_iterator begin() const
	{
	    return data_;
    }
	iterator begin()
	{
	    return data_;
    }

	// End (const and non const)
	// Pre:
	//		None.
	// Post:
	//		returns end of data_
	// Exception Neutral
	// No-Throw Guarantee
	const_iterator end() const
	{
	    return begin() + size();
    }
	iterator end()
	{
	    return begin() + size();
    }



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//NOTE: resize kept saying "bad_alloc". Mr.Marken thinks it has to do with windows not having
//      a huge allocation maximum. On my machine, two tests didn't pass for the large array, but
//      they shouldn't throw on yours.
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

	// Resize
	// Pre:
	//		newsize >= 0
	// Post:
	//		changes size of array.
	//       If newsize > capacity_, makes new array with new capacity_
	// Exception Neutral
	// Strong Guarantee
	void resize(size_type newsize)
	{
		if(newsize <= capacity_)
		{
			size_ = newsize;
		}
		else
		{
			size_type newCapacity;
			value_type * newData;
            newCapacity = newsize*2;
			newData = new value_type[newCapacity];

			try
			{
				copy(begin(), end(), newData);
			}
			catch(...)
			{
				delete [] newData;
				throw;
			}

			delete [] data_;
			data_ = newData;
			capacity_ = newCapacity;
			size_ = newsize;
		}
	}

	// Insert
	// Pre:
	//		0 <= pos <= size_
	// Post:
	//		increases size +1
	//		data_[idx] = value
	//		iterator pointing to data_[idx] is returned
	// Exception Neutral
	// Basic Guarantee
	iterator insert(iterator pos, const value_type & value)
	{
		size_type idx = std::distance(begin(), pos);
		resize(size_+1);
		data_[size_-1] = value;
		pos = &data_[idx];
		std::rotate(pos, end()-1, end());
        return pos;
	}

	// Remove
	// Pre:
	//		0 <= pos <= size_
	// Post:
	//		decreases size-1
	//		data_[pos] is deleted
	//		returns pointer to next index
	// Exception Neutral
	// Basic Guarantee
	iterator remove(iterator pos)
	{
		std::rotate(pos, pos+1, end());
		resize(size_-1);
        return pos;
	}

	// Swap
	// Pre:
	//		None.
	// Post:
    //		size_      swaps with  other.size_
	// 		capacity_  swaps with  other.capacity_
    //		data_      swaps with  other.data_
	// Exception Neutral
	// No-Throw Guarantee
	void swap(TVSArray & other) noexcept
	{
        std::swap(size_, other.size_);
		std::swap(capacity_, other.capacity_);
		std::swap(data_, other.data_);
	}

// ***** TVSArray: Data Members *****
private:
	size_type capacity_;
	size_type size_;
	value_type * data_;

}; // End of class TVSArray


#endif //FILE_TVSARRAY_H_INCLUDED
