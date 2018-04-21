#ifndef MAP_ALLOC_H
#define MAP_ALLOC_H

/*
	All comments in .cpp file
*/

#include <cstddef> // for size_t

void* mapAlloc(std::size_t size);

void mapFree(void * freeMe);

#endif // MAP_ALLOC_H