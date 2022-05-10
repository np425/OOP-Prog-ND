#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define LINE "--------------------------"

/*

4.1 Užduotis:
 - Klasė asmuo:
   - vardas
   - pavardė
   - amžius
 - Klasė studentas (nuo asmens klasės):
   - id
   - vidurkis
   - dalykai (pavadinimas, pažymys)
   - skaičiuoja vidurkį
 - Nuskaito duomenis ir įrašo į studento objektą
 - Apskaičiuoja vidurkį
 - Atspausdina visus duomenis apie studentą
*/

class Asmuo {
    std::string vardas_;
    std::string pavarde_;
    unsigned amzius_;

public:
    Asmuo(std::string vardas, std::string pavarde, unsigned amzius) : vardas_(std::move(vardas)),
        pavarde_(std::move(pavarde)), amzius_(amzius) {
    }

    friend std::ostream &operator<<(std::ostream &os, const Asmuo &asmuo) {
        return os << asmuo.vardas_ << " " << asmuo.pavarde_ << " (" << asmuo.amzius_ << ")";
    }
};

class Studentas : public Asmuo {
    unsigned id_;
    std::vector<std::string> dalykai_;
    double vidurkis_;
public:
    Studentas(std::string vardas, std::string pavarde, unsigned amzius, unsigned id, std::vector<std::string> dalykai,
              double vidurkis) :
        Asmuo(std::move(vardas), std::move(pavarde), amzius), id_(id),
        dalykai_(std::move(dalykai)),
        vidurkis_(vidurkis) {
    }

    friend std::ostream &operator<<(std::ostream &os, const Studentas &studentas) {
        os << (const Asmuo &) studentas << " ID = " << studentas.id_ << std::endl;
        os << "Dalykai: " << std::endl;

        for (const std::string &dalykas: studentas.dalykai_) {
            os << "- " << dalykas << std::endl;
        }

        os << LINE << std::endl;

        os << "Vidurkis: " << studentas.vidurkis_;
        return os;
    }
};

int main() {
    std::string vardas, pavarde;
    unsigned amzius, id, dalykuKiekis;
    double vidurkis;

    std::cout << "Įveskite vardą: ";
    std::cin >> vardas;

    std::cout << "Įveskite pavardę: ";
    std::cin >> pavarde;

    std::cout << "Įveskite amžių: ";
    std::cin >> amzius;

    std::cout << "Įveskite studento ID: ";
    std::cin >> id;

    std::cout << "Įveskite dalykų kiekį: ";
    std::cin >> dalykuKiekis;

    std::vector<std::string> dalykai(dalykuKiekis);

    for (unsigned i = 0; i < dalykuKiekis; ++i) {
        std::cout << "Įveskite " << i + 1 << " dalyko pavadinimą: " << std::endl;

        std::string pav;
        std::cin >> pav;

        dalykai[i] = pav;
    }

    std::cout << "Įveskite dalykų vidurkį: ";
    std::cin >> vidurkis;

    Studentas studentas(vardas, pavarde, amzius, id, dalykai, vidurkis);
    std::cout << studentas << std::endl;

    return 0;
}
