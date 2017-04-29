#include <iostream>
#include "Final.h"
/*
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
*/
/*
This is due thursday May 5th at 5:00 PM Exactly and it comes in 3 parts. Check to make sure it compiles on all platforms as solutions
 which do not compile get a 0.
Part A.

Your job is to write a Money class, with overloaded operators. Money is counted in cents only (no fractions of a penny) and output
in standard form like $12.35. You should be able to perform the following operations using normal C++ syntax:

    Test if one Money object is equal to another (==)
    Test if one Money object is not equal to another (!=)
    Test if one Money object is less than another (<)
    Test if one Money object is less than or equal to another (<=)
    Test if one Money object is greater than another (>)
    Test if one Money object is greater than or equal to another (>=)
    Add Money to an existing Money object (+=)
    Subtract Money from an existing Money object (-=)
    Add two Money objects (+)
    Subtract two Money objects (-)
    Multiply a double times a Money object (*)
    Multiply a Money object times a double (* and *=)
    Divide a Money object by a double (/ and /=)
    Print a Money object to an ostream. Examples include -$3.03, $1542.16, and $0.00.
    You should include a default constructor that makes a Money object have value $0.00, as well as a constructor that takes two
    integers (dollars and cents) and one that takes a double (in dollars, you should round appropriately if it's not an integral
    number of cents, so 45.6789 should give you $45.68, but 45.6723 should give you $45.67. Be careful to make this work properly
    for negative amounts too!)
    You should also be able to assign Money objects, and copy them. But remember the compiler will write operator= and the copy constructor
    for you. If you aren't dealing with dynamic memory, the ones it writes are usually fine, right?
    You should take care to pass parameters and return values correctly, using const and references where appropriate. Specifically,
    remember that assignment operators return the object assigned to, by reference. Usually assignment operators are written as member
    functions (although I won't require this here) so the last line would be "return *this;"



Part B:
Write a function template printVector which takes two parameters: an ostream, and a vector (of anything!) Your function should
output the contents of the vector to the ostream, with newlines between them and a newline at the end.

Part C:
Write a class template to wrap a pointer using RAII. Your class should be called RAIIPtr. The idea is to be able to use an
RAIIPtr<T> in the same way you would use a  T*, but not have to worry about deleting the pointer when you are done. For
instance, the following code should work:

    RAIIPtr<int> iptr(new int);
    *iptr = 7;
    cout << *iptr << endl;
    RAIIPtr<string> sptr(new string("hello");
    cout << sptr->length() << endl;
To make things easy, we will disallow copying and assignment of these pointers (so it will act very much like a C++11 scoped_ptr.)
 There is a common trick to do this - declare the copy constructor and assignment operator as private, and do not implement them.
 You will need to write the following member functions:

    A constructor which takes a T*
    An overloaded operator* which returns the object the pointer points at. (Note: this should return by reference, do you see why?)
    An overloaded operator-> which should return the raw pointer to the object. (Surprisingly, operator-> is unary - just write it
    as a member function with no operators. The compiler does the right thing!)
    A destructor which deletes the pointer (because that's what RAII is all about!)

Remember that templates can not be compiled separately, so all of this will go in your hw6.h file, which should also contain the
answer to part A. Even though the class definition and member function definitions are all in the same file, you should still not
put the definitions for the member functions in the class definition, they should be after it.
You should turn one file hw6.h (which contains the definition of printVector and of your RAIIPtr class.)
The Test program is attached and should be added to git with your other code.
*/
