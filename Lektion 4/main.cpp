#include <iostream>
#include <string>
using namespace std;

#include "Friend.h"
#include "Dice.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	// Skapar vi en pekare och pekar p� null
	Friend * friend1 = nullptr;
	Friend * friend2 = nullptr;
	// friend1 -> null 

	// Skapar nytt minne p� heapen med new och pekar p� det
	friend1 = new Friend("Alice", 1994);
	friend2 = friend1;
	// friend1 -> (234) "Alice" 1994
	// friend2 -> (234) "Alice" 1994

	// f�r att anropa funktion hos pekare
	// anv�nder man -> ist�llet f�r .
	// detta s�ger att anv�nd det som pekas p�
	cout << friend1->toString() << endl;
	cout << friend2->toString() << endl;


	// frig�r minnet som pekaren pekar p�
	delete friend1;
	// delete -> 234
	// friend1 -> (234)
	// friend2 -> (234)
	// OBS man kan inte tabort samma plats tv� g�nger!

	// peka om pekaren till null f�r att undvika misstag
	friend1 = nullptr;
	friend2 = nullptr;
	// friend1 -> null
	// friend2 -> null


	// skapar en pekare
	Dice * d1;
	// skapar en pekare som pekar p� nullptr
	Dice * d2 = nullptr;
	// skapar en pekare som pekar p� ett nytt dyanamiskt dice objekt
	Dice * d3 = new Dice(12);
	// skapar en pekare som pekar p� ett dynamiskt array med 5 dice objekt
	Dice * d4 = new Dice[5];
	// skapar ett statiskt array med 5 dice pekare
	Dice * d5[5];
	// skapar ett statiskt array med 5 dice pekare som pekar p� nullptr
	Dice * d6[5] = { nullptr };

	// fungerar inte! d2 har inget objekt!
	//d2->toss();
	// d3 �r ett vanligt dice objekt p� heapen
	d3->toss();
	// d4 �r ett dyanismt array med dice objekt, v�lj objektet och anropa normalt
	d4[0].toss();

	system("pause");
	return 0;
}