/*
Alex Medeiros
Die namespace
	Constains basic dice that can be used for attacking and rolling damage

Dice Class
	Used to build more complex dice attacks.
*/ 

#pragma once

namespace Die {
	int roll(int dice, int num);
	int d2(int num = 1);
	int d4(int num = 1);
	int d6(int num = 1);
	int d8(int num = 1);
	int d10(int num = 1);
	int d12(int num = 1);
	int d20(int num = 1);
	int d100(int num = 1);
}

class Dice
{
public:
	Dice(){}
	Dice(int type);
	Dice(int type, int roll);

	//Basic Dice rolling that is defined in class
	int roll();
	//This will roll and drop the lowest 'drops' value rolled
	int rDropLowest(int drops = 1);
	//This will roll and drop the highest 'drops' value rolled
	int rDropHighest(int drops = 1);

    int getDieType();
    int getDieRoll();

	void setType(int t);
	void setRolls(int r);
private:
	int type_ = 0;
	int rolls_ = 1;
};

