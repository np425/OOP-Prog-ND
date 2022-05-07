#include <iostream>

/*

2.3 Užduotis:
 - Klasė darbuotojas, su privačiais duomenimis:
   - amžius
   - darbo patirtis
   - atlyginimas
   - mokesčiai
 - Skaičiuoja mokesčius
 - Juos atspausdina
 - Įrašo į darbuotojo objektą duomenis
 - Atspausdina darbuotojo objekto duomenis

*/

class Darbuotojas {
public:
    constexpr static double SODRA = 0.09;
    constexpr static double MOKESCIAI = 0.15;

private:
    unsigned amzius_;
    unsigned darboPatirtis_;
    unsigned atlyginimas_;
    double mokesciai_;

public:
    void spausdintiDuomenis() const {
        std::cout << "Amžius: " << amzius_ << std::endl;
        std::cout << "Darbo patirtis: " << darboPatirtis_ << std::endl;
        std::cout << "Atlyginimas: " << atlyginimas_ << std::endl;
        spausdintiMokescius();
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

    double skaiciuotiMokescius() {
        return this->mokesciai_ = atlyginimas_ * (SODRA + MOKESCIAI);
    }

    void spausdintiMokescius() const {
        std::cout << "Mokesčiai: " << this->mokesciai_ << std::endl;
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

    darb.skaiciuotiMokescius();
    darb.spausdintiDuomenis();

    return 0;
}
