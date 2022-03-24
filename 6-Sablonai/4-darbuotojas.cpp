#include <iostream>
#include <stdexcept>

/*

4 Užduotis:
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
	class NetinkamiDuomenys {
		std::string klaida;
	public:
		NetinkamiDuomenys(std::string klaida) : klaida(klaida) {}
		std::string gautiNeatitikima() const { return klaida; }
	};

	Darbuotojas(unsigned amzius, unsigned darboPatirtis, unsigned atlyginimas) {
		if (amzius < 18 || amzius > 70) {
			throw NetinkamiDuomenys("Netinkamas amžius");
		} 
		if (darboPatirtis > amzius) {
			throw NetinkamiDuomenys("Netinkama patirtis");
		}
		if (atlyginimas < 300) {
			throw NetinkamiDuomenys("Per mažas atlyginimas");
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
	} catch (const Darbuotojas::NetinkamiDuomenys& e) {
		std::cerr << e.gautiNeatitikima() << std::endl;
	}

	return 0;
}
