#pragma once
#include <string>
using namespace std;

class Person
{
public:
	Person(string name, string mail);
	virtual ~Person();

	Person(const Person &other);
	Person& operator=(const Person &other);

	string getName() const;
	string getMail() const;

	void setName(string name);
	void setMail(string mail);

	string toString() const;
	virtual string toStringSpecific() const = 0;



private:
	string name;
	string mail;
};