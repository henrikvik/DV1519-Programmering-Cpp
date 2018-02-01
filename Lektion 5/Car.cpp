#include "Car.h"
#include <sstream>

Car::Car(string model, int year)
{
	this->model = model;
	this->year = year;
}

string Car::toString() const
{
	stringstream sout;
	sout << this->model << ", " << this->year;
	return sout.str();
}