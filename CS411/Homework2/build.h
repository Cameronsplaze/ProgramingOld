// Cameron Showalter
//CS411 Algorithms
//Last updated: 9-26-2017


//NOTE:
// It will compile if you type -std=c++11 or -std=c++14,
// but not if you don't type either and leave it blank.


#ifndef BUILD_H_INCLUDED
#define BUILD_H_INCLUDED


#include <vector>

class BridgePlacer
{
public:

	BridgePlacer(const std::vector<std::vector<int> > & bridges, int numCities);
	int getMasterWeight();

private:
	void bridge_recurse(int j);
	bool bridgePlaceable(int j);

private:
	std::vector< std::vector<int> > currBridges;
	std::vector< std::vector<int> > bridgeList;

	int masterWeight;
	int tempWeight;
	int smallerNumberCities;
};


int build(int westCities, int eastCities, const std::vector<std::vector<int> > & bridgeList);


#endif // BUILD_H_INCLUDED


