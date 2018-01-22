#pragma once

#include "Friend.h"

class FriendBook
{
public:
	FriendBook(string title);
	~FriendBook();

	bool addFriend(string name, int birthDate); // parameters name, birthyear - use  the == operator to avoid multiples
	bool removeFriend(string name, int birthDate); // parameters name, birthyear, ...
	bool existFriend(string name, int birthDate) const; // parameters name, birthyear, ...
	void getFriendsBornByYearAsString(string arr[], int nrOf, int year) const;
	int getNrOfFriends() const;
	string getTitle() const;
	void setTitle(string title);
	void clear();
	void getFriendsAsString(string arr[], int nrOf)const;

	void saveOnFile() const; // filename name of owner followed by .txt
	void readFromFile(); // filename name of owner followed by .txt

private:
	Friend * friends;
	int friendsCapacity;
	int friendsCount;

	string title;

	void expand();
};