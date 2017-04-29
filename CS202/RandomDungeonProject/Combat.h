#pragma once

#include <vector>

#include "Player.hpp"
#include "Character.h"

class Combat
{
public:
	//starts the combat with the players provided
	void startCombat(std::vector<Player>& players);

	void meleeAttack(Character & pc, Character & mob);
	//int rangedAttack(Character & pc, Character & mob);

private:
	std::vector<Character> initiative_;

};
