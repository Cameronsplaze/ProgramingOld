/*
The dice class will create a die that has the properties of number of rolls and what type.
The type, for example, would be set to 6 for a 6 sided die. Then the rolls is how many d6 are chosen.

Die is a namespace that contains quick rolling functions that are analogous to standard dice.

*/

#include "Dice.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <iostream>


Dice::Dice(int type): type_(type), rolls_(1)
{}
Dice::Dice(int type, int roll) : type_(type), rolls_(roll)
{}

int Dice::roll()
{
	int sum = 0;
	for (int i = 1; i < rolls_; i++)
	{
		sum += rand() % type_ + 1;
	}
	return sum;
}
//This will roll and drop the lowest 'drops' value rolled
int Dice::rDropLowest(int drops)
{
	std::vector<int> rolls(rolls_);
	for (std::size_t i = 0; i < rolls.size(); i++)
	{
		rolls[i]=rand() % type_ + 1;
	}
	std::sort(rolls.begin(), rolls.end());
	int sum=0;
	for (std::size_t i = drops; i < rolls.size(); i++)
	{
		sum += rolls[i];
	}
	return sum;
}
//This will roll and drop the highest 'drops' value rolled
int Dice::rDropHighest(int drops)
{
	std::vector<int> rolls(rolls_);
	for (std::size_t i = 0; i < rolls.size(); i++)
	{
		rolls[i] = rand() % type_ + 1;
	}
	std::sort(rolls.begin(), rolls.end());
	int sum=0;
	for (int i = 0; i < rolls_-drops; i++)
	{
		sum += rolls[i];
	}
	return sum;
}
void Dice::setType(int t)
{
	type_ = t;
}
void Dice::setRolls(int r)
{
	rolls_ = r;
}

int Dice::getDieType()
{
    return type_;
}

int Dice::getDieRoll()
{
    return rolls_;
}

//Deneral Rolling function
int Die::roll(int dice, int num)
{
	if (num > 0)
		return (rand() % dice + 1) + roll(dice, num - 1);
	else
		return 0;
}
//Specific Dice Rolling for Typical DnD dice
int Die::d2(int num)
{
	if (num > 0)
		return (rand() % 2 + 1) + d2(num - 1);
	else
		return 0;
}
int Die::d4(int num)
{
	if (num > 0)
		return (rand() % 4 + 1) + d4(num - 1);
	else
		return 0;
}
int Die::d6(int num)
{
	if (num > 0)
		return (rand() % 6 + 1) + d6(num - 1);
	else
		return 0;
}
int Die::d8(int num)
{
	if (num > 0)
		return (rand() % 8 + 1) + d8(num - 1);
	else
		return 0;
}
int Die::d10(int num)
{
	if (num > 0)
		return (rand() % 10 + 1) + d10(num - 1);
	else
		return 0;
}
int Die::d12(int num)
{
	if (num > 0)
		return (rand() % 12 + 1) + d12(num - 1);
	else
		return 0;
}
int Die::d20(int num)
{
	if (num > 0)
		return (rand() % 20 + 1) + d20(num - 1);
	else
		return 0;
}
int Die::d100(int num)
{
	if (num > 0)
		return (rand() % 100 + 1) + d100(num - 1);
	else
		return 0;
}
