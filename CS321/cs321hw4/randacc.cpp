/*
	-randacc.cpp
	-Cameron Showalter
	-Last Revised: 3-28-2018
	-Read and write records inside a file with random access.
	 size of each record is "RECORD_LENGTH"
*/

#include <iostream>
#include <fstream>
#include <string>
#include "randacc.h"
#include <unistd.h> // for _exit, write, close
#include <sys/mman.h> // for mmap, munmap, related constants
#include <fcntl.h> // for open, related constants


const size_t RECORD_LENGTH = 8;
const std::string FILEPATH = "randacc.txt";
const size_t NUM_OF_RECORDS = 100;
const size_t SIZE = RECORD_LENGTH * NUM_OF_RECORDS;


/*
	readRecord:
		Given a ptr, prompts the user for an ID and reads the record
		of RECORD_LENGTH back to the user
*/
void readRecord(char* p)
{
		// read a record
	int record_ID;
	std::cout << "Which record would you like to read? (0-99): ";
	std::cin >> record_ID;
	std::cout << std::endl;

	if(record_ID < 0 || record_ID > 99)
	{
		std::cout << "Wrong ID, start over." << std::endl;
		return;
	}
	std::cout << std::endl;

	for(int i=0; i<RECORD_LENGTH; ++i)
	{
		std::cout << p[(record_ID*RECORD_LENGTH)+i];
	}
	std::cout << std::endl;
}

/*
	writeRecord:
		prompts the user for an ID, and writes over the previus
		record of the same ID with user input. if user_input is greater
		than RECORD_LENGTH, it will truncate to RECORD_LENGTH size.
*/
void writeRecord(char* p)
{
		// write a record
	std::string usrInput = "";
	int record_ID;
	std::cout << "What do you want to write? (up to " << RECORD_LENGTH << " chars): ";
	std::cin >> usrInput;
	std::cout << std::endl;
	usrInput.resize(RECORD_LENGTH, '-');

	std::cout << "Where would you like to write to? (0-99): ";
	std::cin >> record_ID;
	std::cout << std::endl;
	if(record_ID < 0 || record_ID > 99)
	{
		std::cout << "Wrong ID, start over." << std::endl;
		return;
	}

	for(int i=0; i<RECORD_LENGTH; ++i)
	{
		p[(record_ID*RECORD_LENGTH)+i] = usrInput[i];
	}
}

/*
	randacc:
		A function that lets you create a file, and have random access
		to records inside the file. If the file exists, it will not be
		overridden. Configs for the file (FILEPATH, RECORD_LENGTH, NUM_OF_RECORDS)
		Are declared at the top of this file.
*/
void randacc()
{
    std::ifstream f(FILEPATH.c_str());
    bool fileExists = f.good();


	int fd = open( FILEPATH.c_str(), O_RDWR | O_CREAT, 0644);
	if(fd == -1)
	{
		std::cout << "Can't make file," << FILEPATH << ", Quitting" << std::endl;
		return;
	}

	if(!fileExists)
	{
		for(std::size_t i=0; i<SIZE; ++i)
		{
			write(fd, "-", 1);

		}
	}
	void* addr = mmap( nullptr, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0 );

	char* p = (char*)addr;

	while(true)
	{
		std::cout << std::endl << std::endl <<
		"	1: Read a record" << std::endl <<
		"	2: Write a record" << std::endl <<
		"	3: Quit" << std::endl <<
		"Enter a Number(1-3): ";

		int answer;
		std::cin >> answer;

		if(answer == 1)
		{
			readRecord(p);
		}
		else if(answer == 2)
		{
			writeRecord(p);
		}
		else if(answer == 3)
		{
			std::cout << "Quitting" << std::endl;
			close(fd);
			munmap(addr, SIZE);
			return;
		}
		else
		{
			std::cout << "Please enter something between 1-3" << std::endl;
		}
	}	
}