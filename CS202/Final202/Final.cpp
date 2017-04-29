#include "Final.h"


//Cameron Showalter
//CS 202 Final
// May 6, 2016
// Round Off error when passing "-$3.03"
//

//takes a number and puts it in string form
string Money::toString() const
{
    ostringstream oss;
    if( dols_< 0)
    {
        oss << "-$";
        //std::cout << "-$";
        oss<< (dols_-dols_-dols_)<<".";
        //std::cout << (dols_-dols_-dols_) << ".";
    }
    else{
        oss<<"$";
        //std::cout << "$";
        oss<< dols_ << ".";
        //std::cout << dols_ << ".";
    }

    //std::cout <<std::endl<< "->" << cents_<<"<-" << std::endl;
    if(cents_==0)
    {
        oss<<"00";
        //std::cout << "00";

    }
    else if(cents_<0)
    {
        if(cents_>-10)
        {
            oss<< "0" << (cents_-cents_-cents_);
            //std::cout<<"0"<<(cents_-cents_-cents_);
        }
        else{
            oss<< (cents_-cents_-cents_);
            //std::cout<<(cents_-cents_-cents_);

        }
    }
    else{ //else if cents_>0
        if(cents_<10)
        {
            oss<< "0" << (cents_);
            //std::cout<<"0"<<(cents_);
        }
        else{
            oss<< (cents_);
            //std::cout<<(cents_);

        }
    }
    return oss.str();
}
//sets dols_ and cents_ by accepting a double (like 3.04)
Money::Money(double d)
{
    dols_ = (int)d;
    //cents_= (int)((d-(int)d)*1000.0);
    if(d<0)
    {
        d=d-d-d;//makes a negative become positive with same value. (-8 -> +8)
    }
    if(((double)d*1000-((int)(d*100))*10)>4)//checks if number in third dec. place >4
    {
        cents_=((int)((d-(int)d)*100.0))+1;//round up
        //std::cout << "roundUp"<< ((double)d*1000-((int)(d*100))*10)<<std::endl;
    }
    else{//number in third dec. place <=4
        cents_=(int)((d-(int)d)*100.0);//round down
        //std::cout << "roundDown"<<((double)d*1000-((int)(d*100))*10)<<std::endl;

    }
}
//sets dols_ and cents_ by accepting two doubles
Money::Money(double d, double c)
{
    dols_ = d;
    cents_= c;
}
//add two Money together
Money operator+(const Money & lhs, const Money & rhs)
{
    Money rv(lhs.dols_+rhs.dols_, lhs.cents_+rhs.cents_);
    return rv;
}
//subtracts two Money together
Money operator-(const Money & lhs, const Money & rhs)
{
    Money rv(lhs.dols_-rhs.dols_, lhs.cents_-rhs.cents_);
    return rv;
}
//print ostream
ostream& operator<<(ostream & temp, const Money & rhs)
{
    temp << rhs.toString();
    return temp;
}
//sets dols and cents equal to whats passed
Money Money::operator=(const Money & lhs)
{
    if(!(&lhs==this))
    {
        dols_=lhs.getD();
        cents_=lhs.getC();
    }
    return *this;
}
//checks if equal
bool operator==(const Money & lhs, const Money & rhs)
{
    if (lhs.dols_!=rhs.dols_)
    {
        return false;
    }
    if (lhs.cents_!=rhs.cents_)
    {
        return false;
    }
    return true;
}
//checks if not equal
bool operator!=(const Money & lhs, const Money & rhs)
{
    return !(lhs==rhs);
}
//checks if less than
bool operator<(const Money & lhs, const Money & rhs)
{
    if (lhs.dols_>rhs.dols_)
    {
        return false;
    }
    if (lhs.dols_==rhs.dols_ && lhs.cents_>=rhs.cents_)
    {
        return false;
    }
    return true;
}
//checks if greater than
bool operator>(const Money & lhs, const Money & rhs)
{
    if (lhs.dols_<rhs.dols_ || lhs.dols_ == rhs.dols_)
    {
        return false;
    }
    return true;
}
//checks if less than or equal to
bool operator<=(const Money & lhs, const Money & rhs)
{
    return !(lhs>rhs);
}
//checks if greater than or equal to
bool operator>=(const Money & lhs, const Money & rhs)
{
    return !(lhs<rhs);
}
//multiplies Money via double
Money operator* (Money lhs, double amount)
{
    Money rv(lhs.dols_*amount, lhs.cents_*amount);
    //cout << endl << amount << endl;
    return rv;
}
//multiplies Money via double different statements
Money operator* (double amount, Money lhs)
{
    Money rv(lhs.dols_*amount, lhs.cents_*amount);
    //cout << endl << amount << endl;
    return rv;
}
//Divides Money via double
Money operator/ (Money lhs, double amount)
{
    Money rv(lhs.dols_/amount, lhs.cents_/amount);
    //cout << endl << amount << endl;
    return rv;
}
//Money subtract another Money
Money & Money::operator-= (const Money & rhs)
{
    dols_=(dols_-rhs.getD());
    cents_=(cents_-rhs.getC());
    return *this;
}
//Money add another Money
Money & Money::operator+= (const Money & rhs)
{
    dols_=(dols_+rhs.getD());
    cents_=(cents_+rhs.getC());
    return *this;
}
//Money subtract another Money

Money & Money::operator*= (const double &rhs)
{
    dols_=(dols_*rhs);
    cents_=(cents_*rhs);
    return *this;
}
Money & Money::operator/= (const double &rhs)
{
    dols_=(dols_/rhs);
    cents_=(cents_/rhs);
    return *this;
}

