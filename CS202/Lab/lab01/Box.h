#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

#include <iostream>
//using namespace std;
class Box{
public:
    Box(){
        length_ = 0;
        numberOfBoxes_=1;
    }
    void setLength(int length){
        length_ = length;
        numberOfBoxes++;

    }
    ~Box()
    {
        numberOfBoxes--;
    };
    int getLength()
    {
        return length_;
    }
    void setLength(int newLength)
    {
        length_ = newLength;
    }
    int getNumberOfBoxes()
    {
        return numberOfBoxes_;
    }
    void setNumberOfBoxes(int newBoxes)
    {
        numberOfBoxes_ = newBoxes;
    }
    void printBox()
    {
        for(int i=0; i<length_; i++)
        {
            for(int j=0; j<length_; j++)
            {
                std::cout << "X";
            }
            std::cout << std::endl;
        }
    }
    void printAllBoxes()
    {
        for(int i=0; i<numberOfBoxes_; i++)
        {
            printBox();
            std::cout<<std::endl;
        }
    }
private:
    int length_;
    int numberOfBoxes_;
};


#endif // BOX_H_INCLUDED
