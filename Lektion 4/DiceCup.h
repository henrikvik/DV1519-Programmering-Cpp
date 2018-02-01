#pragma once

#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

#include "Dice.h"

class DiceCup
{
public:
	DiceCup();
	~DiceCup();

	void addDice(int sides);
	void removeDice(int index);

private:
	Dice ** dice;
	int diceCapacity;
	int diceCount;

	void expand();
};