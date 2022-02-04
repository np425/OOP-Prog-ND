#include <iostream>
#include <cmath> // sqrt
#define POW_2(x) (x*x)

/*

2 Užduotis:
 - Klasė skritulys:
   - spindulys
   - plotas
 - Klasė ritinys (kilęs iš klasės skritulys)
   - aukštinė
   - tūris
 - Įrašo į ritinį duomenis 
 - Apskaičiuoja jo tūrį
 - Tūrį atspausdina
*/

class Skritulys {
protected:
	double r;
	double s;

public:
	void keistiSpinduli(double r) {
		this->r = r;
		this->s = M_PI*POW_2(r);
	}
	double gautiSpinduli() { return this->r; }

	double gautiPlota() { return this->s; }
};

class Ritinys: public Skritulys {
protected:
	double v;
	double h;

public:
	void keistiAukstine(double h) {
		this->h = h;
		this->v = s*h;
	}
	double gautiTuri() { return this->v; }
	double gautiPlota() { return 2*M_PI*r*(r+h); }
};

int main() {
	double r, h;
	Ritinys rit;

	std::cout << "Įveskite spindulio ilgį: ";
	std::cin >> r;

	std::cout << "Įveskite aukštinės ilgį: ";
	std::cin >> h;

	rit.keistiSpinduli(r);
	rit.keistiAukstine(h);

	std::cout << "Ritinio tūtis: " << rit.gautiTuri() << std::endl;
}
