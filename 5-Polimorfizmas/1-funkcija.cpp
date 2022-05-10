#include <iostream>
#include <cmath>
#include <array>
#include <memory>

/*

5.1 Užduotis:
 - Klasė Funkcija (abstrakti):
   - f(x) (abstraktus metodas)
 - Klasė Laipsninė funkcija (kilus iš klasės funkcija):
   - f(x)
 - Klasė Tiesinė funkcija (kilus iš klasės funkcija):
   - f(x)
 - Klasė Sinusoidė (kilus iš klasės funkcija):
   - f(x)
 - Nuskaitoma k, b, n kintamieji
 - Masyvas į kiekvieną išvestinę funkciją, su atitinkamais kintamaisiais
 - Išsprendžiama kiekviena funkcija su x
 - Atspausdinamas rezultatas
*/

class Funkcija {
public:
    virtual double operator()(double x) const = 0;
    virtual const char *gautiPavadinima() const = 0;
    virtual ~Funkcija() = default;
};

// y = kx + b
class TiesineFunkcija : public Funkcija {
    double k_;
    double b_;

public:
    TiesineFunkcija(double k, double b) : k_(k), b_(b) {
    }

    double operator()(double x) const override {
        return k_ * x + b_;
    }

    const char *gautiPavadinima() const override {
        return "tiesinė";
    }
};

// y = x^n
class LaipsnineFunkcija : public Funkcija {
    double n_;

public:
    explicit LaipsnineFunkcija(double n) : n_(n) {
    }

    double operator()(double x) const override {
        return std::pow(x, n_);
    }

    const char *gautiPavadinima() const override {
        return "laipsninė";
    }
};

// y = sin(x)
class Sinusoide : public Funkcija {
public:
    double operator()(double x) const override {
        return std::sin(x);
    }

    const char *gautiPavadinima() const override {
        return "sinusoidė";
    }
};

int main() {
    double k, b, n, x;
    std::cout << "Įveskite tiesinės funkcijos k kintamąjį: ";
    std::cin >> k;

    std::cout << "Įveskite tiesinės funkcijos b kintamąjį: ";
    std::cin >> b;

    std::cout << "Įveskite laipsninės funkcijos n kintamąjį: ";
    std::cin >> n;

    std::cout << "Įveskite x: ";
    std::cin >> x;

    std::array<std::unique_ptr<Funkcija>, 3> funkcijos = {
        std::make_unique<TiesineFunkcija>(k, b),
        std::make_unique<LaipsnineFunkcija>(n),
        std::make_unique<Sinusoide>()
    };

    for (const auto &funkcija: funkcijos) {
        std::cout << funkcija->gautiPavadinima() << ": y=" << (*funkcija)(x) << std::endl;
    }

    return 0;
}
