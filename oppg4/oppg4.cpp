/*
 * Oppgave 4 ooprog
 *
 * Lag et program som inneholder en struct Tid med int-datamedlemmene time,
    minutt og sekund. Lag også funksjonen:
    struct Tid storst(const struct Tid tid1, const struct Tid tid2)
    som finner ut hvilken av de to parametrene som er størst/senest/høyest, og returnerer denne.
    Lag (i main) også fire Tid-variable som initieres til noen passende/ønskede verdier.
    Programmet skal så finne ut (vha. storst(…)) hvilken av de fire structene som totalt er
    størst/senest/høyest, og skrive så til slutt ut (på skjermen) dennes datamedlemmer.

 */

#include <iostream>

using namespace std;

struct Tid
{
    int time, minutt, sekund;
};

struct Tid storst(const struct Tid tid1, const struct Tid tid2);

int main()
{
    Tid nr1, nr2, nr3, nr4;

    nr1.time = 1;
    nr1.minutt= 1;
    nr1.sekund = 1;

    nr2.time = 2;
    nr2.minutt = 2;
    nr2.sekund = 2;

    nr3.time = 3;
    nr3.minutt = 3;
    nr3.sekund = 3;

    nr4.time = 4;
    nr4.minutt = 4;
    nr4.sekund = 4;

    return 0;
}

struct Tid storst(const struct Tid tid1, const struct Tid tid2)
{
    if (tid1.time > tid2.time)
    {
        return tid1;
    }
    else if (tid1.time == tid2.time)
    {
        if (tid1.minutt > tid2.minutt)
        {
            return tid1;
        }
    }
    else if (tid1.minutt == tid2.minutt)
    {
        if (tid1.sekund > tid2.sekund)
        {
            return tid1;
        }
    }
    return tid2;
}