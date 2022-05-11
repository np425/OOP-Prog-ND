#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>

#define LINE "----------------------------------"

/*

5.3 Užduotis:
 - Klasė prekės:
   - pavadinimas
   - kiekis
   - vieneto kaina
 - Klasė prekės su nuolaida (kilus iš klasės prekės):
   - pavadinimas
   - kiekis
   - nuolaidos dydis
 - Nuskaito kiekvienos prekės informaciją
 - Jei turi nuolaida sukuriamas prekės su nuolaidą objektas
 - Jei neturi nuolaidos sukuriamas prekės objektas
 - Objektai yra masyve
 - Suskaičiuojama prekių vertės
 - Suskaičiuojama visų prekių vertės
 - Kainos spausdinamos
*/

class Prekes {
protected:
    std::string pavadinimas_;
    unsigned kiekis_;
    double vntKaina_;

public:
    Prekes(std::string pavadinimas, unsigned kiekis, double vntKaina) : pavadinimas_(std::move(pavadinimas)),
        kiekis_(kiekis), vntKaina_(vntKaina) {
    }

    std::string gautiPavadinima() const {
        return pavadinimas_;
    }

    virtual double gautiKiekioKaina() const {
        return kiekis_ * vntKaina_;
    }
};

class Prekes_su_nuolaida : public Prekes {
    double nuolaida_;

public:
    Prekes_su_nuolaida(std::string pavadinimas, unsigned kiekis, double vntKaina, double nuolaida)
        : Prekes(std::move(pavadinimas), kiekis, vntKaina), nuolaida_(nuolaida) {
    }

    double gautiKiekioKaina() const override {
        return kiekis_ * vntKaina_ * (1 - nuolaida_);
    }
};

bool prekeTuriNuolaida() {
    while (true) {
        char atsakymas;

        std::cout << "Ar turi nuolaidą? t arba n: ";
        std::cin >> atsakymas;

        if (atsakymas == 't') {
            return true;
        } else if (atsakymas == 'n') {
            return false;
        }

        std::cout << "Nesupratau, prašome pakartoti įvėdimą." << std::endl;
    }
}

void gautiPrekes(std::vector<std::unique_ptr<Prekes>> &prekes) {
    for (unsigned i = 0; i < prekes.size(); ++i) {
        std::string pavadinimas;
        unsigned vntKiekis;
        double vntKaina;

        std::cout << "Įveskite " << i + 1 << " prekės pavadinimą: ";
        std::cin >> pavadinimas;

        std::cout << "Įveskite vienetų kiekį: ";
        std::cin >> vntKiekis;

        std::cout << "Įveskite vieneto kainą: ";
        std::cin >> vntKaina;

        if (!prekeTuriNuolaida()) {
            prekes[i] = std::make_unique<Prekes>(pavadinimas, vntKiekis, vntKaina);
            continue;
        }

        double nuolaida;

        std::cout << "Įveskite nuolaidos procento dalį: ";
        std::cin >> nuolaida;

        prekes[i] = std::make_unique<Prekes_su_nuolaida>(pavadinimas, vntKiekis, vntKaina, nuolaida);
    }
}

int main() {
    unsigned prekiuKiekis;
    double visuPrekiuKaina;

    std::cout << "Įveskite skirtingų prekių kiekį: ";
    std::cin >> prekiuKiekis;

    std::vector<std::unique_ptr<Prekes>> prekes(prekiuKiekis);

    gautiPrekes(prekes);

    for (const auto &preke: prekes) {
        double prekesKaina = preke->gautiKiekioKaina();

        visuPrekiuKaina += prekesKaina;

        std::cout << std::left << std::setw(25) << preke->gautiPavadinima() << prekesKaina << std::endl;
    }

    std::cout << LINE << std::endl;
    std::cout << std::left << std::setw(25) << "Visų prekių kaina" << visuPrekiuKaina << std::endl;

    return 0;
}
