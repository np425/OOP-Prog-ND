#include <iostream>
#include <cmath> // M_PI
#define POW_2(x) (x*x)

/*

2 Užduotis:
 - Klasė (abstrakti) geometrinė figūra:
   - plotas() (abstrakti funkcija)
 - Klasė stačiakampis (kilus iš klasės geometrinė figūra):
   - ilgis
   - plotis
   - plotas()
 - Klasė trikampis (kilus iš klasės geometrinė figūra):
   - aukštine
   - ilgis (pagrindo)
   - plotas()
 - Klasė skritulys (kilus iš klasės geometrinė figūra):
   - spindulys
   - plotas()
 - Nuskaito stačiakampio ilgį, plotą, trikampio aukštinę, pagrindo ilgį, skritulio spindulį
 - Masyvas į kiekvieną figūra, su atitinkamais kintamaisiais
 - Suskaičiuoja kiekvienos figūros plotą
 - Jį atspausdina
*/

class GeometrineFigura {
public:
	virtual double plotas() = 0;

	virtual const char* pav() = 0;
};

class Staciakampis : public GeometrineFigura {
protected:
	double ilgis;
	double plotis;

public:
	virtual double plotas() {
		return ilgis*plotis;
	}

	Staciakampis(double ilgis, double plotis) : ilgis(ilgis), plotis(plotis) {}

	virtual const char* pav() { return "stačiakampis"; }
};

class Trikampis : public GeometrineFigura {
protected:
	double pagrIlgis;
	double aukstine;

public:
	virtual double plotas() {
		return pagrIlgis*aukstine/2;
	}

	Trikampis(double pagrIlgis, double aukstine) : pagrIlgis(pagrIlgis), aukstine(aukstine) {}
	virtual const char* pav() { return "trikampis"; }
};

class Skritulys : public GeometrineFigura {
protected:
	double spindulys;

public:
	virtual double plotas() {
		return M_PI*POW_2(spindulys);
	}

	Skritulys(double spindulys) : spindulys(spindulys) {}
	virtual const char* pav() { return "skritulys"; }
};

int main() {
	double ilgis, plotis, pagrIlgis, aukstine, spindulys;
	GeometrineFigura* fig[3];

	std::cout << "Įveskite stačiakampio ilgį: ";
	std::cin >> ilgis;

	std::cout << "Įveskite stačiakampio plotį: ";
	std::cin >> plotis;

	std::cout << "Įveskite trikampio pagrindo ilgį: ";
	std::cin >> pagrIlgis;

	std::cout << "Įveskite trikampio aukštinę: ";
	std::cin >> aukstine;

	std::cout << "Įveskite apskritimo spindulį: ";
	std::cin >> spindulys;

	fig[0] = new Staciakampis(ilgis, plotis);
	fig[1] = new Trikampis(pagrIlgis, aukstine);
	fig[2] = new Skritulys(spindulys);

	for (int i = 0; i != 3; ++i) {
		std::cout << fig[i]->pav() << ": S=" << fig[i]->plotas() << std::endl;
	}

	return 0;
}
