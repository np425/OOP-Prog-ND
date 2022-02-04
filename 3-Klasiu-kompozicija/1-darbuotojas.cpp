#include <iostream>

/*

1 Užduotis:
 - Klasė atlyginimas:
   - darbo vietos kaina
   - darbdavio sumokami mokesčiai:
     - skaičiuojami nuo darbo vietos kainos
     - SODRA: 31,17%
   - darbuotojo sumokami mokesčiai:
     - skaičiuojami nuo likusios darbdavio mokesčių dalies
     - pajamų mokėstis: 15%
	 - SODRA: 9%
   - darbuotojo gaunama pinigų suma
 - Klasė darbuotojas, su privačiais duomenimis:
   - amžius
   - darbo patirtis
   - atlyginimas (klasė atlyginimas)
 - Įrašo į darbuotojo objektą duomenis
 - Atspausdina darbuotojo objekto duomenis

*/

class Atlyginimas {
	unsigned darboKaina;
	unsigned darbdavioMokesciai;
	unsigned darbuotojoMokesciai;
	unsigned darbuotojoPajamos;

public:
	constexpr static float DARBDAVIO_SODRA = 0.3117;
	constexpr static float DARBUOTOJO_SODRA = 0.15;
	constexpr static float DARBUOTOJO_PAJAM_MOKESC = 0.09;
	constexpr static float DARBUOTOJO_MOKESC = DARBUOTOJO_SODRA + DARBUOTOJO_PAJAM_MOKESC;

	void skaiciuotiAtlyginima(unsigned darboKaina) {
		this->darboKaina = darboKaina;
		this->darbdavioMokesciai = darboKaina * DARBDAVIO_SODRA;
		this->darbuotojoMokesciai = (darboKaina - this->darbdavioMokesciai) * DARBUOTOJO_MOKESC; 
		this->darbuotojoPajamos = darboKaina - this->darbdavioMokesciai - this->darbuotojoMokesciai;
	}

	void spausdintiAtlyginima() {
		std::cout << "Atlyginimas ant popieriaus: " << darboKaina << std::endl;
		std::cout << "Darbdavio mokesčiai: " << darbdavioMokesciai << std::endl;
		std::cout << "Darbuotojo mokesčiai: " << darbuotojoMokesciai << std::endl;
		std::cout << "Atlyginimas į rankas: " << darbuotojoPajamos << std::endl;
	}
};

class Darbuotojas {
	unsigned amzius;
	unsigned darboPatirtis;
	Atlyginimas atlyginimas;

	//Darbuotojas(unsigned amzius, unsigned darboPatirtis, unsigned atlyginimas) {
	//	this->amzius = amzius;
	//	this->darboPatirtis = darboPatirtis;
	//	this->atlyginimas = atlyginimas;
	//}
	
public:
	void spausdintiDuomenis() {
		std::cout << "Amžius: " << amzius << std::endl;
		std::cout << "Darbo patirtis: " << darboPatirtis << std::endl;
		atlyginimas.spausdintiAtlyginima();
	}

	unsigned gautiAmziu() { return this->amzius; }
	void keistiAmziu(unsigned amzius) { this->amzius = amzius; }

	unsigned gautiDarboPatirti() { return this->darboPatirtis; }
	void keistiDarboPatirti(unsigned patirtis) { this->darboPatirtis = patirtis; }

	Atlyginimas gautiAtlyginima() { return this->atlyginimas; }
	void keistiAtlyginima(unsigned darboKaina) { 
		this->atlyginimas.skaiciuotiAtlyginima(darboKaina);
	}
};

int main() {
	Darbuotojas darb;

	unsigned amzius;
	unsigned darboPatirtis;
	unsigned darboKaina;

	std::cout << "Amžius: ";
	std::cin >> amzius;
	std::cout << "Darbo patirtis: ";
	std::cin >> darboPatirtis;
	std::cout << "Atlyginimas ant popieriaus: ";
	std::cin >> darboKaina;

	darb.keistiAmziu(amzius);
	darb.keistiDarboPatirti(darboPatirtis);
	darb.keistiAtlyginima(darboKaina);

	darb.spausdintiDuomenis();

	return 0;
}
