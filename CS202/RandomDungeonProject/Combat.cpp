#include "Character.h"
#include "Dice.h"
#include "Combat.h"


//starts the combat with the players provided
void Combat::startCombat(std::vector<Player>& players)
{

}

void Combat::meleeAttack(Character & attacker, Character & defender)
{
	int mods = ((attacker.getAttributes().getAttribute("STR") - 10) / 2) + attacker.getProficeniency();
	Dice hit(20,1);
	if (hit.roll() + mods > defender.getAC())
	{
		if (attacker.getInventory().size() != 0)
		{
			//defender.setHP(defender.getHP() - (attacker.getInventory().getWeapon(0).getDamage().roll() + attacker.getAttributes().getAttribute("STR") - 10) / 2);
		}
		else
		{
			Dice fist(2, 1);
			//defender.setHP(defender.getHP() - (fist.roll() + attacker.getAttributes().getAttribute("STR") - 10) / 2);
		}
		//HIT
	}
	else
	{
		//Miss
	}
}

//
//void Combat::rangedAttack(Character & attacker, Character & defender)
//{
//	int mods = ((attacker.getAttributes().getAttribute("DEX") - 10) / 2) + attacker.getProficeniency();
//	Dice hit(20, 1);
//	if (hit.roll() + mods > defender.getAC())
//	{
//		if (attacker.getInventory().size() != 0)
//		{
//			defender.setHP(defender.getHP() - (attacker.getInventory().getWeapon(0).getDamage().roll() + attacker.getAttributes().getAttribute("STR") - 10) / 2);
//		}
//		else
//		{
//			Dice fist(2, 1);
//			defender.setHP(defender.getHP() - (fist.roll() + attacker.getAttributes().getAttribute("STR") - 10) / 2);
//		}
//		//HIT
//	}
//	else
//	{
//		//Miss
//	}
//}