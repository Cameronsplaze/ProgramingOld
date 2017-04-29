#ifndef HW7_H_INCLUDED
#define HW7_H_INCLUDED
#include <iostream>
using namespace std;

class Rational{
    private:
    int numerator_;
    int denominator_;

    public:
        Rational(int x=1, int y=1)
        {
        numerator_ = x;
        denominator_ = y;
        }

int getNumerator();
int getDenominator();
void changeNumerator(int);
void changeDenominator(int);

Rational add(Rational &);
Rational sub(Rational &);

};
int Rational::getNumerator()
{
    return numerator_;
}
int Rational::getDenominator()
{
    return denominator_;
}
void Rational::changeNumerator(int a)
{
    numerator_ = a;
}
void Rational::changeDenominator(int a)
{
    denominator_ = a;
}
Rational Rational::add(Rational & a){
    Rational b;
    b.changeNumerator(numerator_ * a.getNumerator() + numerator_ * a.getDenominator());
    b.changeDenominator(denominator_ * a.getDenominator());
    return b;
}
Rational Rational::sub(Rational & a){
    Rational b;
    b.changeNumerator(numerator_ * a.getDenominator() - denominator_ * a.getNumerator());
    b.changeDenominator(numerator_ * a.getDenominator());
    return b;
}
#endif // HW7_H_INCLUDED
