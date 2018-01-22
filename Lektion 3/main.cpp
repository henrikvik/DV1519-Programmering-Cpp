#include <iostream>
using namespace std;

#include "FriendBook.h"

const int MAX_CHOISE = 7;
int openMenu();

void addFriend(FriendBook & friendBook);
void showFriends(FriendBook & friendBook);
void removeFriend(FriendBook & friendBook);
void searchFriend(FriendBook & friendBook);
void getFriendsByYear(FriendBook & friendBook);
void saveBook(FriendBook & friendBook);
void loadBook(FriendBook & friendBook);

int main()
{
    FriendBook friendBook("TestBook");

    int choise = openMenu();
    while (choise < MAX_CHOISE)
    {
        switch (choise)
        {
        case 0: addFriend(friendBook);		break;
        case 1: showFriends(friendBook);	break;
        case 2: removeFriend(friendBook);	break;
        case 3: searchFriend(friendBook);	break;
        case 4: getFriendsByYear(friendBook); break;
        case 5: saveBook(friendBook);		  break;
        case 6: loadBook(friendBook);         break;
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
    cout << "2. Remove Friend" << endl;
    cout << "3. Search Friend" << endl;
    cout << "4. Search Friend by Year" << endl;
    cout << "5. Save book to file" << endl;
    cout << "6. Load book from file" << endl;

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
    int nrOfFriends = friendBook.getNrOfFriends();
    string * arr = new string[nrOfFriends];

    friendBook.getFriendsAsString(arr, nrOfFriends);

    for (int i = 0; i < nrOfFriends; i++)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;
}

void removeFriend(FriendBook & friendBook)
{
    cout << "Name: ";
    cin.ignore();
    string name;
    getline(cin, name);

    cout << "BirthDate: ";
    int birthDate;
    cin >> birthDate;

    bool didRemove = friendBook.removeFriend(name, birthDate);

    if (didRemove)
    {
        cout << "Friend removed." << endl;
    }
    else
    {
        cout << "Friend not found." << endl;
    }
}

void searchFriend(FriendBook & friendBook)
{
    cout << "Name: ";
    string name;
    cin.ignore();
    getline(cin, name);

    cout << "BirthDate: ";
    int birthDate;
    cin >> birthDate;

    bool friendFound = friendBook.existFriend(name, birthDate);

    if (friendFound)
    {
        cout << "Friend is in your list!" << endl;
    }
    else
    {
        cout << "Could not find friend." << endl;
    }
}

void getFriendsByYear(FriendBook & friendBook)
{
    cout << "Year: ";
    int year;
    cin >> year;

    int nrOfFriends = friendBook.getNrOfFriends();
    string * arr = new string[nrOfFriends];

    friendBook.getFriendsBornByYearAsString(arr, nrOfFriends, year);

    for (int i = 0; i < nrOfFriends; i++)
    {
        if (arr[i] != "")
        {
            cout << arr[i] << endl;
        }
    }
}

void saveBook(FriendBook & friendBook)
{
    friendBook.saveOnFile();
    cout << "FriendBook saved!" << endl;
}

void loadBook(FriendBook & friendBook)
{
    friendBook.readFromFile();
    cout << "FriendBook loaded!" << endl;
}
