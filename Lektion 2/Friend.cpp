#include "Friend.h"
#include <sstream>
#include <iostream>

Friend::Friend()
{
    this->name = "";
    this->birthYear = 0;
}

Friend::Friend(string name, int birthYear)
{
    this->name = name;
    this->birthYear = birthYear;
}

Friend::~Friend()
{
    cout << "Friend " << name << "has been destroyed." << endl;
}

int Friend::age(int year) const
{
    return year - birthYear;
}

string Friend::toString() const
{
    stringstream sin;

    sin << this->name << ", " << this->birthYear;

    return sin.str();
}

bool Friend::operator<(Friend & other) const
{
    return this->birthYear < other.birthYear;
}

bool Friend::operator==(Friend & other) const
{
    return this->birthYear == other.birthYear;
}

void Friend::operator=(Friend & other)
{
    this->name = other.name;
    this->birthYear = other.birthYear;
}
