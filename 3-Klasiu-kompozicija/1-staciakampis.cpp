#include <iostream>
#include <cmath>
#include <array>

#define POW_2(x) ((x)*(x))

/*

3.1 Užduotis:
 - Klasė Taškas:
  - x, y
  - implementuoja atimtį, tai yra atstumą tarp dviejų taškų
 - Klasė Stačiakampis:
   - 4 taškai
   - gautiPlota()
   - gautiPerimetra()
*/

class Taskas {
public:
    double x;
    double y;

    double operator-(const Taskas &taskas) const {
        return std::sqrt(POW_2(x - taskas.x) + POW_2(y - taskas.y));
    }

    friend std::istream &operator>>(std::istream &is, Taskas &taskas) {
        return is >> taskas.x >> taskas.y;
    }
};

class Staciakampis {
public:
    typedef std::array<Taskas, 4> Taskai;

private:
    std::array<double, 2> atkarpos_{};
    Taskai taskai_;

    std::array<double, 2> skaiciuotiAtkarpas() const {
        std::array<double, 2> atkarpos{};

        // Apskaičiuoja atkarpas iš taškų
        for (int i = 1; i < 4; ++i) {
            if (taskai_[i].x == taskai_[0].x) {
                atkarpos[0] = taskai_[0] - taskai_[i];
            } else if (taskai_[i].y == taskai_[0].y) {
                atkarpos[1] = taskai_[0] - taskai_[i];
            }
        }

        return atkarpos;
    }

public:
    explicit Staciakampis(Taskai taskai) : taskai_(taskai) {
        atkarpos_ = skaiciuotiAtkarpas();
    }

    inline double gautiPerimetra() {
        return (atkarpos_[0] + atkarpos_[1]) * 2;
    };

    inline double gautiPlota() {
        return atkarpos_[0] * atkarpos_[1];
    };
};

int main() {
    Staciakampis::Taskai taskai{};

    for (int i = 1; i <= 4; ++i) {
        std::cout << "Įveskite " << i << " taško koordinates (x y): " << std::endl;
        std::cin >> taskai[i - 1];
    }

    Staciakampis staciakampis(taskai);

    std::cout << "Stačiakampio perimetras: " << staciakampis.gautiPerimetra() << std::endl;
    std::cout << "Stačiakampio plotas: " << staciakampis.gautiPlota() << std::endl;

    return 0;
}
