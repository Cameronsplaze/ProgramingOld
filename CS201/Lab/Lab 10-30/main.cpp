#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
    const int SIZE = 5;
    int * iptr = new int[SIZE];
    //BB: This line seems like error checking, but it doesn't do alot. It just prints out an error message and then segfaults when the program tries to execute anyways.
    //BB: This if statement should have a return 1 or something in it to be truely safe. 
    //BB: Finally, remember this only works if iptr == 0. If iptr isn't zero, then it still can be pointing to memory that will cause a segfault
    if(!iptr)
    {
        cout << "you just did something bad...." << endl;
    }
    for(int i=0; i< SIZE; i++)
    {
        //BB: Just a note, but *(iptr+1) is exactly the same as iptr[i]. In fact the [] operator is just shorthand for *(iptr+i)
        *(iptr+i) = rand()%100 +1;
        cout << *(iptr + i) << endl;
    }
    //BB: you increment the pointer, and then try to dealocate it, which causes an error.
    cout << *iptr ++ << endl;
    delete[] iptr;
    return 0;
}
