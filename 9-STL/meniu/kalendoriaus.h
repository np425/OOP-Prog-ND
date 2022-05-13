//
// Created by nerpo on 2022-05-13.
//

#ifndef OOP_PROG_ND_KALENDORIAUS_H
#define OOP_PROG_ND_KALENDORIAUS_H

#include "meniu.h"
#include "../kalendorius.h"

#define LINE "-----------------------"

class UzduotiesMeniu : public Meniu {
    UzduociuSarasas &uzduociuSarasas_;
    UzduociuSarasas::iterator &uzduotis_;

public:
    explicit UzduotiesMeniu(UzduociuSarasas &uzduociuSarasas, UzduociuSarasas::iterator &uzduotis) : uzduociuSarasas_(
        uzduociuSarasas), uzduotis_(uzduotis) {
    }

    bool tinkamasPasirinkimas(unsigned int pasirinkimas) const override {
        return pasirinkimas <= 3;
    }

    void rodyti() const override {
        std::cout << "0. Grįžti" << std::endl;
        std::cout << "1. Keisti aprašą" << std::endl;
        std::cout << "2. Pažymėti/Atžymėti kaip pabaigtą" << std::endl;
        std::cout << "3. Šalinti" << std::endl;
    }

    void keistiAprasa() {
        std::string aprasas;

        std::cout << "Įveskite naują aprašą:" << std::endl;
        std::getline(std::cin, aprasas);

        uzduotis_->aprasas = aprasas;
    }

    void aptarnauti() override {
        unsigned meniuPasirinkimas;

        do {
            meniuPasirinkimas = gautiTinkamaPasirinkima();

            switch (meniuPasirinkimas) {
                case 0:
                    break;
                case 1:
                    keistiAprasa();
                    break;
                case 2:
                    uzduotis_->baigta = !uzduotis_->baigta;
                    break;
                case 3:
                    uzduotis_ = uzduociuSarasas_.erase(uzduotis_);
                    break;
                default:
                    break;
            }
        } while (meniuPasirinkimas != 0 && meniuPasirinkimas != 3);
    }
};

class DienosMeniu : public Meniu {
    UzduociuSarasas &dienosUzduotys_;

public:
    explicit DienosMeniu(UzduociuSarasas &dienosUzduotys) : dienosUzduotys_(dienosUzduotys) {
    }

    bool tinkamasPasirinkimas(unsigned int pasirinkimas) const override {
        return pasirinkimas <= dienosUzduotys_.size() + 1;
    }

    void rodyti() const override {
        std::cout << "0. Grįžti" << std::endl;
        std::cout << "1. Nauja Užduotis" << std::endl;

        unsigned i = 2;

        if (dienosUzduotys_.empty()) {
            return;
        }

        std::cout << LINE << std::endl;
        for (auto const &uzduotis: dienosUzduotys_) {
            std::cout << i++ << ". [" << (uzduotis.baigta ? "x" : "-") << "] ";
            std::cout << uzduotis.aprasas << std::endl;
        }
    }

    void pridetiNaujaUzduoti() {
        Uzduotis uzduotis;

        std::cout << "Įveskite naujos užduoties aprašą: " << std::endl;
        std::getline(std::cin, uzduotis.aprasas);

        dienosUzduotys_.insert(dienosUzduotys_.begin(), uzduotis);
    }

    void aptarnauti() override {
        while (true) {
            unsigned meniuPasirinkimas = gautiTinkamaPasirinkima();

            if (meniuPasirinkimas == 0) {
                break;
            }

            if (meniuPasirinkimas == 1) {
                pridetiNaujaUzduoti();
                continue;
            }

            auto it = dienosUzduotys_.begin();
            std::advance(it, meniuPasirinkimas - 2);
            UzduotiesMeniu(dienosUzduotys_, it).aptarnauti();
        }
    }
};

#endif //OOP_PROG_ND_KALENDORIAUS_H
