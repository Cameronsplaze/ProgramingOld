/*
Alex Medeiros
Enemy
	Direved from player. 
	Enemy is an AI type of player. 
	update function will move the ai inside of the combat system
*/

#pragma once


#include "Player.hpp"


class Enemy :
	public Player
{
public:
	Enemy();
	~Enemy();
	virtual void handleInput(Event& e, const float dt);
	virtual void update(Event& e, const float dt);

private:
	
};

