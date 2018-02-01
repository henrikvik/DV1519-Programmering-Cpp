#include <iostream>
#include <string>
using namespace std;

int main()
{
    // pekare innehåller ingen data, det har information om vart data finns
    // nullptr säger att denna pekare inte pekar på någonting
    string * names = nullptr;
    int namesCapacity = 0;
    int namesCount = 0;

    namesCapacity = 5;
    names = new string[namesCapacity];

    // lägg till namnet Alice på plats namesCount som är lika med 0
    names[namesCount] = "Alice";
    // öka names count med ett, namesCount är nu 1
    namesCount++;


    // repitera detta för Bob och Charles
    names[namesCount] = "Bob";
    namesCount++;
    names[namesCount] = "Charles";
    namesCount++;

    // gå igenom från index 0 till index i < namesCount som är 3
    // plats 0, 1, 2 kommer att loopas över
    for (int i = 0; i < namesCount; i++)
    {
        cout << names[i] << endl;
    }

    // be användaren lägga till ett namn
    cout << "Add a new name: ";
    string newName;
    getline(cin, newName);

    // lägg till det nya namnet
    names[namesCount] = newName;
    namesCount++;

    // skriv ut alla namn igen
    for (int i = 0; i < namesCount; i++)
    {
        cout << names[i] << endl;
    }

    cout << "Enter a name to remove: ";
    string removeName;
    getline(cin, removeName);

    // vi behöver hitta indexet på namnet så vi kan ta bort det ur arrayet
    int removeIndex = -1;
    //OBS! vi har laggt till "&& removeIndex == -1" på for loopens condition
    // detta säger att vi fortsättar bara loopa om removeIndex är lika med -1
    for (int i = 0; i < namesCount && removeIndex == -1; i++)
    {
        if (removeName == names[i])
        {
            removeIndex = i;
        }
    }

    // om removeIndex inte är lika med -1 så har vi hittat indexet för namnet att ta bort
    if (removeIndex != -1)
    {
        /* Det snabbaste sättet att ta bort bryt sig inte om sortering
        // vi ersätter namnet på plats removeIndex med det sista namnet
        // vi får det sisa namnet via namesCount - 1 för att arrayer börjar på 0
        // om namesCount skulle var lika med 1: 1-1 = 0, det första och ända namnet
        // liggre på plats 0.
        names[removeIndex] = names[namesCount - 1];
        //*/

        //* Om vi vill sortera med ordningen kvar måste vi flytta fram alla namn ett steg

        // OBS vi loopar bara till namesCount - 1 för att unvika out of bounds error
        // och vi börjar på removeIndex för att vi vill bara flytta på det som kommer efter
        for (int i = removeIndex; i < namesCount - 1; i++)
        {
            // om vi inte hadde haft namesCount här så skulle vi 
            // få out of bounds på den sista itterationen pga i + 1
            names[i] = names[i + 1];
        }
        //*/

        // vi sänker namesCount med ett, namesCount är nu 3
        namesCount--;
    }
    else
    {
        cout << "Could not find name." << endl;
    }

    // skriv ut alla namn igen
    for (int i = 0; i < namesCount; i++)
    {
        cout << names[i] << endl;
    }

    // för att expandera arrays krävs ett par steg
    // öka kapaciteten
    namesCapacity += 10;
    // skapa nytt array på heapen
    string * tempPtr = new string[namesCapacity];
    // kopiera över gammal data
    for (int i = 0; i < namesCount; i++)
    {
        tempPtr[i] = names[i];
    }
    // ta bort gammalt array fån heapen
    delete[] names;
    // använd den gammla pekaren till den nya datan
    names = tempPtr;

    
    // ta bort names för att undvika minnesläcka
    delete[] names;
    system("pause");
    return 0;
}
