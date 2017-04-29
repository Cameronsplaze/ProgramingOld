#pragma once

#include <string>
#include <iostream>
#include <sstream>

#include "Weapon.h"
#include "Character.h"

Character::Character()
{
	name_ = "noone";
	class_ = Class(none);
	attributes_.setAttribute("STR", 0);
	attributes_.setAttribute("DEX", 0);
	attributes_.setAttribute("CON", 0);
	attributes_.setAttribute("INT", 0);
	attributes_.setAttribute("WIS", 0);
	movement_ = 5;
	initiative_ = 0;
	HP_ = 0;
	AC_ = 10;
	level_ = 1;
	proficeniency_ = (level_ / 4) + 2;
}

Character::Character(std::string name, CharClass cc)
{
	Dice stats(6, 4);
	name_ = name;
	class_ = Class(cc);
	attributes_.setAttribute("STR", stats.rDropLowest());
	attributes_.setAttribute("DEX", stats.rDropLowest());
	attributes_.setAttribute("CON", stats.rDropLowest());
	attributes_.setAttribute("INT", stats.rDropLowest());
	attributes_.setAttribute("WIS", stats.rDropLowest());
	HP_ = (class_.getHitDie() + (attributes_.getAttribute("CON") - 10) / 2) + 20;
	AC_ = 10 + (attributes_.getAttribute("DEX") - 10) / 2;
	movement_ = 5;
	initiative_ = (attributes_.getAttribute("DEX") - 10) / 2;
	level_ = 1;
	proficeniency_ = (level_ / 4) + 2;
}


std::string car(Character & car)
{
	std::string os;
	std::stringstream ss;
	ss << "Name: " << car.getName() << std::endl;
	ss << "Class: " << car.getClass().getClass() << std::endl;
	ss << "Level: " << car.getLevel() << std::endl;
	ss << "HP: " << car.getHP() << std::endl;
	ss << "AC: " << car.getAC() << std::endl;
	os = ss.str();
	return os;
}
std::string att(Attributes & att)
{
	std::string os;
	std::stringstream ss;
	ss << "Str: " << att.getAttribute("STR") << std::endl;
	ss << "Dex: " << att.getAttribute("DEX") << std::endl;
	ss << "Con: " << att.getAttribute("CON") << std::endl;
	ss << "Int: " << att.getAttribute("INT") << std::endl;
	ss << "Wis: " << att.getAttribute("WIS") << std::endl;
	os = ss.str();
	return os;
}

int Character::rollInitiative()
{
	Dice init(20, 1);
	return init.roll() + initiative_;
}

std::string Character::getName()
{
	return name_;
}
Class Character::getClass()
{
	return class_;
}
int Character::getHP()
{
	return HP_;
}
int Character::getAC()
{
	return AC_;
}

int Character::getLevel()
{
	return level_;
}



Attributes Character::getAttributes()
{
	return attributes_;
}

int Character::getProficeniency()
{
	return proficeniency_;
}

Inventory Character::getInventory()
{
	return inventory_;
}


void Character::rollStats()
{
	Dice stats(6, 4);
	Dice hd(class_.getHitDie(), level_-1);
	attributes_.setAttribute("STR", stats.rDropLowest());
	attributes_.setAttribute("DEX", stats.rDropLowest());
	attributes_.setAttribute("CON", stats.rDropLowest());
	attributes_.setAttribute("INT", stats.rDropLowest());
	attributes_.setAttribute("WIS", stats.rDropLowest());
	HP_ = (class_.getHitDie() + hd.roll() + (((attributes_.getAttribute("CON") - 10) / 2) * level_));
	AC_ = 10 + (attributes_.getAttribute("DEX") - 10) / 2;
}


void Character::setMovement(int m)
{
	movement_ = m;
}

void Character::setDamage(int dmg)
{
	HP_ -= dmg;
}

void Character::setHP(int hp)
{
	HP_ = hp;
}
void Character::setAC(int ac)
{
	AC_ = ac;
}


void Character::setName(std::string & name)
{
	name_ = name;
}
void Character::setClass(CharClass cc)
{
	if (cc == fighter)
	{
		class_ = Class(fighter);
		Dice hd(class_.getHitDie(), level_ - 1);
		HP_ = (class_.getHitDie() + hd.roll() + (((attributes_.getAttribute("CON") - 10) / 2) * level_));
		//inventory_.add(Weapon(0, 100, 5, "Long Sword", "A very long Sword", 1, 8));
		movement_ = 5;
	}
	if (cc == rogue)
	{
		class_ = Class(rogue);
		Dice hd(class_.getHitDie(), level_ - 1);
		HP_ = (class_.getHitDie() + hd.roll() + (((attributes_.getAttribute("CON") - 10) / 2) * level_));
		//inventory_.add(Weapon(0, 101, 1, "Dagger ", "A short pointy peice of metal", 1, 4));
		movement_ = 6;
	}
	if (cc == wizard)
	{
		class_ = Class(wizard);
		Dice hd(class_.getHitDie(), level_ - 1);
		HP_ = (class_.getHitDie() + hd.roll() + (((attributes_.getAttribute("CON") - 10) / 2) * level_));
		//inventory_.add(Weapon(0, 102, 5, "Quarterstaff", "A long bashey stick", 1, 6));
		movement_ = 4;
	}

}

void Character::levelUp()
{	
	level_ ++;
	Dice hd(class_.getHitDie(), level_);
	HP_ += (hd.roll() + (((attributes_.getAttribute("CON") - 10) / 2) * level_));
	proficeniency_ = (int) (level_ / 4) + 2;
}

