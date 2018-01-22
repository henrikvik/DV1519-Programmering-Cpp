#include <iostream>
using namespace std;

#include "FriendBook.h"

const int MAX_CHOISE = 2;
int openMenu();

void addFriend(FriendBook & friendBook);
void showFriends(FriendBook & friendBook);

int main()
{
	FriendBook friendBook("TestBook");

	int choise = openMenu();
	while (choise < MAX_CHOISE)
	{
		switch (choise)
		{
		case 0:
			addFriend(friendBook);
			break;
		case 1:
			showFriends(friendBook);
			break;
		}

		choise = openMenu();
	}
	return 0;
	system("pause");

}

int openMenu()
{
	cout << "0. Add Friend" << endl;
	cout << "1. Show Friends" << endl;

	int choise = 0;
	cin >> choise;

	return choise;
}

void addFriend(FriendBook & friendBook)
{
	cout << "Name: ";
	string name;
	cin.ignore();
	getline(cin, name);
	cout << "BirthDate: ";
	int birthDate;
	cin >> birthDate;
	friendBook.addFriend(name, birthDate);
}

void showFriends(FriendBook & friendBook)
{
	const int SIZE = 100;
	string arr[SIZE];

	friendBook.getFriendsAsString(arr, SIZE);

	int nrOfFriends = friendBook.getNrOfFriends();

	for (int i = 0; i < nrOfFriends; i++)
	{
		cout << arr[i] << endl;
	}
}