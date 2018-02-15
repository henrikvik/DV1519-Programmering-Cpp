#pragma once
#include <string>
using namespace std;

class Furniture
{
public:
	Furniture();
	virtual ~Furniture();

	virtual string toString() const = 0;
	virtual Furniture* clone() const = 0;
private:
};