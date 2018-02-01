#include "Friend.h"
#include <sstream>

Friend::Friend(string name, int birthYear)
{
	this->name = name;
	this->birthYear = birthYear;
}
Friend::~Friend()
{
}

string Friend::toString() const
{
	stringstream sout;
	sout << this->name << ", " << this->birthYear;
	return sout.str();
}

int Friend::age(int year) const
{
	return year - this->birthYear;
}

bool Friend::operator==(Friend const& other) const
{
	return (this->name == other.name) 
		&& (this->birthYear == other.birthYear);
}