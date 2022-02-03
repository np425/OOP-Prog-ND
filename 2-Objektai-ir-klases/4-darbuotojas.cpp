#include <iostream>

/*

4 Užduotis:
 - Klasė darbuotojas, su privačiais duomenimis:
   - amžius
   - darbo patirtis
   - atlyginimas
   - mokesčiai
 - Leidžia priskirti pradinius duomenis, sukūrimo metu
 - Skaičiuoja mokesčius
 - Juos atspausdina
 - Įrašo į darbuotojo objektą duomenis
 - Atspausdina darbuotojo objekto duomenis

*/

class Darbuotojas {
private:
	unsigned amzius;
	unsigned darboPatirtis;
	unsigned atlyginimas;
	double mokesciai;

	constexpr static double SODRA = 0.09;
	constexpr static double MOKESCIAI = 0.15;

public:
	Darbuotojas(unsigned amzius, unsigned darboPatirtis, unsigned atlyginimas) {
		this->amzius = amzius;
		this->darboPatirtis = darboPatirtis;
		this->atlyginimas = atlyginimas;
	}

	void spausdintiDuomenis() {
		std::cout << "Amžius: " << amzius << std::endl;
		std::cout << "Darbo patirtis: " << darboPatirtis << std::endl;
		std::cout << "Atlyginimas: " << atlyginimas << std::endl;
		spausdintiMokescius();
	}

	unsigned gautiAmziu() { return this->amzius; }
	void keistiAmziu(unsigned amzius) { this->amzius = amzius; }

	unsigned gautiDarboPatirti() { return this->darboPatirtis; }
	void keistiDarboPatirti(unsigned patirtis) { this->darboPatirtis = patirtis; }

	unsigned gautiAtlyginima() { return this->atlyginimas; }
	void keistiAtlyginima(unsigned atlyginimas) { this->atlyginimas = atlyginimas; }

	double skaiciuotiMokescius() { return this->mokesciai = atlyginimas * (SODRA+MOKESCIAI); }
	void spausdintiMokescius() { 
		std::cout << "Mokesčiai: " << this->mokesciai << std::endl; 
	}
};

int main() {

	unsigned amzius;
	unsigned darboPatirtis;
	unsigned atlyginimas;

	std::cout << "Amžius: ";
	std::cin >> amzius;
	std::cout << "Darbo patirtis: ";
	std::cin >> darboPatirtis;
	std::cout << "Atlyginimas: ";
	std::cin >> atlyginimas;

	Darbuotojas darb(amzius, darboPatirtis, atlyginimas);

	darb.skaiciuotiMokescius();

	darb.spausdintiDuomenis();

	return 0;
}
