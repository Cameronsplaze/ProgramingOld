/*
	Ship.h
	CS 372 Battleship Project
	By Frank Cline, Cameron Showalter
	2-8-17
*/
#ifndef SHIP_H
#define SHIP_H

class Ship
{
private:
	int height_;
	int width_;
	int health_;
	bool destroyed_;
public:
	Ship(int width, int height);

	int getWidth();
	int getHeight();

	int getHealth();

	void shipHit();

	bool isDestroyed();

};

#endif
