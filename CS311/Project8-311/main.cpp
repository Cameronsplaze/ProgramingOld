//Cameron Showalter
//Assignment 8, 311
//12-6-2016


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::map;

using std::size_t;

//  fileExists
//pre:
//  name of File
//post:
//  bool on if it exists
bool fileExists(const string& fname)
{
    ifstream file(fname.c_str());
    return (bool)file;
}

typedef map<string, size_t> numberWords;

void countWords(ifstream& in, numberWords& nWords)
{
    string str;
    while (in >> str)
    {
        ++nWords[str];
    }
}
//  main
//pre:
//  n/a
//post:
//  tells the user what distinct words are in a file,
//  and how many times each one accures

int main()
{

    string fname;
    bool goodFile = false;

    while(!goodFile){
        cout << "Enter a file name (QUIT to exit): ";
        getline(std::cin, fname);
        ifstream ifs(fname);
        cout<<endl;
        if(fileExists(fname))
        {
            goodFile = true;
        }
        else if(fname=="QUIT")
        {
            return 0;
        }
    }

    ifstream infile(fname);
    numberWords n;
    countWords(infile, n);

    cout << "Number of Different Words: " << n.size() << endl;

    for (numberWords::iterator x = n.begin(); x != n.end(); x++)
    {
        cout << x->first << " "<< x->second << endl;
    }
    return 0;
}
