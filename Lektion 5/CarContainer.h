#pragma once
#include "Car.h"

class CarContainer
{
public:
	CarContainer();
	CarContainer(CarContainer const& other);
	~CarContainer();

	void addCar(string model, int year);
	void carsAsString(string strings[], int stringsSize) const;

	int getCarCount() const;

	CarContainer& operator=(CarContainer const& other);

private:
	Car ** cars;
	int carCapacity;
	int carCount;

	void freeMemory();
	void makeCopy(CarContainer const& other);
};