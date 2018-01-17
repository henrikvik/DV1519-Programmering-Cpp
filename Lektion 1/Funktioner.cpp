#include <iostream>
#include <string>
using namespace std;


// överlagrade funktioner har samma namn
// men olika parametrar/argument för att skilja på dem
void addName(string names[], int &namesCount);
void addName(string name, string names[], int &namesCount);

void printNames(string names[], int namesCount);

bool removeName(string names[], int &namesCount);
int findName(string name, string names[], int namesCount);
bool removeNameFast(int index, string names[], int &namesCount);
bool removeNameSorted(int index, string names[], int &namesCount);

// här använder vi ett default argument om användaren inte
// skickar in ett eget värde så kommer default argumentet att användas
// default argument måste vara i slutet av en funtion
// vi använder även *& vilket är en pekar-referens detta låter oss läsa pekaren och ändra dess värde
void expandNames(string *& names, int namesCount, int & namesCapacity, int increaseAmount = 10);

int main()
{
    string * names = nullptr;
    int namesCapacity = 0;
    int namesCount = 0;

    namesCapacity = 5;
    names = new string[namesCapacity];

    addName("Alice", names, namesCount);
    addName("Bob", names, namesCount);
    addName("Charles", names, namesCount);

    printNames(names, namesCount);

    addName(names, namesCount);

    printNames(names, namesCount);

    bool removedName = removeName(names, namesCount);
    if (removedName)
    {
        cout << "Removed name!" << endl;
    }
    else
    {
        cout << "Could not find name!" << endl;
    }

    printNames(names, namesCount);

    expandNames(names, namesCount, namesCapacity);
    cout << "Expanding array!" << endl;

    for (int i = 0; i < 10 ; i++)
    {
        addName("Name " + std::to_string(i), names, namesCount);
    }

    printNames(names, namesCount);

    system("pause");
    return 0;
}

void addName(string names[], int & namesCount)
{
    cout << "Add a new name: ";
    string newName;
    getline(cin, newName);

    addName(newName, names, namesCount);
}

void addName(string name, string names[], int & namesCount)
{
    names[namesCount] = name;
    namesCount++;
}

void printNames(string names[], int namesCount)
{
    for (int i = 0; i < namesCount; i++)
    {
        cout << names[i] << endl;
    }
}

bool removeName(string names[], int & namesCount)
{
    cout << "Enter a name to remove: ";
    string name;
    getline(cin, name);

    int removeIndex = findName(name, names, namesCount);

    bool removedName = false;
    //removedName = removeNameFast(removeIndex, names, namesCount);
    removedName = removeNameSorted(removeIndex, names, namesCount);

    return removedName;
}

int findName(string name, string names[], int namesCount)
{
    int index = -1;
    for (int i = 0; i < namesCount && index == -1; i++)
    {
        if (name == names[i])
        {
            index = i;
        }
    }

    return index;
}

bool removeNameFast(int index, string names[], int & namesCount)
{
    bool removed = false;
    if (index != -1)
    {
        names[index] = names[namesCount - 1];
        namesCount--;
        removed = true;
    }

    return removed;
}

bool removeNameSorted(int index, string names[], int & namesCount)
{
    bool removed = false;
    if (index != -1)
    {
        for (int i = index; i < namesCount - 1; i++)
        {
            names[i] = names[i + 1];
        }

        namesCount--;
        removed = true;
    }

    return removed;
}

void expandNames(string *& names, int namesCount, int & namesCapacity, int increaseAmount)
{
    namesCapacity += increaseAmount;
    string * tempPtr = new string[namesCapacity];

    for (int i = 0; i < namesCount; i++)
    {
        tempPtr[i] = names[i];
    }

    delete[] names;
    names = tempPtr;
}

