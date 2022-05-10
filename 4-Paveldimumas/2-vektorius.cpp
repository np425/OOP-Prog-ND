#include <iostream>
#include <cmath>

#define POW_2(x) ((x)*(x))

/*

4.2 Užduotis:
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
    double x_;
    double y_;

public:
    Vektorius2D(double x, double y) : x_(x), y_(y) {
    }

    virtual inline double skaiciuotiAtstuma() {
        return std::sqrt(POW_2(x_) + POW_2(y_));
    }
};

class Vektorius3D : public Vektorius2D {
protected:
    double z_;

public:
    Vektorius3D(double x, double y, double z) : Vektorius2D(x, y), z_(z) {
    }

    inline double skaiciuotiAtstuma() override {
        return std::sqrt(POW_2(x_) + POW_2(y_) + POW_2(z_));
    }
};

int main() {
    int x, y, z;

    std::cout << "Įveskite vektoriaus koordinates (x y z): ";
    std::cin >> x >> y >> z;

    Vektorius3D vektorius(x, y, z);

    std::cout << "Vektoriaus ilgis: " << vektorius.skaiciuotiAtstuma() << std::endl;

    return 0;
}
