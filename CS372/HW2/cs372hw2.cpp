//cs372hw2.cpp
//Cameron Showalter


#include "cs372hw2.h"
#include <string>	//string stoi
#include <stdlib.h>    // atoi
#include <vector> //vector
#include <cctype> // isdigit
#include <iostream> // cout endl

//NOTE: it said to assume correct input is passed, so you never actually never need to check the delimiters
//strings have to be: ("optional delimiter tag") folowed by fence post style number-delimiter-number

int Add(std::string numbers)
{
	int returnMe = 0;
	std::vector<int> passedNegatives;
	bool foundNegative = false;

	//check for possible delimiter tag... and just delete it
	if(numbers.size() >= 5 && numbers.at(0)=='/' && numbers.at(1)=='/')
	{
		//no need for it, so make it line up with strings that are passed without delimiters
		numbers.erase(0,4); //no need to know what it is because it is assumed that we are given good input... sadily
	}
	for(unsigned int i=0; i<numbers.size(); ++i)
	{	
		//previus term was delimiter, even if delimiter is negative, thats two in a row
		if(numbers.at(i) == '-')
		{
			foundNegative = true;
			++i;//move past the negative
		}
		int j = i;
		while( i<numbers.size()-1 && std::isdigit(numbers.at(i+1)) )
		{
			//keep going forward while the nextchar is a int, and the char after that isn't past the string
			++i;
		}

		//j = index first char of "int"
		//i = index last char of "int"
		if(foundNegative)
		{
			passedNegatives.push_back( -1 * std::stoi(numbers.substr(j,i-j+1)) );
		}
		else
		{
			returnMe += std::stoi( numbers.substr(j,i-j+1) );
		}
		foundNegative = false;
		//at end of the current number, now to skip the delimiter and start the loop again:
		++i;
	}
	if(passedNegatives.size() != 0)
	{
		std::cout << "negatives not allowed: ";
		for(unsigned int i=0; i<passedNegatives.size(); ++i)
		{
			std::cout << passedNegatives[i] << " ";
		}
		std::cout << std::endl << "Non-Negatives Add to: " << returnMe << std:: endl << std::endl;
	}
	else
	{
		std::cout << "Calculated Total of numbers: " << returnMe << std::endl;
	}
	return returnMe;
}