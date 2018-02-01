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
	// itterera över varje element och ta bort deras värde ifrån heapen
	for (int i = 0; i < this->diceCount; i++)
	{
		delete this->dice[i];
		this->dice[i] = nullptr;
	}
	// ta sedan bort arrayed för det är också dynamiskt allokerat
	delete[] this->dice;
	this->dice = nullptr;
}

void DiceCup::removeDice(int index)
{
	// ta bort det gammla elementet
	delete this->dice[index];
	// kopeiera pekaren ifrån det sista elementet
	this->dice[index] = this->dice[this->diceCount - 1];
	// peka det sista elementet till null, för att undvika att ha samma
	// på olika platser som kan leda till krash
	this->dice[this->diceCount - 1] = nullptr;
	// sänk diceCount med 1 för det finns ett element mindre
	this->diceCount--;
}

void DiceCup::addDice(int sides)
{
	// kollar ifall vi behöver expandera det dynamiska arrayet
	if (this->diceCount == this->diceCapacity)
	{
		expand();
	}

	//skapa ett nytt objek på heapen och ge det till pekaren på sista platsen i arrayed
	this->dice[this->diceCount] = new Dice(sides);
	// öka diceCount med 1
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