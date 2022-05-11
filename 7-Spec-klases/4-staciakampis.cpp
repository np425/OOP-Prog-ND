#include <iostream>
#include <vector>
#include <cmath>

/*

7.4 Užduotis:
 - Klasė Taskas:
   - x
   - y
 - Klasė Staciakampis:
   - bendras (statinis) taškas t1
   - atskiras taškas t2
   - skaičiuoja perimetrą
   - skaičiuoja plotą
 - Pasirenka kiekį stačiakampių
 - Pasirenka bendrą tašką stačiakampių
 - Parenka individualų tašką kiekvienam stačiakampiui
 - Atspausdina plotą, perimetrą
 - Vėl pasirenka bendrą tašką stačiakampių
 - Vėl atspausdina plotą, perimetrą
*/

class Taskas {
public:
    double x;
    double y;

    friend std::istream &operator>>(std::istream &is, Taskas &taskas) {
        return is >> taskas.x >> taskas.y;
    }
};

class Staciakampis {
    static Taskas bendrasTaskas_;
    Taskas individualusTaskas_;

public:
    explicit Staciakampis(Taskas taskas) : individualusTaskas_(taskas) {
    }

    static void keistiBendraTaska(Taskas taskas) {
        bendrasTaskas_ = taskas;
    }

    double gautiPerimetra() const {
        return std::abs(2 * (individualusTaskas_.x - bendrasTaskas_.x + individualusTaskas_.y - bendrasTaskas_.y));
    }

    double gautiPlota() const {
        return std::abs((individualusTaskas_.x - bendrasTaskas_.x) * (individualusTaskas_.y - bendrasTaskas_.y));
    }
};

Taskas Staciakampis::bendrasTaskas_{0, 0};

int main() {
    Taskas taskas{};
    std::cout << "Įveskite bendrą stačiakampių tašką (x,y): ";
    std::cin >> taskas;

    Staciakampis::keistiBendraTaska(taskas);

    unsigned staciakampiuKiekis;
    std::cout << "Įveskite stačiakampių kiekį: ";
    std::cin >> staciakampiuKiekis;

    std::vector<Staciakampis> staciakampiai;

    for (unsigned i = 0; i < staciakampiuKiekis; ++i) {
        std::cout << "Įveskite " << i + 1 << " stačiakampio individualų tašką (x,y): ";
        std::cin >> taskas;

        staciakampiai.emplace_back(taskas);
    }

    for (unsigned i = 0; i < staciakampiuKiekis; ++i) {
        std::cout << i + 1 << " Stačiakampio perimetras = " << staciakampiai[i].gautiPerimetra() << std::endl;
        std::cout << i + 1 << " Stačiakampio plotas = " << staciakampiai[i].gautiPlota() << std::endl;
    }

    std::cout << "Vėl įveskite bendrą stačiakampių tašką (x,y): ";
    std::cin >> taskas;

    Staciakampis::keistiBendraTaska(taskas);

    for (unsigned i = 0; i < staciakampiuKiekis; ++i) {
        std::cout << i + 1 << " Stačiakampio perimetras = " << staciakampiai[i].gautiPerimetra() << std::endl;
        std::cout << i + 1 << " Stačiakampio plotas = " << staciakampiai[i].gautiPlota() << std::endl;
    }

    return 0;
}
