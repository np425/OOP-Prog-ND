#include <iostream>
#include <string>
#include <algorithm>

/*

1 Užduotis:
 - Klasė darbuotojas:
   - vardas
   - pavardė
   - specialybė
   - amžius
   - darbo patirtis
   - atlyginimas

   - Pagal Pasirinkimo Enumeraciją, galima dinamiškai pasirinkti kuriuos duomenis spausdinti

 - Leidžia pasirinkti kuriuos duomenis įrašyti ar keisti (visi duomenys turi būti užpildyti)
 - Įrašo į darbuotojo objektą pasirinktinus duomenis
 - Kai baigiama rašyti, galima pakeisti atspausdinimo tvarką
*/

class Darbuotojas {
public:
    constexpr static unsigned DuomenuKiekis = 6;

    enum Pasirinkimas {
        P_VARDAS = 0,
        P_PAVARDE,
        P_SPECIALYBE,
        P_AMZIUS,
        P_PATIRTIS,
        P_ATLYGINIMAS
    };

    static constexpr const char* const PasirinkimoPav[DuomenuKiekis] = {
        "Vardas",
        "Pavardė",
        "Specialybė",
        "Amžius",
        "Patirtis",
        "Atlyginimas"
    };

    typedef Pasirinkimas PasirinkimoTvarka[DuomenuKiekis];

private:
    std::string vardas;
    std::string pavarde;
    std::string specialybe;
	unsigned amzius = 0;
	unsigned patirtis = 0;
	unsigned atlyginimas = 0;

public:
	Darbuotojas() {
	}

    inline bool uzpildytiDuomenys() const {
	    return !vardas.empty() && !pavarde.empty() && !specialybe.empty()
	        && amzius && patirtis && atlyginimas;
    }

	void keistiVarda() {
		std::cout << "Įveskite vardą: " << std::endl;
        std::cin >> vardas;
	}

	void keistiPavarde() {
		std::cout << "Įveskite pavardę: " << std::endl;
        std::cin >> pavarde;
	}

	void keistiSpecialybe() {
		std::cout << "Įveskite specialybę: " << std::endl;
        std::cin >> specialybe;
	}

	void keistiAmziu() {
		std::cout << "Įveskite amžių: " << std::endl;
		std::cin >> amzius;
	}

	void keistiPatirti() {
		std::cout << "Įveskite darbo patirtį: " << std::endl;
		std::cin >> patirtis;
	}

	void keistiAtlyginima() {
		std::cout << "Įveskite atlyginimą: " << std::endl;
		std::cin >> atlyginimas;
	}

    inline void keistiPasirinkima(const Pasirinkimas pasirinkimas) {
	    constexpr void (Darbuotojas::*keitimai[Darbuotojas::DuomenuKiekis])() = {
		    &Darbuotojas::keistiVarda, &Darbuotojas::keistiPavarde, &Darbuotojas::keistiSpecialybe,
		    &Darbuotojas::keistiAmziu, &Darbuotojas::keistiPatirti, &Darbuotojas::keistiAtlyginima
	    };

        (this->*keitimai[pasirinkimas])();
    }

	std::string gautiVarda() const { return vardas; }
	std::string gautiPavarde() const { return pavarde; }
    std::string gautiSpecialybe() const { return specialybe; }
	unsigned gautiAmziu() const { return amzius; }
	unsigned gautiPatirti() const { return patirtis; }
	unsigned gautiAtlyginima() const { return atlyginimas; }

    void spausdintiVarda() {
        std::cout << "Vardas: " << vardas << std::endl;
    }

    void spausdintiPavarde() {
        std::cout << "Pavardė: " << pavarde << std::endl;
    }

    void spausdintiSpecialybe() {
        std::cout << "Specialybė: " << specialybe << std::endl;
    }

    void spausdintiAmziu() {
        std::cout << "Amžius: " << amzius << std::endl;
    }

    void spausdintiPatirti() {
        std::cout << "Patirtis: " << patirtis << std::endl;
    }

    void spausdintiAtlyginima() {
        std::cout << "Atlyginimas: " << atlyginimas << std::endl;
    }

	inline void spausdintiDuomenis(const PasirinkimoTvarka spausdinimoTvarka) {
        constexpr void (Darbuotojas::*spausdinimai[DuomenuKiekis])() = {
            &Darbuotojas::spausdintiVarda, &Darbuotojas::spausdintiPavarde, &Darbuotojas::spausdintiSpecialybe,
            &Darbuotojas::spausdintiAmziu, &Darbuotojas::spausdintiPatirti, &Darbuotojas::spausdintiAtlyginima
        };

        for (unsigned i = 0; i < DuomenuKiekis; ++i) {
            //spausdintiPasirinkima(spausdinimoTvarka[i]);
            (this->*spausdinimai[spausdinimoTvarka[i]])();
        }
	}
};
constexpr const char* const Darbuotojas::PasirinkimoPav[DuomenuKiekis];

void darbuotojoIvestiesMeniu(const Darbuotojas& darb) {
    std::cout << "Darbuotojo duomenys" << std::endl;

    std::cout << "0. " << "Baigti įvedimą" << std::endl;
    std::cout << "1. " << (!darb.gautiVarda().empty() ? "Keisti" : "Įrašyti") << " vardą" << std::endl;
    std::cout << "2. " << (!darb.gautiPavarde().empty() ? "Keisti" : "Įrašyti") << " pavardę" << std::endl;
    std::cout << "3. " << (!darb.gautiSpecialybe().empty() ? "Keisti" : "Įrašyti") 
                                         << " specialybę" << std::endl;
    std::cout << "4. " << (darb.gautiAmziu() ? "Keisti" : "Įrašyti") << " amžių" << std::endl;
    std::cout << "5. " << (darb.gautiPatirti() ? "Keisti" : "Įrašyti") << " patirtį" << std::endl;
    std::cout << "6. " << (darb.gautiAtlyginima() ? "Keisti" : "Įrašyti") 
                                                     << " atlyginimą" << std::endl;
}

void darbuotojoIsvestiesMeniu(const Darbuotojas::PasirinkimoTvarka& spausdinimoTvarka) {
    std::cout << "0. " << "Spausdinti duomenis" << std::endl;
    for (unsigned i = 0; i < Darbuotojas::DuomenuKiekis; ++i) {
        std::cout << i+1 << ". " << Darbuotojas::PasirinkimoPav[spausdinimoTvarka[i]] << std::endl;
    }
}

template <class T>
int pasirinkimoMeniu(void (*meniu)(const T&), const int atsakymoReziai[2], const T& meniuArgumentas) {
	while (true) {
        meniu(meniuArgumentas);

		int ats;
		std::cout << "Įveskite pasirinkimo numerį: ";
		std::cin >> ats;

        if (ats >= atsakymoReziai[0] && ats <= atsakymoReziai[1]) {
            return ats;
        }

	    std::cout << "Nesupratau pasirinkimo, prašome pakartoti įvestį." << std::endl;
	}
}

void apkeistiPasirinkimoTvarka(int ka, const Darbuotojas::PasirinkimoTvarka spausdinimoTvarka) {
    unsigned suKuoNr;

    while (true) {
        std::cout << "Iveskite su kuriuo numeriu apkeisti" << std::endl;
        std::cin >> suKuoNr;

        if (suKuoNr > 0 && suKuoNr <= Darbuotojas::DuomenuKiekis) {
            break;
        }

        std::cout << "Nesupratau pasirinkimo, prašome pakartoti įvestį." << std::endl;
    }

    // -1, kadangi pirmas pasirinkimas prasideda nuo 0
    suKuoNr = suKuoNr - 1;

    std::swap((int&)(spausdinimoTvarka[ka]), (int&)(spausdinimoTvarka[suKuoNr]));
}

int main() {
	Darbuotojas darb;
    int meniuAts;

    constexpr int meniuReziai[2] = {0, Darbuotojas::DuomenuKiekis};

    while (true) {
        meniuAts = pasirinkimoMeniu(&darbuotojoIvestiesMeniu, meniuReziai, darb);

        if (meniuAts == 0) {
            if (darb.uzpildytiDuomenys()) {
                break;
            }

		    std::cout << "Prašome užpildyti likusius duomenis." << std::endl;
        } else {
            // -1, kadangi pirmas pasirinkimas prasideda nuo 0
            darb.keistiPasirinkima((Darbuotojas::Pasirinkimas)(meniuAts - 1));
        }
    } 

    // Pradinė spausdinimo tvarka
    Darbuotojas::PasirinkimoTvarka spausdinimoTvarka = {
        Darbuotojas::P_VARDAS,
        Darbuotojas::P_PAVARDE,
        Darbuotojas::P_SPECIALYBE,
        Darbuotojas::P_AMZIUS,
        Darbuotojas::P_PATIRTIS,
        Darbuotojas::P_ATLYGINIMAS
    };

    while (true) {
        meniuAts = pasirinkimoMeniu(&darbuotojoIsvestiesMeniu, meniuReziai, spausdinimoTvarka);

        if (meniuAts == 0) {
            break;
        }

        apkeistiPasirinkimoTvarka(meniuAts - 1, spausdinimoTvarka);
    }

	darb.spausdintiDuomenis(spausdinimoTvarka);

	return 0;
}
