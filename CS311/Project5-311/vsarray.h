// vsarray.h  INCOMPLETE
// Glenn G. Chappell
// 19 Oct 2016
// Updated: 26 Oct 2016
//
// For CS 311 Fall 2016
// Header for class VSArray
// Very Smart Array of ints
// Preliminary to Assignment 5
//
// History:
// - v1:
//   - Skeleton forms of package header & source.
//   - Class VSArray definition (exists, but is not finished).
//   - Definitions of all public member types.
//   - Prototypes & dummy definitions (at least) for all package
//     functions.
//   - Declarations of all data members.
//   - Comments indicating class invariants.
//   - Correct (hopefully) definitions for all package functions that do
//     not involve copying/moving or resizing of the array.
// - v2:
//   - Combined default ctor, ctor from size into single function.
//   - Wrote copy ctor.
//   - Added exception-safety guarantees to all completed functions.
// - v3:
//   - Revised class invariants to allow for _data being a null pointer.
//   - Wrote move ctor & brought it into .h file.
// - v4:
//   - Internal redesign to allow for amortized constant-time
//     insert-at-end.
//     - Add _capacity data member.
//     - Modify all completed functions accordingly.
//     - Default ctor sets capacity to DEFAULT_CAP (currently 16).
//   - Split default ctor, ctor from size into two functions again.

#ifndef FILE_VSARRAY_H_INCLUDED
#define FILE_VSARRAY_H_INCLUDED

#include <cstddef>
using std::size_t;


// *********************************************************************
// class VSArray - Class definition
// *********************************************************************


// class VSArray
// Very Smart Array of ints.
// Resizable, copyable/movable, exception-safe.
// Invariants:
//     0 <= _size <= _capacity.
//     _data points to an int array, allocated with new [], owned by
//      *this, holding _capacity ints
//      OR _data is a null pointer, and _capacity == 0.
class VSArray {

// ***** VSArray: types & constants *****
public:

    using value_type = int;         // Type of data item in array
    using size_type = size_t;       // For array size & indices
    using iterator = value_type *;  // Iterator types, as in the STL
    using const_iterator = const value_type *;

    static const size_type DEFAULT_CAP = size_type(16);
                                    // Capacity used by default ctor

// ***** VSArray: ctor(s), op=, dctor
public:

    // Default ctor
    // Pre:
    // Post:
    // Strong Guarantee
    explicit VSArray()
        :_capacity(DEFAULT_CAP),
         _size(size_type(0)),
         _data(new value_type[DEFAULT_CAP])
    {}

    // Ctor from size
    // Pre:
    // Post:
    // Strong Guarantee
    explicit VSArray(size_type size)
        :_capacity(size),
         _size(size),
         _data(new value_type[size])
    {}

    // Copy ctor (defined in .cpp file)
    // Pre:
    // Post:
    // Strong Guarantee
    VSArray(const VSArray & other);

    // Move ctor
    // Pre:
    // Post:
    // No-Throw Guarantee
    VSArray(VSArray && other) noexcept
        :_capacity(other._capacity),
         _size(other._size),
         _data(other._data)
    {
        other._capacity = size_type(0);
        other._size = size_type(0);
        other._data = nullptr;
    }

    // Dctor
    // Pre:
    // Post:
    // No-Throw Guarantee
    ~VSArray()
    { delete [] _data; }

    // Copy assignment (defined in .cpp file)
    // Pre:
    // Post:
    VSArray & operator=(const VSArray & rhs);

    // Move assignment (defined in .cpp file)
    // Pre:
    // Post:
    VSArray & operator=(VSArray && rhs) noexcept;

// ***** VSArray: general public operators *****
public:

    // operator[] (non-const & const)
    // Pre:
    // Post:
    // No-Throw Guarantee
    value_type & operator[](size_type index)
    { return _data[index]; }
    const value_type & operator[](size_type index) const
    { return _data[index]; }

// ***** VSArray: general public functions *****
public:

    // size
    // Pre:
    // Post:
    // No-Throw Guarantee
    size_type size() const
    { return _size; }

    // empty
    // Pre:
    // Post:
    // No-Throw Guarantee
    bool empty() const
    { return _size == 0; }

    // begin (non-const & const)
    // Pre:
    // Post:
    // No-Throw Guarantee
    iterator begin()
    { return _data; }
    const_iterator begin() const
    { return _data; }

    // end (non-const & const)
    // Pre:
    // Post:
    // No-Throw Guarantee
    iterator end()
    { return begin() + size(); }
    const_iterator end() const
    { return begin() + size(); }

    // resize (defined in .cpp file)
    // Pre:
    // Post:
    void resize(size_type newsize);

    // insert (defined in .cpp file)
    // Pre:
    // Post:
    iterator insert(iterator pos,
                    const value_type & item);

    // remove (defined in .cpp file)
    // Pre:
    // Post:
    iterator remove(iterator pos);

    // swap (defined in .cpp file)
    // Pre:
    // Post:
    void swap(VSArray & other) noexcept;

// ***** VSArray: data members *****
private:

     size_type    _capacity;  // Amount of allocated space
     size_type    _size;      // Size of our array
     value_type * _data;      // Pointer to our array

}; // End class VSArray


#endif //#ifndef FILE_VSARRAY_H_INCLUDED

