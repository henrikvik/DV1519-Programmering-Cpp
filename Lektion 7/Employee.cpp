#include "Employee.h"
#include <sstream>

Employee::Employee(string name, string mail, int salary)
	: Person(name, mail)
{
	this->salary = salary;
}

Employee::~Employee()
{
}

int Employee::getSalary() const
{
	return this->salary;
}

void Employee::setSalary(int salary)
{
	this->salary = salary;
}

string Employee::toStringSpecific() const
{
	stringstream sout;
	sout << "Salary: " << this->salary;
	return sout.str();
}