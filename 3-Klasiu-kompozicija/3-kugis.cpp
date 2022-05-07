#include <iostream>
#include <cmath>
#include <array>

#define POW_2(x) ((x)*(x))

/*

3.3 Užduotis:
 - Klasė skritulys:
   - Spindulys
   - Plotas
 - Klasė kūgis:
   - Aukštinė
   - 2 pagrindai (klasė skritulys)
   - Tūris
 - Įrašo į kūgi duomenis
 - Apskaičiuoja jo tūrį
 - Tūrį atspausdina

*/

class Skritulys {
    double spindulys_;
    double plotas_;

    inline double skaiciuotiPlota() const {
        return M_PI * POW_2(spindulys_);
    }

public:
    explicit Skritulys(double spindulys) : spindulys_(spindulys) {
        plotas_ = skaiciuotiPlota();
    }

    double gautiPlota() const {
        return plotas_;
    }
};

class Kugis {
    std::array<Skritulys, 2> pagrindai_;
    double aukstis_;
    double turis_;

    inline double skaiciuotiTuri() {
        return (pagrindai_[0].gautiPlota()
                + std::sqrt(pagrindai_[0].gautiPlota() * pagrindai_[1].gautiPlota())
                + pagrindai_[1].gautiPlota()) / 3 * aukstis_;
    }

public:
    Kugis(std::array<double, 2> spinduliai, double aukstis) :
        pagrindai_({Skritulys(spinduliai[0]), Skritulys(spinduliai[1])}), aukstis_(aukstis) {
        turis_ = skaiciuotiTuri();
    }

    double gautiTuri() const {
        return turis_;
    }
};

int main() {
    std::array<double, 2> spinduliai{};
    double aukstis;

    std::cout << "1 pagrindo spindulys: ";
    std::cin >> spinduliai[0];

    std::cout << "2 pagrindo spindulys: ";
    std::cin >> spinduliai[1];

    std::cout << "Kūgio aukštinė: ";
    std::cin >> aukstis;

    Kugis kugis(spinduliai, aukstis);

    std::cout << "Kūgio tūris: " << kugis.gautiTuri() << std::endl;

    return 0;
}
