#include <iostream>
#include <stdexcept>

/*

2 Užduotis:
 - Klasė darbuotojas: 
   - amžius
   - darbo patirtis
   - atlyginimas
 - Įrašo į darbuotojo objektą duomenis
 - Jei duomenys neatitinka ribojimus, parašo klaidą
 - Kitu atvėju atspausdina darbuotojo objekto duomenis

*/

class Darbuotojas {
	unsigned amzius;
	unsigned darboPatirtis;
	unsigned atlyginimas;

public:
	Darbuotojas(unsigned amzius, unsigned darboPatirtis, unsigned atlyginimas) {
		if (amzius < 18 || amzius > 70) throw std::runtime_error("Amžius neatitinka ribojimų");
		if (darboPatirtis > amzius) throw std::runtime_error("Patirtis aukštesnė negu amžius");
		if (atlyginimas < 300) throw std::runtime_error("Atlyginimas mažiau už 300");
		
		this->amzius = amzius;
		this->darboPatirtis = darboPatirtis;
		this->atlyginimas = atlyginimas;
	}
	
	void spausdintiDuomenis() {
		std::cout << "Amžius: " << amzius << std::endl;
		std::cout << "Darbo patirtis: " << darboPatirtis << std::endl;
		std::cout << "Atlyginimas: " << atlyginimas << std::endl;
	}
};

int main() {
	unsigned amzius, patirtis, atlyginimas;

	std::cout << "Amžius: ";
	std::cin >> amzius;

	std::cout << "Darbo patirtis: ";
	std::cin >> patirtis;

	std::cout << "Atlyginimas: ";
	std::cin >> atlyginimas;

	try {
		Darbuotojas darb(amzius, patirtis, atlyginimas);
		darb.spausdintiDuomenis();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
