#ifndef OOP_PROG_ND_PERSONALO_H
#define OOP_PROG_ND_PERSONALO_H

#include "meniu.h"
#include "darbuotojo.h"

#include "../personalas.h"

class PersonaloIvestiesMeniu : public Meniu {
protected:
    Personalas &personalas_;

public:
    explicit PersonaloIvestiesMeniu(Personalas &personalas) : personalas_(personalas) {
    }

    bool tinkamasPasirinkimas(unsigned pasirinkimas) const override {
        return pasirinkimas <= Personalas::DARBUOTOJU_KIEKIS;
    }

    void rodyti() const override {
        std::cout << "0. " << "Baigti pildyti personalą" << std::endl;
        for (unsigned i = 0; i < Personalas::DARBUOTOJU_KIEKIS; ++i) {
            bool uzpildytas = personalas_.gautiDarbuotoja(i).duomenysUzpildyti();

            std::cout << i + 1 << ". " << (uzpildytas ? "Keisti" : "Pildyti")
                      << " darbuotoją: " << personalas_.gautiDarbuotoja(i).gautiVarda() << " "
                      << personalas_.gautiDarbuotoja(i).gautiPavarde() << std::endl;
        }
    }

    void aptarnauti() override {
        unsigned meniuPasirinkimas;

        while (true) {
            meniuPasirinkimas = gautiTinkamaPasirinkima();

            if (meniuPasirinkimas != 0) {
                DarbuotojoIvestiesMeniu darbIvestiesMeniu(personalas_.gautiDarbuotoja(meniuPasirinkimas - 1));
                darbIvestiesMeniu.aptarnauti();
                continue;
            }

            if (personalas_.duomenysUzpildyti()) {
                break;
            }

            std::cout << "Prašome užpildyti likusius duomenis." << std::endl;
        }
    }
};

class PersonaloFiltravimoMeniuPagalAmziu : public Meniu {
protected:
    Personalas &personalas_;
    Darbuotojas::DuomenuPasirinkimas &spausdinimoTvarka_;

public:
    PersonaloFiltravimoMeniuPagalAmziu(Personalas &personalas, Darbuotojas::DuomenuPasirinkimas &spausdinimoTvarka)
        : personalas_(personalas), spausdinimoTvarka_(spausdinimoTvarka) {
    }

    bool tinkamasPasirinkimas(unsigned pasirinkimas) const override {
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
        unsigned meniuPasirinkimas;

        constexpr bool (*amziuGrupes[DarbuotojoAmzius::AMZIU_GRUPIU_KIEKIS])(unsigned) = {
            DarbuotojoAmzius::jaunas, DarbuotojoAmzius::vidutinis,
            DarbuotojoAmzius::pagyvenes, DarbuotojoAmzius::senyvas
        };

        meniuPasirinkimas = gautiTinkamaPasirinkima();

        if (meniuPasirinkimas == 0) {
            personalas_.spausdintiDarbuotojus(spausdinimoTvarka_);
        } else {
            personalas_.filtruotiAmziu(amziuGrupes[meniuPasirinkimas - 1], spausdinimoTvarka_);
        }
    }
};

class PersonaloFiltravimoMeniu : public Meniu {
protected:
    Personalas &personalas_;
    Darbuotojas::DuomenuPasirinkimas &spausdinimoTvarka_;

public:
    PersonaloFiltravimoMeniu(Personalas &personalas, Darbuotojas::DuomenuPasirinkimas &spausdinimoTvarka)
        : personalas_(personalas), spausdinimoTvarka_(spausdinimoTvarka) {
    }

    bool tinkamasPasirinkimas(unsigned pasirinkimas) const override {
        return pasirinkimas <= 3;
    }

    void rodyti() const override {
        std::cout << "0. Rodyti visus darbuotojus" << std::endl;
        std::cout << "1. Filtruoti pagal amžių" << std::endl;
        std::cout << "2. Filtruoti pagal patirtį" << std::endl;
        std::cout << "3. Filtruoti pagal atlyginimą" << std::endl;
    }

    void aptarnauti() override {
        constexpr Darbuotojas::DuomensPasirinkimas darbuotojoFiltrai[3] = {
            Darbuotojas::D_AMZIUS, Darbuotojas::D_PATIRTIS, Darbuotojas::D_ATLYGINIMAS
        };

        unsigned meniuPasirinkimas;

        meniuPasirinkimas = gautiTinkamaPasirinkima();

        if (meniuPasirinkimas == 0) {
            personalas_.spausdintiDarbuotojus(spausdinimoTvarka_);
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

        personalas_.filtruotiMinMax(filtras, min, max, darbuotojoFiltrai[meniuPasirinkimas - 1], spausdinimoTvarka_);
    }
};

#endif//OOP_PROG_ND_PERSONALO_H
