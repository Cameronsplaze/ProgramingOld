// Cameron Showalter
// main.cpp

#include <iostream>
#include <cstddef> // size_t
#include <string>


#include "mapalloc.h"
#include "randacc.h"

/*
	To compile mapalloc.h and randacc.h
*/

int main()
{
	std::cout << "-----Part A-----" << std::endl;
	std::size_t size = 32;
	void* ptr = mapAlloc(size);
	char* charPTR = (char*) ptr;

    std::string msg = "Cameron-Waz-Here";
    for (size_t i = 0; i < msg.size(); ++i)
    {
        charPTR[i+3] = msg[i];
    }

	std::cout << ptr << std::endl;
	mapFree(ptr);

	std::cout << "-----Part B-----" << std::endl;
	randacc();



	return 0;
}