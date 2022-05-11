#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>

#define LINE "----------------------------------"

/*

7.2 Užduotis:
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
 - Laikoma brangiausia, ir pigiausia prekes per visa programas leidima
 - Kainos spausdinamos
*/

class Prekes {
    std::string pavadinimas_;
    unsigned kiekis_{};
    double vntKaina_{};
    double kiekioKaina_{};

    static double visuPrekiuKaina_;

    static Prekes *pigiausia_;
    static Prekes *brangiausia_;

    Prekes() = default;

public:
    Prekes(std::string pavadinimas, unsigned kiekis, double vntKaina) : pavadinimas_(std::move(pavadinimas)),
        kiekis_(kiekis), vntKaina_(vntKaina) {
        kiekioKaina_ = vntKaina_ * kiekis_;
        visuPrekiuKaina_ += kiekioKaina_;

        if (!pigiausia_ || kiekioKaina_ < pigiausia_->kiekioKaina_) {
            pigiausia_ = this;
        }

        if (!brangiausia_ || kiekioKaina_ > brangiausia_->kiekioKaina_) {
            brangiausia_ = this;
        }
    }

    ~Prekes() {
        visuPrekiuKaina_ -= kiekioKaina_;
    }

    std::string gautiPavadinima() const {
        return pavadinimas_;
    }

    unsigned gautiKieki() const {
        return kiekis_;
    }

    double gautiVntKaina() const {
        return vntKaina_;
    }

    double gautiKiekioKaina() const {
        return kiekioKaina_;
    }

    static double gautiVisuPrekiuKaina() {
        return visuPrekiuKaina_;
    }

    static Prekes *gautiPigiausiaPreke() {
        return pigiausia_;
    }

    static Prekes *gautiBrangiausiaPreke() {
        return brangiausia_;
    }
};

double Prekes::visuPrekiuKaina_ = 0;
Prekes *Prekes::pigiausia_ = nullptr;
Prekes *Prekes::brangiausia_ = nullptr;

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

    Prekes *pigiausiaPreke = Prekes::gautiPigiausiaPreke();
    Prekes *brangiausiaPreke = Prekes::gautiBrangiausiaPreke();

    if (pigiausiaPreke) {
        std::cout << "Pigiausia prekė: " << pigiausiaPreke->gautiPavadinima() << ", "
                  << pigiausiaPreke->gautiVntKaina();
        std::cout << " x " << pigiausiaPreke->gautiKieki() << " = "
                  << pigiausiaPreke->gautiKiekioKaina() << std::endl;
    } else {
        std::cout << "Pigiausios prekės nėra" << std::endl;
    }

    if (brangiausiaPreke) {
        std::cout << "Brangiausia prekė: " << brangiausiaPreke->gautiPavadinima() << ", "
                  << brangiausiaPreke->gautiVntKaina();
        std::cout << " x " << brangiausiaPreke->gautiKieki() << " = "
                  << brangiausiaPreke->gautiKiekioKaina() << std::endl;
    } else {
        std::cout << "Brangiausios prekės nėra" << std::endl;
    }

    return 0;
}