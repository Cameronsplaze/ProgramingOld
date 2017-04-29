/*
Alex Medeiros
Player Class
	This class acts as a wrapper for entity that is specific to the player. 

*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "Character.h"
#include "Event.hpp"
#include "Attack.hpp"

class Player : public Entity, public Character
{
public:
	Player();

	virtual void use() {} //Vitrual function of entity

	//Used to take the input the player wants to do
	//Vitrual so that enemy can overide the userinput type of input
	virtual void handleInput(Event& e, const float dt);

	//Update checks if the input is valid
	void update(Event& e, const float dt);
	//Will return false when the turn is over.
	bool turn();
	void setTurn(bool t);

	Attack baseAttack;
	
	sf::Vector2i getLocation() const;

	bool isDead();

	sf::View playerView;
protected:
	const float TILESIZE_f;
	const int TILESIZE_i;

	float lastPress_;
	const float PRESSTIME;

	//Loction is pixel position diveded by tilesize
	sf::Vector2i location_;

	bool turn_ = true;
	bool dead_ = false;
	void updateLocation();
};