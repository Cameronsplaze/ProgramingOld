// Cameron Showalter
//CS411 Algorithms
//Homework 5
//Last updated:11-20-2017




#ifndef BUILD_H_INCLUDED
#define BUILD_H_INCLUDED

#include <algorithm>
#include <vector>

class BridgePlacer
{
public:

	// Sets up to call bridge_recurse and updates the workspace
	BridgePlacer(const std::vector<std::vector<int> > & bridges, int west, int east);

	// The return value for this class
	int getMasterWeight();

private:
	// goes through the bridgelist and finds the best combo of bridges
	// for the government to use to become rich
	int bridge_recurse(int j);

	// checks if bridge is placeable. relies on fact that bridgeList is sorted
	bool bridgePlaceable(int attemptBridge, int lastPlacedBridge);

private:
	// The list of bridges in sorted order
	std::vector< std::vector<int> > bridgeList;

	// the memory of whats already been calculated
	std::vector<int> workspace;

	// number of cities on each side
	int westCities;
	int eastCities;

	//the return variable 
	int returnMe;
};

// compares two bridges to sort them
bool compareVec(std::vector<int> a, std::vector<int> b);

int build(int westCities, int eastCities, const std::vector<std::vector<int> > & bridgeList);


#endif // BUILD_H_INCLUDED


