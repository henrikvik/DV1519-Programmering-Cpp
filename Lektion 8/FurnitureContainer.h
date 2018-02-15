#pragma once
#include "Furniture.h"

class FurnitureContainer 
{
public:
	FurnitureContainer(int capacity = 10);
	virtual ~FurnitureContainer();

	FurnitureContainer(const FurnitureContainer &other);
	FurnitureContainer& operator=(const FurnitureContainer &other);

	void addTable();
	void addStool();

	void getAsStrings(string strings[]) const;

	int getFurnitureCount() const;

private:
	Furniture ** furnitures;
	int furnitureCount;
	int furnitureCap;

	void add(Furniture * furniture);
	void expand();
	void freeMemory();
	void makeCopy(const FurnitureContainer & other);
};