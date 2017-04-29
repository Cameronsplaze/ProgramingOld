//Cameron Showalter
//CS 201
#include <iostream>

using namespace std;

//Converts centimeters to feet and inches.
void homework3A(){

    double inches=0;
    int feet=0;
    double centi=0;
    cout << "How many centimeters?: ";
    if(centi >= 0){
        cin >> centi;
        inches = centi / 2.53;
        while(inches >= 12){
            inches = inches -12;
            feet = feet + 1;
        }
        cout << endl << "You have " << feet << " feet and " << inches << " inches!!";
    }
    else{
        cout << "Next time pick a positive number.";
    }
}
// Takes two numbers and tells you the sum, product, and difference
void homework3B(){
    int number1 = 0;
    int number2 = 0;
    cout << "Give me two numbers. number one: ";
    cin >> number1;
    cout << endl << "Give me number two: ";
    cin >> number2;
    cout << endl << "The product is : " << number1 * number2 << endl;
    cout << endl << "The sum is : " << number1 + number2 << endl;
    if(number1>number2){
        cout << endl << "The difference is : " << number1 - number2;
    }
    else{
        cout << endl << "The difference is : " << number2 - number1;
    }
}
// Tells you how big your next paycheck is
void homework3C(){
    double hourlyWage = 0;
    double hoursWorked = 0;
    double wage = 0;
    cout << "How much do you make pr hour? \n(Not trying to be rude, my teacher made me ask): ";
    cin >> hourlyWage;
    cout << "\nHow many hours have you worked?: ";
    cin >> hoursWorked;
    wage = hourlyWage*hoursWorked;
    cout << fixed << setprecision(2) << "\nYou've made &" << wage << " Dollars!";
}

int main()
{
    cout << "***Homework 3A***" << endl;
    //homework3A();

    cout << endl << "***Homework 3B***" << endl;
    //homework3B();

    cout << endl << "***Homework 3C***" << endl;
    homework3C();
    return 0;
}
