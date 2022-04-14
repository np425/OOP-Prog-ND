#include <iostream>
#include <iomanip> // std::left, set::setw
#include <cstring> // std::strcpy
#define PAV_DYDIS 30

/*

2 Užduotis:
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
	char pav[PAV_DYDIS];
	unsigned kiekis;
	double vntKaina;
	double kiekioKaina;
	static double visuPrekiuKaina;
    static Prekes* pig;
    static Prekes* brang;

    Prekes() {}

public:
	Prekes(char* pav, unsigned kiekis, double vntKaina) 
        : kiekis(kiekis), vntKaina(vntKaina) {
		strcpy(this->pav, pav);
		kiekioKaina = vntKaina * kiekis;
		visuPrekiuKaina += kiekioKaina;

        if (!pig) {
            pig = new Prekes;
            *pig = *this;
        } else if (kiekioKaina < pig->kiekioKaina) {
            *pig = *this;
        }

        if (!brang) {
            brang = new Prekes;
            *brang = *this;
        } else if (kiekioKaina > brang->kiekioKaina) {
            *brang = *this;
        }
	}
	
	~Prekes() {
		visuPrekiuKaina -= kiekioKaina;
        if (!visuPrekiuKaina) {
            delete pig;
            delete brang;
        }
	}

	const char* gautiPav() { return pav; }
    double gautiKieki() { return kiekis; }
    double gautiVntKaina() { return vntKaina; }
    double gautiKiekioKaina() { return kiekioKaina; }
	virtual double visoKaina() { return kiekioKaina; }

	static double gautiVisuPrekiuKaina() { return visuPrekiuKaina; }

    static Prekes* gautiPig() { return pig; }
    static Prekes* gautiBrang() { return brang; }
};

double Prekes::visuPrekiuKaina = 0;
Prekes* Prekes::pig = nullptr;
Prekes* Prekes::brang = nullptr;

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

    Prekes* brang = Prekes::gautiBrang();
    Prekes* pig = Prekes::gautiPig();
    
    if (pig) {
        std::cout << "Pigiausia preke: " << pig->gautiPav() << ", " << pig->gautiVntKaina();
        std::cout << " x " << pig->gautiKieki() << " = " << pig->gautiKiekioKaina() << std::endl;
    } else {
        std::cout << "Pigiausios prekes nera" << std::endl;
    }

    if (brang) {
        std::cout << "Brangiausia preke: " << brang->gautiPav() << ", " << brang->gautiVntKaina();
        std::cout << " x " << brang->gautiKieki() << " = " << brang->gautiKiekioKaina() << std::endl;
    } else {
        std::cout << "Brangiausios prekes nera" << std::endl;
    }

	for (unsigned i = 0; i < n; ++i) {
		delete prekes[i];
	}

	delete[] prekes;

	return 0;
}
