#include <iostream>
#include <string.h>

#define VARDO_ILGIS 100
#define KREDITU_SK 6

/*

5 Užduotis:
 - Klasė Studentas:
   - vardas
   - pavardė
   - kreditai
   - pažymiai
   - skaičiuoja vidurkį: 
     - suma kredito su įvertinimu sandauga ir padalinima iš visų kreditų sumos
 - Nuskaito duomenis
 - Įrašo duomenis į Studentas objektą
 - Atspausdina duomenis su vidurkiu
*/

class Studentas {
	char vardas[VARDO_ILGIS];
	char pavarde[VARDO_ILGIS];
	unsigned kred[KREDITU_SK];
	unsigned paz[KREDITU_SK];

public:
	double gautiSemestroVid() {
		double vid = 0;
		double kredSum = 0;

		for (int i = 0; i < KREDITU_SK; ++i) {
			vid += kred[i] * paz[i];
			kredSum += kred[i];
		}

		return vid / kredSum;
	}

	const char* gautiVarda() const { return vardas; }
	void keistiVarda(const char* vard) { 
		strcpy(vardas, vard);
	}

	const char* gautiPavarde() const { return pavarde; }
	void keistiPavarde(const char* vard) { 
		strcpy(pavarde, vard);
	}

	const unsigned* gautiKred() const { return kred; }
	void keistiKred(const unsigned* nauj) { 
		memcpy(kred, nauj, sizeof(*kred)*KREDITU_SK);
	}

	const unsigned* gautiPaz() const { return paz; }
	void keistiPaz(const unsigned* nauj) { 
		memcpy(paz, nauj, sizeof(*paz)*KREDITU_SK);
	}

	void spausdinti() {
		std::cout << "Kreditų skaičius: " << KREDITU_SK << std::endl;
		std::cout << "Vardas: " << vardas << std::endl;
		std::cout << "Pavardė: " << pavarde << std::endl;

		std::cout << "Kreditai: ";
		for (int i = 0; i < KREDITU_SK; ++i) {
			std::cout << kred[i] << " "; 
		}
		std::cout << std::endl; 

		std::cout << "Įvertinimai: ";
		for (int i = 0; i < KREDITU_SK; ++i) {
			std::cout << paz[i] << " "; 
		}
		std::cout << std::endl; 

		std::cout << "Vidurkis: " << this->gautiSemestroVid() << std::endl;
	}
};

int main() {
	char vard[VARDO_ILGIS];
	char pav[VARDO_ILGIS];
	unsigned kred[KREDITU_SK];
	unsigned paz[KREDITU_SK];
	Studentas stud;

	std::cout << "Įveskite vardą:" << std::endl;
	std::cin >> vard;

	std::cout << "Įveskite pavardę:" << std::endl;
	std::cin >> pav;

	std::cout << "Įveskite " << KREDITU_SK << " kreditus (atskirtais tarpais)" << std::endl;
	for (int i = 0; i < KREDITU_SK; ++i) {
		std::cin >> kred[i];
	}

	std::cout << "Įveskite " << KREDITU_SK << " pažymius (atskirtais tarpais)" << std::endl;
	for (int i = 0; i < KREDITU_SK; ++i) {
		std::cin >> paz[i];
	}

	//std::cout << vard << std::endl;
	//std::cout << pav << std::endl;

	stud.keistiVarda(vard);
	stud.keistiPavarde(pav);
	stud.keistiKred(kred);
	stud.keistiPaz(paz);

	stud.spausdinti();

    return 0;
}
