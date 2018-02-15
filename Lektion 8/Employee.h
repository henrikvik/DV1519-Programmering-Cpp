#pragma once
#include "Person.h"

class Employee : public Person
{
public:
	Employee(string name, string mail, string department, int salary);
	virtual ~Employee();

	int getSalary() const;
	void setSalary(int salary);
	
	string getDepartment() const;
	void setDepartment(string department);

	string toStringSpecific() const;

private:
	string department;
	int salary;
};