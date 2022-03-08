#include <iostream>
#include <cmath> // sqrt

/*

3 Užduotis:
 - Klasė skritulys:
   - Spindulys
   - Plotas
 - Klasė kūgis:
   - Aukštinė
   - 2 pagrindai (klasė skritulys)
   - Tūris
 - Įrašo į kūgi duomenis
 - Apskaičiuoja jo tūrį
 - Tūrį atspausdina

*/

class Skritulys {
	double r;
	double s;

public:
	void keistiSpinduli(double r) {
		this->r = r;
		this->s = M_PI*r*r;
	}
	double gautiSpinduli() { return this->r; }
	double gautiPlota() { return this->s; }

};

class Kugis {
	Skritulys pagr[2];
	double h;
	double v;

	void skaiciuotiTuri() {
		this->v = (pagr[0].gautiPlota() 
	        	  + sqrt(pagr[0].gautiPlota() * pagr[1].gautiPlota()) 
	         	  + pagr[1].gautiPlota()) / 3 * this->h;
	}

public:
	double gautiTuri() { return this->v; }

	void keisti1PagrSpinduli(double r) { 
		this->pagr[0].keistiSpinduli(r);
		skaiciuotiTuri();
	}
	Skritulys gauti1Pagr() { return this->pagr[0]; }

	void keisti2PagrSpinduli(double r) {
		this->pagr[1].keistiSpinduli(r);
		skaiciuotiTuri();
	};
	Skritulys gauti2Pagr() { return this->pagr[1]; }

	void keistiAukstine(double h) { 
		this->h = h;
		skaiciuotiTuri();
	}
	double gautiAukstine() { return this->h; }
	
};

int main() {
	double r1, r2, h;
	Kugis kugis;

	std::cout << "1 pagrindo spindulys: ";
	std::cin >> r1;
	std::cout << "2 pagrindo spindulys: ";
	std::cin >> r2;
	std::cout << "Kūgio aukštinė: ";
	std::cin >> h;

	kugis.keisti1PagrSpinduli(r1);
	kugis.keisti2PagrSpinduli(r2);
	kugis.keistiAukstine(h);

	std::cout << "Kūgio plotas: " << kugis.gautiTuri() << std::endl;
}
