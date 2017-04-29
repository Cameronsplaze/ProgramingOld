#include <iostream>

using namespace std;


double average(double numberOne, double numberTwo, double numberThree, double numberFour){
    return ((numberOne + numberTwo + numberThree + numberFour)/4);
}
int loopToOnehundred(int counter){
    int returnMe = 0;
    for(int i=counter; i<=1000; i+=counter){
        returnMe++;
    }
    return returnMe;
}
int main()
{
    double numberOne;
    double numberTwo;
    double numberThree;
    double numberFour;

    cout << "***Part1***" << endl;
    cout << "Number 1/4: ";
    cin >> numberOne;
    cout << endl << "Number 2/4: ";
    cin >> numberTwo;
    cout << endl << "Number 3/4: ";
    cin >> numberThree;
    cout << endl << "Number 4/4: ";
    cin >> numberFour;
    cout << endl << "The average of the four numbers is " << average(numberOne, numberTwo, numberThree, numberFour);

    int counter;
    cout << endl << "***Part2***" << endl;
    cout <<"pick a number to count to 1000 by: ";
    cin >> counter;
    cout << "It took this many times to reach 1000 counting by you're number: " <<loopToOnehundred(counter);
    return 0;
}
