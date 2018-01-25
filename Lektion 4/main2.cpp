#include <iostream>
using namespace std;

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

#include "Dice.h"
#include "DiceCup.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	
	DiceCup diceCup;
	diceCup.addDice(12);
	diceCup.addDice(20);
	diceCup.addDice(4);
	diceCup.addDice(6);

	for (int i = 0; i < 10; i++)
	{
		diceCup.addDice(6);
	}



	system("pause");
	return 0;
}