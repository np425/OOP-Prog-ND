#include <iostream>
#include <cmath> // sqrt
#define POW_2(x) (x*x)

/*

4 Užduotis:
 - Klasė taškas:
   - x
   - y
 - Klasė atkarpa
   - 2 taškai
   - atstumas
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

class Taskas {
public:
	double x;
	double y;
};

class Atkarpa {
	double ats;
	Taskas pradzia;
	Taskas pabaiga;

	void skaiciuotiAts() {
		this->ats = sqrt(POW_2(pabaiga.x-pradzia.x)+POW_2(pabaiga.y-pradzia.y));
	}

public:
	void keistiPradziosTaska(Taskas pradzia) { 
		this->pradzia = pradzia;
		skaiciuotiAts();
	}
	Taskas gautiPradziosTaska() { return this->pradzia; }

	void keistiPabaigosTaska(Taskas pabaiga) { 
		this->pabaiga = pabaiga;
		skaiciuotiAts();
	}
	Taskas gautiPabaigosTaska() { return this->pabaiga; }

	double gautiAts() { return this->ats; }
};

class Skritulys {
	Atkarpa r;
	double s;

public:
	void keistiSpinduli(Atkarpa r) {
		this->r = r;
		this->s = M_PI*r.gautiAts()*r.gautiAts();
	}
	double gautiSpinduli() { return this->r.gautiAts(); }
	double gautiPlota() { return this->s; } 
};

class Kugis {
	Skritulys pagr[2];
	Atkarpa h;
	double v;

	void skaiciuotiTuri() {
		this->v = (pagr[0].gautiPlota() 
	        	  + sqrt(pagr[0].gautiPlota() * pagr[1].gautiPlota()) 
	         	  + pagr[1].gautiPlota()) / 3 * this->h.gautiAts();
	}

public:
	double gautiTuri() { return this->v; }

	void keisti1PagrSpinduli(Atkarpa r) { 
		this->pagr[0].keistiSpinduli(r);
		skaiciuotiTuri();
	}
	Skritulys gauti1Pagr() { return this->pagr[0]; }

	void keisti2PagrSpinduli(Atkarpa r) {
		this->pagr[1].keistiSpinduli(r);
		skaiciuotiTuri();
	};
	Skritulys gauti2Pagr() { return this->pagr[1]; }

	void keistiAukstine(Atkarpa h) { 
		this->h = h;
		skaiciuotiTuri();
	}
	Atkarpa gautiAukstine() { return this->h; }
	
};

int main() {
	Atkarpa r1, r2, h;
	Taskas taskas;
	double x, y;

	Kugis kugis;

	std::cout << "1 pagrindo spindulio pradžios koordinatė (x y): ";
	std::cin >> taskas.x >> taskas.y;
	r1.keistiPradziosTaska(taskas);
	
	std::cout << "1 pagrindo spindulio pabaigos koordinatė (x y): ";
	std::cin >> taskas.x >> taskas.y;
	r1.keistiPabaigosTaska(taskas);

	std::cout << "2 pagrindo spindulio pradžios koordinatė (x y): ";
	std::cin >> taskas.x >> taskas.y;
	r2.keistiPradziosTaska(taskas);
	
	std::cout << "2 pagrindo spindulio pabaigos koordinatė (x y): ";
	std::cin >> taskas.x >> taskas.y;
	r2.keistiPabaigosTaska(taskas);

	std::cout << "Aukštinės pradžios koordinatė (x y): ";
	std::cin >> taskas.x >> taskas.y;
	h.keistiPradziosTaska(taskas);
	
	std::cout << "Aukštinės pabaigos koordinatė (x y): ";
	std::cin >> taskas.x >> taskas.y;
	h.keistiPabaigosTaska(taskas);

	kugis.keisti1PagrSpinduli(r1);
	kugis.keisti2PagrSpinduli(r2);
	kugis.keistiAukstine(h);

	std::cout << "Kūgio plotas: " << kugis.gautiTuri() << std::endl;
}
