#include <iostream>
using namespace std;

#include "Student.h"


int main()
{
	Person person1("Alice", "alice@notarealmail.com");
	Student student1("Henrik", "henkvik@gmail.com", 7824);

	cout << person1.getName() << ", " << person1.getMail() << endl;
	cout << student1.getName() << ", " << student1.getMail() << endl;

	//Funkar inte! Person är inte en Student!
	//cout << person1.getRegNr() << endl;
	cout << student1.getRegNr() << endl;

	Person * personPtr1 = new Student("Bob", "bob@notarealmail.com", 8301);
	Person * personPtr2 = new Person("Donnald", "donnald@notarealmail.com");
	cout << personPtr1->getName() << ", " << personPtr1->getMail() << endl;

	// En Person är ej en Student så vi kan inte använda en Student pekare till ett Person objekt.
	//Student * studentPtr1 = new Person("Charles", "charles@notarealmail.com");
	Student * studentPtr1 = new Student("Charles", "charles@notarealmail.com", 7165);


	Student * studentPtr2 = nullptr;
	studentPtr2 = dynamic_cast<Student*>(personPtr2);
	if (studentPtr2 != nullptr)
	{
		cout << studentPtr2->getName() << ", " << studentPtr2->getRegNr() << endl;
	}
	else
	{
		cout << "Is not convertible to Student pointer." << endl;
	}



	system("pause");
	return 0;
}