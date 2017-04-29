#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "hw1.h"

int getIdFromFile(string fileName, istream & itest, ostream & otest)
{
    vector<string> names;
    vector<int> userID;

    bool nameFound = false;
    int count = 0;
    ifstream myFile;
    myFile.open ("users.dat");
    string personsName;





    if(myFile.is_open())
    {
        while(!myFile.eof())
        {
            string name;
            myFile >> name;
            int id;
            myFile >> id;
            names.push_back(name);
            userID.push_back(id);
            cout << name << " " << id <<endl;
        }
        while(!nameFound){

            for(int i=0; i<names.size(); i++){
                if(names[i].compare(personsName)==0){
                    cout << "Same Name";
                    nameFound=true;
                }
            }
        }
    }
    else
    {
        cout << "404 File Not Found" << endl;
    }
    myFile.close();
    return 0;
}





/*
B:
In this exercise, you will write a function to read a binary file in "random access" mode. Your function will open a file that contains a list of 4-byte binary integers. You should
read the first integer to find the index of the next integer, print this index to an ostream, and repeat until you hit a negative integer. *IF* the file was an array of integers,
you'd be doing something like this:
int i=0;
          while (i >=0 )
          {
            i=myArray[i];
            cout << i << "\n";
          }
You can implement this using either seekg to jump around in the file (remember that an integers size, probably 4 bytes but possibly 8 depending on your system, can be found by writing
sizeof(int)), or by reading the whole file into a big array first. I promise I won't make an infinite loop or an out-of-bounds index--if your indices repeat or become
huge, then you're seeking to the wrong spot!
Your function should be called numberChase and should take two parameters, a C++ string for the filename, and an ostream to print the indices too.
(HINT: The first file the testing program checks contains the four integers +3 0 -77 +2; you're supposed to follow the integers. So after reading the 3, you jump to *integer* 3; this
 has the value 2, so you jump to *integer* 2; this has the value -77 so you stop.)
*/
