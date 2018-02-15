#pragma once
#include "Furniture.h"

class Stool : public Furniture
{
public:
	Stool();
	virtual ~Stool();

	string toString() const override;
	Stool * clone() const override;
private:
};