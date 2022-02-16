#include <iostream>

/*

5 Užduotis:
 - Klasė GeometrineFigura:
   - kraštinių skaičius
   - taisyklingumas
 - Nuskaito duomenis
 - Įrašo duomenis į GeometrineFigura objektą
 - Atspausdina duomenis
*/

class GeometrineFigura {
    unsigned krastSk;
    bool taisyklingumas;

public:
    GeometrineFigura() {}
    GeometrineFigura(unsigned krastSk, bool taisyklingumas) : krastSk(krastSk), taisyklingumas(taisyklingumas) {}

    unsigned gautiKrastSk() { return krastSk; }
    void keistiKrastSk(unsigned krastSk) { this->krastSk = krastSk; }

    unsigned gautiTaisyklinguma() { return taisyklingumas; }
    void keistiTaisyklinguma(unsigned taisyklingumas) { this->taisyklingumas = taisyklingumas; }

};

int main() {
    unsigned krastSk;
    char tais;

    std::cout << "Įveskite figūros kraštinių skaičių: ";
    std::cin >> krastSk;

    while (true) {
        std::cout << "Įveskite figūros taisyklingumą (t/n): ";
        std::cin >> tais;

        if (tais == 't' || tais == 'n') break;
        std::cout << "Nesupratau ką ivedėte, prašau įvesti dar kartą." << std::endl;
    }

    GeometrineFigura fig(krastSk, tais=='t');

    std::cout << "Kraštinių skaičius: " << fig.gautiKrastSk() << std::endl;
    std::cout << "Taisyklingumas: " << (fig.gautiTaisyklinguma() ? "taip" : "ne") << std::endl;

    return 0;
}
