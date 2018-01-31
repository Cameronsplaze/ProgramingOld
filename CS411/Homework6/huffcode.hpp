// huffcode.hpp  UNFINISHED
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Header for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2017

#ifndef FILE_HUFFCODE_H_INCLUDED
#define FILE_HUFFCODE_H_INCLUDED

#include <string>
#include <unordered_map>
#include <vector>

#include <memory>



class HuffNode
{
public:

	HuffNode(std::shared_ptr<HuffNode> left, std::shared_ptr<HuffNode> right, int weight)
	{
		totalWeight = weight;
		leftPath = left;
		rightPath = right;
		letterValue = NULL;
	}

	HuffNode(char letter, int weight)
	{
		totalWeight = weight;
		leftPath = NULL;
		rightPath = NULL;
		letterValue = letter;
	}

	int getWeight(){
		return totalWeight;
	}
	char getChar(){
		return letterValue;
	}
	std::shared_ptr<HuffNode> getLeftPath(){
		return leftPath;
	}
	std::shared_ptr<HuffNode> getRightPath(){
		return rightPath;
	}

private:
	int totalWeight;
	char letterValue;

	std::shared_ptr<HuffNode> leftPath;
	std::shared_ptr<HuffNode> rightPath;
};




// Class HuffCode
// Encoding & decoding using a Huffman code
class HuffCode {

// ***** HuffCode: ctors, dctor, op= *****
public:

    // Compiler-generated default ctor, copy ctor, copy =, dctor used

// ***** HuffCode: general public functions *****
public:
	void mapper(HuffNode &currNode, std::string decoder);

    void setWeights(const std::unordered_map<char, int> &theweights);

    std::string encode(const std::string & text) const;

    std::string decode(const std::string & codestr) const;

// ***** HuffCode: data members *****
private:
	std::shared_ptr<HuffNode> root_;
	std::vector<std::pair<char, std::string>> charMaps_;

};  // End class HuffCode





#endif //#ifndef FILE_HUFFCODE_H_INCLUDED

