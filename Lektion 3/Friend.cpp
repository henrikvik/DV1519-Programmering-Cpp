#include "Friend.h"
#include <sstream>
#include <iomanip>

const int Friend::MAX_MONTH = 12;
const int Friend::MAX_DAY = 31;

Friend::Friend(string name, int birthDate)
{
	this->name = name;
	setBirthDate(birthDate);
}

string Friend::toString() const
{
	stringstream sout;
	sout << this->name << ", ";
	sout << birthYear << "-";

	if (birthMonth < 10)
	{
		sout << "0";
	}
	sout << birthMonth << "-";

	if (birthDay < 10)
	{
		sout << "0";
	}
	sout << birthDay;

	return sout.str();
}

void Friend::setBirthDate(int birthDate)
{
	// 199603 20
	int day = birthDate % 100;
	// 1996 03
	int month = birthDate / 100 % 100;
	// 1996
	int year = birthDate / 100 / 100;

	if (day > MAX_DAY)
	{
		throw "Not a valid birth date.";
	}
	if (month > MAX_MONTH)
	{
		throw "Not a valid birth date.";
	}

	this->birthDay = day;
	this->birthMonth = month;
	this->birthYear = year;
}

bool Friend::operator==(Friend const& other) const
{
	return (this->name == other.name)
		&& (this->birthYear == other.birthYear)
		&& (this->birthMonth == other.birthMonth)
		&& (this->birthDay == other.birthDay);
}

int Friend::age(int year) const
{
	return year - birthYear;
}

int Friend::getBirthYear() const
{
	return this->birthYear;
}

int Friend::getBirthMonth() const
{
	return this->birthMonth;
}

int Friend::getBirthDay() const
{
	return this->birthDay;
}

string Friend::getName() const
{
	return this->name;
}