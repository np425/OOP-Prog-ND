#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-exception-baseclass"

#include <iostream>
#include <stdexcept>
#include <utility>

/*

6.4 Užduotis:
 - Klasė darbuotojas: 
   - amžius
   - darbo patirtis
   - atlyginimas
 - Įrašo į darbuotojo objektą duomenis
 - Jei duomenys neatitinka ribojimus, parašo klaidą
 - Kitu atvėju atspausdina darbuotojo objekto duomenis

*/

class Darbuotojas {
    unsigned amzius_;
    unsigned darboPatirtis_;
    unsigned atlyginimas_;

public:
    class NetinkamiDuomenys {
        std::string klaida_;
    public:
        explicit NetinkamiDuomenys(std::string klaida) : klaida_(std::move(klaida)) {
        }

        std::string gautiNeatitikima() const {
            return klaida_;
        }
    };

    Darbuotojas(unsigned amzius, unsigned darboPatirtis, unsigned atlyginimas) : amzius_(amzius),
        darboPatirtis_(darboPatirtis), atlyginimas_(atlyginimas) {
        if (amzius < 18 || amzius > 70) {
            throw NetinkamiDuomenys("Netinkamas amžius");
        }
        if (darboPatirtis > amzius) {
            throw NetinkamiDuomenys("Netinkama patirtis");
        }
        if (atlyginimas < 300) {
            throw NetinkamiDuomenys("Per mažas atlyginimas");
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Darbuotojas &darbuotojas) {
        os << "Amžius: " << darbuotojas.amzius_ << std::endl;
        os << "Darbo patirtis: " << darbuotojas.darboPatirtis_ << std::endl;
        os << "Atlyginimas: " << darbuotojas.atlyginimas_;
        return os;
    }
};

int main() {
    unsigned amzius, patirtis, atlyginimas;

    std::cout << "Amžius: ";
    std::cin >> amzius;

    std::cout << "Darbo patirtis: ";
    std::cin >> patirtis;

    std::cout << "Atlyginimas: ";
    std::cin >> atlyginimas;

    try {
        Darbuotojas darbuotojas(amzius, patirtis, atlyginimas);
        std::cout << "Tinkamas darbuotojas" << std::endl;
        std::cout << darbuotojas << std::endl;
    } catch (const Darbuotojas::NetinkamiDuomenys &e) {
        std::cerr << e.gautiNeatitikima() << std::endl;
    }

    return 0;
}

#pragma clang diagnostic pop