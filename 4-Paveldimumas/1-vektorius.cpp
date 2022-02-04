#include <iostream>
#include <cmath> // sqrt
#define POW_2(x) (x*x)

/*

1 Užduotis:
 - Klasė 2d vektorius:
   - x
   - y
   - ats
 - Klasė 3d vektorius (kilęs iš 2d vektoriaus):
   - z
   - ats
 - Įrašo į 3d vektorų duomenis
 - Apskaičiuoja jo atstumą
 - Atstumą atspausdina
*/

class Vektorius2D {
protected:
	double x;
	double y;
	double ats;

	virtual void skaiciuotiAts() {
		this->ats = sqrt(POW_2(this->x)+POW_2(this->y));
	}

public:
	void keistiX(double x) {
		this->x = x;
		skaiciuotiAts();
	}
	double gautiX() { return this->x; }
	
	void keistiY(double y) {
		this->y = y;
		skaiciuotiAts();
	}
	double gautiY() { return this->y; }

	double gautiAts() { return this->ats; }
};

class Vektorius3D : public Vektorius2D {
protected:
	double z;

	void skaiciuotiAts() {
		this->ats = sqrt(POW_2(this->x)+POW_2(this->y)+POW_2(this->z));
	}

public:
	void keistiZ(double z) {
		this->z = z;
		skaiciuotiAts();
	}
	double gautiZ() { return this->z; }
};

int main() {
	int x, y, z;
	Vektorius3D v;

	std::cout << "Įveskite vektoriaus koordinates (x y z): ";
	std::cin >> x >> y >> z;

	v.keistiX(x);
	v.keistiY(y);
	v.keistiZ(z);

	std::cout << "Vektoriaus ilgis: " << v.gautiAts() << std::endl;
}
