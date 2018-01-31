// nqueen_slow.cpp
// Glenn G. Chappell
// 9 Dec 2015
//
// For CS 411/611 Fall 2015
// n-Queens Problem
// Exhaustive Search (No Backtracking)

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <cstddef>
using std::size_t;


typedef vector<int> BoardType;  // Holds queen loc's on a chessboard

// We represent a partial queen placement on a chessboard as a BoardType
// object (board) and an int (n). The int (n) gives the size of the
// chessboard. Thus, n = 8 means an 8 x 8 chessboard. Object board is a
// listing of the queen positions (columns) on 0 or more rows of the
// chessboard (at most n rows). There is at most one queen per row. Its
// position (column) is given by a number from 0 to n-1, inclusive.
//
// For example, a Board holding 1, 3, with n = 4 means a 4 x 4
// chessboard with queens in its first 2 rows. The queen in the row 0
// (1st row) lies in column 1 (the 2nd square), and the queen in row 1
// (2nd row) lies in column 3 (the 4th & last square). This is pictured
// below:
//
// +---+---+---+---+
// |   | Q |   |   |
// +---+---+---+---+
// |   |   |   | Q |
// +---+---+---+---+
// |   |   |   |   |
// +---+---+---+---+
// |   |   |   |   |
// +---+---+---+---+
//
// We print a queen arrangement by printing the position of the queen in
// each column. For example, "1 3 0 2" represents the following
// arrangement of queens on a 4x4 chessboard:
//
// +---+---+---+---+
// |   | Q |   |   |
// +---+---+---+---+
// |   |   |   | Q |
// +---+---+---+---+
// | Q |   |   |   |
// +---+---+---+---+
// |   |   | Q |   |
// +---+---+---+---+


// printBoard
// Given a full solution to the n-Queens Problem (see above), print it
// to cout as a list of numbers, giving the column numbers (0 .. n-1) of
// queens in successive rows. Numbers are separated by blanks,
// terminated by a newline.
// Pre:
//     n > 0
//     board.size() == n
//     Each entry of board is in [0, n-1].
//     board, n represent a full solution to the n-Queens Problem (see
//      above).
// Post:
//     board has been printed to cout, as above.
void printBoard(const BoardType & board,
                int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (i != 0)
            cout << " ";
        cout << board[i];
    }
    cout << endl;
}


// checkQueen
// Given a partial solution to the n-Queens Problem (see above) in which
//  the already placed queens cannot attack each other, determine
//  whether a proposed new queen placement is acceptable, that is, if it
//  cannot attack any any of the existing queens. Return value is true
//  if there is no possible attack.
// Pre:
//     board represents a placement of non-attacking queens on an n x n
//      chessboard (see above).
//     board.size() < n.
//     board.size() <= newRow < n.
//     0 <= newCol < n.
// Post:
//     Return value is true if, when a new queen is placed in row newRow
//      and column newCol, this new queen cannnot attack any other queen
//      on the chessboard. False otherwise.
bool checkQueen(const BoardType & board,
                int n,
                int newRow,
                int newCol)
{
    for (int oldRow = 0; oldRow < newRow; ++oldRow)
    {
        int oldCol = board[oldRow];

        // vertical attack from existing queen?
        if (newCol == oldCol)
            return false;

        // NW-SE diagonal attack from existing queen?
        if (newRow - newCol == oldRow - oldCol)
            return false;

        // NE-SW diagonal attack from existing queen?
        if (newRow + newCol == oldRow + oldCol)
            return false;

        // NOTE: We do not need to check for horizontal attacks, since
        //  there is at most one queen in each row.
    }
    return true;
}


// nQueen_recurse
// Given a partial solution to the n-Queens Problem (see above), print
// out all non-attacking placements of n queens that include the given
// queens. Return number of placements.
// Recursive.
// Pre:
//     n > 0.
//     board.size() <= n.
//     Each entry of board is in [0 .. n-1].
//     board represents a placement of queens on an n x n chessboard
//      (see above).
// Post:
//     All solutions have been printed (see above).
//     b is equal to the value of b when the function was called.
int nQueen_recurse(BoardType & board,
                   int n)
// NOTE: We can pass b by reference since the function always restores
//  it to the same state it was in when the function was called. Because
//  the correct execution of the function depends on this fact, it is a
//  postcondition.
{
    // BASE CASE
    if (board.size() == size_t(n))
    {
        // A full solution?
        for (int i = 0; i < n; ++i)
        {
            if (!checkQueen(board, n, i, board[i]))
                return 0;  // No
        }

        // Yes! Print it.
        printBoard(board, n);
        return 1;
    }

    // RECURSIVE CASE
    // Try each position in next row
    int total = 0;
    for (int newCol = 0; newCol < n; ++newCol)
    {
        // Add a queen in position newCol in the next row & recurse.
        board.push_back(newCol);            // Add new queen
        total += nQueen_recurse(board, n);  // Recursive call
        board.pop_back();                   // Remove queen
    }
    return total;
}


// nQueen
// Print all solutions to the n-Queens Problem for a chessboard of the
// given size. That is, print a representation of every placement of n
// mututally non-attacking queens on an n x n chessboard. Return number
// of placements.
// Pre:
//     n > 0.
// Post:
//     All solutions printed (see above).
int nQueen(int n)
{
    BoardType board;  // Empty board
    return nQueen_recurse(board, n);
}


// getNum
// Prints prompt to cout and then inputs a number of type int on a line
// from cin. Repeats until valid number obtained; returns it to caller
// in reference argument. Return is false if number could not be
// obtained.
bool getNum(const string & prompt,
            int & num)
{
    while (true)
    {
        cout << prompt;
        string line;
        getline(cin, line);
        if (!cin)
        {
            if (cin.eof())
                return false;
            continue;
        }

        istringstream istr(line);
        istr >> num;
        if (!istr)
            continue;
        return true;
    }
}


// Main program
// Repeatedly inputs a number n and prints all n-Queen solutions.
// Terminates on n == 0.
int main()
{
    // Print header
    cout << "n-Queen Solver" << endl;
    cout << endl;

    while (true)
    {
        // Prompt & input chessboard size, with retry on bad input
        int n;
        while (true)
        {
            bool success = getNum("Chessboard size (0 to quit)? ", n);
            if (!success)
                return 0;
            if (n == 0)  // Done
                return 0;
            if (n > 0)   // Got a good value
                break;

            // Handle negative size
            cout << endl;
            cout << "Size must be nonnegative" << endl;
        }

        // Print solutions to n-Queens Problem
        cout << endl;
        cout << "n-Queen solutions for "
             << n << " x " << n
             << " chessboard (see source for explanation):" << endl;
        cout << "-----------------------" << endl;
        int count = nQueen(n);
        cout << "-----------------------" << endl;
        cout << "Number of solutions found: " << count << endl;
        cout << endl;
    }
}

