/*

Testing assignment operator equal
Testing equality when equal
Testing inequality when equal
*/

#ifndef MyArrayTEST_H_INCLUDED
#define MyArrayTEST_H_INCLUDED

#include <ostream>
#include <iostream>
//using namespace std;
template<typename T>
class MyArray{
public:
    MyArray()
    {
        mySize_ = 0;
        mStr = new T&[mySize_];
    };

    MyArray(int s)
    {
        mySize_ = s;
        mStr = new T&[mySize_];
    };
    MyArray(const MyArray& copier)
    {
        mySize_ = copier.size();
        mStr = new T&[mySize_];
        for(int i=0; i<mySize_; i++)
        {
            mStr[i] = copier[i];
        }
    };
    //deconstructor
    ~MyArray()
    {
        if(mySize_)
        {
            mySize_ = 0;
        }
        delete[] mStr;
    };
    T& operator[] (int index)
    {
        return mStr[index];
    }
    T& operator[] (int index) const
    {
        return mStr[index];
    }
    int size()
    {
        return mySize_;
    }
    int size() const
    {
        return mySize_;
    }
    int Resize(int newSize)
    {
        mySize_ = newSize;
    }

    MyArray& operator= (const MyArray& copier)
    {


        if(*this != copier)
        {


            mySize_ = copier.size();
            mStr = new T&[mySize_];
            for(int i=0; i<mySize_; i++)
            {
                mStr[i] = copier[i];

               // std::cout << mStr[i] << " " << copier[i] << std::endl;
            }
        }
        return *this;
    }

    /*

     MyArray & operator= (const MyArray& copier)
    {
        if(mStr!=copier)
        {
            if(mySize_!=0)
            {
                delete[] data_;
            }
            mySize_=rhs.size();
            data_=new T&
        }
       return *this;
    }


  */



    MyArray operator+ (const MyArray& str2)
    {
        MyArray temp(mySize_+str2.size());
        for(int i=0; i< (mySize_+str2.size()); i++)
        {
            if(i<mySize_){
                temp[i] = mStr[i];
            }
            else{
                temp[i] = str2[i-mySize_];
            }
        }
        return temp;
    }
    bool operator== (const MyArray& str2)
    {
        if(mySize_ == str2.size()){
            for(int i=0; i<mySize_; i++){
                if(!(mStr[i]==str2[i]))
                {
                    std::cout << mStr[i] << " " << str2[i] << std::endl;
                    return false;
                }
            }
        return true;
        }
    return false;
    }

    bool operator!= (const MyArray& str2)
    {
        return !(*this==str2);
    }


 private:
    int mySize_;
    T& mStr;

};

inline std::ostream& operator<< (std::ostream & ss, MyArray pizza)
    {
        for(int i=0; i<pizza.size(); i++)
        {
            ss<< pizza[i];
        }
    }


#endif
/*
    friend MyArray & operator+(const MyArray & lhs, const MyArray & rhs);
    friend bool operator==(const MyArray & lhs, const MyArray & rhs);
    friend bool operator!=(const MyArray & lhs, const MyArray & rhs);
*/
