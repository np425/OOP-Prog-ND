#include <iostream>
#include <cmath> // M_PI
#define POW_2(x) (x*x)

/*

1 Užduotis:
 - Klasė stačiakampis <T1,T2>
   - ilgis (T1)
   - plotis (T2)
   - plotas (T2)
 - Sukuria trys stačiakampio objektus:
   1. <int,int>
   2. <double,double>
   3. <int,double>
 - Juos nuskaito
 - Atspausdina kiekvieno stačiakampio plotą
*/

template <typename T1, typename T2>
class Staciakampis {
	T1 ilgis;
	T2 plotis;
	T2 plotas;

public:
	T2 gautiPlota() {
		return this->plotas;
	}

	void keistiIlgi(T1 ilgis) {
		this->ilgis = ilgis;
		plotas = ilgis*plotis;
	}

	void keistiPloti(T2 plotis) {
		this->plotis = plotis;
		plotas = ilgis*plotis;
	}
};

template <typename T1, typename T2>
void nuskaitytiStaciakampi(Staciakampis<T1,T2>& stac) {
	T1 ilgis;
	T2 plotis;

	std::cout << "Įveskite stačiakampio ilgį: ";
	std::cin >> ilgis;

	std::cout << "Įveskite stačiakampio plotį: ";
	std::cin >> plotis;

	stac.keistiIlgi(ilgis);
	stac.keistiPloti(plotis);
}

int main() {
	Staciakampis<int, int> stac1;
	Staciakampis<double, double> stac2;
	Staciakampis<int, double> stac3;

	std::cout << "1. ilgis, plotis ir plotas - sveikieji skaičiai" << std::endl;
	nuskaitytiStaciakampi(stac1);
	std::cout << "Plotas: " << stac1.gautiPlota() << std::endl;

	std::cout << "2. ilgis, plotis ir plotas - realieji skaičiai" << std::endl;
	nuskaitytiStaciakampi(stac2);
	std::cout << "Plotas: " << stac2.gautiPlota() << std::endl;

	std::cout << "3. ilgis - sveikasis skaičius, plotis ir plotas - realieji skaičiai" << std::endl;
	nuskaitytiStaciakampi(stac3);
	std::cout << "Plotas: " << stac3.gautiPlota() << std::endl;

	return 0;
}
