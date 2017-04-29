#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

#include <String>
#include <iostream>
//using namespace std;
using std::string;
using std::ostream;



class Box{
    public:
    enum FillType{FILLED, HOLLOW, CHECKERED};
    Box()
    {
                numberOfBoxes_++;

        width_=1;
        height_=1;
        type_=FILLED;
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
        string st3 = "Checkered";
        if(type_==FILLED)
        {
            return st1;
        }
        else if(type_==HOLLOW)
        {
            return st2;
        }
        return st3;
    }
    string type() const
    {
        string st1 = "Filled";
        string st2 = "Hollow";
        string st3 = "Checkered";
        if(type_==FILLED)
        {
            return st1;
        }
        else if(type_==HOLLOW)
        {
            return st2;
        }
        return st3;
    }
    Box(int width, int height)
    {
                numberOfBoxes_++;

        width_ = width;
        height_ = height;
        type_=FILLED;
    }
    Box(int width, int height, FillType typeBox)
    {
                numberOfBoxes_++;

        width_ = width;
        height_ = height;
        type_ = typeBox;
    }
    ostream& print(ostream &testing)
    {

            for(int i=0; i<height_; i++)
            {
                for(int j=0; j<width_; j++)
                {
                    if(type_==FILLED)
                    {
                        testing << "x";
                    }
                    else if(type_==HOLLOW)
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
                std::cout << testing;
            }
            return testing;
            //testing << "x\n";
            //return testing;
                std::cout << "testing" << std::endl;

    }
    ostream& print(ostream &testing) const
    {

            for(int i=0; i<height_; i++)
            {
                for(int j=0; j<width_; j++)
                {
                    if(type_==FILLED)
                    {
                        testing << "x";
                    }
                    else if(type_==HOLLOW)
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
                std::cout << testing << std::endl;
            }
            return testing;
            //testing << "x\n";
            //return testing;
                std::cout << "testing" << std::endl;

    }
    static int howMany()
    {
        numberOfBoxes_++;
        return numberOfBoxes_;
    }




    //friend ostream &operator<<(ostream &testing);
    private:
        int width_;
        int height_;
        static int numberOfBoxes_;
       //enum class type{FILLED, HOLLOW, CHECKERED};
       FillType type_;


};
int Box::numberOfBoxes_ = 0;

inline std::ostream& operator<< (std::ostream & ss, Box ms)
    {

    }
/*
ostream &operator<<(ostream &testing)
{
    testing << Box();
    return testing;
}
*/
#endif // BOX_H_INCLUDED
