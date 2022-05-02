#ifndef MENIU_H
#define MENIU_H

#include <cstring>
#include <iostream>

#include "darbuotojas.h"
#include "personalas.h"

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

class DarbuotojoIvestiesMeniu : public Meniu {
protected:
    Darbuotojas& mDarb;

public:
    DarbuotojoIvestiesMeniu(Darbuotojas& darb) : mDarb(darb) {
    }

    virtual bool tinkamasPasirinkimas(unsigned pasirinkimas) {
        return pasirinkimas <= Darbuotojas::DuomenuKiekis; 
    }

    virtual void rodyti() const {
        std::cout << "Darbuotojo duomenys: " << std::endl;

        std::cout << "0. " << "Baigti įvedimą" << std::endl;
        std::cout << "1. " << (!mDarb.gautiVarda().empty() ? "Keisti" : "Įrašyti") << " vardą: "  << mDarb.gautiVarda() << std::endl;
        std::cout << "2. " << (!mDarb.gautiPavarde().empty() ? "Keisti" : "Įrašyti") << " pavardę: "  << mDarb.gautiPavarde() << std::endl;
        std::cout << "3. " << (!mDarb.gautiSpecialybe().empty() ? "Keisti" : "Įrašyti") << " specialybę: " 
                                         << mDarb.gautiSpecialybe() << std::endl;
        std::cout << "4. " << (mDarb.gautiAmziu() ? "Keisti" : "Įrašyti") << " amžių: " << mDarb.gautiAmziu() << std::endl;
        std::cout << "5. " << (mDarb.gautiPatirti() ? "Keisti" : "Įrašyti") << " patirtį: " << mDarb.gautiPatirti() << std::endl;
        std::cout << "6. " << (mDarb.gautiAtlyginima() ? "Keisti" : "Įrašyti") << " atlyginimą: " 
                                                     << mDarb.gautiAtlyginima() << std::endl;
    }

    virtual void aptarnauti() {
        int meniuAts;

        while (true) {
            meniuAts = gautiPasirinkima();

            if (meniuAts != 0) {
                // -1, kadangi pirmas pasirinkimas prasideda nuo 0
                mDarb.keistiPasirinkima((Darbuotojas::DuomensPasirinkimas)(meniuAts - 1));
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
    Darbuotojas::DuomenuPasirinkimas& mSpausdinimoTvarka;

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

        std::swap((int&)(mSpausdinimoTvarka[kaNr]), (int&)(mSpausdinimoTvarka[suKuoNr]));
    }

public:
    // Be & ?
    DarbuotojoDuomenuTvarkosSpausdinimoMeniu(Darbuotojas::DuomenuPasirinkimas& spausdinimoTvarka) : mSpausdinimoTvarka(spausdinimoTvarka)  {
    }

    virtual bool tinkamasPasirinkimas(unsigned pasirinkimas) {
        return pasirinkimas <= Darbuotojas::DuomenuKiekis; 
    }

    virtual void rodyti() const {
        std::cout << "0. " << "Išsaugoti spausdinimo tvarką" << std::endl;
        std::cout << "   Spausdinimo eilės tvarka: (pasirinkti numerį, kad apkeisti)" << std::endl;
        for (unsigned i = 0; i < Darbuotojas::DuomenuKiekis; ++i) {
            std::cout << i+1 << ". " << Darbuotojas::DuomenuPasirinkimoPav[mSpausdinimoTvarka[i]] << std::endl;
        }
    }

    virtual void aptarnauti() {
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

class PersonaloIvestiesMeniu : public Meniu {
protected:
    Personalas& mPersonalas;

public:
    PersonaloIvestiesMeniu(Personalas& personalas) : mPersonalas(personalas) {
    }

    virtual bool tinkamasPasirinkimas(unsigned pasirinkimas) {
        return pasirinkimas <= Personalas::DARBUOTOJU_KIEKIS; 
    }

    virtual void rodyti() const {
        std::cout << "0. " << "Baigti pildyti personalą" << std::endl;
        for (unsigned i = 0; i < Personalas::DARBUOTOJU_KIEKIS; ++i) {
            bool uzpildytas = mPersonalas.gautiDarbuotoja(i).duomenysUzpildyti();

            std::cout << i+1 << ". " << (uzpildytas ? "Keisti" : "Pildyti") 
                << " darbuotoją: " << mPersonalas.gautiDarbuotoja(i).gautiVarda() << " " 
                << mPersonalas.gautiDarbuotoja(i).gautiPavarde() << std::endl;
        }
    }

    virtual void aptarnauti() {
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
    Personalas& mPersonalas;
    Darbuotojas::DuomenuPasirinkimas& mSpausdinimoTvarka;

public:
    PersonaloFiltravimoMeniuPagalAmziu(Personalas& personalas, Darbuotojas::DuomenuPasirinkimas& spausdinimoTvarka) 
        : mPersonalas(personalas), mSpausdinimoTvarka(spausdinimoTvarka) {
    }

    virtual bool tinkamasPasirinkimas(unsigned pasirinkimas) {
        return pasirinkimas <= DarbuotojoAmzius::AMZIU_GRUPIU_KIEKIS; 
    }

    virtual void rodyti() const {
        std::cout << "0. Rodyti visus darbuotojus" << std::endl;
        std::cout << "1. Filtruoti jauno (18-30) amžiaus darbuotojus" << std::endl;
        std::cout << "2. Filtruoti vidutinio (31-50) amžiaus darbuotojus" << std::endl;
        std::cout << "3. Filtruoti pagyvenusio (51-70) amžiaus darbuotojus" << std::endl;
        std::cout << "4. Filtruoti senyvo (71+) amžiaus darbuotojus" << std::endl;
    }

    virtual void aptarnauti() {
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
    Personalas& mPersonalas;
    Darbuotojas::DuomenuPasirinkimas& mSpausdinimoTvarka;

public:
    PersonaloFiltravimoMeniu(Personalas& personalas, Darbuotojas::DuomenuPasirinkimas& spausdinimoTvarka) 
        : mPersonalas(personalas), mSpausdinimoTvarka(spausdinimoTvarka) {
    }

    virtual bool tinkamasPasirinkimas(unsigned pasirinkimas) {
        return pasirinkimas <= 3; 
    }

    virtual void rodyti() const {
        std::cout << "0. Rodyti visus darbuotojus" << std::endl;
        std::cout << "1. Filtruoti pagal amžių" << std::endl;
        std::cout << "2. Filtruoti pagal patirtį" << std::endl;
        std::cout << "3. Filtruoti pagal atlyginimą" << std::endl;
    }

    virtual void aptarnauti() {
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

        auto filtras = [] (unsigned reiksme, unsigned min, unsigned max) {
            return reiksme >= min && reiksme <= max;
        }; 

        mPersonalas.filtruotiMinMax(filtras, min, max, darbFiltrai[meniuAts - 1], mSpausdinimoTvarka);
    }
};

#endif
