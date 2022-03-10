#include <iostream>
#include <string>
#include <map>
#include <iomanip>

/*

1 Užduotis:
 - Klasė asmuo:
   - vardas
   - pavardė
   - amžius
 - Klasė studentas (nuo asmens klasės):
   - id
   - vidurkis
   - dalykai (pavadinimas, pažymys)
   - skaičiuoja vidurkį
 - Nuskaito duomenis ir įrašo į studento objektą
 - Apskaičiuoja vidurkį
 - Atspausdina visus duomenis apie studentą
*/

class Asmuo {
	std::string vardas;
	std::string pavarde;
	unsigned amzius;

public:
	std::string gautiVarda() { return vardas; }
	std::string gautiPavarde() { return pavarde; }
	unsigned gautiAmziu() { return amzius; }
	
	void keistiVarda(std::string _vardas) { vardas = _vardas; }
	void keistiPavarde(std::string _pavarde) { pavarde = _pavarde; }
	void keistiAmziu(unsigned _amzius) { amzius = _amzius; }
};

class Studentas : public Asmuo {
	unsigned id;
	std::map<std::string, unsigned> dalykai;
	double vidurkis;

	void perskaiciuotiVidurki();
public:
	std::map<std::string, unsigned>& gautiDalykus() { return dalykai; }
	unsigned gautiID() { return id; }
	double gautiVidurki() { return vidurkis; }

	void keistiID(unsigned _id) { id = _id; }
	void pridetiDalyka(std::string, unsigned);
};

void Studentas::perskaiciuotiVidurki() {
	vidurkis = 0;
	for (auto it = dalykai.begin(); it != dalykai.end(); ++it) {
		vidurkis += it->second;
	}
	vidurkis /= dalykai.size();
}

void Studentas::pridetiDalyka(std::string pav, unsigned paz) {
	dalykai[pav] = paz;
	perskaiciuotiVidurki();
}

int main() {
	Studentas stud;
	std::string vardas, pavarde;
	unsigned amzius, id, n;

	std::cout << "Įveskite vardą: ";
	std::cin >> vardas;

	std::cout << "Įveskite pavardę: ";
	std::cin >> pavarde;

	std::cout << "Įveskite amžių: ";
	std::cin >> amzius;

	std::cout << "Įveskite studento ID: ";
	std::cin >> id;

	std::cout << "Įveskite kiek dalykų yra: ";
	std::cin >> n;

	stud.keistiVarda(vardas);
	stud.keistiPavarde(pavarde);
	stud.keistiAmziu(amzius);
	stud.keistiID(id);

	std::cout << "Įveskite " << n << " dalykų pavadinimus ir pažymius: " << std::endl;
	for (unsigned i = 0; i < n; ++i) {
		std::string pav;
		unsigned paz;

		std::cin >> pav >> paz;
		stud.pridetiDalyka(pav, paz);
	}

	std::cout << stud.gautiVarda() << " " << stud.gautiPavarde() << " (" << stud.gautiAmziu() << ") ";
	std::cout << "[" << stud.gautiID() << "]; dalykai: " << std::endl;

	for (auto it = stud.gautiDalykus().begin(); it != stud.gautiDalykus().end(); ++it) {
		std::cout << "- " << std::left << std::setw(17) << it->first << it->second << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	std::cout << "Vidurkis: " << stud.gautiVidurki() << std::endl;
	return 0;
}
