#include <iostream>

/*

4 Užduotis:
 - Klasė Taskas:
   - x
   - y
 - Klasė Staciakampis:
   - bendras (statinis) taškas t1
   - atskiras taškas t2
   - skaičiuoja perimetrą
   - skaičiuoja plotą
 - Pasirenka kiekį stačiakampių
 - Atspausdina plotą, perimetrą 
*/

struct Taskas {
    double x;
    double y;
};

std::istream& operator>>(std::istream& is, Taskas& t) {
    std::cin >> t.x >> t.y;
}

class Staciakampis {
    static Taskas t1;
    Taskas t2;

public:
    Staciakampis() {
    }

    static void keistiT1(Taskas t) {
        t1 = t;
    }

    void keistiT2(Taskas t) {
        t2 = t;
    }

    double gautiPerimetra() {
        return abs(2 * (t2.x - t1.x + t2.y - t1.y));
    }

    double gautiPlota() {
        return abs((t2.x - t1.x) * (t2.y - t1.y));
    }
};
Taskas Staciakampis::t1;

int main() {
    Taskas t;

    std::cout << "Iveskite pirmaji staciakampiu taska (x,y):" << std::endl;
    std::cin >> t;

    Staciakampis::keistiT1(t);

    unsigned n;
    std::cout << "Kiek staciakampiu skaiciuosite?" << std::endl;
    std::cin >> n;    

    Staciakampis* stac = new Staciakampis[n];

    for (unsigned i = 0; i < n; ++i) {
        std::cout << "Iveskite " << i+1 << " staciakampo antraji taska (x,y):" << std::endl;
        std::cin >> t;

        stac[i].keistiT2(t);
    }

    for (unsigned i = 0; i < n; ++i) {
        std::cout << i + 1 << " Staciakampio perimetras = " << stac[i].gautiPerimetra() << std::endl;
        std::cout << i + 1 << " Staciakampio plotas = " << stac[i].gautiPlota() << std::endl;
    }

    delete[] stac;

    return 0;
}
