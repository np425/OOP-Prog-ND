#include <iostream>
#include <stdexcept>

/*

3 Užduotis:
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
	class NetinkamasAmzius{};
	class NetinkamaPatirtis{};
	class MazasAtlyginimas{};

	Darbuotojas(unsigned amzius, unsigned darboPatirtis, unsigned atlyginimas) {
		if (amzius < 18 || amzius > 70) {
			throw NetinkamasAmzius();
		} 
		if (darboPatirtis > amzius) {
			throw NetinkamaPatirtis();
		}
		if (atlyginimas < 300) {
			throw MazasAtlyginimas();
		}
		
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
	} catch (const Darbuotojas::NetinkamasAmzius&) {
		std::cerr << "Netinkamas amžius" << std::endl;
	} catch (const Darbuotojas::NetinkamaPatirtis&) {
		std::cerr << "Netinkama patirtis" << std::endl;
	} catch (const Darbuotojas::MazasAtlyginimas&) {
		std::cerr << "Per mažas atlyginimas" << std::endl;
	}

	return 0;
}
