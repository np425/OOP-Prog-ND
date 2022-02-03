#include <iostream>

/*

1 Užduotis:
 - Klasė darbuotojas, su viešais duomenimis:
   - amžius
   - darbo patirtis
   - atlyginimas
 - Įrašo į darbuotojo objektą duomenis
 - Atspausdina darbuotojo objekto duomenis

*/

class Darbuotojas {
public:
	unsigned amzius;
	unsigned darboPatirtis;
	unsigned atlyginimas;

	//Darbuotojas(unsigned amzius, unsigned darboPatirtis, unsigned atlyginimas) {
	//	this->amzius = amzius;
	//	this->darboPatirtis = darboPatirtis;
	//	this->atlyginimas = atlyginimas;
	//}
	
	void spausdintiDuomenis() {
		std::cout << "Amžius: " << amzius << std::endl;
		std::cout << "Darbo patirtis: " << darboPatirtis << std::endl;
		std::cout << "Atlyginimas: " << atlyginimas << std::endl;
	}
};

int main() {
	Darbuotojas darb;

	std::cout << "Amžius: ";
	std::cin >> darb.amzius;
	std::cout << "Darbo patirtis: ";
	std::cin >> darb.darboPatirtis;
	std::cout << "Atlyginimas: ";
	std::cin >> darb.atlyginimas;

	darb.spausdintiDuomenis();

	return 0;
}
