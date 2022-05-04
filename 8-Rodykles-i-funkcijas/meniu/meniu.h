#ifndef OOP_PROG_ND_MENIU_H
#define OOP_PROG_ND_MENIU_H

#include <iostream>

#include "../darbuotojas.h"
#include "../personalas.h"

class Meniu {
public:
    virtual bool tinkamasPasirinkimas(unsigned pasirinkimas) = 0;

    virtual void rodyti() const = 0;

    virtual int gautiPasirinkima() {
        while (true) {
            rodyti();

            int ats;
            std::cout << "Įveskite pasirinkimo numerį: ";
            std::cin >> ats;

            if (tinkamasPasirinkimas(ats)) {
                return ats;
            }

            std::cout << "Nesupratau pasirinkimo, prašome pakartoti įvestį." << std::endl;
        }
    }

    virtual void aptarnauti() = 0;
};

#endif//OOP_PROG_ND_MENIU_H
