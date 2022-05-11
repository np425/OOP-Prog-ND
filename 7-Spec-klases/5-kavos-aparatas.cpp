#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <stdexcept>

/*

7.5 Užduotis:
 - Klasė Gėrimas:
   - pavadinimas
   - kaina
 - Klasė KavosAutomatas:
   - Laiko gėrimus
   - Leidžia pasirinkti gėrimą
   - Leidžia nusipirkti gėrimą ir atmeta gražą
 - Pasirenka gėrimą
 - Nusiperka gėrimą
 - Atspausdina gražą
*/

// Išreiškiama sveikais skaičiais kad lengviau būtų skaičiuoti
typedef unsigned Centai;

constexpr std::array<Centai, 8> NOMINALAI = {200, 100, 50, 20, 10, 5, 2, 1};

struct Gerimas {
    const char *pavadinimas;
    Centai kainaCentais;

    friend std::ostream &operator<<(std::ostream &is, const Gerimas &gerimas) {
        std::cout << gerimas.pavadinimas << ": " << gerimas.kainaCentais / 100.0 << "€";
        return is;
    }
};

std::vector<double> atskirtiGraza(Centai visaGraza) {
    std::vector<double> atsGraza;

    for (unsigned i = 0; i < NOMINALAI.size();) {
        if (visaGraza / NOMINALAI[i]) {
            visaGraza = visaGraza - NOMINALAI[i];
            atsGraza.push_back(NOMINALAI[i] / 100.0);
        } else {
            ++i;
        }
    }

    return atsGraza;
}

class KavosAutomatas {
public:
    static constexpr const unsigned GERIMU_KIEKIS = 5;
    static constexpr const std::array<Gerimas, GERIMU_KIEKIS> GERIMAI = {
        Gerimas{"Latte", 70},
        Gerimas{"Cappuccino", 80},
        Gerimas{"Espresso", 90},
        Gerimas{"Affogato", 130},
        Gerimas{"Flat White", 70}
    };

private:
    static const Gerimas *gerimoPasirinkimas_;

public:
    static void pasirinktiMeniuGerima(unsigned gerimoMeniuSkaicius) {
        if (gerimoMeniuSkaicius > GERIMU_KIEKIS) {
            throw std::runtime_error("Nėra tokio gėrimo");
        }
        gerimoPasirinkimas_ = &GERIMAI[gerimoMeniuSkaicius - 1];
    }

    static std::vector<double> pirktiPasirinktaGerima(double imoka) {
        if (!gerimoPasirinkimas_) {
            throw std::runtime_error("Nėra pasirinkto gėrimo");
        }

        auto imokaCentais = (Centai) (imoka * 100);

        if (imokaCentais < gerimoPasirinkimas_->kainaCentais) {
            throw std::runtime_error("Neužtenka pinigų nusipirkti gėrimo");
        }

        Centai visaGraza = imokaCentais - gerimoPasirinkimas_->kainaCentais;

        return atskirtiGraza(visaGraza);
    }

    static void rodytiMeniu() {
        for (unsigned i = 0; i < GERIMU_KIEKIS; ++i) {
            std::cout << i + 1 << ". " << GERIMAI[i] << std::endl;
        }
    }
};

const Gerimas *KavosAutomatas::gerimoPasirinkimas_ = nullptr;
constexpr const std::array<Gerimas, KavosAutomatas::GERIMU_KIEKIS> KavosAutomatas::GERIMAI;
//= {
//    Gerimas{"Latte", 70},
//    Gerimas{"Cappuccino", 80},
//    Gerimas{"Espresso", 90},
//    Gerimas{"Affogato", 130},
//    Gerimas{"Flat White", 70}
//};

void nusipirktiGerima() {
    unsigned gerimoMeniuSkaicius;

    std::cout << "Įveskite gėrimo skaičių: ";
    std::cin >> gerimoMeniuSkaicius;

    KavosAutomatas::pasirinktiMeniuGerima(gerimoMeniuSkaicius);

    double imoka;
    std::cout << "Įveskite pinigų įmoką: ";
    std::cin >> imoka;

    std::vector<double> graza = KavosAutomatas::pirktiPasirinktaGerima(imoka);

    std::cout << "Graža: " << std::endl;
    for (const double &pinigas: graza) {
        std::cout << pinigas << "€" << std::endl;
    }
}

int main() {
    KavosAutomatas::rodytiMeniu();

    try {
        nusipirktiGerima();
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
