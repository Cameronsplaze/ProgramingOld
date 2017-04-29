#ifndef TWOD_H_INCLUDED
#define TWOD_H_INCLUDED

class TwoD
{
    public:
        TwoD()
        {
            x_=0;
            y_=0;
        }
        TwoD(int x, int y)
        {
            x_=x;
            y_=y;
        }
        int getX()
        {
            return x_;
        }
        int getY()
        {
            return y_;
        }
        void setX(int x)
        {
            x_=x;
        }
        void setY(int y)
        {
            y_=y;
        }

    private:
        int x_;
        int y_;

};
class ThreeD : public TwoD
{
public:
    ThreeD()
    {
        TwoD();
        z_=0;
    }
    ThreeD(int x, int y, int z)
    {
        TwoD(x,y);
        z_=z;
    }
private:
    int z_;
};



#endif // TWOD_H_INCLUDED

