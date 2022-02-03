#include <iostream>

/*

2 Užduotis:
 - Klasė darbuotojas, su privačiais duomenimis:
   - amžius
   - darbo patirtis
   - atlyginimas
 - Įrašo į darbuotojo objektą duomenis
 - Atspausdina darbuotojo objekto duomenis

*/

class Darbuotojas {
private:
	unsigned amzius;
	unsigned darboPatirtis;
	unsigned atlyginimas;

	//Darbuotojas(unsigned amzius, unsigned darboPatirtis, unsigned atlyginimas) {
	//	this->amzius = amzius;
	//	this->darboPatirtis = darboPatirtis;
	//	this->atlyginimas = atlyginimas;
	//}
	
public:
	void spausdintiDuomenis() {
		std::cout << "Amžius: " << amzius << std::endl;
		std::cout << "Darbo patirtis: " << darboPatirtis << std::endl;
		std::cout << "Atlyginimas: " << atlyginimas << std::endl;
	}

	unsigned gautiAmziu() { return this->amzius; }
	void keistiAmziu(unsigned amzius) { this->amzius = amzius; }

	unsigned gautiDarboPatirti() { return this->darboPatirtis; }
	void keistiDarboPatirti(unsigned patirtis) { this->darboPatirtis = patirtis; }

	unsigned gautiAtlyginima() { return this->atlyginimas; }
	void keistiAtlyginima(unsigned atlyginimas) { this->atlyginimas = atlyginimas; }
};

int main() {
	Darbuotojas darb;

	unsigned amzius;
	unsigned darboPatirtis;
	unsigned atlyginimas;

	std::cout << "Amžius: ";
	std::cin >> amzius;
	std::cout << "Darbo patirtis: ";
	std::cin >> darboPatirtis;
	std::cout << "Atlyginimas: ";
	std::cin >> atlyginimas;

	darb.keistiAmziu(amzius);
	darb.keistiDarboPatirti(darboPatirtis);
	darb.keistiAtlyginima(atlyginimas);

	darb.spausdintiDuomenis();

	return 0;
}
