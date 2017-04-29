/*

Testing assignment operator equal
Testing equality when equal
Testing inequality when equal
*/

#ifndef MyStringTEST_H_INCLUDED
#define MyStringTEST_H_INCLUDED

#include <ostream>
#include <iostream>
//using namespace std;

class MyString{
public:
    MyString()
    {
        mySize_ = 0;
        mStr = new char[mySize_];
    };

    MyString(int s)
    {
        mySize_ = s;
        mStr = new char[mySize_];
    };
    MyString(const MyString& copier)
    {
        mySize_ = copier.size();
        mStr = new char[mySize_];
        for(int i=0; i<mySize_; i++)
        {
            mStr[i] = copier[i];
        }
    };
    //deconstructor
    ~MyString()
    {
        if(mySize_)
        {
            mySize_ = 0;
        }
        delete[] mStr;
    };
    char &operator[] (int index)
    {
        return mStr[index];
    }
    char operator[] (int index) const
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

    MyString& operator= (const MyString& copier)
    {


        if(*this != copier)
        {


            mySize_ = copier.size();
            mStr = new char[mySize_];
            for(int i=0; i<mySize_; i++)
            {
                mStr[i] = copier[i];

               // std::cout << mStr[i] << " " << copier[i] << std::endl;
            }
        }
        return *this;
    }

    /*

     MyString & operator= (const MyString& copier)
    {
        if(mStr!=copier)
        {
            if(mySize_!=0)
            {
                delete[] data_;
            }
            mySize_=rhs.size();
            data_=new char
        }
       return *this;
    }


  */



    MyString operator+ (const MyString& str2)
    {
        MyString temp(mySize_+str2.size());
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
    bool operator== (const MyString& str2)
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

    bool operator!= (const MyString& str2)
    {
        return !(*this==str2);
    }


 private:
    int mySize_;
    char* mStr;

};

inline std::ostream& operator<< (std::ostream & ss, MyString pizza)
    {
        for(int i=0; i<pizza.size(); i++)
        {
            ss<< pizza[i];
        }
    }


#endif
/*
    friend MyString & operator+(const MyString & lhs, const MyString & rhs);
    friend bool operator==(const MyString & lhs, const MyString & rhs);
    friend bool operator!=(const MyString & lhs, const MyString & rhs);
*/
