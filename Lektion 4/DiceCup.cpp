#include "DiceCup.h"

DiceCup::DiceCup()
{
	this->diceCapacity = 10;
	this->diceCount = 0;
	this->dice = new Dice*[this->diceCapacity];

	for (int i = 0; i < this->diceCapacity; i++)
	{
		this->dice[i] = nullptr;
	}
}

DiceCup::~DiceCup()
{
	// itterera �ver varje element och ta bort deras v�rde ifr�n heapen
	for (int i = 0; i < this->diceCount; i++)
	{
		delete this->dice[i];
		this->dice[i] = nullptr;
	}
	// ta sedan bort arrayed f�r det �r ocks� dynamiskt allokerat
	delete[] this->dice;
	this->dice = nullptr;
}

void DiceCup::removeDice(int index)
{
	// ta bort det gammla elementet
	delete this->dice[index];
	// kopeiera pekaren ifr�n det sista elementet
	this->dice[index] = this->dice[this->diceCount - 1];
	// peka det sista elementet till null, f�r att undvika att ha samma
	// p� olika platser som kan leda till krash
	this->dice[this->diceCount - 1] = nullptr;
	// s�nk diceCount med 1 f�r det finns ett element mindre
	this->diceCount--;
}

void DiceCup::addDice(int sides)
{
	// kollar ifall vi beh�ver expandera det dynamiska arrayet
	if (this->diceCount == this->diceCapacity)
	{
		expand();
	}

	//skapa ett nytt objek p� heapen och ge det till pekaren p� sista platsen i arrayed
	this->dice[this->diceCount] = new Dice(sides);
	// �ka diceCount med 1
	this->diceCount++;
}

void DiceCup::expand()
{
	this->diceCapacity += 10;
	Dice ** tempPtr = new Dice*[this->diceCapacity];

	for (int i = 0; i < this->diceCount; i++)
	{
		tempPtr[i] = this->dice[i];
	}

	delete[] this->dice;
	this->dice = tempPtr;
}