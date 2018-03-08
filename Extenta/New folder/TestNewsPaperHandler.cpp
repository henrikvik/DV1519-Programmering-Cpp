#include <iostream>
using namespace std;

#include "NewsPaperHandler.h"

void printAll(NewsPaperHandler const& handler);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	NewsPaperHandler handler(2);

	cout << "Adding 4 papers:" << endl;
	handler.addNewsPaper("Wow!",		  13);
	handler.addNewsPaper("Amazing Stuff", 20);
	handler.addNewsPaper("Yes Paper",	  322);
	handler.addNewsPaper("Beep Boop",	  7);
	printAll(handler);

	cout << "Adding existing paper: " << handler.addNewsPaper("Beep Boop", 7)	  << endl;
	cout << "Removing paper       : " << handler.removeNewsPaper("Amazing Stuff") << endl;
	cout << "Removing same paper  : " << handler.removeNewsPaper("Amazing Stuff") << endl;
	printAll(handler);

	cout << "Copy constructor handler: " << endl;
	NewsPaperHandler handler2(handler);
	printAll(handler2);

	cout << "Copy operator handler: " << endl;
	NewsPaperHandler handler3(2);
	handler3.addNewsPaper("Dont Dead Open Inside", 0);
	handler3 = handler;
	printAll(handler3);

	system("pause");
	return 0;
}

void printAll(NewsPaperHandler const & handler)
{
	size_t size = handler.getNrOfNewsPapers();
	string * strings = new string[size];

	handler.getAll(strings);
	for (size_t i = 0; i < size; i++)
	{
		cout << "  " << strings[i] << endl;
	}

	cout << endl;

	delete[] strings;
}
