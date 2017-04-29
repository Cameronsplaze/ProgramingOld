#include <iostream>
#include <string>
#include "Box.h"
using namespace std;

int main()
{
    Box::setCounter(5);
    cout << Box::getCount()<<endl;
    setLength(6);
    cout << Box::getSize() << endl;
    return 0;
}
