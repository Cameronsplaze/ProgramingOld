#include "Box.h"
    void setSize(int sizeMe)
    {
        length_ = sizeMe;
    }
    void setSizeZero()
    {
        length = 0;
    }
    void setCounter(newNumber)
    {
        counter_ = newNumber;
    }
    int getSize()
    {
        return length_;
    }
    int getCount()
    {
        return counter;
    }
    void printABox()
    {
        int length = getSize();
        for(int i=0; i<length; i++)){
            for(int j=0; j<length; j++){
                cout <<"x";
            }
            cout << endl;
        }
    }
    void derementCounter()
    {
        counter_--;
    }
