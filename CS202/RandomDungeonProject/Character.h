#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Class.hpp"
#include "Attributes.h"
#include "Dice.h"
#include "Item.h"
#include "Weapon.h"
#include "Inventory.h"


class Character :public Attributes
{
public:
	Character();
	Character(std::string name_, CharClass cc);
	std::string getName();
	Class getClass();
	Attributes getAttributes();
	int getHP();
	int getAC();
	int getLevel();
	int getProficeniency();
	Inventory getInventory();

	//substracts damage
	void setDamage(int dmg);

	int rollInitiative();
protected:
	Inventory inventory_;

	void setHP(int hp);
	void setAC(int ac);
	void setMovement(int m);
	void setName(std::string & name);
	void setClass(CharClass cc);
	void rollStats();
	void levelUp();


	std::string name_;
	Class class_;
	Attributes attributes_;
	int movement_;
	int initiative_;
	int HP_;
	int AC_;
	int level_;
	int proficeniency_;

};


std::string car(Character & cars);
std::string att(Attributes & att);