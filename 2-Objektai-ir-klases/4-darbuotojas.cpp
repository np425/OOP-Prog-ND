#include <iostream>

/*

2.4 Užduotis:
 - Klasė darbuotojas, su privačiais duomenimis:
   - amžius
   - darbo patirtis
   - atlyginimas
   - mokesčiai
 - Leidžia priskirti pradinius duomenis, sukūrimo metu
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

    inline double skaiciuotiMokescius() const {
        return atlyginimas_ * (SODRA + MOKESCIAI);
    }

public:
    Darbuotojas(unsigned amzius, unsigned darboPatirtis, unsigned atlyginimas) : amzius_(amzius),
        darboPatirtis_(darboPatirtis), atlyginimas_(atlyginimas) {
        mokesciai_ = skaiciuotiMokescius();
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
    unsigned amzius;
    unsigned darboPatirtis;
    unsigned atlyginimas;

    std::cout << "Amžius: ";
    std::cin >> amzius;

    std::cout << "Darbo patirtis: ";
    std::cin >> darboPatirtis;

    std::cout << "Atlyginimas: ";
    std::cin >> atlyginimas;

    Darbuotojas darbuotojas(amzius, darboPatirtis, atlyginimas);

    std::cout << darbuotojas << std::endl;

    return 0;
}
