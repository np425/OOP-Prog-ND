#include <iostream>
#include <iomanip> // std::left, set::setw
#include <cstring> // std::strcpy
#define PAV_DYDIS 30

/*

3 Užduotis:
 - Klasė prekės:
   - pavadinimas
   - kiekis
   - vieneto kaina
 - Klasė prekės su nuolaida (kilus iš klasės prekės):
   - pavadinimas
   - kiekis
   - nuolaidos dydis
 - Nuskaito kiekvienos prekės informaciją
 - Jei turi nuolaida sukuriamas prekės su nuolaidą objektas
 - Jei neturi nuolaidos sukuriamas prekės objektas
 - Objektai yra masyve
 - Suskaičiuojama prekių vertės
 - Suskaičiuojama visų prekių vertės
 - Kainos spausdinamos
*/

class Prekes {
protected:
	char pav[PAV_DYDIS];
	unsigned kiekis;
	double vntKaina;

public:
	Prekes(char* pav, unsigned kiekis, double vntKaina) : kiekis(kiekis), vntKaina(vntKaina) {
		strcpy(this->pav, pav);
	}

	const char* gautiPav() { return pav; }
	virtual double visoKaina() { return kiekis*vntKaina; }
};

class Prekes_su_nuolaida : public Prekes {
	double nuolaida;

public:
	Prekes_su_nuolaida(char* pav, unsigned kiekis, double vntKaina, double nuolaida)
	      : Prekes(pav, kiekis, vntKaina), nuolaida(nuolaida) {}
	
	virtual double visoKaina() { return kiekis*vntKaina*(1-nuolaida); }
};

int main() {
	Prekes** prekes;
	char pav[PAV_DYDIS];
	char ats;
	unsigned n, kiekis;
	double kaina, nuolaida, visoKaina=0;

	std::cout << "Įveskite skirtingų prekių kiekį: ";
	std::cin >> n;

	prekes = new Prekes*[n];

	for (unsigned i = 0; i < n; ++i) {
		std::cout << "Įveskite " << i+1 << " prekės pavadinimą: ";
		std::cin >> pav;

		std::cout << "Įveskite vienetų kiekį: ";
		std::cin >> kiekis;

		std::cout << "Įveskite vieneto kainą: ";
		std::cin >> kaina;

		while (true) {
			std::cout << "Ar turi nuolaidą? t arba n: ";
			std::cin >> ats;

			if (ats == 't') {
				std::cout << "Įveskite nuolaidos procento dalį: ";
				std::cin >> nuolaida;
				prekes[i] = new Prekes_su_nuolaida(pav, kiekis, kaina, nuolaida);
			} else if (ats == 'n') {
				prekes[i] = new Prekes(pav, kiekis, kaina);
			} else {
				std::cout << "Nesupratau, prašome pakartoti įvėdimą." << std::endl;
				continue;
			}

			break;
		}
	}
	
	for (unsigned i = 0; i < n; ++i) {
		kaina = prekes[i]->visoKaina();
		visoKaina += kaina;

		std::cout << std::left << std::setw(25) << prekes[i]->gautiPav() << kaina << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	std::cout << std::left << std::setw(25) << "Visų prekių kaina" << visoKaina << std::endl;

	for (unsigned i = 0; i < n; ++i) {
		delete prekes[i];
	}

	delete[] prekes;

	return 0;
}
