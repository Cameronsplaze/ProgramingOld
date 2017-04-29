#include "Crypto.h"
#include <new>
#include <iostream>

using namespace std;

bool debug = false;

const int SIZE = 26;

char upper[SIZE] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
char lower[SIZE] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

//Takes a char string and will subsitute the letter with a value from the given key
char * encryptSub(char * plainText, char * key)
{
	int len = getSize(plainText);
	char * res = new char[len];

	for (int i = 0; i < len; i++)
	{
		//What letter of the alphabet
		//Used to replace with correct letter from key
		int place = getPlace(plainText[i]);

		if (place == -1)
		{
			//This is not a letter and does not need to be changed
			res[i] = plainText[i];
		}
		else {
			//Finds the correct letter to be swapped
			res[i] = key[place];
		}
		if (debug)
			cout << res[i];
	}

	return res;
}

//Takes the given cipher and uses that to find the correct letter to subsitute back
char * decryptSub(char * cipher, char * key)
{
	int len = getSize(cipher);
	char * res = new char[len];

	for (int i = 0; i < len; i++)
	{
		//What letter of the alphabet
		//Used to replace with correct letter from key
		int place = getKeyPlace(cipher[i], key);

		if (place == -1)
		{
			//This is not a letter and does not need to be changed
			res[i] = cipher[i];
		}
		else {
			//Finds the correct letter to be swapped
			res[i] = upper[place]; //Needs to be capital...
		}
		if (debug)
			cout << res[i];
	}


	return res;
}

//Returns which letter of the KEY the letter is.
int getKeyPlace(char letter, char * key)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (letter == key[i])
		{
			return i;
		}
	}

	//if the letter is not found it is not a letter
	return -1;
}


//Returns which letter of the alphabet the letter is.
int getPlace(char letter)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (letter == upper[i] || letter == lower[i])
		{
			return i;
		}
	}

	//if the letter is not found it is not a letter
	return -1;
}


//returns the size of the array
int getSize(char * string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}
