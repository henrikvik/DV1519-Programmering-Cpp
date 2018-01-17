#include <iostream>
#include <string>
using namespace std;

int main()
{
    // pekare inneh�ller ingen data, det har information om vart data finns
    // nullptr s�ger att denna pekare inte pekar p� n�gonting
    string * names = nullptr;
    int namesCapacity = 0;
    int namesCount = 0;

    namesCapacity = 5;
    names = new string[namesCapacity];

    // l�gg till namnet Alice p� plats namesCount som �r lika med 0
    names[namesCount] = "Alice";
    // �ka names count med ett, namesCount �r nu 1
    namesCount++;


    // repitera detta f�r Bob och Charles
    names[namesCount] = "Bob";
    namesCount++;
    names[namesCount] = "Charles";
    namesCount++;

    // g� igenom fr�n index 0 till index i < namesCount som �r 3
    // plats 0, 1, 2 kommer att loopas �ver
    for (int i = 0; i < namesCount; i++)
    {
        cout << names[i] << endl;
    }

    // be anv�ndaren l�gga till ett namn
    cout << "Add a new name: ";
    string newName;
    getline(cin, newName);

    // l�gg till det nya namnet
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

    // vi beh�ver hitta indexet p� namnet s� vi kan ta bort det ur arrayet
    int removeIndex = -1;
    //OBS! vi har laggt till "&& removeIndex == -1" p� for loopens condition
    // detta s�ger att vi forts�ttar bara loopa om removeIndex �r lika med -1
    for (int i = 0; i < namesCount && removeIndex == -1; i++)
    {
        if (removeName == names[i])
        {
            removeIndex = i;
        }
    }

    // om removeIndex inte �r lika med -1 s� har vi hittat indexet f�r namnet att ta bort
    if (removeIndex != -1)
    {
        /* Det snabbaste s�ttet att ta bort bryt sig inte om sortering
        // vi ers�tter namnet p� plats removeIndex med det sista namnet
        // vi f�r det sisa namnet via namesCount - 1 f�r att arrayer b�rjar p� 0
        // om namesCount skulle var lika med 1: 1-1 = 0, det f�rsta och �nda namnet
        // liggre p� plats 0.
        names[removeIndex] = names[namesCount - 1];
        //*/

        //* Om vi vill sortera med ordningen kvar m�ste vi flytta fram alla namn ett steg

        // OBS vi loopar bara till namesCount - 1 f�r att unvika out of bounds error
        // och vi b�rjar p� removeIndex f�r att vi vill bara flytta p� det som kommer efter
        for (int i = removeIndex; i < namesCount - 1; i++)
        {
            // om vi inte hadde haft namesCount h�r s� skulle vi 
            // f� out of bounds p� den sista itterationen pga i + 1
            names[i] = names[i + 1];
        }
        //*/

        // vi s�nker namesCount med ett, namesCount �r nu 3
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

    // f�r att expandera arrays kr�vs ett par steg
    // �ka kapaciteten
    namesCapacity += 10;
    // skapa nytt array p� heapen
    string * tempPtr = new string[namesCapacity];
    // kopiera �ver gammal data
    for (int i = 0; i < namesCount; i++)
    {
        tempPtr[i] = names[i];
    }
    // ta bort gammalt array f�n heapen
    delete[] names;
    // anv�nd den gammla pekaren till den nya datan
    names = tempPtr;

    system("pause");
    return 0;
}