#include <iostream>
#include <string>
using namespace std;

#include "Friend.h"
#include "Dice.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	// Skapar vi en pekare och pekar på null
	Friend * friend1 = nullptr;
	Friend * friend2 = nullptr;
	// friend1 -> null 

	// Skapar nytt minne på heapen med new och pekar på det
	friend1 = new Friend("Alice", 1994);
	friend2 = friend1;
	// friend1 -> (234) "Alice" 1994
	// friend2 -> (234) "Alice" 1994

	// för att anropa funktion hos pekare
	// använder man -> istället för .
	// detta säger att använd det som pekas på
	cout << friend1->toString() << endl;
	cout << friend2->toString() << endl;


	// frigör minnet som pekaren pekar på
	delete friend1;
	// delete -> 234
	// friend1 -> (234)
	// friend2 -> (234)
	// OBS man kan inte tabort samma plats två gånger!

	// peka om pekaren till null för att undvika misstag
	friend1 = nullptr;
	friend2 = nullptr;
	// friend1 -> null
	// friend2 -> null


	// skapar en pekare
	Dice * d1;
	// skapar en pekare som pekar på nullptr
	Dice * d2 = nullptr;
	// skapar en pekare som pekar på ett nytt dyanamiskt dice objekt
	Dice * d3 = new Dice(12);
	// skapar en pekare som pekar på ett dynamiskt array med 5 dice objekt
	Dice * d4 = new Dice[5];
	// skapar ett statiskt array med 5 dice pekare
	Dice * d5[5];
	// skapar ett statiskt array med 5 dice pekare som pekar på nullptr
	Dice * d6[5] = { nullptr };

	// fungerar inte! d2 har inget objekt!
	//d2->toss();
	// d3 är ett vanligt dice objekt på heapen
	d3->toss();
	// d4 är ett dyanismt array med dice objekt, välj objektet och anropa normalt
	d4[0].toss();

	system("pause");
	return 0;
}