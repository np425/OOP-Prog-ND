#include <iostream>
#include <limits>

/*

2.5 Užduotis:
 - Klasė GeometrineFigura:
   - kraštinių skaičius
   - taisyklingumas
 - Nuskaito duomenis
 - Įrašo duomenis į GeometrineFigura objektą
 - Atspausdina duomenis
*/

class GeometrineFigura {
    unsigned krastSk_;
    bool taisyklingumas_;

public:
    GeometrineFigura(unsigned krastSk, bool taisyklingumas) : krastSk_(krastSk), taisyklingumas_(taisyklingumas) {
    }

    unsigned gautiKrastSk() const {
        return krastSk_;
    }

    unsigned gautiTaisyklinguma() const {
        return taisyklingumas_;
    }
};

template<class T>
void gautiReiksme(T &reiksme) {
    while (true) {
        std::cin >> reiksme;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (std::cin) {
            break;
        }

        std::cin.clear();
        std::cout << "Nesupratau ką ivedėte, prašau įvesti dar kartą." << std::endl;
    }
}

int main() {
    unsigned krastSk;
    char taisyklingumas;

    std::cout << "Įveskite figūros kraštinių skaičių: ";
    gautiReiksme(krastSk);

    while (true) {
        std::cout << "Įveskite figūros taisyklingumą (t/n): ";
        gautiReiksme(taisyklingumas);

        if (taisyklingumas == 't' || taisyklingumas == 'n') {
            break;
        }

        std::cout << "Nesupratau ką ivedėte, prašau įvesti dar kartą." << std::endl;
    }

    GeometrineFigura fig(krastSk, taisyklingumas == 't');

    std::cout << "Kraštinių skaičius: " << fig.gautiKrastSk() << std::endl;
    std::cout << "Taisyklingumas: " << (fig.gautiTaisyklinguma() ? "taip" : "ne") << std::endl;

    return 0;
}
