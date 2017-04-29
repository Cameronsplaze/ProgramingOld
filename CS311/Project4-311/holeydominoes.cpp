// holeydominoes.cpp

// Cameron Showalter
// 10-18-16
// Assignment 4

#include "holeydominoes.h"
#include <vector>

//using namespace std;
using std::size_t;
using std::vector;

//description in holeydominoes.h
int holeyDominoes(int height, int width, int row, int column) // height, width, row, column
{
    if ((height*width)%2 == 0)
    {
        return 0;
    }
    int returnMe = 0;
    boardType board;

    for (size_t i=0; i<width; i++)
    {
    	vector<int> vec;
    	board.push_back(vec);
        for (size_t j=0; j < height; j++)
        {
            board[i].push_back(0);
        }
    }
    board[column][row] = 1; //forbidden square
    returnMe += holeyDominoes_recursive(board, 0);
    return returnMe;
}


//description in holeydominoes.h
int holeyDominoes_recursive(boardType & board, int numberCalls)
{
    if ( board.size()*board[0].size() == 2*numberCalls+1 )
    {
        return 1;
    }
    int returnMe = 0;
    for (size_t i=0; i < board.size(); ++i)
    {
    	for (size_t j=0; j < board[i].size(); ++j)
    	{

    		if (board[i][j] != 0)
            {
                continue;
            }
    		if (j+1 < board[i].size() && board[i][j+1] == 0)
            {
				board[i][j] = 1;
				board[i][j+1] = 1;
				returnMe += holeyDominoes_recursive(board, numberCalls + 1);
				board[i][j] = 0;
				board[i][j+1] = 0;
			}
    		if (i+1 < board.size() && board[i+1][j] == 0)
            {
    			board[i][j] = 1;
    			board[i+1][j] = 1;
    			returnMe += holeyDominoes_recursive(board, numberCalls+1);
    			board[i][j] = 0;
    			board[i+1][j] = 0;
    		}
			return returnMe;
    	}
    }
}
