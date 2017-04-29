#pragma once

#include "Entity.hpp"
#include <iostream>



class Door : public Entity
{
public:
	Door()
	{
		canUse_ = true;
	}

	virtual void use()
	{
		if (solid_)
		{
			solid_ = false;
			this->sprite_.setColor(sf::Color(127, 127, 127, 150));
		}
		else
		{
			solid_ = true;
			this->sprite_.setColor(sf::Color(255, 255, 255, 255));
		}
	}

private:

};

class Wall : public Entity
{
public:
	Wall()
	{
		solid_ = true;
	}
	virtual void use()
	{
		//std::cout << "cannot use a wall" << std::endl;
	}

private:

};

class Floor : public Entity
{
public:
	Floor()
	{
		solid_ = false;
	}
	virtual void use()
	{
	}

private:

};