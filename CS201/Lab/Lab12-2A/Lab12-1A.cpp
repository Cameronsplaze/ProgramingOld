#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string input, Filename;
    char inputText;
    fstream inputFile;
    inputFile.open("jukeBoxHero.txt");
    cout << "Do you want to input a new file (y/n): ";
    cin >> inputText;
    getline(inputFile, input);
    if(inputText == 'y'){
        cout << "What do you want to name the new file?: ";
        cin >> Filename;
        while(inputFile)
        {
            inputFile << input << endl;
            getline(inputFile, input);
        }
    cout << "File finished." << endl;
    inputFile.close();
    }
    else{
        while(inputFile)
        {
            cout << input << endl;
            getline(inputFile, input);
        }
    }
    return 0;
}
