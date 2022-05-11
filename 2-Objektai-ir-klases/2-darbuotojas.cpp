#include <iostream>

/*

2.2 Užduotis:
 - Klasė darbuotojas, su privačiais duomenimis:
   - amžius
   - darbo patirtis
   - atlyginimas
 - Įrašo į darbuotojo objektą duomenis
 - Atspausdina darbuotojo objekto duomenis

*/

class Darbuotojas {
    unsigned amzius_;
    unsigned darboPatirtis_;
    unsigned atlyginimas_;

public:
    void keistiAmziu(unsigned amzius) {
        amzius_ = amzius;
    }

    void keistiDarboPatirti(unsigned patirtis) {
        darboPatirtis_ = patirtis;
    }

    void keistiAtlyginima(unsigned atlyginimas) {
        atlyginimas_ = atlyginimas;
    }

    friend std::ostream& operator<<(std::ostream& os, const Darbuotojas& darbuotojas) {
        os << "Amžius: " << darbuotojas.amzius_ << std::endl;
        os << "Darbo patirtis: " << darbuotojas.darboPatirtis_ << std::endl;
        os << "Atlyginimas: " << darbuotojas.atlyginimas_;
        return os;
    }
};

int main() {
    Darbuotojas darbuotojas{};

    unsigned amzius;
    unsigned darboPatirtis;
    unsigned atlyginimas;

    std::cout << "Amžius: ";
    std::cin >> amzius;

    std::cout << "Darbo patirtis: ";
    std::cin >> darboPatirtis;

    std::cout << "Atlyginimas: ";
    std::cin >> atlyginimas;

    darbuotojas.keistiAmziu(amzius);
    darbuotojas.keistiDarboPatirti(darboPatirtis);
    darbuotojas.keistiAtlyginima(atlyginimas);

    std::cout << darbuotojas << std::endl;

    return 0;
}
