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
void forelesningSkrivData(const Forelesning *f);

int main()
{
    // Lager en struct array med structer "forelesninger som inneholder"
    // structen Forelesning
    Forelesning forelesninger[MAXFORELESNINGER];

    // Variabel som holder antall forelesninger
    int antFore = 0;

    // Les inn antall forelesninger
    antFore = lesTall("Skriv inn hvor mange forelesninger: ",
                          1, MAXFORELESNINGER);

    // For loop som leser inn emne, foreleser og sted
    for (int i = 0; i < antFore; i++)
    {
        cout << "\nData om forelesning nr." << i + 1 << ":\n";
        forelesningLesData(&forelesninger[i]);
    }

    // For loop som skriver ut data som er lagt inn
    for (int i = 0; i < antFore; i++)
    {
        cout << "\nInnleste data om forelesning nr." << i + 1 << ":\n";
        forelesningSkrivData(&forelesninger[i]);
    }

    return 0;
}

void forelesningLesData(Forelesning *f)
{
    cout << "Skriv inn emne: ";
    cin.getline(f->emne, STRLEN / 2);
    cout << "\nSkriv inn foreleser: ";
    cin.getline(f->foreleser, STRLEN);
    cout << "\nSkriv inn sted: ";
    cin.getline(f->sted, STRLEN / 2);
    f->timeStart = lesTall("Time-start", 8, 20);
    f->minuttStart = lesTall("Minutt-start", 0, 59);
    f->timeSlutt = lesTall("Time-slutt", f->timeStart + 1, 20);
    f->minuttSlutt = lesTall("Minutt-Slutt", 0, 59);
}
void forelesningSkrivData(const Forelesning *f)
{
    cout
        << "\nEmne: " << f->emne
        << "\nForeleser: " << f->foreleser
        << "\nSted: " << f->sted
        << "\nTimen starter: " << f->timeStart
        << ":" << f->minuttStart
        << "\nTimen slutter: " << f->timeSlutt
        << ":" << f->minuttSlutt << "\n\n";
}