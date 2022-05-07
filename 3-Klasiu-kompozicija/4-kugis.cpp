#include <iostream>
#include <cmath>
#include <array>

#define POW_2(x) ((x)*(x))

/*

3.4 Užduotis:
 - Klasė taškas:
   - x
   - y
 - Klasė atkarpa
   - 2 taškai
   - atstumas
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

class Taskas {
public:
    double x;
    double y;

    friend std::istream &operator>>(std::istream &is, Taskas &taskas) {
        return is >> taskas.x >> taskas.y;
    }
};

class Atkarpa {
    std::array<Taskas, 2> taskai_;
    double atstumas_;

    inline double skaiciuotiAtstuma() const {
        return std::sqrt(POW_2(taskai_[1].x - taskai_[0].x) + POW_2(taskai_[1].y - taskai_[0].y));
    }

public:
    explicit Atkarpa(std::array<Taskas, 2> taskai) : taskai_(taskai) {
        atstumas_ = skaiciuotiAtstuma();
    }

    double gautiAtstuma() const {
        return atstumas_;
    }
};


class Skritulys {
    Atkarpa spindulys_;
    double plotas_;

    inline double skaiciuotiPlota() const {
        return M_PI * POW_2(spindulys_.gautiAtstuma());
    }

public:
    explicit Skritulys(Atkarpa spindulys) : spindulys_(spindulys) {
        plotas_ = skaiciuotiPlota();
    }

    double gautiPlota() const {
        return plotas_;
    }
};

class Kugis {
    std::array<Skritulys, 2> pagrindai_;
    Atkarpa aukstis_;
    double turis_;

    inline double skaiciuotiTuri() {
        return (pagrindai_[0].gautiPlota()
                + std::sqrt(pagrindai_[0].gautiPlota() * pagrindai_[1].gautiPlota())
                + pagrindai_[1].gautiPlota()) / 3 * aukstis_.gautiAtstuma();
    }

public:
    Kugis(std::array<Skritulys, 2> pagrindai, Atkarpa aukstis) : pagrindai_(pagrindai), aukstis_(aukstis) {
        turis_ = skaiciuotiTuri();
    }

    double gautiTuri() const {
        return turis_;
    }
};

inline Atkarpa gautiAtkarpa(const char *kieno) {
    std::array<Taskas, 2> taskai{};

    std::cout << kieno << " pradžios koordinatė (x y): ";
    std::cin >> taskai[0];

    std::cout << kieno << " pabaigos koordinatė (x y): ";
    std::cin >> taskai[1];

    return Atkarpa(taskai);
}

int main() {
    Atkarpa spindulys1 = gautiAtkarpa("1 pagrindo spindulio");
    Atkarpa spindulys2 = gautiAtkarpa("2 pagrindo spindulio");
    Atkarpa aukstine = gautiAtkarpa("Aukštinės");

    Kugis kugis({Skritulys(spindulys1), Skritulys(spindulys2)}, aukstine);

    std::cout << "Kūgio tūris: " << kugis.gautiTuri() << std::endl;

    return 0;
}
