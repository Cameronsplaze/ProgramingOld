#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#include <iostream>
using namespace std;
class Complex
{
    public:
        Complex()
        {
            real_=0;
            imag_=0;
        }
        Complex(int stuff)
        {
            real_=stuff;
            imag_=stuff;
        }
        Complex(int imag, int real)
        {
            real_=real;
            imag_=imag;
        }
        int getImag()
        {
            return imag_;
        }
        void setImag(int imag)
        {
            imag_=imag;
        }
        int getReal()
        {
            return real_;
        }
        void setReal(int real)
        {
            real_=real;
        }
        //---Operator "+"---
    Complex operator+ (Complex& returnMe)
    {
        returnMe = real_+imag_;
        return returnMe;
    }
    Complex operator+ (Complex& returnMe) const
    {
        returnMe = real_+imag_;
        return returnMe;
    }
    //---Operator "-"---
    Complex operator- (Complex& returnMe)
    {
        returnMe = real_-imag_;
        return returnMe;
    }
    Complex operator- (Complex& returnMe) const
    {
        returnMe = real_-imag_;
        return returnMe;
    }
    //---Operator "*"---
    Complex operator* (Complex& returnMe)
    {
        returnMe = real_*imag_;
        return returnMe;
    }
    Complex operator* (Complex& returnMe) const
    {
        returnMe = real_*imag_;
        return returnMe;
    }
    //---Operator "/"---
    Complex operator/ (Complex& returnMe)
    {
        returnMe = real_/imag_;
        return returnMe;
    }
    Complex operator/ (Complex& returnMe) const
    {
        returnMe = real_/imag_;
        return returnMe;
    }

    private:
        int real_;
        int imag_;
};

#endif // COMPLEX_H_INCLUDED
