#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

#include <String>
#include <iostream>
//using namespace std;
using std::string;
using std::ostream;

class Box{
    public:
        Box()
        {
            width_=1;
            height_=1;
            filled_=true;
        }
        int getWidth()
        {
            return width_;
        }

        void setWidth(int newWidth)
        {
            width_ = newWidth;
        }
        int getHeight()
        {
            return height_;
        }
        void setHeight(int newHeight)
        {
            height_ = newHeight;
        }

        int getWidth() const
        {
            return width_;
        }
        int getHeight() const
        {
            return height_;
        }
        string type()
        {
            string st1 = "Filled";
            string st2 = "Hollow";
            if(filled_)
            {
                return st1;
            }
            return st2;
        }
        string type() const
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
        ostream& print(ostream &testing)
        {
            for(int i=0; i<height_; i++)
            {
                for(int j=0; j<width_; j++)
                {
                    if(filled_)
                    {
                        testing << "x";
                    }
                    else
                    {
                        if( i==0 || j==0 || i==height_-1 || j==width_-1 ){
                            testing << "x";
                        }
                        else{
                        testing << " ";
                        }
                    }
                }
                testing << "\n";
            }
            return testing;
            //testing << "x\n";
            //return testing;
        }
        ostream& print(ostream &testing) const
        {
                      for(int i=0; i<height_; i++)
            {
                for(int j=0; j<width_; j++)
                {
                    if(filled_)
                    {
                        testing << "x";
                    }
                    else
                    {
                        if( i==0 || j==0 || i==height_-1 || j==width_-1 ){
                            testing << "x";
                        }
                        else{
                        testing << " ";
                        }
                    }
                }
                testing << "\n";
            }
            return testing;
            //testing << "x\n";
            //return testing;
        }
    //friend ostream &operator<<(ostream &testing);
    private:
        int width_;
        int height_;
        bool filled_;
};
/*
ostream &operator<<(ostream &testing)
{
    testing << Box();
    return testing;
}
*/
#endif // BOX_H_INCLUDED
