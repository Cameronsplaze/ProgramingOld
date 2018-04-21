/*
	-mapalloc.cpp
	-Cameron Showalter
	-Last Revised: 3-28-2018
	-uses mmap to allocate space inside a file, and munmap
	 to free the space when done. 
*/


#include "mapalloc.h"

#include <cstddef>
#include <string>
#include <iostream>
#include <unistd.h> // for _exit, write, close
#include <sys/mman.h> // for mmap, munmap, related constants
#include <fcntl.h> // for open, related constants


// how mamy digits to save for the size
static int SIZE_BUFFER = 4;


/*
	putSizeAtBeginning:
		takes the size_t size, and stores it as a string at the
		beginning of the pointer. Padds the beginning with 0's
		as needed (total size = SIZE_BUFFER digits.)
*/
void putSizeAtBeginning(std::size_t size, void* addr)
{
	int numDigits = std::to_string(size).size(); // number of "chars"

	// how many leading zeros you need for size:
	std::string size_as_string;
	for(int i=0; i<SIZE_BUFFER-numDigits; ++i)
	{
		//write the leading '0's
		size_as_string += '0';
	}
	size_as_string += std::to_string(size);

	char* p = (char*) addr;
	for(int i=0; i<SIZE_BUFFER; ++i)
	{
		p[i] = size_as_string.at(i);
	}
}


/*
	takeSizeFromBeginning:
		takes the first SIZE_BUFFER number of chars from the pointer,
		and returns the int it contains.
*/
int takeSizeFromBeginning(void* freeMe)
{
	char* p = (char*)freeMe;
	std::string size_as_string;
	for(int i=0; i<SIZE_BUFFER; ++i)
	{
		size_as_string += p[i];
	}
	return std::stoi(size_as_string);
}

/*
	mapAlloc:
		Takes a size, and returns a void pointer to memory with that many bites. 
		DO NOT request a size with more than int SIZE_BUFFER digits. Increase 
		the SIZE_BUFFER at the top of this file if 4 is not enough. (up to size = 9999)
*/
void* mapAlloc(std::size_t size)
{
	size += SIZE_BUFFER; // Extra room to store size variable
    std::string filepath = "mapalloc.txt"; // Path of file to map

    int fd = open( filepath.c_str(), O_RDWR | O_CREAT | O_TRUNC, 0644 );
	if(fd == -1)
	{
		std::cout << "Can't make file," << filepath << ", Quitting" << std::endl;
		return nullptr;
	}
	// populates where you can write with "-"
    for(size_t i=0; i<size; ++i)
    {
        write(fd, "-", 1);
    }
    write(fd, "\n", 1);

	void* addr = mmap(
        nullptr,                 
        size,                    
        PROT_READ | PROT_WRITE, 
        MAP_SHARED,
        fd,                      // File descriptor
        0);                      // Byte offset in file

	if(addr == MAP_FAILED)
	{
		return nullptr;
	}
	//puts the size at the beginning of the allocated space
	putSizeAtBeginning(size, addr);

	// return a pointer to past where you wrote your size
	// convert to char to get rid of warnings
	char* return_ptr = ((char*) addr) + SIZE_BUFFER;
	return (void*) return_ptr;
}

/*
	mapFree:
		Frees all space with the returned pointer, including
		the space reserved to hold the size.
*/
void mapFree(void * freeMe)
{
	if(freeMe == nullptr)
	{
		return;
	}
	// convert to a char just to avoid warnings, then go back
	char* move_ptr = ((char*)freeMe)-SIZE_BUFFER;
	freeMe = (void*) move_ptr;

	int size = takeSizeFromBeginning(freeMe);
	munmap(freeMe, size);

}