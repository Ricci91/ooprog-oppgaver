// lesdata2.h

#ifndef LESDATA2_H
#define LESDATA2_H

#include <iostream>
#include <iomanip>



/**
 * Leser og returnerer et heltall mellom to gitte grenser
 * 
 * @param t - ber bruker om input
 * @param min - minimum godtatt tall
 * @param max - max godtatt tall
 * 
 * @return Godtatt verdi i intervallet min og max
*/
inline int lesTall(const char t[], const int min, const int max)
{
    int tall;
    do
    {
        std::cout << "\t" << t << " (" << std::setw(2) << min << " - " << 
        std::setw(2) << max << ")    ";
        std::cin >> tall; 
    }    
    while (tall < min || tall > max);
    return tall;
}

#endif // LESDATA2_H