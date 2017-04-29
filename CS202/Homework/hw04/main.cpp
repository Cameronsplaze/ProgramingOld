//Cameron Showalter
//CS201
#include <iostream>
#include <iomanip>

using namespace std;
//takes length and width and returns area
int getArea(int length, int width){
    return (length * width);
}
//takes length and width and returns parimeter
int getParim(int length, int width){
    return ((length * 2)+(width * 2));
}
//takes time fallen and gives distance fallen (on earth)
double distance(int timeFall){
    return ((1.0/2.0)*(9.81)*((double)timeFall)*((double)timeFall));
}
// takes a size and prints a mult table of said size
void multTable(int tableSize){
    tableSize++;
    for (int i=0; i<tableSize; i++){
        for(int j=0; j<tableSize; j++){
            cout << setw(4)<<i*j;
        }
        cout << endl;
    }
}
int main()
{
    //takes length and width and returns parim and area
    cout << "***PART ONE***" << endl;
    int length;
    int width;
    cout << "Give me the length of a rectangle: ";
    cin >> length;
    cout << "Give me the width of a rectangle: ";
    cin >> width;
    cout << endl << "Area: " << getArea(length, width);
    cout << endl << "parimeter: " << getParim(length, width);

    //takes time and gives how long an object has been falling
    cout << endl << "***PART TWO***" << endl;
    int timeFall;
    cout << "How long have you been falling? (s): ";
    cin >> timeFall;
    cout << "You've been falling for " << distance(timeFall) << " Meters!";

    //takes an int and prints a multTable
    cout << endl << "***PART THREE***" << endl;
    int tableSize;
    cout << "how big is the table? (int): ";
    cin >> tableSize;
    multTable(tableSize);

    return 0;
}
