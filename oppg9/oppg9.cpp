/**
 * OPPG 9
 *
 * @author Richard Frøyland, NTNU
 * @file oppg9.cpp
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "LesData2.h"
using namespace std;

// Class Dato
class Dato
{
private:
    int dag, maaned, aar; // Dato inter

public:
    Dato() // Parameterløs constructor:
    {
        dag = 1;
        maaned = 1;
        aar = 2000;
    }

    Dato(int d, int m, int a) // Setter alle datamedlemmer
    {
        dag = d;
        maaned = m;
        aar = a;
    }

    void lesData() // Leser ALLE datamedlemmer
    {
        dag = lesInt("Dag", 1, 30);
        maaned = lesInt("Maaned", 1, 12);
        aar = lesInt("Aar", 2000, 2200);
    }

    void skrivData() // Skriver ALLE datamedlemmer
    {
        cout << setfill('0') << setw(2) << dag
             << "/" << setw(2) << maaned << "/" << aar;
    }

    bool sammeAar(const Dato &dato) // Sjekker om eget aar er samme som klassens
    {
        return this->aar == dato.aar;
    }

    bool sammeAarsdag(const Dato &dato) // Er dag i året det samme som klassens
    {
        return this->dag == dato.dag && this->maaned == dato.maaned;
    }

    bool tidligereEnn(const Dato &dato) // Er egen dato tidligere enn klassens
    {
        if (this->aar < dato.aar)
        {
            return true;
        }
        else if (this->aar == dato.aar)
        {
            if (this->maaned < dato.maaned)
            {
                return true;
            }
            else if (this->maaned == dato.maaned && this->dag < dato.dag)
            {
                return true;
            }
        }

        return false;
    }




};

    int main()
    {
        Dato dato1(8, 2, 2001),
             dato2;

        dato2.lesData();

        cout << "\nDato nr.1:\n";
        dato1.skrivData();

        cout << "\nDato nr.2:\n";
        dato2.skrivData();

        cout << "\nEr dato nr. 1 mindre enn dato nr. 2?\n";
        if (dato1.tidligereEnn(dato2))
        {
            cout << "\nJa.\n";
        }
        else
        {
            cout << "\nNei\n";
        }

        return 0;
    }