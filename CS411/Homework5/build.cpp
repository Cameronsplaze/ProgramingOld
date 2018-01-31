// Cameron Showalter
//CS411 Algorithms
//Last updated: 9-26-2017


#include <iostream>
#include <vector>
#include "build.h"






BridgePlacer::BridgePlacer(const std::vector<std::vector<int> > & bridges, int west, int east)
	:bridgeList(bridges),
	workspace(bridges.size(), -1 )
{

	//bridgeList(bridges);
	westCities = west;
	eastCities = east;



	//workspace.resize( bridges.size() );
	//std::fill(workspace.begin(), workspace.end(), -1);
	std::sort(bridgeList.begin(), bridgeList.end(), compareVec); 

	// the last element in workspace is equal to the last element in the bridgelist
	workspace[bridgeList.size()-1] = bridgeList[bridgeList.size()-1][2]; 

	returnMe = bridge_recurse(0);
}

int BridgePlacer::getMasterWeight()
{
	return returnMe;
}

int BridgePlacer::bridge_recurse(int j)
{	
	// maybe add check for if all cities are used up? sorted order, so if one side 
	// touches the last element, skip rest?

	int returnMaximum = 0;
	for(int i=j; i<bridgeList.size(); ++i)
	{
		if( bridgePlaceable(i, j-1) )
		{
			if(workspace[i] == -1)
			{
				// If base case, don't recurse
				if( bridgeList[i][0] == westCities-1 || bridgeList[i][1] == eastCities-1 )
				{
					workspace[i] = bridgeList[i][2];
				}
				else
				{
					workspace[i] = bridgeList[i][2] + bridge_recurse(i+1);
				}
			}
			returnMaximum = std::max(returnMaximum, workspace[i]);
		}
	}
	return returnMaximum;
}

bool BridgePlacer::bridgePlaceable(int attemptBridge, int lastPlacedBridge)
{
	// "-1" becasue "0-1" is passed in, and this means no other bridges are currently used
	if(lastPlacedBridge == -1)
		return true;
	if( (bridgeList[lastPlacedBridge][0] <= bridgeList[attemptBridge][0] && bridgeList[lastPlacedBridge][1] >= bridgeList[attemptBridge][1]) ||
		(bridgeList[lastPlacedBridge][0] >= bridgeList[attemptBridge][0] && bridgeList[lastPlacedBridge][1] <= bridgeList[attemptBridge][1]) )
	{
		return false;
	}
	return true;
}

int build(int westCities, int eastCities, const std::vector<std::vector<int> > & bridgeList)
{
	if(bridgeList.size() == 0)
		return 0;

	BridgePlacer weightedBridges(bridgeList, westCities, eastCities);
	return weightedBridges.getMasterWeight();
}

bool compareVec(std::vector<int> a, std::vector<int> b)
{
	if(a[0] == b[0])
		return a[1] < b[1];
	return a[0] < b[0];
}
