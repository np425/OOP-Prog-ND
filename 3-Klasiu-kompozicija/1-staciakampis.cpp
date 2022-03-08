#include <iostream>
#include <cmath>

/*

1 Užduotis:
 - Klasė Taškas:
  - x, y
  - implementuoja atimtį, tai yra atstumą tarp dviejų taškų
 - Klasė Stačiakampis:
   - 4 taškai
   - plotas()
   - perimetras()
*/

class Taskas {
public:
	double x;
	double y;

	double operator-(const Taskas&);
};

double Taskas::operator-(const Taskas& t) {
	return sqrt(pow(x-t.x, 2) + pow(y-t.y, 2));
}

class Staciakampis {
	Taskas t[4];
	double atk[2];
	double s;
	double p;

public:	
	Staciakampis(Taskas[4]);
	double perimetras();
	double plotas();
};

// Netikrina ar iš tikrujų yra stačiakampis
// Ima kad 4 taškai iš tiesų sudaro stačiakampį
// Todėl 4 taškas nebūtinas
Staciakampis::Staciakampis(Taskas nt[4]) {
	for (int i = 0; i < 4; ++i) {
		t[i] = nt[i];
	}
	for (int i = 1; i < 4; ++i) {
		if (t[i].x == t[0].x) {
			atk[0] = t[0] - t[i];
		} else if (t[i].y == t[0].y) {
			atk[1] = t[0] - t[i];
		}
	}
}

double Staciakampis::perimetras() {
	return (atk[0] + atk[1]) * 2;
}

double Staciakampis::plotas() {
	return atk[0] * atk[1];
}

int main() {
	Taskas t[4];

	for (int i = 1; i <= 4; ++i) {
		std::cout << "Įveskite " << i << " taško koordinates (x y): " << std::endl;
		std::cin >> t[i-1].x >> t[i-1].y;
	}

	Staciakampis st(t);

	std::cout << "Stačiakampio perimetras: " << st.perimetras() << std::endl;
	std::cout << "Stačiakampio plotas: " << st.plotas() << std::endl;

	return 0;
}
