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
   - kiekio kaina
   - visų prekių kaina (statinis kintamasis)
 - Nuskaito kiekvienos prekės informaciją
 - Objektai yra masyve
 - Suskaičiuojama prekių vertės
 - Suskaičiuojama visų prekių vertės per statinį kintamąjį
 - Kainos spausdinamos
*/

class Prekes {
protected:
	char pav[PAV_DYDIS];
	unsigned kiekis;
	double vntKaina;
	double kiekioKaina;
	static double visuPrekiuKaina;

public:
	Prekes(char* pav, unsigned kiekis, double vntKaina) : kiekis(kiekis), vntKaina(vntKaina) {
		strcpy(this->pav, pav);
		kiekioKaina = vntKaina * kiekis;
		visuPrekiuKaina += kiekioKaina;
	}
	
	~Prekes() {
		visuPrekiuKaina -= kiekioKaina;
	}

	const char* gautiPav() { return pav; }
	virtual double visoKaina() { return kiekioKaina; }

	static double gautiVisuPrekiuKaina() { return visuPrekiuKaina; }
};
double Prekes::visuPrekiuKaina = 0;

int main() {
	Prekes** prekes;
	char pav[PAV_DYDIS];
	unsigned n, kiekis;
	double kaina;

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

		prekes[i] = new Prekes(pav, kiekis, kaina);
	}
	
	for (unsigned i = 0; i < n; ++i) {
		kaina = prekes[i]->visoKaina();
		std::cout << std::left << std::setw(25) << prekes[i]->gautiPav() << kaina << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	std::cout << std::left << std::setw(25) << "Visų prekių kaina" 
	          << Prekes::gautiVisuPrekiuKaina() << std::endl;

	for (unsigned i = 0; i < n; ++i) {
		delete prekes[i];
	}

	delete[] prekes;

	return 0;
}
