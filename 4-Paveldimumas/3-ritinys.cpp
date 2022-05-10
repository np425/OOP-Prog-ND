#include <iostream>
#include <cmath>

#define POW_2(x) ((x)*(x))

/*

4.3 Užduotis:
 - Klasė skritulys:
   - spindulys
   - plotas
 - Klasė ritinys (kilęs iš klasės skritulys)
   - aukštinė
   - tūris
 - Įrašo į ritinį duomenis 
 - Apskaičiuoja jo tūrį
 - Tūrį atspausdina
*/

class Skritulys {
protected:
    double spindulys_;
    double plotas_;

    inline double skaiciuotiPlota() {
        return M_PI * POW_2(spindulys_);
    }

public:
    explicit Skritulys(double spindulys) : spindulys_(spindulys) {
        plotas_ = skaiciuotiPlota();
    }
};

class Ritinys : public Skritulys {
protected:
    double aukstis_;
    double turis_;

    inline double skaiciuotiTuri() {
        return plotas_ * aukstis_;
    }

public:
    Ritinys(double spindulys, double aukstis) : Skritulys(spindulys), aukstis_(aukstis) {
        turis_ = skaiciuotiTuri();
    }

    double gautiTuri() const {
        return turis_;
    }
};

int main() {
    double spindulys, aukstis;

    std::cout << "Įveskite spindulio ilgį: ";
    std::cin >> spindulys;

    std::cout << "Įveskite aukštinės ilgį: ";
    std::cin >> aukstis;

    Ritinys ritinys(spindulys, aukstis);

    std::cout << "Ritinio tūris: " << ritinys.gautiTuri() << std::endl;

    return 0;
}
