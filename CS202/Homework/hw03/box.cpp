#include "box.h"
#include <String>
#include <iostream>
using namespace std;

    Box::Box()
    {
        width_=1;
        height_=1;
        filled_=true;
    }
    int Box::getWidth()
    {
        return width_;
    }
    int Box::getWidth() const
    {
        return width_;
    }
    void Box::setWidth(int newWidth)
    {
        width_ = newWidth;
    }
    int Box::getHeight()
    {
        return height_;
    }
    void Box::setHeight(int newHeight)
    {
        height_ = newHeight;
    }

    int Box::getWidth() const
    {
        return width_;
    }
    int Box::getHeight() const
    {
        return height_;
    }
    string Box::type()
    {
        string st1 = "Filled";
        string st2 = "Hollow";
        if(filled_)
        {
            return st1;
        }
        return st2;
    }
    string Box::type() const
    {
        string st1 = "Filled";
        string st2 = "Hollow";
        if(filled_)
        {
            return st1;
        }
        return st2;
    }
    Box(int width, int height)
    {
        width_ = width;
        height_ = height;
        filled_ = true;
    }
    Box(int width, int height, bool filled)
    {
        width_ = width;
        height_ = height;
        filled_ = filled;
    }
    void print(ostream& testing)
    {
        testing << "x";
    }
    ostream& print(ostream &testing) const
    {
        testing << "x";
        return testing;
    }
