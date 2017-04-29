#pragma once
#include "Item.h"
#include "Dice.h"

class Weapon : public Item
{
public:
	Weapon();
	Weapon(bool heavy, bool martial, int range, Dice damage);
	Weapon(int cost, int id, int weight, std::string name, std::string description, bool heavy, bool martial, int range, Dice damage);
	// Mutator functions
	void setHeavy(bool heavy);
	void setMartial(bool martial);
	void setRange(int range);
	void setDamage(Dice damage);
	// Accessor functions
	bool isHeavy();
	bool isMartial();
	int range();
	Dice damage();
private:
	// bool to tell if heavy or light weapon
	bool heavy_;
	// bool to tell if martial or simple weapon
	bool martial_;
	// int for range (blocks are 32x32)
	int range_;
	// die for damage
	Dice damage_;
};
