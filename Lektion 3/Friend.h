#pragma once
#include <string>
using namespace std;

class Friend
{
public:
	Friend(string name = "", int birthDate = 19000101);

	string toString() const;
	void setBirthDate(int birthDate);

	bool operator==(Friend const& other) const;

	int age(int year) const;

	int getBirthYear() const;
	int getBirthMonth() const;
	int getBirthDay() const;

	string getName() const;

private:
	static const int MAX_MONTH;
	static const int MAX_DAY;

	string name;
	int birthYear;
	int birthMonth;
	int birthDay;
};