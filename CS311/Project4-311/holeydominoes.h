// holeydominoes.h

// Cameron Showalter
// 10-18-16
// Assignment 4
#ifndef HOLEYDOMINOES_H_INCLUDED
#define HOLEYDOMINOES_H_INCLUDED

#include <vector>
using std::vector;

typedef vector<vector<int>> boardType;


// holeyDominoes
// Pre:
//		0 <= row < height
//		0 <= column < width
// Post:
//		return number of combinations with the forbidden square
int holeyDominoes(int height, int width, int row, int column);



// holeyDominoes_recursive
// finds combos of dominoes on the board
// Pre: n/a
// Post:
// 		return number of combinations with the forbidden square
int holeyDominoes_recursive(boardType & board, int numberCalls);

#endif // HOLEYDOMINOES_H_INCLUDED
