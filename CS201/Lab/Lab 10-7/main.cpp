#include <iostream>

using namespace std;
double average(double a, double b, double c, double d)
{
    return (a+b+c+d)/4.0;
}
int main()
{
    double a;
    double b;
    double c;
    double d;
    cout << "Please give me four numbers." << endl;
    cout <<"first number: ";
    cin >> a;
    cout <<"second number: ";
    cin >> b;
    cout <<"third number: ";
    cin >> c;
    cout <<"fourth number: ";
    cin >> d;
    cout << average(a,b,c,d);
    return 0;
}
