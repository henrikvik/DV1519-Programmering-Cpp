#pragma once
#include <string>
using namespace std;

class Friend
{
public:
    // En konstruktor har samma namn som klassen och anv�nds f�r att skapa nya objekt
    Friend();
    // Man kan ha hur m�nga konstrukt�rer som h�lst med hj�lp av �verlagring
    Friend(string name, int birthYear);
    // en klass har alltid en(bara en) dekonstruktor som k�rs n�r objetekt
    // ska f�rst�ras detta sker mannuelt med dynamiskt minne (delete functionen)
    // eller automatiskt via statiskt minne n�r variablens scope l�mnas
    ~Friend();

    // medlems funtioner kan bara anropas av objekt av klassen
    // anv�nd const efter funtions prototypen ifall funktionen inte �ndrar p� n�gon data
    int age(int year) const;
    string toString() const;

    // operat�rs �verlagring g�r s� du kan �verlagra de inbyggda operat�rerna
    // som tex +, -, <, >, ==, =
    // friendA < friendB?
    bool operator<(Friend & other) const;
    bool operator==(Friend & other) const;
    void operator=(Friend & other);

private:
    // medlems variablar �r private f�r att undvika ov�ntade �ndringar
    string name;
    int birthYear;
};