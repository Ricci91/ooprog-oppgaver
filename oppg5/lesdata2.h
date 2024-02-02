// lesdata2.h

#ifndef LESDATA2_H
#define LESDATA2_H

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

const int MAXCHAR = 200;


int lesTall(const char* t, const int min, const int max);



/**
 * Leser og returnerer et heltall mellom to gitte grenser
 * 
 * @param t - ber bruker om input
 * @param min - minimum godtatt tall
 * @param max - max godtatt tall
 * 
 * @return Godtatt verdi i intervallet min og max
*/
inline int lesTall(const char* t, const int min, const int max)
{
    char buffer[MAXCHAR] = "";
    int tall;
    bool feil = false;
    do
    {
        feil = false;
        std::cout << "\t" << t << " (" << std::setw(2) << min << " - " << 
        std::setw(2) << max << ")    ";
        std::cin.getline(buffer, MAXCHAR);
        tall = atoi(buffer);
        if (tall == 0 && buffer[0] != '0')
        {
            feil = true; std::cout << "\nERROR: Not an integer!\n\n";
        }
    }    
    while (feil || tall < min || tall > max);
    return tall;
}

#endif // LESDATA2_H