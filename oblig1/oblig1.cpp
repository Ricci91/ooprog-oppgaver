/**
 *  OOPROG OBLIG 1
 *  
 *  Program som leser inn, lagrer og skriver ut info om restauranter
 *  
 * @author Richard Frøyland, NTNU
 * @file oblig1.cpp
*/

//Includes
#include <iostream>
#include <string>
#include <iomanip>
#include "LesData2.h"

using namespace std;

//Struct Restaurant
    //String navn, adresse, type, omtale
    //Int terningkast 1-6

struct Restaurant
{
    string navn, //Navn på restaurant
           adresse, //Gateadresse til restaurant
           type, //Type restaurant (indisk, thai osv)
           omtale; //Lengre omtale av restaurant
    int terningkast;  //Karakter 1-6
};

void nyRestaurant();
void restaurantLesData(Restaurant & restaurant);
void restaurantSkrivData(const Restaurant* restaurant);
void skrivAlleRestauranter();
void skrivMeny();
void slettAlt();

vector <Restaurant*> gRestauranter; 

/**
 * Hovedprogrammet:
*/

int main ()
{
    char kommando;

    skrivMeny();

    kommando = lesChar("\nKommando");

    while (kommando != 'Q')
    {
        switch(kommando)
        {
            case 'N': nyRestaurant();           break;
            case 'S': skrivAlleRestauranter();  break;
            default: skrivMeny();               break;
        }
        skrivMeny();
        kommando = lesChar("\nKommando");
    }

    cout << "\nTakk for at du brukte programmet!"
         << "\n\nDu skrev inn følgende restauranter:\n\n";
    
    skrivAlleRestauranter();

    slettAlt();

    return 0;
}

/**
 * Ny restaurant legges inn i strukturen (vectoren 'gRestauranter)
 * 
 * @see bokLesData(...)
*/
void nyRestaurant()
{
    Restaurant* nyRestaurant = new Restaurant; //Oppretter ny restaurant
    cout << "\nNy restaurant:\n";
    restaurantLesData(*nyRestaurant); //All data leses inn
    gRestauranter.push_back(nyRestaurant); //Legges bakerst i vector
    cout << "\n\tNy restaurant som er lagt inn har nummer: "
         << gRestauranter.size() << "\n";
}

/**
 * Leser inn og fyller alle en Restaurant sine datamedlemmer
 * 
 * @param restaurant - Structen som får datamedlemmer innlest
*/
void restaurantLesData(Restaurant & restaurant)
{
    cout << "\tNavn:    ";      getline(cin, restaurant.navn);
    cout << "\tAdresse:     ";  getline(cin, restaurant.adresse);
    cout << "\tType:    ";      getline(cin, restaurant.type);
    cout << "\tOmtale:  ";      getline(cin, restaurant.omtale);
    restaurant.terningkast = lesInt("\tTerningkast: ", 1, 6);
}

/**
 * Funksjon som skriver alle restaurantdata
 * 
 * @param resaturant - Structen med info om restaurantene
*/
void restaurantSkrivData(const Restaurant* restaurant)
{
    cout << "\t" << restaurant->navn << "\n"
         << "-----------------------------------\n"
         << "Adresse: " << restaurant->adresse << "\n"
         << "Type mat: " << restaurant->type << "\n"
         << "Omtale: " << restaurant->omtale << "\n"
         << "Terningkast: " << restaurant->terningkast << "\n\n\n";
}

/**
 * Funksjon som skriver alle restaurantene
 * 
 * @see restaurantSkrivData(const Restaurant* restaurant)
*/
void skrivAlleRestauranter()
{
    for (int i = 0; i < gRestauranter.size(); i++)
    {
        cout << "Restaurant nr." << setw(2) << i+1 << ":";
        restaurantSkrivData(gRestauranter[i]);
    }
}

/**
 * Skriver programmets menyvalg på skjermen
*/
void skrivMeny()
{
    cout << "\nFølgede kommandoer er tilgjengelig:\n"
         << "\tN - Legg til ny restaurant\n"
         << "\tS - Skriv ut alle restauranter med info\n"
         << "\tQ - Avslutt program\n";
}

/**
 * Sletter alle tilpekte structer og pekere i vector
*/
void slettAlt()
{
    //Fjerner alt i vectoren
    while (!gRestauranter.empty()) //Så lenge det er pekere i vectoren
    {
        delete gRestauranter[gRestauranter.size()-1]; //Sletter siste tilpekte
        gRestauranter.pop_back(); //Sletter selve pekeren
    }

    cout << "\n\nVectoren er tom - antallet er: " << gRestauranter.size()
         << "\n\n";
}