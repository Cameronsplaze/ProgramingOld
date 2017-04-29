#include <iostream>

using namespace std;

int main()
{
    double number1;
    double number2;
    int userInput;
    cout << "Enter number one:";
    cin >> number1; //<< endl;
    cout << "Enter number two:";
    cin >> number2;// << endl;
    cout << "Now what would you like to do?\n1.Add\n2.Subtract\n3.Multiply\n4.Divide" <<endl;
    cin >> userInput;
    switch(userInput){
        case 1: cout << "Add: " << number1 + number2;
        break;
        case 2: cout << "Subtract: " << number1 - number2;
        break;
        case 3: cout << "Multiply: " << number1 * number2;
        break;
        case 4: cout << "Divide: " << number1 / number2;
        break;

        default: cout <<"Pick 1-4 next time.";
        break;
    }
    return 0;
}
