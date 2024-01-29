/**
 * Oppgave 2 i OOPROG
 *
 * @file oppg2.cpp
 * @author Richard Froyland, NTNU
 */

#include <iostream>
#include <iomanip>

using namespace std;

const int MINTEMP = -70;
const int MAXTEMP = 70;
const int MAXNEDBOR = 200;
const int MINDAGER = 5;
const int MAXDAGER = 31;

/**
 * Hovedprogrammet:
 */

int main()
{
    char svar;
    int antDager,
        min,
        max,
        nedbor,
        totMin,
        totMax,
        totNedbor;

    cout << "\nLese inn vardata for en maned (J/n): ";
    cin >> svar;

    while (svar != 'N' && svar != 'n')
    {
        do
        {
            cout << "Antall dager i maneden (" << MINDAGER << "-" << MAXDAGER << ")";
            cin >> antDager; 

        } while (antDager < MINDAGER || antDager > MAXDAGER);

        for (int i = 0; i < antDager; i++)
        {
            cout << "\nDag nr." << setw(2) << i + 1 << ":\n";

            do
            {
                cout << "\tMinustemp (" << setw(2) << MINTEMP << " til " << MAXTEMP << "): ";
                cin >> min;
            } while (min < MINTEMP || min > MAXTEMP);

            do
            {
                cout << "\tMaksimumstemp (" << setw(2) << min << " til " << MAXTEMP << "): ";
                cin >> max;
            } while (min < MINTEMP || max > MAXTEMP);

            do
            {
                cout << "Nedbor (0 til " << MAXNEDBOR << "):";
                cin >> nedbor;
            } while (nedbor < 0 || nedbor > MAXNEDBOR);
        }
        totMin = totMax = totNedbor = 0;

        cout << "\n\nGjennomsnittling min.temp: " << fixed << setprecision(2) << static_cast<float>(totMin) / antDager << "grader C\n";

        cout << "Gjennomsnittlig max.temp: " << fixed << setprecision(2) << static_cast<float>(totMax) / antDager << "grader C\n";

        cout << "Gjennomsnittlig nedbor: " << fixed << setprecision(2) << static_cast<float>(totNedbor) / antDager << "mm\n";

        cout << "\nLese in vaerdata for en maned til? (J/n): ";
        cin >> svar;
    }

    cout << "\n\n\nHa en fortsatt god dag!\n\n";
    return 0;
}