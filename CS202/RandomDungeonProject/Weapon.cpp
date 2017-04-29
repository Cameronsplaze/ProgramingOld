#include "Weapon.h"

Weapon::Weapon():Item()
{
	heavy_ = false;
	martial_ = false;
	range_ = -1;
	Dice damage;
	damage_ = damage;
	type_ = Item::ItemType::WEAPON;
}

Weapon::Weapon(bool heavy, bool martial, int range, Dice damage):Item()
{
	heavy_ = heavy;
	martial_ = martial;
	range_ = range;
	damage_ = damage;
	type_ = Item::ItemType::WEAPON;
}

Weapon::Weapon(int cost, int id, int weight, std::string name, std::string description, bool heavy, bool martial, int range, Dice damage):Item(cost, id, weight, name, description, Item::ItemType::WEAPON)
{
	heavy_ = heavy;
	martial_ = martial;
	range_ = range;
	damage_ = damage;
}

// Mutator functions
void Weapon::setHeavy(bool heavy)
{
	heavy_ = heavy;
}

void Weapon::setMartial(bool martial)
{
	martial_ = martial;
}

void Weapon::setRange(int range)
{
	range_ = range;
}

void Weapon::setDamage(Dice damage)
{
	damage_ = damage;
}

// Accessor functions
bool Weapon::isHeavy()
{
	return heavy_;
}

bool Weapon::isMartial()
{
	return martial_;
}

int Weapon::range()
{
	return range_;
}

Dice Weapon::damage()
{
	return damage_;
}