#include "FriendBook.h"
#include <iostream>

FriendBook::FriendBook(string title)
{
	this->title = title;

	friendsCount = 0;
	friendsCapacity = 10;
	friends = new Friend[friendsCapacity];
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
	}
	catch (char * c)
	{
		cout << c << endl;
	}
	
	return didAdd;
}

void FriendBook::getFriendsAsString(string arr[], int nrOf) const
{
	for (int i = 0; i < nrOf && i < friendsCount; i++)
	{
		arr[i] = this->friends[i].toString();
	}
}

int FriendBook::getNrOfFriends() const
{
	return this->friendsCount;
}