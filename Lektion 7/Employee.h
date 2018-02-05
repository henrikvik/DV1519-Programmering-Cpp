#pragma once
#include "Person.h"

class Employee : public Person
{
public:
	Employee(string name, string mail, int salary);
	virtual ~Employee();

	int getSalary() const;
	void setSalary(int salary);

	string toStringSpecific() const;

private:
	int salary;
};