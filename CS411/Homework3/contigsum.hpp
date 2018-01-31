// inversions.h
// Cameron Showalter
// 13 Oct 2017

#ifndef CONTIGSUM_HPP_INCLUDED
#define CONTIGSUM_HPP_INCLUDED

#include <algorithm>	// for std::max
#include <iostream>     // for std::cout, std::endl, std::cin

struct allValues
{
	int singleMaxValue; //A
	int anchoredLeft; //B
	int anchoredRight; //C
	int totalSize; //D
};


template<typename RAIter>
allValues recursiveContigsum(RAIter first, RAIter last)
{
	// Check for root cases
	if(last-first < 2)
	{
		allValues returnMe;

		returnMe.singleMaxValue = *first;

		returnMe.anchoredLeft = *first;
		returnMe.anchoredRight = *(last-1);
		returnMe.totalSize = 0;
		int tempSize = last-first;
		for(unsigned int i=0; i<tempSize; ++i)
		{
			returnMe.totalSize += *(first+i);
		}
		return returnMe;
	}
	//not root, combine two sides
	else
	{
		allValues leftSide = recursiveContigsum(first, first+(last-first)/2); // last/2
		allValues rightSide = recursiveContigsum(first+(last-first)/2, last);			// first+(last-first)/2

		allValues returnMe;
		returnMe.singleMaxValue = std::max( std::max(leftSide.singleMaxValue, rightSide.singleMaxValue), leftSide.anchoredRight + rightSide.anchoredLeft); //max( maxLeft, maxRight, maxBothCombined)
		returnMe.anchoredLeft = std::max(leftSide.anchoredLeft, leftSide.totalSize + rightSide.anchoredLeft); //max( anchorleftside, allLeft + rightAnchoredLeft)
		returnMe.anchoredRight= std::max(rightSide.anchoredRight, rightSide.totalSize + leftSide.anchoredRight);
		returnMe.totalSize = leftSide.totalSize + rightSide.totalSize;

		return returnMe;
	}


}



template<typename RAIter>
int contigSum(RAIter first, RAIter last)
{
	if(last-first == 0)
	{
		return 0;
	}
	allValues totalSum = recursiveContigsum(first, last);
	// messy, but puts the max of the struct, or 0 incase all of struct is negative into returnMe
	int returnMe = std::max(std::max( std::max(totalSum.singleMaxValue,totalSum.anchoredLeft), std::max(totalSum.anchoredRight,totalSum.totalSize) ), 0);
	return returnMe;
}



#endif // CONTIGSUM_HPP_INCLUDED

// A - 