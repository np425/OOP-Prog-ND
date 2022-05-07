#include <iostream>
#include <algorithm>
#include <random>
#include <array>

constexpr unsigned MASYVO_DYDIS = 100000;
constexpr int MAX_GEN_SK = 10000000;
constexpr int MIN_GEN_SK = -10000000;

typedef std::array<int, MASYVO_DYDIS> Masyvas;

/*

1.7 užduotis:
 1. Sudeda atsitiktines reikšmes (palei dabartinį laiką) į masyvą nuo 0 iki MAX_GEN_SK
 2. Jį surikiuoja
 3. Randa reikšmes kurios nesikartoja
 4. Jas atspausdina

*/

inline void generuotiMasyva(Masyvas::iterator it, Masyvas::const_iterator end) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(MIN_GEN_SK, MAX_GEN_SK);

    for (; it < end; ++it) {
        *it = dist(mt);
    }
}

inline void spausdintiNesikartojanciasReiksmes(Masyvas::iterator it, Masyvas::const_iterator end) {
    if (it == end) {
        return;
    }

    auto praeitaReiksme = it;

    for (++it; it < end; ++it) {
        if (*it == *praeitaReiksme) {
            continue;
        }

        if (it - praeitaReiksme == 1) {
            std::cout << *praeitaReiksme << std::endl;
        }

        praeitaReiksme = it;
    }

    if (it - praeitaReiksme == 1) {
        std::cout << *praeitaReiksme << std::endl;
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

    std::sort(masyvas.begin(), masyvas.end());

    std::cout << "Masyvas:" << std::endl;
    spausdintiMasyva(masyvas.begin(), masyvas.end());
    std::cout << std::endl;

    std::cout << "Nesikartojančios reikšmės:" << std::endl;
    spausdintiNesikartojanciasReiksmes(masyvas.begin(), masyvas.end());

    return 0;
}
