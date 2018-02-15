#pragma once
#include "Furniture.h"

class Table : public Furniture
{
public:
	Table();
	virtual ~Table();

	string toString() const override;
	Table* clone() const override;
private:
};
