#pragma once
#include <string>
using namespace std;

class Friend
{
public:
    // En konstruktor har samma namn som klassen och används för att skapa nya objekt
    Friend();
    // Man kan ha hur många konstruktörer som hälst med hjälp av överlagring
    Friend(string name, int birthYear);
    // en klass har alltid en(bara en) dekonstruktor som körs när objetekt
    // ska förstöras detta sker mannuelt med dynamiskt minne (delete functionen)
    // eller automatiskt via statiskt minne när variablens scope lämnas
    ~Friend();

    // medlems funtioner kan bara anropas av objekt av klassen
    // använd const efter funtions prototypen ifall funktionen inte ändrar på någon data
    int age(int year) const;
    string toString() const;

    // operatörs överlagring gör så du kan överlagra de inbyggda operatörerna
    // som tex +, -, <, >, ==, =
    // friendA < friendB?
    bool operator<(Friend & other) const;
    bool operator==(Friend & other) const;
    void operator=(Friend & other);

private:
    // medlems variablar är private för att undvika oväntade ändringar
    string name;
    int birthYear;
};