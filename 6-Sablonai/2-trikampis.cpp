#include <iostream>
#include <cmath> 
#include <string>

/*

2 Užduotis:
 - Klasė trikampis
 	- a
	- b
	- c 
*/

class NetaisyklingasTrikampis {
	std::string klaida;

public:
	NetaisyklingasTrikampis(std::string klaida) : klaida(klaida) {}
	std::string gautiKlaida() const { return klaida; }
};

class Trikampis {
	double a, b, c, ilg;

	double ilgKrastine() {
		if (a > b && a > c) {
			return a;
		} 
		if (b > a && b > c) {
			return b;
		}
		return c;
	}

public:
	Trikampis(double a, double b, double c) : a(a), b(b), c(c) {
		ilg = ilgKrastine();
		if (a > b && a > c) {
			ilg = a;
		}
		
		if (a+b < c || a+c < b || b+c < a) {
			throw NetaisyklingasTrikampis("Ilgiausia kraštinė: " + std::to_string(ilg));
		}
	}
};

int main() {
	double a, b, c;

	std::cout << "Iveskite kraštinę a: " << std::endl;
	std::cin >> a;

	std::cout << "Iveskite kraštinę b: " << std::endl;
	std::cin >> b;

	std::cout << "Iveskite kraštinę c: " << std::endl;
	std::cin >> c;

	try {
		Trikampis t(a,b,c);
		std::cout << "Taisyklingas trikampis" << std::endl;
	} catch (const NetaisyklingasTrikampis& t) {
		std::cerr << "Netaisyklingas trikampis" << std::endl;
		std::cerr << t.gautiKlaida() << std::endl;
	}

	return 0;
}
