#include <iostream>
#include <fstream>
#include <String>
//Got help from http://arstechnica.com/civis/viewtopic.php?t=689363
//to show how reinterpret_cast works.
//using namespace std;
using std::cout;
int main()
{
    int data;
    int counter=0;
    int total;
    std::ifstream infile;
    infile.open("C:\\Users\\Cameron\\Desktop\\Lab2\\data.dat", std::ifstream::binary | std::ifstream::in);
    //data = infile.get();


    while(!infile.eof())
    {
        infile.read(reinterpret_cast<char*>(&data), sizeof(int));
        total = total + data;
        counter++;
        //cout << counter << endl;
    }
    cout << (total/counter);
    infile.close();

/*
    ifstream in("data.dat", ios_base::binary);

    int x(0);

    in.read(reinterpret_cast<char*>(&x), sizeof(int));

    std::cout << x;
*/

    /*
    const char* BinaryFile = "data.dat";
    int toStore = 10;
    ofstream myFile(BinaryFile, binary);

    myFile.write((char*) & toStore, sizeof(toStore));
    myFile.close();

    int toRestore = 0;
    ifstream otherFile(BinaryFile, binary);
    otherFile.read((char*) & toRestore, sizeof(toRestore));

    cout << toRestore << endl;
*/
    return 0;

}
