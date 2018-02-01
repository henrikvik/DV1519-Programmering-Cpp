#include "FriendBook.h"
#include <iostream>
#include <fstream>

FriendBook::FriendBook(string title)
{
	this->title = title;

	friendsCount = 0;
	friendsCapacity = 10;
	friends = new Friend[friendsCapacity];
}

FriendBook::~FriendBook()
{
	delete[] friends;
}

bool FriendBook::addFriend(string name, int birthDate)
{
	bool didAdd = false;
	try
	{
		Friend newFriend(name, birthDate);

		this->friends[this->friendsCount] = newFriend;
		this->friendsCount++;
		didAdd = true;

		if (this->friendsCount == this->friendsCapacity)
		{
			expand();
		}
	}
	catch (char * c)
	{
		cout << c << endl;
	}
	
	return didAdd;
}

void FriendBook::getFriendsAsString(string arr[], int nrOf) const
{
	for (int i = 0; i < nrOf; i++)
	{
		arr[i] = this->friends[i].toString();
	}
}

int FriendBook::getNrOfFriends() const
{
	return this->friendsCount;
}

bool FriendBook::removeFriend(string name, int birthDate)
{
	bool didRemove = false;

	try
	{
		Friend searchFriend(name, birthDate);

		int friendIndex = -1;
		for (int i = 0; i < friendsCount && friendIndex == -1; i++)
		{
			if (friends[i] == searchFriend)
			{
				friendIndex = i;
			}
		}

		if (friendIndex != -1)
		{
			this->friends[friendIndex] = this->friends[this->friendsCount - 1];
			this->friendsCount--;
			didRemove = true;
		}
	}
	catch (char * c)
	{
		cout << c << endl;
	}

	return didRemove;
}

bool FriendBook::existFriend(string name, int birthDate) const
{
	bool friendFound = false;

	try
	{
		Friend searchFriend(name, birthDate);

		for (int i = 0; i < friendsCount && friendFound == false; i++)
		{
			if (this->friends[i] == searchFriend)
			{
				friendFound = true;
			}
		}
	}
	catch (char * c)
	{
		cout << c << endl;
	}

	return friendFound;
}

void FriendBook::getFriendsBornByYearAsString(string arr[], int nrOf, int year) const
{
	int stringCount = 0;

	for (int i = 0; i < friendsCount; i++)
	{
		if (friends[i].getBirthYear() == year)
		{
			arr[stringCount] = friends[i].toString();
			stringCount++;
		}
	}

}

void FriendBook::saveOnFile() const
{
	ofstream fout;
	fout.open(this->title + ".txt");
	
	for (int i = 0; i < friendsCount; i++)
	{
		int birthDate = 0;
		// 1994
		// 199400
		// 19940000
		birthDate += friends[i].getBirthYear() * 100 * 100;
		// 19940000
		//   + 1200
		birthDate += friends[i].getBirthMonth() * 100;
		// 19940000
		//   + 1200
		//     + 31
		birthDate += friends[i].getBirthDay();

		fout << friends[i].getName() << endl;
		fout << birthDate << endl;
	}

	fout.close();
}

void FriendBook::readFromFile()
{
    clear();

    ifstream fin;
    fin.open(this->title + ".txt");

    string name = "";
    int birthDate = 0;

    // kör så länge det finns rader att hämta och lägg raden i name variablen
    while (getline(fin, name))
    {
        // hämta fördelse datum
        fin >> birthDate;
        // ignorera \n och gå till nästa rad
        fin.ignore();

        addFriend(name, birthDate);
    }

    fin.close();
}

void FriendBook::clear()
{
	this->friendsCount = 0;
}

void FriendBook::expand()
{
	this->friendsCapacity += 10;
	Friend * tempPtr = new Friend[this->friendsCapacity];

	for (int i = 0; i < this->friendsCount; i++)
	{
		tempPtr[i] = this->friends[i];
	}

	delete[] friends;
	friends = tempPtr;
}