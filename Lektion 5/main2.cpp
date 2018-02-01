#include <iostream>
#include <string>
using namespace std;

#include <crtdbg.h>

#include "CarContainer.h"


void printCars(CarContainer const& carContainer);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// skapa ett nytt dynaiskt objekt av typen CarContainer
	CarContainer * cc1 = new CarContainer();
	// l�gg till tv� element i det interna arrayet
	cc1->addCar("Volvo", 1994);
	cc1->addCar("Audi", 2006);

	// skriv ut alla element
	printCars(*cc1);
	
	//skapa ett nytt objekt av typ CarContainer med hj�lp av copy-konstruktorn
	CarContainer cc2(*cc1);

	printCars(cc2);

	// skapar ett nytt CarContainer objekt
	CarContainer cc3;
	// skriv �ver all gammal data i cc3 med tilldelningsoperatorn
	cc3 = cc2;

	printCars(cc3);

	// anropa tilldelnings operatorn p� sig sj�lv
	// f�r att kolla ifall det hanteras korrekt
	cc3 = cc3;
	printCars(cc3);

	delete cc1;
	system("pause");
	return 0;
}

void printCars(CarContainer const& carContainer)
{
	int carCount = carContainer.getCarCount();
	string * carStrings = new string[carCount];

	carContainer.carsAsString(carStrings, carCount);

	for (int i = 0; i < carCount; i++)
	{
		cout << carStrings[i] << endl;
	}

	delete[] carStrings;
}