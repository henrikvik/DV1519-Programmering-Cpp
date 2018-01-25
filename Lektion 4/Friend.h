#pragma once
#include <string>
using namespace std;

class Friend
{
public:
	Friend(string name = "", int birthYear = 0);
	~Friend();

	string toString() const;
	int age(int year) const;

	bool operator==(Friend const& other) const;

private:
	string name;
	int birthYear;
};