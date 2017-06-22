/*
	BoardSquare.cpp
	CS 372 Battleship Project
	By Frank Cline, Cameron Showalter
	2-16-17
*/


#include "BoardSquare.h"
#include <iostream>
using std::cout;
using std::endl;

char BoardSquare::printPlayerSquare()
{
	if (ship_ && selected_)
	{
			return 'X';
	}
	else if (ship_)
	{
		return '#';
	}
	else if (selected_)
	{
	    return 'M';
	}
	else
	{
		return '.';
	}
}

char BoardSquare::printOppSquare()
{
	if (ship_ && selected_)
	{
			return 'X';
	}
	else if (selected_)
	{
		return 'M';
	}
	else
	{
		return '.';
	}
}

void BoardSquare::addShip(Ship *s)
{
	ship_ = s;
}

bool BoardSquare::isSelected()
{
	return selected_;
}

void BoardSquare::Hit()
{
	selected_ = true;
	if (ship_)
	{
		return ship_->shipHit();
	}
}

Ship* BoardSquare::squareShip()
{
	if (ship_)
	{
		return ship_;
	}
	return nullptr;
}
