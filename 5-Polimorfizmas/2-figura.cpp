#include <iostream>
#include <cmath>
#include <array>
#include <memory>

#define POW_2(x) ((x)*(x))

/*

5.2 Užduotis:
 - Klasė (abstrakti) geometrinė figūra:
   - plotas() (abstrakti funkcija)
 - Klasė stačiakampis (kilus iš klasės geometrinė figūra):
   - ilgis
   - plotis
   - plotas()
 - Klasė trikampis (kilus iš klasės geometrinė figūra):
   - aukštine
   - ilgis (pagrindo)
   - plotas()
 - Klasė skritulys (kilus iš klasės geometrinė figūra):
   - spindulys
   - plotas()
 - Nuskaito stačiakampio ilgį, plotą, trikampio aukštinę, pagrindo ilgį, skritulio spindulį
 - Masyvas į kiekvieną figūra, su atitinkamais kintamaisiais
 - Suskaičiuoja kiekvienos figūros plotą
 - Jį atspausdina
*/

class GeometrineFigura {
public:
    virtual double gautiPlota() const = 0;
    virtual const char *gautiPavadinima() const = 0;

    virtual ~GeometrineFigura() = default;
};

class Staciakampis : public GeometrineFigura {
protected:
    double ilgis_;
    double plotis_;

public:
    Staciakampis(double ilgis, double plotis) : ilgis_(ilgis), plotis_(plotis) {
    }

    double gautiPlota() const override {
        return ilgis_ * plotis_;
    }

    const char *gautiPavadinima() const override {
        return "stačiakampis";
    }
};

class Trikampis : public GeometrineFigura {
protected:
    double pagrIlgis_;
    double aukstis_;

public:
    double gautiPlota() const override {
        return pagrIlgis_ * aukstis_ / 2;
    }

    Trikampis(double pagrIlgis, double aukstis) : pagrIlgis_(pagrIlgis), aukstis_(aukstis) {
    }

    const char *gautiPavadinima() const override {
        return "trikampis";
    }
};

class Skritulys : public GeometrineFigura {
protected:
    double spindulys_;

public:
    explicit Skritulys(double spindulys) : spindulys_(spindulys) {
    }

    double gautiPlota() const override {
        return M_PI * POW_2(spindulys_);
    }

    const char *gautiPavadinima() const override {
        return "skritulys";
    }
};

int main() {
    double ilgis, plotis, pagrIlgis, aukstis, spindulys;

    std::cout << "Įveskite stačiakampio ilgį: ";
    std::cin >> ilgis;

    std::cout << "Įveskite stačiakampio plotį: ";
    std::cin >> plotis;

    std::cout << "Įveskite trikampio pagrindo ilgį: ";
    std::cin >> pagrIlgis;

    std::cout << "Įveskite trikampio aukštinės ilgį: ";
    std::cin >> aukstis;

    std::cout << "Įveskite apskritimo spindulį: ";
    std::cin >> spindulys;

    std::array<std::unique_ptr<GeometrineFigura>, 3> figuros = {
        std::make_unique<Staciakampis>(ilgis, plotis),
        std::make_unique<Trikampis>(pagrIlgis, aukstis),
        std::make_unique<Skritulys>(spindulys)
    };

    for (const auto &figura: figuros) {
        std::cout << figura->gautiPavadinima() << ": plotas = " << figura->gautiPlota() << std::endl;
    }

    return 0;
}
