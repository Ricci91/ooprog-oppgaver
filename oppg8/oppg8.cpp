/**
 * Oppgave 8
Lag et program som inneholder:
• struct Kamp med string’ene hjemmeNavn og borteNavn og int’ene
hjemmeMaal og borteMaal.
• den (initielt tomme) globale vector’en gKampene, med pekere til kamper
• main som:
o lager nye kamper og legger disse inn i gKampene, så lenge brukeren ønsker.
Hver kamp sine data leses inn vha. funksjonen:
void kampLesData(Kamp & kamp)
o skriver ut alle de lagrede kampene sine data, bl.a. vha. funksjonen:
void kampSkrivData(const Kamp* kamp)
o til slutt sletter alle kampene tilpekt og pekerne lagret i gKampene

*@author Richard Frøyland, NTNU
*@file oppg8.cpp
*/

#include <iostream>
#include <string>
#include "LesData2.h"

using namespace std;

struct Kamp
{
    string hjemmeNavn, borteNavn;
    int hjemmeMaal, borteMaal;
};

void kampLesData(Kamp & kamp);
void kampSkrivData(Kamp * kamp);

vector <Kamp*> gKampene;

int main()
{
    char keepRunning = 'y';

    while (keepRunning == 'y')
    {
       Kamp* newKamp = new Kamp(); //Alloker ny kamp i minnet

       kampLesData(*newKamp); //Les data inn i kamp

       gKampene.push_back(newKamp); //Add pointer til vector

       cout << "Vil du legge inn en til kamp? (y/n)";
       cin >> keepRunning;
       cin.ignore(); //Ignorer newline
    }

    //Iterer over gKampene for å printe data
    for (Kamp* k : gKampene)
    {
        kampSkrivData(k);
    }

    //Rydd opp dynamisk allokerte Kamp objekt
    for (Kamp* k : gKampene)
    {
        delete k;
    }

    gKampene.clear();

    return 0;
}


void kampLesData(Kamp & kamp)
{
    cout << "Skriv inn Hjemmenavn:";
    getline(cin, kamp.hjemmeNavn);

    cout << "Skriv inn Bortenavn:";
    getline(cin, kamp.borteNavn);

    kamp.hjemmeMaal = lesInt("Skriv inn antall Hjemmemaal: ", 0, 99);

    kamp.borteMaal = lesInt("Skriv inn antall Bortemaal: ", 0, 99);
}

void kampSkrivData(Kamp * kamp)
{
    cout << kamp->hjemmeNavn << " : " << kamp->hjemmeMaal << "\n";
    cout << kamp->borteNavn << " : " << kamp->borteMaal << "\n";
}