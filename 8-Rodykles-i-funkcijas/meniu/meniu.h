#ifndef OOP_PROG_ND_MENIU_H
#define OOP_PROG_ND_MENIU_H

#include <iostream>

class Meniu {
public:
    virtual bool tinkamasPasirinkimas(unsigned pasirinkimas) = 0;

    virtual void rodyti() const = 0;

    virtual int gautiPasirinkima() {
        while (true) {
            rodyti();

            int meniuPasirinkimas;
            std::cout << "Įveskite pasirinkimo numerį: ";
            std::cin >> meniuPasirinkimas;

            if (tinkamasPasirinkimas(meniuPasirinkimas)) {
                return meniuPasirinkimas;
            }

            std::cout << "Nesupratau pasirinkimo, prašome pakartoti įvestį." << std::endl;
        }
    }

    virtual void aptarnauti() = 0;
};

#endif//OOP_PROG_ND_MENIU_H
