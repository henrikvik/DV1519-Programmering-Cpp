#ifndef UNIVERSITYREGISTER_H
#define UNIVERSITYREGISTER_H

#include "Person.h"

class UniversityRegister
{
public:
	UniversityRegister(int capacity = 10);
	virtual ~UniversityRegister();

	UniversityRegister(const UniversityRegister &other);
	UniversityRegister& operator=(const UniversityRegister &other);

	void add(string name, string mail, int regNr);
	void add(string name, string mail, string department, int salary);

	int calcStudentCount() const;
	int calcEmployeeCount() const;
	int getPersonsCount() const;

	// what är en flagga som kan vara "employee", "student" eller "all"
	void getAsStrings(string strings[], string what) const;  

private:
	Person ** persons;
	int personsCount;
	int personsCapacity;

	void expand();
	void copy(const UniversityRegister &other);
	void freeMemory();
};

#endif //UNIVERSITYREGISTER_H