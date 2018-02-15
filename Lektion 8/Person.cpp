#include "Person.h"
#include <sstream>

Person::Person(string name, string mail)
{
	this->name = name;
	this->mail = mail;
}

Person::~Person()
{
}

Person::Person(const Person &other)
{
	this->name = other.name;
	this->mail = other.mail;
}

Person& Person::operator=(const Person & other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->mail = other.mail;
	}

	return *this;
}


string Person::getName() const
{
	return this->name;
}

string Person::getMail() const
{
	return this->mail;
}

void Person::setName(string name)
{
	this->name = name;
}

void Person::setMail(string mail)
{
	this->mail = mail;
}

string Person::toString() const
{
	stringstream sout;
	sout << this->name << ", ";
	sout << this->mail << ", ";
	sout << toStringSpecific();
	return sout.str();
}

