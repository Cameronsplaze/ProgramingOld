
/*Cameron Showalter
CS201
11-15-15
HOMEWORK 6
*/

#ifndef HW_6_INCLUDED
#define HW_6_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;

int * reverseArray(const int arry[], const int size);
//only YOU... can delete aarryTwo
int * reverseArray(const int arry[], const int size){
	int arryTwo[size];
	int *arryTwo_ptr = new int[size];

	//BB: this works, but you can combine the two steps and not have to use 2 for loops
	for(int i=0; i<size; i++){
		arryTwo[i] = arry[i];
		arryTwo_ptr[i] = arryTwo[i];
	}
	for(int i = 0; i < size/2; i++)
	{
		int temp = arryTwo_ptr[i];
		arryTwo_ptr[i] = arryTwo_ptr[size-1-i];
		arryTwo_ptr[size-1-i] = temp;
	}
	return arryTwo_ptr;
}
#endif
