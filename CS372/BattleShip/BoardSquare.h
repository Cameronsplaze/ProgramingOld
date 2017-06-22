/*
	BoardSquare.h
	CS 372 Battleship Project
	By Frank Cline, Cameron Showalter
	2-8-17
*/

//#includeC:\Users\Cameron\Desktop\BattleShip372\catch.hpp "Ship.h"

#include "Ship.h"

#ifndef BOARD_SQUARE_H
#define BOARD_SQUARE_H

class BoardSquare
{
public:
	BoardSquare():selected_(false),ship_(nullptr)
	{}

	char printPlayerSquare();

	char printOppSquare();

	void addShip(Ship *s);

	bool isSelected();

	void Hit();

	Ship* squareShip();

private:
	Ship *ship_;
	bool selected_;
};

#endif
