#include "FurnitureContainer.h"
#include "Table.h"
#include "Stool.h"

FurnitureContainer::FurnitureContainer(int capacity)
{
	this->furnitureCap = capacity;
	this->furnitureCount = 0;
	this->furnitures = new Furniture*[capacity];
}

FurnitureContainer::~FurnitureContainer()
{
	freeMemory();
}

FurnitureContainer::FurnitureContainer(const FurnitureContainer &other)
{
	makeCopy(other);
}

FurnitureContainer& FurnitureContainer::
						operator=(const FurnitureContainer &other)
{
	if (this != &other)
	{
		freeMemory();
		makeCopy(other);
	}

	return *this;
}

void FurnitureContainer::addTable()
{
	add(new Table());
}

void FurnitureContainer::addStool()
{
	add(new Stool());
}

void FurnitureContainer::getAsStrings(string strings[]) const
{
	int stringsCount = 0;
	for (int i = 0; i < this->furnitureCount; i++)
	{
		strings[stringsCount] = this->furnitures[i]->toString();
		stringsCount++;
	}
}

int FurnitureContainer::getFurnitureCount() const
{
	return this->furnitureCount;
}

void FurnitureContainer::add(Furniture * furniture)
{
	if (this->furnitureCount == this->furnitureCap)
	{
		expand();
	}

	this->furnitures[this->furnitureCount] = furniture;
	this->furnitureCount++;
}

void FurnitureContainer::expand()
{
	this->furnitureCap += 10;
	Furniture ** temp = new Furniture*[this->furnitureCap];

	for (int i = 0; i < this->furnitureCount; i++)
	{
		temp[i] = this->furnitures[i];
	}

	delete[] this->furnitures;
	this->furnitures = temp;
}

void FurnitureContainer::freeMemory()
{
	for (int i = 0; i < this->furnitureCount; i++)
	{
		delete this->furnitures[i];
	}
	delete[] this->furnitures;

	this->furnitureCount = 0;
	this->furnitureCap = 0;
	this->furnitures = nullptr;
}

void FurnitureContainer::makeCopy(const FurnitureContainer &other)
{
	this->furnitureCap = other.furnitureCap;
	this->furnitureCount = other.furnitureCount;

	this->furnitures = new Furniture*[other.furnitureCap];

	for (int i = 0; i < other.furnitureCount; i++)
	{
		this->furnitures[i] = other.furnitures[i]->clone();

		/*
		Table * tablePtr = dynamic_cast<Table*>(other.furnitures[i]);
		if (tablePtr != nullptr)
		{
			this->furnitures[i] = new Table(*tablePtr);
		}

		Stool * stoolPtr = dynamic_cast<Stool*>(other.furnitures[i]);
		if (stoolPtr != nullptr)
		{
			this->furnitures[i] = new Stool(*stoolPtr);
		}
		*/
	}
}