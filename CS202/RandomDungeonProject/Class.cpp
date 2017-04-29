
#include <string>

#include "Class.hpp"

Class::Class()
{
	name_ = "No Class";
	hitDie_ = 1;

}
Class::Class(CharClass cc)
{
	if (cc == none)
	{
		name_ = "None";
		hitDie_ = 1;
	}
	if (cc == fighter)
	{
		name_ = "Fighter";
		hitDie_ = 10;
	}
	if (cc == rogue)
	{
		name_ = "Rogue";
		hitDie_ = 8;
	}
	if (cc == wizard)
	{
		name_ = "Wizard";
		hitDie_ = 6;
	}
	if (cc == brute)
	{
		name_ = "Brute";
		hitDie_ = 8;
	}
	if (cc == artilary)
	{
		name_ = "Artilary";
		hitDie_ = 6;
	}
	if (cc == brute)
	{
		name_ = "Caster";
		hitDie_ = 4;
	}
}
std::string Class::getClass()
{
	return name_;
}

int Class::getHitDie()
{
	return hitDie_;
}