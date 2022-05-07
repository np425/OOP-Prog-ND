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
    void spausdintiDuomenis() const {
        std::cout << "Amžius: " << amzius_ << std::endl;
        std::cout << "Darbo patirtis: " << darboPatirtis_ << std::endl;
        std::cout << "Atlyginimas: " << atlyginimas_ << std::endl;
    }

    void keistiAmziu(unsigned amzius) {
        this->amzius_ = amzius;
    }

    void keistiDarboPatirti(unsigned patirtis) {
        this->darboPatirtis_ = patirtis;
    }

    void keistiAtlyginima(unsigned atlyginimas) {
        this->atlyginimas_ = atlyginimas;
    }
};

int main() {
    Darbuotojas darb{};

    unsigned amzius;
    unsigned darboPatirtis;
    unsigned atlyginimas;

    std::cout << "Amžius: ";
    std::cin >> amzius;

    std::cout << "Darbo patirtis: ";
    std::cin >> darboPatirtis;

    std::cout << "Atlyginimas: ";
    std::cin >> atlyginimas;

    darb.keistiAmziu(amzius);
    darb.keistiDarboPatirti(darboPatirtis);
    darb.keistiAtlyginima(atlyginimas);

    darb.spausdintiDuomenis();

    return 0;
}
