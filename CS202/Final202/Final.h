#ifndef Money_H_INCLUDED
#define Money_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::ostringstream;
using std::cout;
using std::endl;
using std::ostream;
using std::string;

//using namespace std;

//==========================(Part A)==========================
class Money
{
public:

    Money():dols_(0), cents_(0)
    {
    }
    Money(double d);
    Money(double d, double c);
    //Money(int d, int c):dols_(d), cents_(c){        }
    double getD()
    {
        return dols_;
    }
    double getC()
    {
        return cents_;
    }
    double getD() const
    {
        return dols_;
    }
    double getC() const
    {
        return cents_;
    }

    string toString();

    string toString() const;

    friend Money operator+(const Money & lhs, const Money & rhs);
    friend ostream& operator<<(ostream & oss, const Money & rhs);
    friend Money operator-(const Money & lhs, const Money & rhs);
    friend bool operator==(const Money & lhs, const Money & rhs);
    friend bool operator!=(const Money & lhs, const Money & rhs);
    friend bool operator< (const Money & lhs, const Money & rhs);
    friend bool operator> (const Money & lhs, const Money & rhs);
    friend bool operator<=(const Money & lhs, const Money & rhs);
    friend bool operator>=(const Money & lhs, const Money & rhs);

    friend Money operator* (Money lhs, double amount);
    friend Money operator* (double amount, Money lhs);
    friend Money operator/ (Money lhs, double amount);

    Money &operator-= (const Money & rhs);
    Money &operator+= (const Money & rhs);
    Money &operator*= (const double & rhs);
    Money &operator/= (const double &rhs);



    //friend Money operator+= (Money lhs, Money rhs);
    //friend Money operator*= (Money lhs, double amount);
    Money operator=(const Money & lhs);

private:

    int dols_;
    int cents_;

};

Money operator+(const Money & lhs, const Money & rhs);
Money operator-(const Money & lhs, const Money & rhs);

ostream& operator<<(ostream & oss, const Money & rhs);
bool operator==(const Money & lhs, const Money & rhs);
bool operator!=(const Money & lhs, const Money & rhs);
bool operator<(const Money & lhs, const Money & rhs);
bool operator>(const Money & lhs, const Money & rhs);
bool operator<=(const Money & lhs, const Money & rhs);
bool operator>=(const Money & lhs, const Money & rhs);

Money operator* (Money lhs, double amount);
Money operator* (double amount, Money lhs);
Money operator/ (Money lhs, double amount);



//==========================(Part B)==========================
template<typename T>
void printVector(std::ostream& output, std::vector<T>& vec)
{
   for(int i=0; i<vec.size(); i++)
   {
       output<<vec[i]<<"\n";
   }
   //return output;
}
template<typename T>
void printVector(std::ostream& output, const std::vector<T>& vec)
{
   for(int i=0; i<vec.size(); i++)
   {
       output<<vec[i]<<"\n";
   }
   //return output;
}


//==========================(Part C)==========================
template <typename T>
class RAIIPtr
{
public:
    RAIIPtr<T>(T* s)
    {
        t_=s;
    }
    ~RAIIPtr<T>()
    {
        delete t_;
    }
    T & operator*()
    {
        return *t_;
    }
    T * operator -> ()
    {
        return t_;
    }
private:
    T* t_;
    RAIIPtr<T>(const RAIIPtr<T> & orig){}
    RAIIPtr<T> &operator=(const RAIIPtr<T> & rhs){}
};


#endif
