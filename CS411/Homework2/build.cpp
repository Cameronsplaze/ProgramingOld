// Cameron Showalter
//CS411 Algorithms
//Last updated: 9-26-2017


//NOTE:
// It will compile if you type -std=c++11 or -std=c++14,
// but not if you don't type either and leave it blank.



#include <vector>
#include "build.h"


BridgePlacer::BridgePlacer::BridgePlacer(const std::vector<std::vector<int> > & bridges, int numCities)
{
	masterWeight = 0;
	tempWeight = 0;
	smallerNumberCities = numCities;
	bridgeList = bridges;
	bridge_recurse(0);
}

int BridgePlacer::getMasterWeight()
{
	return masterWeight;
}

void BridgePlacer::bridge_recurse(int j)
{
	//starting off where you left off, keep going through the vector
	for(int i=j; i<bridgeList.size(); ++i)
	{
		if( bridgePlaceable(i) )//bunch of checks for placing a bridge correctly
		{
			//set everything up for the recursive call
			j=i+1;


			//now place it
			currBridges.push_back(bridgeList[i]);
			tempWeight += bridgeList[i][2];
			
			if(tempWeight > masterWeight)
			{
				masterWeight = tempWeight;
			}

			// now build/continue without it

			//If currBridges DOES equal the smaller side of cities, anything the recurse does will
			//	return false anyway... so skip it
			if(currBridges.size() != smallerNumberCities)
			{
				bridge_recurse(j);
			}
			currBridges.pop_back();
			tempWeight -= bridgeList[i][2];


		}
	}
}

bool BridgePlacer::bridgePlaceable(int j)
{
	for(int i=0; i<currBridges.size(); ++i)
	{
		if( (currBridges[i][0] <= bridgeList[j][0] && currBridges[i][1] >= bridgeList[j][1] ) ||
			 currBridges[i][0] >= bridgeList[j][0] && currBridges[i][1] <= bridgeList[j][1] )
		{
			return false;
		}
	}
	return true;
}

int build(int westCities, int eastCities, const std::vector<std::vector<int> > & bridgeList)
{
	int smallerSize;
	if(westCities < eastCities)
	{
		smallerSize = westCities;
	}
	else //if westCities >= eastCites
	{
		smallerSize = eastCities;
	}

	BridgePlacer weightedBridges(bridgeList, smallerSize);
	return weightedBridges.getMasterWeight();
}
