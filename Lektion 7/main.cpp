#include <iostream>
#include <string>
using namespace std;

#include "Person.h"
#include "Student.h"
#include "Employee.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Student	* s = new Student("Alice", "alice@mail.com", 8237);
	Person * p = new Student("Bob", "bob@mail.com", 6234);
	
	//Fungerar inte! en Person innehåller förlite information
	// för att vara en Student.
	//Student * p2 = new Person("Charles", "charles@mail.com");

	cout << s->getName() << ", " << s->getMail() << ", " << s->getRegNr() << endl;
	cout << p->getName() << ", " << p->getMail() << endl;

	cout << s->toString() << endl;
	cout << p->toString() << endl;

	Person * p2 = new Employee("Charles", "charles@mail.com", 36000);

	cout << p2->toString() << endl;

	delete s;
	delete p;
	delete p2;

	cout << "---====+++++====---" << endl;

	const int SIZE = 4;
	Person * people[SIZE];

	people[0] = new Student("Alice", "a@m.com", 9274);
	people[1] = new Employee("Bob", "b@m.com", 28340);
	people[2] = new Student("Charles", "c@m.com", 2901);
	people[3] = new Employee("Donnald", "d@m.com", 43010);


	for (int i = 0; i < SIZE; i++)
	{
		cout << people[i]->toString() << endl;
	}

	for (int i = 0; i < SIZE; i++)
	{
		Student * tempPtr = nullptr;
		tempPtr = dynamic_cast<Student*>(people[i]);
		if (tempPtr != nullptr)
		{
			cout << tempPtr->getName();
			cout << " is a student! RegNr: ";
			cout << tempPtr->getRegNr();
			cout << endl;
		}

		Employee * tempPtr2 = dynamic_cast<Employee*>(people[i]);
		if (tempPtr2 != nullptr)
		{
			cout << tempPtr2->getName();
			cout << " is an Employee! Salary: ";
			cout << tempPtr2->getSalary();
			cout << endl;
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		delete people[i];
	}

	system("pause");
	return 0;
}