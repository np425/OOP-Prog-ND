#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>

#define LINE "----------------------------------"

/*

7.1 Užduotis:
 - Klasė prekės:
   - pavadinimas
   - kiekis
   - vieneto kaina
   - kiekio kaina
   - visų prekių kaina (statinis kintamasis)
 - Nuskaito kiekvienos prekės informaciją
 - Objektai yra masyve
 - Suskaičiuojama prekių vertės
 - Suskaičiuojama visų prekių vertės per statinį kintamąjį
 - Kainos spausdinamos
*/

class Prekes {
    std::string pavadinimas_;
    unsigned kiekis_;
    double vntKaina_;
    double kiekioKaina_;

    static double visuPrekiuKaina_;

public:
    Prekes(std::string pavadinimas, unsigned kiekis, double vntKaina) : pavadinimas_(std::move(pavadinimas)),
        kiekis_(kiekis), vntKaina_(vntKaina) {
        kiekioKaina_ = vntKaina_ * kiekis_;
        visuPrekiuKaina_ += kiekioKaina_;
    }

    ~Prekes() {
        visuPrekiuKaina_ -= kiekioKaina_;
    }

    std::string gautiPavadinima() const {
        return pavadinimas_;
    }

    double gautiKiekioKaina() const {
        return kiekioKaina_;
    }

    static double gautiVisuPrekiuKaina() {
        return visuPrekiuKaina_;
    }
};

double Prekes::visuPrekiuKaina_ = 0;

int main() {
    unsigned prekiuKiekis;

    std::cout << "Įveskite skirtingų prekių kiekį: ";
    std::cin >> prekiuKiekis;

    std::vector<std::unique_ptr<Prekes>> prekes(prekiuKiekis);

    for (unsigned i = 0; i < prekiuKiekis; ++i) {
        std::string pavadinimas;
        unsigned vntKiekis;
        double vntKaina;

        std::cout << "Įveskite " << i + 1 << " prekės pavadinimą: ";
        std::cin >> pavadinimas;

        std::cout << "Įveskite vienetų kiekį: ";
        std::cin >> vntKiekis;

        std::cout << "Įveskite vieneto kainą: ";
        std::cin >> vntKaina;

        prekes[i] = std::make_unique<Prekes>(pavadinimas, vntKiekis, vntKaina);
    }

    for (const auto &preke: prekes) {
        double kaina = preke->gautiKiekioKaina();
        std::cout << std::left << std::setw(25) << preke->gautiPavadinima() << kaina << std::endl;
    }

    std::cout << LINE << std::endl;
    std::cout << std::left << std::setw(25) << "Visų prekių kaina"
              << Prekes::gautiVisuPrekiuKaina() << std::endl;

    return 0;
}
