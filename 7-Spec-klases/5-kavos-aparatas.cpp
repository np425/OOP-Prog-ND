#include <iostream>
#include <vector>
#include <string>

/*

5 Užduotis:
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
typedef unsigned centai;

struct Gerimas {
    std::string pav;
    centai kaina;
};

std::ostream& operator<<(std::ostream& is, const Gerimas& ger) {
    std::cout << ger.pav << ": " << ger.kaina / 100.0 << "€";
    return is;
}

constexpr centai NOMINALAI[] = {200, 100, 50, 20, 10, 5, 2, 1};

std::vector<double> atskirtiGraza(centai visaGraza) {
    std::vector<double> atsGraza;

    constexpr unsigned nomKiek = sizeof(NOMINALAI)/sizeof(NOMINALAI[0]);

    for (unsigned i = 0; i < nomKiek; ) {
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
    static constexpr unsigned gerimuKiek = 5;
    static Gerimas gerimai[gerimuKiek];
    static const Gerimas *pasirinkimas;

public:
    // gerSk nuo 1
    static void pasirinktiGerima(unsigned gerSk) {
        if (gerSk > gerimuKiek) {
            throw std::runtime_error("Nėra tokio gėrimo");
        }
        pasirinkimas = &gerimai[gerSk-1];
    }

    static std::vector<double> pirktiPasirinktaGerima(double mok) {
        if (!pasirinkimas) {
            throw std::runtime_error("Nėra pasirinkto gėrimo");
        }

        centai mokCentais = (centai)(mok * 100);

        if (mokCentais < pasirinkimas->kaina) {
            throw std::runtime_error("Neužtenka pinigų nusipirkti gėrimo");
        }

        centai visaGraza = mokCentais - pasirinkimas->kaina;

        return atskirtiGraza(visaGraza);
    }

    static void rodytiMeniu() {
       for (unsigned i = 0; i < gerimuKiek; ++i) {
           std::cout << i+1 << ". " << gerimai[i] << std::endl;
       }
    }
};

const Gerimas* KavosAutomatas::pasirinkimas = nullptr;
Gerimas KavosAutomatas::gerimai[gerimuKiek] = {
    {"Latte", 70}, 
    {"Cappuccino", 80}, 
    {"Espresso", 90}, 
    {"Affogato", 130}, 
    {"Flat White", 70}
};

void nusipirktiGerima() {
    unsigned gerSk;
    std::cout << "Įveskite gėrimo skaičių: ";
    std::cin >> gerSk;

    KavosAutomatas::pasirinktiGerima(gerSk);

    double piniguSuma;
    std::cout << "Įveskite pinigų sumą: ";
    std::cin >> piniguSuma;

    std::vector<double> graza;
    graza = KavosAutomatas::pirktiPasirinktaGerima(piniguSuma);

    std::cout << "Graža: " << std::endl;
    for (const double& g : graza) {
        std::cout << g << "€" << std::endl;
    }
}

int main() {
    KavosAutomatas::rodytiMeniu();

    try {
        nusipirktiGerima();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
