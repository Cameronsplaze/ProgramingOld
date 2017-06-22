
/*
	Player.h
	CS 372 Battleship Project
	By Frank Cline, Cameron Showalter
	2-8-17
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"
#include "BoardSquare.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::getline;
#include <vector>
using std::vector;
#include <iomanip>
using std::setw;
#include <string>
using std::string;
#include <utility>
using std::pair;
using std::make_pair;

class Player
{
public:
    vector< vector<BoardSquare> > playerBoard;
    vector< vector<BoardSquare> > oppBoard;

    vector<Ship*> shiplist;

    Player():Player("Player",10,10)
    {}

    ~Player()
    {
        for (auto i=0; i<shiplist.size(); ++i)
        {
            delete shiplist[i];
        }
    }

    Player(string name):Player(name,10,10)
    {}

    Player(string name,int width, int height):heightBoard_(height), widthBoard_(width),
        playerBoard(width, vector<BoardSquare>(height)),
        oppBoard(width, vector<BoardSquare>(height)),
        quit_(false),shiphit_(false),name_(name)
    {}

    Player(int width, int height):heightBoard_(height), widthBoard_(width),
        playerBoard(width, vector<BoardSquare>(height)),
        oppBoard(width, vector<BoardSquare>(height)),
        quit_(false),shiphit_(false),name_("Player")
    {}

    bool hasLost();
    void printBoards();
    void printPlayerBoard();
    void printOppBoard();

    void placeShips();
    //calls canPlaceShip, if true, calls placeShip, returns if it was successful
    bool tryPlaceShipAt(Ship *ship, int x, int y);
    bool canPlaceShip(Ship *ship, int x, int y);
    void placeShip(Ship *ship, int x, int y);
    pair<int,int> stringToBoardCoordinate(string input);

    bool canFire(BoardSquare *square);
    void fire(BoardSquare *square);

    void takeTurn();

    string getUserInput();
    bool isValidInput(const string & input);
    BoardSquare * stringToBoardSquare(const string & input);
    bool hasQuit();
    bool hasHitShip();

    BoardSquare * selectSquare(int x, int y);

    int stringToInt(string text);

    string getName();

private:
    int heightBoard_;
    int widthBoard_;
    bool quit_;
    bool shiphit_;
    string name_;
};

#endif
