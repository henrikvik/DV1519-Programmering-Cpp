#pragma once
#include "NewsPaper.h"

class NewsPaperHandler
{
public:
	NewsPaperHandler(size_t cap);
	virtual ~NewsPaperHandler();

	NewsPaperHandler(NewsPaperHandler const& other);
	NewsPaperHandler& operator=(NewsPaperHandler const& other);

	bool addNewsPaper(string name, int issue);
	bool removeNewsPaper(string name);
	int getNrOfNewsPapers() const;
	void getAll(string strings[]) const;

private:
	NewsPaper ** papers;
	size_t num;
	size_t cap;

	void free();
	void copy(NewsPaperHandler const& other);
	void expand();
};