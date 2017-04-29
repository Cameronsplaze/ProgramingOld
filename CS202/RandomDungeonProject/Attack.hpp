/*
Alex Medeiros 
Attack
	This class holds the attacking information
	-attack roll
	-attack bonus
	-damage roll
	-damage bonus
*/

#pragma once

#include "Dice.h"

class Attack
{
public:
	Attack()
	{
		attackDice_ = new Dice(6);
	}
	Attack(int BAB, int damage, Dice* ad)
	{
		baseAttackBonus_ = BAB;
		baseDamage_ = damage;
		attackDice_ = ad;
	}

	int attackRoll() { return Die::d20() + baseAttackBonus_; }
	int damageRoll() { return attackDice_->roll() + baseDamage_; }

	void setBAB(int bab) { baseAttackBonus_ = bab; }
	void setDamage(int db) { baseDamage_ = db; }
	void setAttackDice(Dice* d) { attackDice_ = d; }

	int getBAB() { return baseAttackBonus_; }
	int getDamage() { return baseDamage_; }
	Dice* attackDice() { return attackDice_; }
private:
	int baseAttackBonus_;
	int baseDamage_;
	Dice* attackDice_;
};