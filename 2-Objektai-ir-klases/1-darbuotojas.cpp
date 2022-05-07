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
    unsigned amzius_;
    unsigned darboPatirtis_;
    unsigned atlyginimas_;

    void spausdintiDuomenis() const {
        std::cout << "Amžius: " << amzius_ << std::endl;
        std::cout << "Darbo patirtis: " << darboPatirtis_ << std::endl;
        std::cout << "Atlyginimas: " << atlyginimas_ << std::endl;
    }
};

int main() {
    Darbuotojas darb{};

    std::cout << "Amžius: ";
    std::cin >> darb.amzius_;

    std::cout << "Darbo patirtis: ";
    std::cin >> darb.darboPatirtis_;

    std::cout << "Atlyginimas: ";
    std::cin >> darb.atlyginimas_;

    darb.spausdintiDuomenis();

    return 0;
}
