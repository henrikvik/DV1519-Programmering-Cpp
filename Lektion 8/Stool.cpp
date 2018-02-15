#include "Stool.h"

Stool::Stool()
{
}

Stool::~Stool()
{
}

string Stool::toString() const
{
	return "This is stool.";
}
Stool * Stool::clone() const
{
	return new Stool(*this);
}