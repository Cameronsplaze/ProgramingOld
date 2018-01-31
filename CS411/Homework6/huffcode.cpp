// huffcode.cpp  UNFINISHED
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Source for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2017

#include "huffcode.hpp"  // for class HuffCode declaration
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

void HuffCode::mapper(HuffNode &currNode, std::string decoder)
{
	char tempChar;
	if(currNode.getChar() == NULL)
	{
		mapper(*currNode.getLeftPath(), decoder + "0" );
		mapper(*currNode.getRightPath(), decoder + "1" );
	}
	else //at leaf
	{
		//std::cout << "testing: " << decoder << "testing2: " << currNode.getChar() << std::endl;
		tempChar = currNode.getChar();
		charMaps_.push_back(std::make_pair(tempChar, decoder));
	}
}

bool comparePairs(HuffNode a, HuffNode b)
{
	if(a.getWeight() == b.getWeight())
		return a.getChar() > b.getChar();
	return a.getWeight() > b.getWeight();
}

void HuffCode::setWeights(const unordered_map<char, int> &theweights)
{
	std::vector<std::pair<char, int>> weightedVector(theweights.begin(), theweights.end());
	std::vector<HuffNode> NodeClasses;
	// make all the base nodes
	for(int i=0; i<weightedVector.size(); ++i)
	{
		NodeClasses.push_back(HuffNode(weightedVector[i].first, weightedVector[i].second));	// char, weight
	}

	if(weightedVector.size() == 0){
		root_ = std::make_shared<HuffNode>(HuffNode(NULL, 0));
		return;
	}
	else if(weightedVector.size() == 1){
		root_ = std::make_shared<HuffNode>(HuffNode(NodeClasses[0].getChar(), NodeClasses[0].getWeight() ));
		return;
	}


	int first;
	int second;
	while(NodeClasses.size() > 1)
	{
		first = NodeClasses.size()-1;
		second = NodeClasses.size()-2;

		std::sort(NodeClasses.begin(), NodeClasses.end(), comparePairs);
		HuffNode newNode(std::make_shared<HuffNode>(NodeClasses[first]), std::make_shared<HuffNode>(NodeClasses[second]), NodeClasses[first].getWeight() + NodeClasses[second].getWeight());

		NodeClasses.pop_back();
		NodeClasses.pop_back();
		NodeClasses.push_back(newNode);
	}

	root_ = std::make_shared<HuffNode>(NodeClasses[0]);
	mapper(*root_, "");
}


string HuffCode::encode(const string & text) const
{
	if(text.size() == 0)
		return "";
	std::string returnMe = "";
	for(int i=0; i<text.size(); ++i)
	{
		for(int j=0; j<charMaps_.size(); ++j)
		{
			if(text.at(i) == charMaps_[j].first)
			{
				returnMe += charMaps_[j].second;
				continue;
			}
		}
	}
    return returnMe;
}


string HuffCode::decode(const string & codestr) const
{
	auto path = *root_;
	std::string returnMe = "";
	for(int i=0; i<codestr.size(); ++i)
	{
		if(codestr.at(i) == '0')
		{
			path = *path.getLeftPath();
		}
		else if(codestr.at(i) == '1')
		{
			path = *path.getRightPath();
		}

		if(path.getChar() != NULL)
		{
			returnMe += path.getChar();
			path = *root_;
		}
	}
    return returnMe;  
}


/*
void printVec(std::vector<HuffNode> &v)
{
	for(int i=0; i<v.size(); ++i)
	{
		std::cout << i << ":  " << v[i].getWeight() << " " << v[i].getChar() << std::endl;
	}
}
void printVec(std::vector<std::pair<char, std::string> > &v)
{
	for(int i=0; i<v.size(); ++i)
	{
		std::cout << i << ": " << v[i].first << " " << v[i].second << std::endl;
	}
}
*/

