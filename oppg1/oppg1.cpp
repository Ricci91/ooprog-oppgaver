/**
 * Oppgave 1 i ooprog
 * 
 * @file oppg1.cpp
 * @author Richard Frøyland, NTNU
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int MAXLOPERE = 10; /// Max antall lopere a lese tider for

/**
 * Hovedprogrammet:
*/

int main()
{
    int distanse,           // Aktuell distanse
        ant500,             // distanse bestar av 'ant500' 500-metere
        min, sek, hundr,    // minutt, sekund og hundredeler
        antallLopere;       // antall lopere det beregnes poengsum for
    float poeng;            // poengsum pa distanse
    char brukerSvar = 'N';       // brukeronske om a gjenta hele programmet

    do
    {
        do
        {
            cout << "\nSkriv en skoytedistanse (500, 1500, 3000, 5000)";
            cin >> distanse; //leser distanse
            
        }
        while (distanse != 500 && distanse != 1500 && 
                distanse != 3000 && distanse != 5000); // gjentar til lovlig
                
        ant500 = distanse / 500;    // beregner antall 500-metere i distanse

        do 
        {
            cout << "\nAntall lopere a lese tider for (1-" << MAXLOPERE <<
                    "): ";
            cin >> antallLopere;
            
        }
        while (antallLopere < 1 || antallLopere > MAXLOPERE);


        for (int i = 1; i <= antallLopere; i++)
        {
            do
            {
                cout << "\nTid (mm, ss, hh): ";
                cin >> min >> sek >> hundr;
                
                
            }
            while (min < 0 || sek < 0 || hundr < 0);

            poeng = ((min*60) + sek + (hundr/100.0)) / ant500;
            cout << "\tPoengsum: " << fixed << setprecision(3) <<  poeng;
        }

        cout << "\n\nLese tider om en ny disantse (j/N):    ";
        
        cin >> brukerSvar;
        brukerSvar = toupper(brukerSvar);
        
        
        
    }
    while (brukerSvar == 'J');


    return 0;
}