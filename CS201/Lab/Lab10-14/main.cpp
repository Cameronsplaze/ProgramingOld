#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
    int total = 0;
    srand(time(0));
    const int SIZE = 100;
    int arry[SIZE];
    //fills with random numbers
    for(int i=0; i<SIZE; i++){
        arry[i] = rand()%100+1;
    }
    //adds up those random numbers
    for(int i=0; i<SIZE; i++){
        total+=arry[i];
    }
    cout << "100 random numbers added together equal: " << total;
    return 0;
}
