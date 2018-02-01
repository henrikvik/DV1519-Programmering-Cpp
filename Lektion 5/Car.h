#pragma once
#include <string>
using namespace std;

class Car
{
public:
	Car(string model = "", int year = 0);

	string toString() const;

private:
	string model;
	int year;
};