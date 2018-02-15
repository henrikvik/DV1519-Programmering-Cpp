#include "Student.h"
#include <sstream>

Student::Student(string name, string mail, int regNr)
	: Person(name, mail)
{
	this->regNr = regNr;
}

Student::~Student()
{
}

int Student::getRegNr() const
{
	return this->regNr;
}

void Student::setRegNr(int regNr)
{
	this->regNr = regNr;
}

string Student::toStringSpecific() const
{
	stringstream sout;
	sout << "RegNr: " << this->regNr;
	return sout.str();
}

Student::Student(const Student &other)
	: Person(other)
{
	this->regNr = other.regNr;
}

Student& Student::operator=(const Student &other)
{
	if (this != &other)
	{
		Person::operator=(other);
		this->regNr = other.regNr;
	}

	return *this;
}