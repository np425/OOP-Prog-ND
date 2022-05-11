#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-exception-baseclass"

#include <iostream>
#include <string>
#include <utility>

/*

6.2 Užduotis:
 - Klasė Trikampis
 	- kraštinė a
	- kraštinė b
	- kraštinė c
    - ilgiausia kraštinė

    - Klasė NetaisyklingasTrikampis
        - klaida

  - Nuskaito kraštines
  - Sukuria Trikampis objektą
  - Jei netaisyklingas trikampis, atspausdina klaidą
*/

class NetaisyklingasTrikampis {
    std::string klaida_;

public:
    explicit NetaisyklingasTrikampis(std::string klaida) : klaida_(std::move(klaida)) {
    }

    std::string gautiKlaida() const {
        return klaida_;
    }
};

class Trikampis {
    double a_, b_, c_, ilgiausiaKrastine_;

    inline double skaiciuotiIlgiausiaKrastine() const {
        if (a_ > b_ && a_ > c_) {
            return a_;
        }
        if (b_ > a_ && b_ > c_) {
            return b_;
        }
        return c_;
    }

    inline bool netaisyklingasTrikampis() const {
        return (a_ + b_ < c_ || a_ + c_ < b_ || b_ + c_ < a_);
    }

public:
    Trikampis(double a, double b, double c) : a_(a), b_(b), c_(c) {
        ilgiausiaKrastine_ = skaiciuotiIlgiausiaKrastine();

        if (netaisyklingasTrikampis()) {
            throw NetaisyklingasTrikampis("Ilgiausia kraštinė: " + std::to_string(ilgiausiaKrastine_));
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Trikampis& trikampis) {
        os << "Kraštinė A: " << trikampis.a_ << std::endl;
        os << "Kraštinė B: " << trikampis.b_ << std::endl;
        os << "Kraštinė C: " << trikampis.c_ << std::endl;
        os << "Ilgiausia kraštinė: " << trikampis.ilgiausiaKrastine_;
        return os;
    }
};

int main() {
    double a, b, c;

    std::cout << "Iveskite kraštinę a: ";
    std::cin >> a;

    std::cout << "Iveskite kraštinę b: ";
    std::cin >> b;

    std::cout << "Iveskite kraštinę c: ";
    std::cin >> c;

    try {
        Trikampis trikampis(a, b, c);
        std::cout << "Taisyklingas trikampis" << std::endl;
        std::cout << trikampis << std::endl;
    } catch (const NetaisyklingasTrikampis &t) {
        std::cerr << "Netaisyklingas trikampis" << std::endl;
        std::cerr << t.gautiKlaida() << std::endl;
    }

    return 0;
}

#pragma clang diagnostic pop