#include <iostream>
#include <string>
using namespace std;

// implementera klassen song i sin egna h och cpp fil samt inkludera den h�r
class Song;

// l�gg till l�t via anv�ndar inmatning
void addSong(Song songs[], int &nrOfSongs);
// via alla l�tar
void showAllSongs(Song songs[], int nrOfSongs);
// s�k l�t, returnerar index
int findSong(Song songs[], string title, int nrOfSongs);
// ta bort l�t, returnerar om det lyckades eller inte
bool removeSong(Song songs[], int index, int &nrOfSongs);
bool removeSong(Song songs[], string title, int &nrOfSongs);
// sortera l�tar, what �r vilken attribut den ska sorteras efter
void sortSongs(Song songs[], string what, int nrOfSongs);
// spara som fil
void save(Song songs[], int nrOfSongs);
// expanderar songs kapacitet med 10
void expand(Song *&songs, int &songCapacity, int nrOfSongs);
// ladda fr�n fil, returnerar nrOfSongs
int load(Song *&songs, int &songCapacity, int &nrOfSongs);


int main()
{
    // skapa ett testprogramm med meny som anv�nder all functioner
    return 0;
}