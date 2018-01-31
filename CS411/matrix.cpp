

#include <iostream>
#include <vector>

// prints the 2D vector....
void printVec(std::vector< std::vector<int> > &v)
{
	for(int i=0; i<20; ++i)
	{
		for(int j=0; j<20; ++j)
		{
			std::cout << v[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// Makes 20x20 Vector that has only 100 accuring once.
void makeVec(std::vector< std::vector<int> > &v)
{
	std::vector<int> newRow;
	int newColumn = 0;
	for(int i=0; i<20; ++i)
	{
		v.push_back(newRow);
		for(int j=0; j<20; ++j)
		{
			v[i].push_back(newColumn);
			v[i][j] = i*j;
		}
	}
}

//find int in a 2D vector
void findIntInVec(std::vector< std::vector<int> > &v, int numberToFind)
{
	// idea is to start at the bottom-left corner, and zig-zag as needed
	// to the top right, shifting over if numbers get too small.
	// speed = 2*O(n), or liniar because currentRow only decreases, and
	// currentColumn only increases.
	int currentRow = v[0].size()-1;
	int currentColumn = 0;

	// not safe because number maybe missing, but just proof of concept
	while(true)
	{
		if(v[currentRow][currentColumn] == numberToFind)
		{
			std::cout << "FOUND AT: " << currentRow << " " << currentColumn << std::endl;
			break;
		}
		else if(v[currentRow][currentColumn] > numberToFind)
		{
			currentRow--;
		}
		else if(v[currentRow][currentColumn] < numberToFind)
		{
			currentColumn++;
		}
	}
}

int main()
{
	std::vector< std::vector<int> > v;
	makeVec(v);
	findIntInVec(v, 100);

	return 0;
}