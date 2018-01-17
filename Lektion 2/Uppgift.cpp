#include <iostream>
#include <string>
using namespace std;

// implementera klassen song i sin egna h och cpp fil samt inkludera den här
class Song;

// lägg till låt via användar inmatning
void addSong(Song songs[], int &nrOfSongs);
// via alla låtar
void showAllSongs(Song songs[], int nrOfSongs);
// sök låt, returnerar index
int findSong(Song songs[], string title, int nrOfSongs);
// ta bort låt, returnerar om det lyckades eller inte
bool removeSong(Song songs[], int index, int &nrOfSongs);
bool removeSong(Song songs[], string title, int &nrOfSongs);
// sortera låtar, what är vilken attribut den ska sorteras efter
void sortSongs(Song songs[], string what, int nrOfSongs);
// spara som fil
void save(Song songs[], int nrOfSongs);
// expanderar songs kapacitet med 10
void expand(Song *&songs, int &songCapacity, int nrOfSongs);
// ladda från fil, returnerar nrOfSongs
int load(Song *&songs, int &songCapacity, int &nrOfSongs);


int main()
{
    // skapa ett testprogramm med meny som använder all functioner
    return 0;
}