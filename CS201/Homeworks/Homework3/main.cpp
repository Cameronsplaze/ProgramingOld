#include <iostream>

using namespace std;
// takes any two doubles and add, subtract, multiply, or divides them.
void homework3A(){
    double number1;
    double number2;
    bool broken = false;
    int userInput;
    cout << "Enter number one:";
    cin >> number1; //<< endl;
    cout << "Enter number two:";
    while(!broken){
        cin >> number2;// << endl;
        cout << "Now what would you like to do?\n1.Add\n2.Subtract\n3.Multiply\n4.Divide" <<endl;
        cin >> userInput;
        switch(userInput){
            case 1: cout << "Add: " << number1 + number2;
            broken = true;
            break;
            case 2: cout << "Subtract: " << number1 - number2;
            broken = true;
            break;
            case 3: cout << "Multiply: " << number1 * number2;
            broken = true;
            break;
            case 4: cout << "Divide: " << number1 / number2;
            broken = true;
            break;

            default: cout <<"Pick 1-4 next time."<<endl;
        }
    }
}
//takes the factorial of any int
void homework3B(){
    int userInput;
    int returnMe=1;
    cout << "What number would you like to take the factorial of?: ";
    cin >> userInput;
    for(int i=userInput; i>0; i--){
        returnMe = returnMe * i;
    }
    cout << "The answer is " << returnMe<<endl;
}
//Adds up all numbers until a -1 is entered
void homework3C(){
    int sum=0;
    int userInput;
    bool broken = false;
    while(!broken){
        cout << "Enter a number(-1 to quit): ";
        cin >> userInput;
        if(userInput == -1){
            broken = true;
        }
        else{
            sum = sum + userInput;
        }
    }
    cout << endl << "The total is " << sum << "."<<endl;
}
int main()
{
    cout <<"***Homework A***"<<endl;
    homework3A();

    cout <<"***Homework B***"<<endl;
    homework3B();

    cout <<"***Homework C***"<<endl;
    homework3C();
    return 0;
}
