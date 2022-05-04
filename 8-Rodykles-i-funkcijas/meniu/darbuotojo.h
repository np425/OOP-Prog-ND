#ifndef OOP_PROG_ND_DARBUOTOJO_H
#define OOP_PROG_ND_DARBUOTOJO_H

#include "meniu.h"

class DarbuotojoIvestiesMeniu : public Meniu {
protected:
    Darbuotojas &mDarb;

public:
    explicit DarbuotojoIvestiesMeniu(Darbuotojas &darb) : mDarb(darb) {
    }

    bool tinkamasPasirinkimas(unsigned pasirinkimas) override {
        return pasirinkimas <= Darbuotojas::DuomenuKiekis;
    }

    void rodyti() const override {
        std::cout << "Darbuotojo duomenys: " << std::endl;

        std::cout << "0. " << "Baigti įvedimą" << std::endl;
        std::cout << "1. " << (!mDarb.gautiVarda().empty() ? "Keisti" : "Įrašyti") << " vardą: " << mDarb.gautiVarda()
                  << std::endl;
        std::cout << "2. " << (!mDarb.gautiPavarde().empty() ? "Keisti" : "Įrašyti") << " pavardę: "
                  << mDarb.gautiPavarde() << std::endl;
        std::cout << "3. " << (!mDarb.gautiSpecialybe().empty() ? "Keisti" : "Įrašyti") << " specialybę: "
                  << mDarb.gautiSpecialybe() << std::endl;
        std::cout << "4. " << (mDarb.gautiAmziu() ? "Keisti" : "Įrašyti") << " amžių: " << mDarb.gautiAmziu()
                  << std::endl;
        std::cout << "5. " << (mDarb.gautiPatirti() ? "Keisti" : "Įrašyti") << " patirtį: " << mDarb.gautiPatirti()
                  << std::endl;
        std::cout << "6. " << (mDarb.gautiAtlyginima() ? "Keisti" : "Įrašyti") << " atlyginimą: "
                  << mDarb.gautiAtlyginima() << std::endl;
    }

    void aptarnauti() override {
        int meniuAts;

        while (true) {
            meniuAts = gautiPasirinkima();

            if (meniuAts != 0) {
                // -1, kadangi pirmas pasirinkimas prasideda nuo 0
                mDarb.keistiPasirinkima((Darbuotojas::DuomensPasirinkimas) (meniuAts - 1));
                continue;
            }

            if (mDarb.duomenysUzpildyti()) {
                break;
            }

            std::cout << "Prašome užpildyti likusius duomenis." << std::endl;
        }
    }
};

class DarbuotojoDuomenuTvarkosSpausdinimoMeniu : public Meniu {
protected:
    Darbuotojas::DuomenuPasirinkimas &mSpausdinimoTvarka;

    void apkeistiPasirinkimoTvarka(int kaNr) {
        unsigned suKuoNr;

        while (true) {
            std::cout << "Iveskite su kuriuo numeriu apkeisti: ";
            std::cin >> suKuoNr;

            if (suKuoNr > 0 && suKuoNr <= Darbuotojas::DuomenuKiekis) {
                break;
            }

            std::cout << "Nesupratau pasirinkimo, prašome pakartoti įvestį." << std::endl;
        }

        // -1, kadangi pirmas pasirinkimas prasideda nuo 0
        kaNr = kaNr - 1;
        suKuoNr = suKuoNr - 1;

        std::swap((int &) (mSpausdinimoTvarka[kaNr]), (int &) (mSpausdinimoTvarka[suKuoNr]));
    }

public:
    // Be & ?
    explicit DarbuotojoDuomenuTvarkosSpausdinimoMeniu(Darbuotojas::DuomenuPasirinkimas &spausdinimoTvarka)
        : mSpausdinimoTvarka(spausdinimoTvarka) {
    }

    bool tinkamasPasirinkimas(unsigned pasirinkimas) override {
        return pasirinkimas <= Darbuotojas::DuomenuKiekis;
    }

    void rodyti() const override {
        std::cout << "0. " << "Išsaugoti spausdinimo tvarką" << std::endl;
        std::cout << "   Spausdinimo eilės tvarka: (pasirinkti numerį, kad apkeisti)" << std::endl;
        for (unsigned i = 0; i < Darbuotojas::DuomenuKiekis; ++i) {
            std::cout << i + 1 << ". " << Darbuotojas::DuomenuPasirinkimoPav[mSpausdinimoTvarka[i]] << std::endl;
        }
    }

    void aptarnauti() override {
        int meniuAts;

        while (true) {
            meniuAts = gautiPasirinkima();

            if (meniuAts == 0) {
                break;
            }

            apkeistiPasirinkimoTvarka(meniuAts);
        }
    }
};

#endif//OOP_PROG_ND_DARBUOTOJO_H
