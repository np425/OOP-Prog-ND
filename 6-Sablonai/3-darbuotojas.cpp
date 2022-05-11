#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-exception-baseclass"

#include <iostream>

/*

6.3 Užduotis:
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
    class NetinkamasAmzius {
    };

    class NetinkamaPatirtis {
    };

    class MazasAtlyginimas {
    };

    Darbuotojas(unsigned amzius, unsigned darboPatirtis, unsigned atlyginimas) : amzius_(amzius),
        darboPatirtis_(darboPatirtis), atlyginimas_(atlyginimas) {
        if (amzius_ < 18 || amzius_ > 70) {
            throw NetinkamasAmzius();
        }
        if (darboPatirtis_ > amzius_) {
            throw NetinkamaPatirtis();
        }
        if (atlyginimas_ < 300) {
            throw MazasAtlyginimas();
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
    } catch (const Darbuotojas::NetinkamasAmzius &) {
        std::cerr << "Netinkamas amžius" << std::endl;
    } catch (const Darbuotojas::NetinkamaPatirtis &) {
        std::cerr << "Netinkama patirtis" << std::endl;
    } catch (const Darbuotojas::MazasAtlyginimas &) {
        std::cerr << "Per mažas atlyginimas" << std::endl;
    }

    return 0;
}

#pragma clang diagnostic pop