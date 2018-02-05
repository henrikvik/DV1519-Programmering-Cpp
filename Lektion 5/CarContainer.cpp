#include "CarContainer.h"

CarContainer::CarContainer()
{
	this->carCount = 0;
	this->carCapacity = 10;
	this->cars = new Car*[this->carCapacity];

	for (int i = 0; i < this->carCapacity; i++)
	{
		this->cars[i] = nullptr;
	}
}

CarContainer::~CarContainer()
{
	freeMemory();
}

CarContainer::CarContainer(CarContainer const& other)
{
	/*this->carCount = other.carCount;
	this->carCapacity = other.carCapacity;

	this->cars = new Car*[other.carCapacity];

	for (int i = 0; i < other.carCount; i++)
	{
		this->cars[i] = new Car(*other.cars[i]);
	}*/
	makeCopy(other);
}

void CarContainer::addCar(string model, int year)
{
	this->cars[this->carCount] = new Car(model, year);
	this->carCount++;
}

void CarContainer::carsAsString(string strings[], int stringsSize) const
{
	for (int i = 0; i < this->carCount && i < stringsSize; i++)
	{
		strings[i] = this->cars[i]->toString();
	}
}

int CarContainer::getCarCount() const
{
	return this->carCount;
}

void CarContainer::freeMemory()
{
	for (int i = 0; i < this->carCount; i++)
	{
		delete this->cars[i];
	}
	delete[] this->cars;

	this->cars = nullptr;
	this->carCount = 0;
	this->carCapacity = 0;
}

void CarContainer::makeCopy(CarContainer const& other)
{
	this->carCapacity = other.carCapacity;
	this->carCount = other.carCount;

	this->cars = new Car*[other.carCapacity];

	for (int i = 0; i < other.carCount; i++)
	{
		this->cars[i] = new Car(*other.cars[i]);
	}
}

// cc1 == cc2 == cc3 == cc4;
CarContainer& CarContainer::operator=(CarContainer const& other)
{
	if (this != &other)
	{
		freeMemory();
		makeCopy(other);
	}

	return *this;
}