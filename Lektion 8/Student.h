#pragma once
#include "Person.h"

class Student : public Person
{
public:
	Student(string name, string mail, int regNr);
	virtual ~Student();

	Student(const Student &other);
	Student& operator=(const Student &other);

	int  getRegNr() const;
	void setRegNr(int regNr);

	string toStringSpecific() const;

private:
	int regNr;
};
