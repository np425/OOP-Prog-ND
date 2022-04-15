#include <iostream>
#define VARDO_ILGIS 20

/*

2 Užduotis:
 - Klasė darbuotojas:
   - vardas
   - pavardė
   - specialybė
   - amžius
   - darbo patirtis
   - atlyginimas
 - Leidžia pasirinkti kuriuos duomenis įrašyti ar keisti
 - Įrašo į darbuotojo objektą pasirinktinus duomenis
 - Kai baigiama rašyti vartotojas pasirenka baigti įrašymą:
   - Jei visi duomenys užpildyti, atspausdina informaciją apie darbuotoją
   - Jei ne visi duomenys užpildyti, prašo užpildyti likusius duomenis
*/

class Darbuotojas {
	char vardas[VARDO_ILGIS];
	char pavarde[VARDO_ILGIS];
	char specialybe[VARDO_ILGIS];
	unsigned amzius;
	unsigned patirtis;
	unsigned atlyginimas;

public:
	Darbuotojas() {
		*vardas = 0;
		*pavarde = 0;
		*specialybe = 0;
		amzius = 0;
		patirtis = 0;
		atlyginimas = 0;
	}

	//Darbuotojas(unsigned amzius, unsigned darboPatirtis, unsigned atlyginimas) {
	//	this->amzius = amzius;
	//	this->darboPatirtis = darboPatirtis;
	//	this->atlyginimas = atlyginimas;
	//}
	
	void spausdintiDuomenis() {
		std::cout << "Vardas: " << vardas << std::endl;
		std::cout << "Pavardė: " << pavarde << std::endl;
		std::cout << "Specialybė: " << specialybe << std::endl;
		std::cout << "Amžius: " << amzius << std::endl;
		std::cout << "Darbo patirtis: " << patirtis << std::endl;
		std::cout << "Atlyginimas: " << atlyginimas << std::endl;
	}

	void keistiVarda() {
		std::cout << "Įveskite vardą: ";
		std::cin.getline(vardas, VARDO_ILGIS);
	}

	void keistiPavarde() {
		std::cout << "Įveskite pavardę: ";
		std::cin.getline(pavarde, VARDO_ILGIS);
	}

	void keistiSpecialybe() {
		std::cout << "Įveskite specialybę: ";
		std::cin.getline(specialybe, VARDO_ILGIS);
	}

	void keistiAmziu() {
		std::cout << "Įveskite amžių: ";
		std::cin >> amzius;
	}

	void keistiPatirti() {
		std::cout << "Įveskite darbo patirtį: ";
		std::cin >> patirtis;
	}

	void keistiAtlyginima() {
		std::cout << "Įveskite atlyginimą: ";
		std::cin >> atlyginimas;
	}

	const char* gautiVarda() const { return vardas; }
	const char* gautiPavarde() const { return pavarde; }
	const char* gautiSpecialybe() const { return specialybe; }
	const unsigned gautiAmziu() const { return amzius; }
	const unsigned gautiPatirti() const { return patirtis; }
	const unsigned gautiAtlyginima() const { return atlyginimas; }
};

void spausdintiPasirinkima(const Darbuotojas& darb) {
	std::cout << "0 " << "Baigti įvedimą" << std::endl;
	std::cout << "1 " << (*darb.gautiVarda() ? "Keisti" : "Įrašyti") << " vardą" << std::endl;
	std::cout << "2 " << (*darb.gautiPavarde() ? "Keisti" : "Įrašyti") << " pavardę" << std::endl;
	std::cout << "3 " << (*darb.gautiSpecialybe() ? "Keisti" : "Įrašyti") 
	                 << " specialybę" << std::endl;
	std::cout << "4 " << (darb.gautiAmziu() ? "Keisti" : "Įrašyti") << " amžių" << std::endl;
	std::cout << "5 " << (darb.gautiPatirti() ? "Keisti" : "Įrašyti") << " patirtį" << std::endl;
	std::cout << "6 " << (darb.gautiAtlyginima() ? "Keisti" : "Įrašyti") 
	                 << " atlyginimą" << std::endl;
}

bool duomenysUzpildyti(const Darbuotojas& darb) {
	return *darb.gautiVarda() && *darb.gautiPavarde() && *darb.gautiSpecialybe()
	 && darb.gautiAmziu() && darb.gautiPatirti() && darb.gautiAtlyginima();
}

int main() {
	Darbuotojas darb;

	using memberFn = void (Darbuotojas::*)();
	memberFn f[] = {
		&Darbuotojas::keistiVarda, &Darbuotojas::keistiPavarde, &Darbuotojas::keistiSpecialybe,
		&Darbuotojas::keistiAmziu, &Darbuotojas::keistiPatirti, &Darbuotojas::keistiAtlyginima
	};

	spausdintiPasirinkima(darb);
	while (true) {
		int ats;
		std::cout << "Įveskite pasirinkimo numerį: ";
		std::cin >> ats;
		std::cin.ignore();

		if (ats < 0 || ats > 6) {
			std::cout << "Nesupratau pasirinkimo, prašome pakartoti įvestį." << std::endl;
			continue;
		}

		if (ats == 0) {
			if (!duomenysUzpildyti(darb)) {
				std::cout << "Prašome užpildyti likusius duomenis." << std::endl;
				continue;
			}
			break;
		}

		(darb.*f[ats-1])();
		std::cout << std::endl << std::endl;

		spausdintiPasirinkima(darb);
	}

	std::cout << std::endl << std::endl;
	darb.spausdintiDuomenis();

	return 0;
}
