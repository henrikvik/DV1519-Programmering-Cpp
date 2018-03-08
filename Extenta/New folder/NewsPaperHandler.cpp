#include "NewsPaperHandler.h"

NewsPaperHandler::NewsPaperHandler(size_t cap)
{
	this->cap = cap;
	this->num = num;
	this->papers = new NewsPaper*[cap];
}

NewsPaperHandler::~NewsPaperHandler()
{
	free();
}

NewsPaperHandler::NewsPaperHandler(NewsPaperHandler const & other)
{
	copy(other);
}

NewsPaperHandler & NewsPaperHandler::operator=(NewsPaperHandler const & other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

bool NewsPaperHandler::addNewsPaper(string name, int issue)
{
	NewsPaper newPaper(name, issue);

	bool exists = false;
	for (size_t i = 0; i < num && !exists; i++)
	{
		if (*papers[i] == newPaper)
		{ 
			exists = true;
		}
	}

	bool added = false;
	if (!exists)
	{
		if (num == cap) expand();
		papers[num++] = new NewsPaper(newPaper);
		added = true;
	}

	return added;
}

bool NewsPaperHandler::removeNewsPaper(string name)
{
	bool removed = false;

	for (size_t i = 0; i < num && !removed; i++)
	{
		if (name == papers[i]->getName())
		{
			delete papers[i];
			papers[i] = papers[--num];
			removed = true;
		}
	}

	return removed;
}

int NewsPaperHandler::getNrOfNewsPapers() const
{
	return num;
}

void NewsPaperHandler::getAll(string strings[]) const
{
	for (size_t i = 0; i < num; i++)
	{
		strings[i] = papers[i]->toString();
	}
}

void NewsPaperHandler::free()
{
	for (size_t i = 0; i < num; i++)
	{
		delete papers[i];
	}
	delete[] papers;
}

void NewsPaperHandler::copy(NewsPaperHandler const & other)
{
	num = other.num;
	cap = other.cap;
	papers = new NewsPaper*[cap];

	for (size_t i = 0; i < num; i++)
	{
		papers[i] = new NewsPaper(*other.papers[i]);
	}
}

void NewsPaperHandler::expand()
{
	cap += 10;
	NewsPaper ** temp = new NewsPaper*[cap];

	for (size_t i = 0; i < num; i++)
	{
		temp[i] = papers[i];
	}

	delete[] papers;
	papers = temp;
}
