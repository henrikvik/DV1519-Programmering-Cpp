#include <iostream>
#include <string>
using namespace std;

#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

// Skapa klassen MovieHandler som kommer att hantera klassen Movie
#include "MovieHandler.h"

// Du ska även testa fyra olika metoder att hantera HAR-relationer
// Det statiska arrayen ska vara minst 10 element stort
// och det dynamiska arrayed ska börja på en kapacitet av 5
// och kommer expandera vid behov.

// Kör din implementering med det 4e alternativet i menyn 
// och se till att varje rad slutar med "OK!"

// Metod 1
// Statiskt array med statiska objekt
// Movie movies[SIZE];

// Metod 2
// Statiskt array med dynamiska objekt
// Movie * movies[SIZE];

// Metod 3
// Dynamisk array med statiska objekt
// Movie * movies;

// Metod 4
// Dynamisk array med dynamiska objekt
// Movie ** movies;

int menu();
void addMovie(MovieHandler & handler);
void removeMovie(MovieHandler & handler);
void showMovies(MovieHandler & handler);
void testHandler();

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    MovieHandler movieHandler;

    bool quit = false;
    while (!quit)
    {
        switch (menu())
        {
        case 0:
            quit = true;
            break;
        case 1:
            addMovie(movieHandler);
            break;
        case 2:
            removeMovie(movieHandler);
            break;
        case 3:
            showMovies(movieHandler);
            break;
        case 4:
            testHandler();
            break;
        default:
            cout << "Not a valid option. Try again." << endl;
            break;
        }
    }

    return 0;
}


int menu()
{
    string options[] = {"Quit", "Add Movie", "Remove Movie", "Show Movies", "Test Handler"};
    for (size_t i = 0; i < 5; i++)
    {
        cout << to_string(i) << ") " << options[i] << endl;
    }

    int choise = 0;
    cin >> choise;

    return choise;
}

void addMovie(MovieHandler & handler)
{
    string name;
    int year;

    cout << "Add a movie!" << endl;
    cout << "Name: ";

    cin.ignore();
    getline(cin, name);

    cout << "Year: ";
    cin >> year;

    handler.addMovie(name, year);
}

void removeMovie(MovieHandler & handler)
{
    string name;
    int year;

    cout << "Remove a movie!" << endl;
    cout << "Name: ";

    cin.ignore();
    getline(cin, name);

    cout << "Year: ";
    cin >> year;

    if (handler.removeMovie(name, year))
    {
        cout << "Movie removed!" << endl;
    }
    else
    {
        cout << "Could not find movie." << endl;
    }
}

void showMovies(MovieHandler & handler)
{
    int movieCount = handler.getMovieCount();
    string * movieStrings = new string[movieCount];

    handler.getMoviesAsString(movieStrings, movieCount);

    cout << "Your movies: " << endl;
    for (int i = 0; i < movieCount; i++)
    {
        cout << movieStrings[i] << endl;
    }

    delete[] movieStrings;
}

void testHandler()
{
    string testDataNames[] = {
        "The Shawshank Redemption", 
        "The Godfather", 
        "The Godfather: Part II", 
        "The Dark Knight", 
        "12 Angry Men", 
        "Schindler's List",
        "Pulp Fiction",
        "The Lord of the Rings: The Return of the King",
        "The Good, the Bad and the Ugly",
        "Fight Club"
    };
    int testDataYears[] = {
        1994,
        1972,
        1974,
        2008,
        1957, 
        1993,
        1994, 
        2003,
        1966, 
        1999
    };

    _CrtMemState startMemState, endMemState, diffMemState;
    _CrtMemCheckpoint( &startMemState );

    MovieHandler * handler = new MovieHandler();

    cout << "Adding test data. ";
    for (size_t i = 0; i < 10; i++)
    {
        handler->addMovie(testDataNames[i], testDataYears[i]);
    }

    int movieCount = handler->getMovieCount();
    cout << "Movies in list " << movieCount << ". ";
    if (movieCount == 10)
    {
        cout << "OK!" << endl;
    }
    else
    {
        cout << "FAIL." << endl;
    }
    

    cout << "Removing a movie. ";
    bool removeMovie1 = handler->removeMovie("12 Angry Men", 1957);
    if (removeMovie1)
    {
        cout << "OK!" << endl;
    }
    else
    {
        cout << "FAIL." << endl;
    }

    cout << "Trying to remove a movie that does not exist. ";
    bool removeMovie2 = handler->removeMovie("Fight Club", 2001);
    if (removeMovie2 == false)
    {
        cout << "OK!" << endl;
    }
    else
    {
        cout << "FAIL." << endl;
    }

    cout << "Removing 2 more movies. ";
    bool removeMovie3 = handler->removeMovie("Schindler's List", 1993);
    bool removeMovie4 = handler->removeMovie("Pulp Fiction", 1994);

    if (removeMovie3 && removeMovie4)
    {
        cout << "OK!" << endl;
    }
    else
    {
        cout << "FAIL." << endl;
    }


    cout << "Clearing all movies. ";
    handler->clear();

    movieCount = handler->getMovieCount();
    cout << "Movies in list " << movieCount << ". ";
    if (movieCount == 0)
    {
        cout << "OK!" << endl;
    }
    else
    {
        cout << "FAIL." << endl;
    }

    delete handler;
    
    _CrtMemCheckpoint( &endMemState );

    cout << "Checking for memory leaks. ";
    if (_CrtMemDifference(&diffMemState, &startMemState, &endMemState))
    {
        cout << "FAIL." << endl;
    }
    else
    {
        cout << "OK!" << endl;
    }
}