#include <iostream>

/*

2.1 Užduotis:
 - Klasė darbuotojas, su viešais duomenimis:
   - amžius
   - darbo patirtis
   - atlyginimas
 - Įrašo į darbuotojo objektą duomenis
 - Atspausdina darbuotojo objekto duomenis

*/

class Darbuotojas {
public:
    unsigned amzius;
    unsigned darboPatirtis;
    unsigned atlyginimas;

    friend std::ostream& operator<<(std::ostream& os, const Darbuotojas& darbuotojas) {
        os << "Amžius: " << darbuotojas.amzius << std::endl;
        os << "Darbo patirtis: " << darbuotojas.darboPatirtis << std::endl;
        os << "Atlyginimas: " << darbuotojas.atlyginimas;
        return os;
    }
};

int main() {
    Darbuotojas darbuotojas{};

    std::cout << "Amžius: ";
    std::cin >> darbuotojas.amzius;

    std::cout << "Darbo patirtis: ";
    std::cin >> darbuotojas.darboPatirtis;

    std::cout << "Atlyginimas: ";
    std::cin >> darbuotojas.atlyginimas;

    std::cout << darbuotojas << std::endl;

    return 0;
}
