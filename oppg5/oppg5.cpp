/**
 * Oppgave 5
 *
 * @file oppg5.cpp
 * @author Richard Froeyland, NTNU
 */

#include <iostream>
#include "lesdata2.h"

using namespace std;

const int STRLEN = 40;           ///< Max.Tekstlengde
const int MAXFORELESNINGER = 10; ///< Max.antall forelesninger

struct Forelesning
{
    char emne[STRLEN / 2],
        foreleser[STRLEN],
        sted[STRLEN / 2];
    int timeStart, minuttStart,
        timeSlutt, minuttSlutt;
};

void forelesningLesData(Forelesning *f);
void foreledningSkrivData(Forelesning *f);

int main()
{
    // Lager en struct array med structer "forelesninger som inneholder"
    // structen Forelesning
    Forelesning forelesninger[MAXFORELESNINGER];

    // Variabel som holder antall forelesninger
    int antFore = 0;

    // Les inn antall forelesninger
    antFore = lesTallTegn("Skriv inn hvor mange forelesninger: ",
                          1, MAXFORELESNINGER);

    // For loop som leser inn emne, foreleser og sted
    for (int i = 0; i < antFore; i++)
    {
        cout << "Skriv inn emne: ";
        cin >> forelesninger[i].emne;
        cout << "\nSkriv inn foreleser: ";
        cin >> forelesninger[i].foreleser;
        cout << "\nSkriv inn sted: ";
        cin >> forelesninger[i].sted;
        cout << "\nSkriv inn når timen starter (time minutt): ";
        cin >> forelesninger[i].timeStart >> forelesninger[i].minuttStart;
        cout << "\nSkriv inn når timen slutter (time minutt): ";
        cin >> forelesninger[i].timeSlutt >> forelesninger[i].minuttSlutt;
        cout << "\n";
    }

    // For loop som skriver ut data som er lagt inn
    for (int i = 0; i < antFore; i++)
    {
        cout << "Info om forelesning nr: " << i
             << "\nEmne: " << forelesninger[i].emne
             << "\nForeleser: " << forelesninger[i].foreleser
             << "\nSted: " << forelesninger[i].sted
             << "\nTimen starter: " << forelesninger[i].timeStart
             << ":" << forelesninger[i].minuttStart
             << "\nTimen slutter: " << forelesninger[i].timeSlutt
             << ":" << forelesninger[i].minuttSlutt << "\n\n";
    }

    return 0;
}