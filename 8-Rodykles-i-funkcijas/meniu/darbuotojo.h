#ifndef OOP_PROG_ND_DARBUOTOJO_H
#define OOP_PROG_ND_DARBUOTOJO_H

#include "meniu.h"
#include "../darbuotojas.h"

class DarbuotojoIvestiesMeniu : public Meniu {
protected:
    Darbuotojas &darbuotojas_;

public:
    explicit DarbuotojoIvestiesMeniu(Darbuotojas &darb) : darbuotojas_(darb) {
    }

    bool tinkamasPasirinkimas(unsigned pasirinkimas) override {
        return pasirinkimas <= Darbuotojas::DUOMENU_KIEKIS;
    }

    void rodyti() const override {
        std::cout << "Darbuotojo duomenys: " << std::endl;

        std::cout << "0. " << "Baigti įvedimą" << std::endl;
        std::cout << "1. " << (!darbuotojas_.gautiVarda().empty() ? "Keisti" : "Įrašyti") << " vardą: " << darbuotojas_.gautiVarda()
                  << std::endl;
        std::cout << "2. " << (!darbuotojas_.gautiPavarde().empty() ? "Keisti" : "Įrašyti") << " pavardę: "
                  << darbuotojas_.gautiPavarde() << std::endl;
        std::cout << "3. " << (!darbuotojas_.gautiSpecialybe().empty() ? "Keisti" : "Įrašyti") << " specialybę: "
                  << darbuotojas_.gautiSpecialybe() << std::endl;
        std::cout << "4. " << (darbuotojas_.gautiAmziu() ? "Keisti" : "Įrašyti") << " amžių: " << darbuotojas_.gautiAmziu()
                  << std::endl;
        std::cout << "5. " << (darbuotojas_.gautiPatirti() ? "Keisti" : "Įrašyti") << " patirtį: " << darbuotojas_.gautiPatirti()
                  << std::endl;
        std::cout << "6. " << (darbuotojas_.gautiAtlyginima() ? "Keisti" : "Įrašyti") << " atlyginimą: "
                  << darbuotojas_.gautiAtlyginima() << std::endl;
    }

    void aptarnauti() override {
        int meniuPasirinkimas;

        while (true) {
            meniuPasirinkimas = gautiPasirinkima();

            if (meniuPasirinkimas != 0) {
                // -1, kadangi pirmas pasirinkimas prasideda nuo 0
                darbuotojas_.keistiPasirinkima((Darbuotojas::DuomensPasirinkimas) (meniuPasirinkimas - 1));
                continue;
            }

            if (darbuotojas_.duomenysUzpildyti()) {
                break;
            }

            std::cout << "Prašome užpildyti likusius duomenis." << std::endl;
        }
    }
};

class DarbuotojoDuomenuTvarkosSpausdinimoMeniu : public Meniu {
protected:
    Darbuotojas::DuomenuPasirinkimas &spausdinimoTvarka_;

    void apkeistiPasirinkimoTvarka(int kaNr) {
        unsigned suKuoNr;

        while (true) {
            std::cout << "Iveskite su kuriuo numeriu apkeisti: ";
            std::cin >> suKuoNr;

            if (suKuoNr > 0 && suKuoNr <= Darbuotojas::DUOMENU_KIEKIS) {
                break;
            }

            std::cout << "Nesupratau pasirinkimo, prašome pakartoti įvestį." << std::endl;
        }

        // -1, kadangi pirmas pasirinkimas prasideda nuo 0
        kaNr = kaNr - 1;
        suKuoNr = suKuoNr - 1;

        std::swap((int &) (spausdinimoTvarka_[kaNr]), (int &) (spausdinimoTvarka_[suKuoNr]));
    }

public:
    // Be & ?
    explicit DarbuotojoDuomenuTvarkosSpausdinimoMeniu(Darbuotojas::DuomenuPasirinkimas &spausdinimoTvarka)
        : spausdinimoTvarka_(spausdinimoTvarka) {
    }

    bool tinkamasPasirinkimas(unsigned pasirinkimas) override {
        return pasirinkimas <= Darbuotojas::DUOMENU_KIEKIS;
    }

    void rodyti() const override {
        std::cout << "0. " << "Išsaugoti spausdinimo tvarką" << std::endl;
        std::cout << "   Spausdinimo eilės tvarka: (pasirinkti numerį, kad apkeisti)" << std::endl;
        for (unsigned i = 0; i < Darbuotojas::DUOMENU_KIEKIS; ++i) {
            std::cout << i + 1 << ". " << Darbuotojas::DuomenuPasirinkimoPavadinimas[spausdinimoTvarka_[i]] << std::endl;
        }
    }

    void aptarnauti() override {
        int meniuPasirinkimas;

        while (true) {
            meniuPasirinkimas = gautiPasirinkima();

            if (meniuPasirinkimas == 0) {
                break;
            }

            apkeistiPasirinkimoTvarka(meniuPasirinkimas);
        }
    }
};

#endif//OOP_PROG_ND_DARBUOTOJO_H
