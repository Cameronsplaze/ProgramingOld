/*
	Ship.cpp
	CS 372 Battleship Project
	By Frank Cline, Cameron Showalter
	2-8-17
*/

#include "Ship.h"
#include <iostream>
using std::cout;
using std::endl;

Ship::Ship(int width, int height):height_(height),width_(width),health_(height*width),destroyed_(false)
{}

int Ship::getHealth()
{
	return health_;
}

void Ship::shipHit()
{
	--health_;
	if(health_==0)
    {
        destroyed_=true;
    }
}
bool Ship::isDestroyed()
{
    return destroyed_;
}

int Ship::getWidth()
{
	return width_;
}

int Ship::getHeight()
{
	return height_;
}
