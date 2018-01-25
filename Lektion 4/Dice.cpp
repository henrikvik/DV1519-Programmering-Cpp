#include "Dice.h"
#include <cstdlib>

using namespace std;

Dice::Dice(int nrOfFaces)
{
	this->nrOfFaces = nrOfFaces;
	this->value = rand()%this->nrOfFaces+1;
}

Dice::~Dice()
{
}

void Dice::toss()
{
	this->value = rand()%this->nrOfFaces +1;
}

int Dice::getValue() const
{
	return this->value;
}

int Dice::getNrOfFaces() const
{
	return this->nrOfFaces;
}