#include "NewsPaper.h"

NewsPaper::NewsPaper(string name, size_t issue)
{
	this->name = name;
	this->issue = issue;
}

NewsPaper::~NewsPaper()
{
}

bool NewsPaper::operator==(NewsPaper const & other) const
{
	return name == other.name;
}

string NewsPaper::getName() const
{
	return name;
}

string NewsPaper::toString() const
{
	return name + " " + to_string(issue);
}
