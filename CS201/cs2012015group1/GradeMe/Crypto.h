/*
Cameron Showalter
Finished 12-4-2015

Teacher: Brandon M.
CS 201 project
V: 1.Whatever
*/

#ifndef TESTING_H_INCLUDED
#define TESTING_H_INCLUDED
//Jim's Code
    //Takes a string and converts it with a key
    char * encryptCaesar(char encryptCaesar[], int key);
    //Takes a incrypted string and decrypts it with a key
    char * decryptCaesar(char decryptCaesar[], int key);

//Alex's Code
    //Takes a char string and will subsitute the letter with a value from the given key
    char * encryptSub(char * plainText, char * key);

    //Takes the given cipher and uses that to find the correct letter to subsitute back
    char * decryptSub(char * cipher, char * key);

    //Returns which letter of the alphabet the letter is.
    int getPlace(char letter);

    //Returns which letter of the KEY the letter is.
    int getKeyPlace(char letter, char * key);

    //returns the size of the array
    int getStringSize(char * string);

    //returns the size of an array
    int getSize(char * string);

//Cameron's Code
    //Makes sure i is never greater than LENGTH, for pointer use
    int maxLength(int i, int LENGTH);

    //Get size of array, also wont conflict with Alex's getSize
    int getSize2(char * string);

    // Takes normal alphabet letters and converts to Morse
    char* encryptMorse(char Morse[]);

    // Takes Morse and converts to normal alphabet letters
    char* decryptMorse(char notMorse[]);

#endif // TESTING_H_INCLUDED
