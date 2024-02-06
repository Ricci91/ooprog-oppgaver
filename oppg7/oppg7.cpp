/**
 * OPPG 7
 *
 * Lag et program som inneholder:
• struct Klokkeslett med int’ene time, minutt og sekund
• de tre funksjonene:
o void les(string & s)
Leser inn og fyller s med en hel tekstlinje (ikke bare ett enkeltord).
Det skal ikke godtas at brukeren kun skriver ‘\n’ – dvs. en tom tekst.
o void les(Klokkeslett & klokkeslett)
Får fylt alle structens datamedlemmer med rimelige verdier.
Bruk den nye LesData2.h til å lese alle tallene.
o void skriv(const Klokkeslett klokkeslett)
*Skriver structens datamedlemmer på formen: "TT:MM:SS"
gjerne med innledende ‘0’ (null) foran alle en-sifrede tall.
• main med:
o en array med tre stk. string (ikke pekere til slike)
o en array med tre stk. Klokkeslett (ikke pekere til slike)
o to for-løkker som leser inn og får fylt alle elementene i de to
arrayene ovenfor ved å bruke aktuell overloaded les-funksjon
o to for-løkker som skriver ut alt innholdet i de to arrayene.
Ifm. klokkeslettene brukes skriv-funksjonen ovenfor.

*@author Richard Frøyland
*@file oppg7.cpp

*/

#include <iostream>
#include <string>
#include <iomanip>
#include "LesData2.h"

using namespace std;

struct Klokkeslett
{
    int time, minutt, sekund;
};

void les(string & s);
void les(Klokkeslett & klokkeslett);
void skriv(const Klokkeslett & klokkeslett);
 
/**
* Hovedprogrammet
*/
int main()
{
    //Array med tre strings
    string sArray[3];


    //Array med tre klokkeslett
    Klokkeslett klokkeArray[3];

    //To for loops som leser inn og fyller elementene i de to
    //arrayene med å bruke overloaded les-funksjon
    
    //Les inn tre strings
    for (int i = 0; i < 3; i++)
    {
        cout << "String nr: " << i + 1 << "\n";
        les(sArray[i]);
    }

    //Les inn tre klokkeslett
    for (int i = 0; i < 3; i++)
    {
        cout << "Klokkeslett nr: " << i + 1 << "\n";
        les(klokkeArray[i]);
    }

    //To for loops som skriver ut alt innhold i de to arrayene

    cout << "Du har skrevet inn følgende strings:\n";
    //Loop som skriver ut stringene
    for (int i = 0; i < 3; i++)
    {
        cout << "String nr: " << i + 1 << "\n"
             << sArray[i] << "\n";
    }

    cout << "Du har skrevet inn følgende klokkeslett:\n";
    //Loop som skriver ut klokkeslettene
    for (int i = 0; i < 3; i++)
    {
        cout << "Klokkeslett nr:\n";
        skriv(klokkeArray[i]);
        cout << "\n";
    }

    return 0;
}

/**
* Leser inn og fyller s med en hel tekstlinje
* 
* @param s - Stringen som blir skrevet til
*/
void les(string & s)
{
    cout << "Skriv inn teksten som skal bli lest inn:\n";
    getline(cin, s);
}

/**
 * Får fylt alle structens datamedlemmer med rimelige verdier.
 * 
 * @param klokkeslett - Structen som blir les
*/
void les(Klokkeslett & klokkeslett)
{
    klokkeslett.time = lesInt("Skriv inn klokkeslettets time:\n",
    1, 23);

    klokkeslett.minutt = lesInt("Skriv inn minutt:\n",
    0, 59);

    klokkeslett.sekund = lesInt("Skriv inn sekund:\n", 
    1, 59);
}


/**
 * Skriver structens datamedlemmer på formen: "TT:MM:SS"
 * 
 * @param klokkeslett - Structen som blir skrevet til
*/
void skriv(const Klokkeslett & klokkeslett)
{
    cout << setfill('0') << setw(2) << klokkeslett.time << ":" 
         << setfill('0') << setw(2) << klokkeslett.minutt << ":" 
         << setfill('0') << setw(2) << klokkeslett.sekund << "\n";
}