#include <iostream>
#include <cmath> // sqrt
#define POW_2(x) (x*x)

/*

3 Užduotis:
 - Klasė geometrinė figūra:
   - perimentras (p)
   - plotas (s)
 - Klasė stačiakampis (kilęs iš klasės geometrinė figūra):
   - ilgis
   - plotis
 - Klasė stačiakampis gretasienis (kilęs iš klasės stačiakampis):
   - aukštis
   - turis
 - Įrašo į stačiakampį gretasienį duomenis per konstruktorius
 - Apskaičiuoja plotą, perimetrą
 - Atspausdina visą informaciją 
*/

class GeometrineFigura {
protected:
	double plotas;
	double perimetras;

public:
	virtual void skaiciuotiPlota() = 0;
	virtual void skaiciuotiPerimetra() = 0;

	virtual void perskaiciuoti() {
		skaiciuotiPerimetra();
		skaiciuotiPlota();
	}

	double gautiPlota() { return this->plotas; }
	double gautiPerimetra() { return this->perimetras; }

	virtual void spausdinti() {
		std::cout << "Plotas: " << plotas << std::endl;
		std::cout << "Perimetras: " << perimetras << std::endl;
	}
};

class Staciakampis : public GeometrineFigura {
protected:
	double ilgis;
	double plotis;

public:
	virtual void skaiciuotiPerimetra() {
		perimetras = 2*(this->ilgis+this->plotis);
	}

	virtual void skaiciuotiPlota() {
		plotas = this->ilgis*this->plotis;
	}

	Staciakampis(double ilgis, double plotis) : GeometrineFigura() {
		this->ilgis = ilgis;
		this->plotis = plotis;
	}

	void keistiIlgi(double ilgis) { 
		this->ilgis = ilgis;
	}
	double gautiIlgi() { return this->ilgis; }

	void keistiPloti(double plotis) { 
		this->plotis = plotis; 
	}
	double gautiPloti() { return this->plotis; }
	
	virtual void spausdinti() {
		GeometrineFigura::spausdinti();
		std::cout << "Ilgis: " << ilgis << std::endl;
		std::cout << "Plotis: " << plotis << std::endl;
	}
};

class StaciakampisGretasienis : public Staciakampis {
protected:
	double aukstis;
	double turis;

public:
	virtual void skaiciuotiTuri() { 
		this->turis = plotas*aukstis;
	}

	virtual void skaiciuotiPerimetra() {
		Staciakampis::skaiciuotiPerimetra();
		perimetras += 2*aukstis;
	}

	virtual void perskaiciuoti() {
		Staciakampis::perskaiciuoti();
		skaiciuotiTuri();
	}

	StaciakampisGretasienis(double ilgis, double plotis, double aukstis)
	                        : Staciakampis(ilgis, plotis) {
		this->aukstis = aukstis;
	}

	void keistiAuksti(double aukstis) { this->aukstis = aukstis; }
	double gautiAuksti() { return this->aukstis; }

	double gautiTuri() { return this->turis; }
	
	virtual void spausdinti() {
		Staciakampis::spausdinti();
		std::cout << "Aukštis: " << aukstis << std::endl;
		std::cout << "Tūris: " << turis << std::endl;
	}
};

int main() {
	double ilgis, aukstis, plotis;

	std::cout << "Įveskite ilgį: ";
	std::cin >> ilgis;

	std::cout << "Įveskite plotį: ";
	std::cin >> plotis;

	std::cout << "Įveskite aukštį: ";
	std::cin >> aukstis;

	StaciakampisGretasienis stac(ilgis, plotis, aukstis);
	stac.perskaiciuoti();
	stac.spausdinti();

	return 0;
}
