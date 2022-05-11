#include <iostream>
#include <string>
#include <array>
#include <utility>

/*

2.6 Užduotis:
 - Klasė Studentas:
   - vardas
   - pavardė
   - kreditai
   - pažymiai
   - skaičiuoja vidurkį: 
     - suma kredito su įvertinimu sandauga ir padalinima iš visų kreditų sumos
 - Nuskaito duomenis
 - Įrašo duomenis į Studentas objektą
 - Atspausdina duomenis su vidurkiu
*/

constexpr unsigned DALYKU_SK = 6;

struct Dalykas {
    unsigned kreditai;
    unsigned pazymis;
};

typedef std::array<Dalykas, DALYKU_SK> Dalykai;

class Studentas {
    std::string vardas_;
    std::string pavarde_;
    Dalykai dalykai_;
    double vidurkis_;

    inline double skaiciuotiVidurki() {
        double vid = 0;
        double kredSum = 0;

        for (unsigned i = 0; i < DALYKU_SK; ++i) {
            vid += dalykai_[i].kreditai * dalykai_[i].pazymis;
            kredSum += dalykai_[i].kreditai;
        }

        return vid / kredSum;
    }

public:
    Studentas(std::string vardas, std::string pavarde, Dalykai dalykai)
        : vardas_(std::move(vardas)), pavarde_(std::move(pavarde)), dalykai_(dalykai) {
        vidurkis_ = skaiciuotiVidurki();
    }

    friend std::ostream& operator<<(std::ostream& os, const Studentas& studentas) {
        os << "Dalykų skaičius: " << DALYKU_SK << std::endl;
        os << "Vardas: " << studentas.vardas_ << std::endl;
        os << "Pavardė: " << studentas.pavarde_ << std::endl;

        os << "Kreditai: ";
        for (const Dalykas &dalykas: studentas.dalykai_) {
            os << dalykas.kreditai << " ";
        }
        os << std::endl;

        os << "Įvertinimai: ";
        for (const Dalykas &dalykas: studentas.dalykai_) {
            os << dalykas.pazymis << " ";
        }
        os << std::endl;

        os << "Vidurkis: " << studentas.vidurkis_;
        return os;
    }
};

int main() {
    std::string vardas;
    std::string pavarde;
    Dalykai dalykai;

    std::cout << "Įveskite vardą:" << std::endl;
    std::cin >> vardas;

    std::cout << "Įveskite pavardę:" << std::endl;
    std::cin >> pavarde;

    std::cout << "Įveskite " << DALYKU_SK << " kreditus (atskirtais tarpais)" << std::endl;
    for (Dalykas &dalykas: dalykai) {
        std::cin >> dalykas.kreditai;
    }

    std::cout << "Įveskite " << DALYKU_SK << " pažymius (atskirtais tarpais)" << std::endl;
    for (Dalykas &dalykas: dalykai) {
        std::cin >> dalykas.pazymis;
    }

    Studentas studentas(vardas, pavarde, dalykai);

    std::cout << studentas << std::endl;

    return 0;
}
