#include "Employee.h"
#include <sstream>

Employee::Employee(string name, string mail, string department, int salary)
	: Person(name, mail)
{
	this->department = department;
	this->salary = salary;
}

string Employee::getDepartment() const
{
	return this->department;
}

void Employee::setDepartment(string department)
{
	this->department = department;
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
	sout << "Department: " << this->department;
	sout << ", Salary: " << this->salary;
	return sout.str();
}