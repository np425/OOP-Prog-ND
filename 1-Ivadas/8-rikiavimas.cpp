#include <iostream>
#include <algorithm>
#include <random>
#include <array>

constexpr unsigned MASYVO_DYDIS = 50;
constexpr int MAX_GEN_SK = +100;
constexpr int MIN_GEN_SK = -100;

typedef std::array<int, MASYVO_DYDIS> Masyvas;
/*

1.8 užduotis:
 1. Sudeda atsitiktines reikšmes (palei dabartinį laiką) į masyvą nuo 0 iki MAX_SK
 2. Jį surikiuoja
 3. Reikšmes atspausdina

*/

inline void generuotiMasyva(Masyvas::iterator it, Masyvas::const_iterator end) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(MIN_GEN_SK, MAX_GEN_SK);

    for (; it < end; ++it) {
        *it = dist(mt);
    }
}

inline void spausdintiMasyva(Masyvas::iterator it, Masyvas::const_iterator end) {
    for (; it < end; ++it) {
        std::cout << *it << std::endl;
    }
}

int main() {
    std::ostream::sync_with_stdio(false);

    Masyvas masyvas{};

    generuotiMasyva(masyvas.begin(), masyvas.end());
    std::cout << "Masyvas:" << std::endl;
    spausdintiMasyva(masyvas.begin(), masyvas.end());
    std::cout << std::endl;

    std::sort(masyvas.begin(), masyvas.end());

    std::cout << "Surikiuotas masyvas:" << std::endl;
    spausdintiMasyva(masyvas.begin(), masyvas.end());
    std::cout << std::endl;

	return 0;
}
