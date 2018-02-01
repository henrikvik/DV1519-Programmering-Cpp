#include "Person.h"

Person::Person(string name, string mail)
{
	this->name = name;
	this->mail = mail;
}

Person::~Person()
{
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