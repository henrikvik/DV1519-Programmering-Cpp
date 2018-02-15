#include "UniversityRegister.h"
#include "Student.h"
#include "Employee.h"

UniversityRegister::UniversityRegister(int capacity)
{
	this->personsCount = 0;
	this->personsCapacity = capacity;
	this->persons = new Person*[capacity];

	for (int i = 0; i < capacity; i++)
	{
		this->persons[i] = nullptr;
	}
}


UniversityRegister::~UniversityRegister()
{
	freeMemory();
}

void UniversityRegister::freeMemory()
{
	for (int i = 0; i < this->personsCount; i++)
	{
		delete this->persons[i];
	}
	delete[] this->persons;

	this->persons = nullptr;
	this->personsCount = 0;
	this->personsCapacity = 0;
}

UniversityRegister::UniversityRegister(const UniversityRegister &other)
{
	copy(other);
}

void UniversityRegister::copy(const UniversityRegister &other)
{
	this->personsCount = other.personsCount;
	this->personsCapacity = other.personsCapacity;

	this->persons = new Person*[other.personsCapacity];

	for (int i = 0; i < other.personsCount; i++)
	{
		Student * studentPtr = dynamic_cast<Student*>(other.persons[i]);
		if (studentPtr != nullptr)
		{
			this->persons[i] = new Student(*studentPtr);
		}
		else
		{
			Employee * employeePtr = dynamic_cast<Employee*>(other.persons[i]);
			if (employeePtr != nullptr)
			{
				this->persons[i] = new Employee(*employeePtr);
			}
		}
	}
}

UniversityRegister& UniversityRegister::operator=(const UniversityRegister &other)
{
	if (this != &other)
	{
		freeMemory();
		copy(other);
	}

	return *this;
}

void UniversityRegister::add(string name, string mail, int regNr)
{
	if (this->personsCount == this->personsCapacity)
	{
		expand();
	}

	this->persons[this->personsCount] = new Student(name, mail, regNr);
	this->personsCount++;
}

void UniversityRegister::add(string name, string mail, string department, int salary)
{
	if (this->personsCount == this->personsCapacity)
	{
		expand();
	}

	this->persons[this->personsCount] = new Employee(name, mail, department, salary);
	this->personsCount++;
}

int UniversityRegister::calcStudentCount() const
{
	int studentCount = 0;
	for (int i = 0; i < this->personsCount; i++)
	{
		if (dynamic_cast<Student*>(this->persons[i]))
		{
			studentCount++;
		}
	}

	return studentCount;
}

int UniversityRegister::calcEmployeeCount() const
{
	int employeeCount = 0;
	for (int i = 0; i < this->personsCount; i++)
	{
		if (dynamic_cast<Employee*>(this->persons[i]))
		{
			employeeCount++;
		}
	}

	return employeeCount;
}

int UniversityRegister::getPersonsCount() const
{
	return this->personsCount;
}

void UniversityRegister::getAsStrings(string strings[], string what) const
{
	int stringsCount = 0;
	for (int i = 0; i < this->personsCount; i++)
	{
		if (
			(what == "all") ||
			(what == "student" && dynamic_cast<Student*>(this->persons[i])) ||
			(what == "employee" && dynamic_cast<Employee*>(this->persons[i]))
		)
		{
			strings[stringsCount] = this->persons[i]->toString();
			stringsCount++;
		}
	}
}

