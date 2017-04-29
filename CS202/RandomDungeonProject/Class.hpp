#pragma once

#include <string>


enum CharClass { none, fighter, rogue, wizard, brute, artilary, caster };


class Class
{
public:
	Class();
	Class(CharClass cc);
	std::string getClass();
	int getHitDie();
protected:
	std::string name_;
	CharClass class_;
	int hitDie_;
};