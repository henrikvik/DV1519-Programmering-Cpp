#include <iostream>
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
using namespace std;

// Skapa klassen MovieHandler som kommer att hantera klassen Movie
// Det statiska arrayen ska vara minst 10 element stort
// och det dynamiska arrayed ska börja på en kapacitet av 5
// och kommer expandera vid behov.
class MovieHandler;
// Statiskt array med statiska objekt
// Movie movies[SIZE];
// Statiskt array med dynamiska objekt
// Movie * movies[SIZE];
// Dynamisk array med statiska objekt
// Movie * movies;
// Dynamisk array med dynamiska objekt
// Movie ** movies;

int menu();
void addMovie(MovieHandler & handler);
void removeMovie(MovieHandler & handler);
void testHandler(MovieHandler & handler);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	bool quit = false;
	while (!quit)
	{
		switch (menu())
		{
		case 0:
			quit = true;
			break;
		case 1:
			addMovie();
			break;
		case 2:
			removeMovie();
			break;
		case 3:
			testHandler();
			break;
		default:
			cout << "Try again" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}
