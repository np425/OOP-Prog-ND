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
    void keistiAmziu(unsigned amzius) {
        amzius_ = amzius;
    }

    void keistiDarboPatirti(unsigned patirtis) {
        darboPatirtis_ = patirtis;
    }

    void keistiAtlyginima(unsigned atlyginimas) {
        atlyginimas_ = atlyginimas;
    }

    void skaiciuotiMokescius() {
        mokesciai_ = atlyginimas_ * (SODRA + MOKESCIAI);
    }

    friend std::ostream& operator<<(std::ostream& os, const Darbuotojas& darbuotojas) {
        os << "Amžius: " << darbuotojas.amzius_ << std::endl;
        os << "Darbo patirtis: " << darbuotojas.darboPatirtis_ << std::endl;
        os << "Atlyginimas: " << darbuotojas.atlyginimas_ << std::endl;
        os << "Mokesčiai: " << darbuotojas.mokesciai_;
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

    darbuotojas.skaiciuotiMokescius();
    std::cout << darbuotojas << std::endl;

    return 0;
}
