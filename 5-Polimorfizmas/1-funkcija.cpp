#include <iostream> #include <cmath> // pow

/*

1 Užduotis:
 - Klasė Funkcija (abstrakti):
   - f(x) (abstraktus metodas)
 - Klasė Laipsninė funkcija (kilus iš klasės funkcija):
   - f(x)
 - Klasė Tiesinė funkcija (kilus iš klasės funkcija):
   - f(x)
 - Klasė Sinusoidė (kilus iš klasės funkcija):
   - f(x)
 - Nuskaitoma k, b, n kintamieji
 - Masyvas į kiekvieną išvestinę funkciją, su atitinkamais kintamaisiais
 - Išsprendžiama kiekviena funkcija su x
 - Atspausdinamas rezultatas
*/

class Funkcija {
public:
	virtual double f(double x) = 0;

	virtual const char* pav() = 0;
};

class TiesineFunkcija : public Funkcija {
	double k;
	double b;

public:
	TiesineFunkcija(double k, double b) : k(k), b(b) {}

	virtual double f(double x) { return k*x+b; }
	
	virtual const char* pav() { return "tiesinė"; }
};

class LaipsnineFunkcija : public Funkcija {
	double n;

public:
	LaipsnineFunkcija(double n) : n(n) {}

	virtual double f(double x) { return pow(x, n); }
	
	virtual const char* pav() { return "laipsninė"; }
};

class Sinusoide : public Funkcija {
public:
	virtual double f(double x) { return sin(x); }
	
	virtual const char* pav() { return "sinusoidė"; }
};

int main() {
	double k, b, n, x;
	Funkcija* func[3];

	std::cout << "Įveskite tiesinės funkcijos k kintamąjį: ";
	std::cin >> k;

	std::cout << "Įveskite tiesinės funkcijos b kintamąjį: ";
	std::cin >> b;

	std::cout << "Įveskite laipsninės funkcijos n kintamąjį: ";
	std::cin >> n;
	
	std::cout << "Įveskite x: ";
	std::cin >> x;
	
	func[0] = new TiesineFunkcija(k, b);
	func[1] = new LaipsnineFunkcija(n);
	func[2] = new Sinusoide();

	for (int i = 0; i != 3; ++i) {
		std::cout << func[i]->pav() << ": y=" << func[i]->f(x) << std::endl;
	}

	return 0;
}
