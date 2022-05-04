#ifndef OOP_PROG_ND_PERSONALO_H
#define OOP_PROG_ND_PERSONALO_H

#include "meniu.h"
#include "darbuotojo.h"

class PersonaloIvestiesMeniu : public Meniu {
protected:
    Personalas &mPersonalas;

public:
    explicit PersonaloIvestiesMeniu(Personalas &personalas) : mPersonalas(personalas) {
    }

    bool tinkamasPasirinkimas(unsigned pasirinkimas) override {
        return pasirinkimas <= Personalas::DARBUOTOJU_KIEKIS;
    }

    void rodyti() const override {
        std::cout << "0. " << "Baigti pildyti personalą" << std::endl;
        for (unsigned i = 0; i < Personalas::DARBUOTOJU_KIEKIS; ++i) {
            bool uzpildytas = mPersonalas.gautiDarbuotoja(i).duomenysUzpildyti();

            std::cout << i + 1 << ". " << (uzpildytas ? "Keisti" : "Pildyti")
                      << " darbuotoją: " << mPersonalas.gautiDarbuotoja(i).gautiVarda() << " "
                      << mPersonalas.gautiDarbuotoja(i).gautiPavarde() << std::endl;
        }
    }

    void aptarnauti() override {
        int meniuAts;

        while (true) {
            meniuAts = gautiPasirinkima();

            if (meniuAts != 0) {
                DarbuotojoIvestiesMeniu darbIvestiesMeniu(mPersonalas.gautiDarbuotoja(meniuAts - 1));
                darbIvestiesMeniu.aptarnauti();
                continue;
            }

            if (mPersonalas.duomenysUzpildyti()) {
                break;
            }

            std::cout << "Prašome užpildyti likusius duomenis." << std::endl;
        }
    }
};

class PersonaloFiltravimoMeniuPagalAmziu : public Meniu {
protected:
    Personalas &mPersonalas;
    Darbuotojas::DuomenuPasirinkimas &mSpausdinimoTvarka;

public:
    PersonaloFiltravimoMeniuPagalAmziu(Personalas &personalas, Darbuotojas::DuomenuPasirinkimas &spausdinimoTvarka)
        : mPersonalas(personalas), mSpausdinimoTvarka(spausdinimoTvarka) {
    }

    bool tinkamasPasirinkimas(unsigned pasirinkimas) override {
        return pasirinkimas <= DarbuotojoAmzius::AMZIU_GRUPIU_KIEKIS;
    }

    void rodyti() const override {
        std::cout << "0. Rodyti visus darbuotojus" << std::endl;
        std::cout << "1. Filtruoti jauno (18-30) amžiaus darbuotojus" << std::endl;
        std::cout << "2. Filtruoti vidutinio (31-50) amžiaus darbuotojus" << std::endl;
        std::cout << "3. Filtruoti pagyvenusio (51-70) amžiaus darbuotojus" << std::endl;
        std::cout << "4. Filtruoti senyvo (71+) amžiaus darbuotojus" << std::endl;
    }

    void aptarnauti() override {
        int meniuAts;

        constexpr bool (*amziuGrupes[DarbuotojoAmzius::AMZIU_GRUPIU_KIEKIS])(unsigned) = {
            DarbuotojoAmzius::jaunas, DarbuotojoAmzius::vidutinis,
            DarbuotojoAmzius::pagyvenes, DarbuotojoAmzius::senyvas
        };

        meniuAts = gautiPasirinkima();

        if (meniuAts == 0) {
            mPersonalas.spausdintiDarbuotojus(mSpausdinimoTvarka);
        } else {
            mPersonalas.filtruotiAmziu(amziuGrupes[meniuAts - 1], mSpausdinimoTvarka);
        }
    }
};

class PersonaloFiltravimoMeniu : public Meniu {
protected:
    Personalas &mPersonalas;
    Darbuotojas::DuomenuPasirinkimas &mSpausdinimoTvarka;

public:
    PersonaloFiltravimoMeniu(Personalas &personalas, Darbuotojas::DuomenuPasirinkimas &spausdinimoTvarka)
        : mPersonalas(personalas), mSpausdinimoTvarka(spausdinimoTvarka) {
    }

    bool tinkamasPasirinkimas(unsigned pasirinkimas) override {
        return pasirinkimas <= 3;
    }

    void rodyti() const override {
        std::cout << "0. Rodyti visus darbuotojus" << std::endl;
        std::cout << "1. Filtruoti pagal amžių" << std::endl;
        std::cout << "2. Filtruoti pagal patirtį" << std::endl;
        std::cout << "3. Filtruoti pagal atlyginimą" << std::endl;
    }

    void aptarnauti() override {
        constexpr Darbuotojas::DuomensPasirinkimas darbFiltrai[3] = {
            Darbuotojas::D_AMZIUS, Darbuotojas::D_PATIRTIS, Darbuotojas::D_ATLYGINIMAS
        };

        int meniuAts;

        meniuAts = gautiPasirinkima();

        if (meniuAts == 0) {
            mPersonalas.spausdintiDarbuotojus(mSpausdinimoTvarka);
            return;
        }

        unsigned min, max;

        std::cout << "Minimali reikšmė: ";
        std::cin >> min;

        std::cout << "Maksimali reikšmė: ";
        std::cin >> max;

        auto filtras = [](unsigned reiksme, unsigned min, unsigned max) {
            return reiksme >= min && reiksme <= max;
        };

        mPersonalas.filtruotiMinMax(filtras, min, max, darbFiltrai[meniuAts - 1], mSpausdinimoTvarka);
    }
};

#include "meniu.h"

#endif//OOP_PROG_ND_PERSONALO_H
