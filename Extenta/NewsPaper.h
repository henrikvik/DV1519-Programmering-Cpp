#pragma once
#include <string>
using namespace std;

class NewsPaper
{
public:
	NewsPaper(string name, size_t issue);
	virtual ~NewsPaper();

	bool operator==(NewsPaper const& other) const;

	string getName() const;
	virtual string toString() const;

private:
	string name;
	size_t issue;
};