/**
 * Oppgave 11
 * Mer øving på klasser og objekter
 *
 * @author Richard Frøyland, NTNU
 * @file oppg11.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include "LesData2.h"
using namespace std;

class Posisjon
{
private:
    int grad, minutt, sekund;
    char retning;

public:
    Posisjon()
    {
        grad = 0;
        minutt = 0;
        sekund = 0;
        retning = 'N';
    };

    void lesData(int gr, char r1, char r2);
    void skrivData();
};

class Skip
{
private:
    int nr;
    string navn;
    Posisjon lengdegrad, breddegrad;

public:
    Skip()
    {
        nr = 0;
        navn = "";
    }

    Skip(int n, string m)
    {
        nr = n;
        navn = m;
    }

    void lesData();
    void skrivData();
};

int main()
{
    vector<Skip> ships(3);

    for (auto& ship: ships)
    {
        ship.lesData();
    }

    for (auto& ship : ships)
    {
        ship.skrivData();
    }

    return 0;
}

void Posisjon::lesData(int gr, char r1, char r2)
{
    // Les inn grad og sikre at det er innenfor gyldig omraade
    grad = lesInt("Oppgi grad: ", 0, gr);

    // Les inn minutt og sikre at det er innenfor gyldig omraade
    minutt = lesInt("Oppgi minutt: ", 0, 59);

    // Les inn sekund og sikre at det er innenfor gyldig omraade
    sekund = lesInt("Oppgi sekund: ", 0, 59);

    // Les inn retning og sikre at den er enten r1 eller r2
    do
    {
        cout << "Oppgi retning (" << r1 << "/" << r2 << "): ";
        cin >> retning;
        retning = toupper(retning);
    } while (retning != r1 && retning != r2);
}

void Posisjon::skrivData()
{
    cout << grad << "º" << minutt << "’" << sekund << "”" << retning;
}

void Skip::lesData()
{
    breddegrad.lesData(90, 'N', 'S');
    lengdegrad.lesData(180, 'E', 'W');
}

void Skip::skrivData()
{
    cout << "Skip Navn: " << navn << "\nSkip Nr: " << nr<< "\nSkip breddegrad: ";
    breddegrad.skrivData();
    cout << "\nSkip Lengdegrad: ";
    lengdegrad.skrivData();
    cout << "\n";
}