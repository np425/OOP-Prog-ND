#include <iostream>
#include <algorithm>
#include <random>
#include <array>

constexpr unsigned MASYVO_DYDIS = 5;
constexpr int MAX_GEN_SK = 10;
constexpr int MIN_GEN_SK = -10;

typedef std::array<int, MASYVO_DYDIS> Masyvas;

/*

1.7 užduotis:
 1. Sudeda atsitiktines reikšmes (palei dabartinį laiką) į masyvą nuo 0 iki MAX_GEN_SK
 2. Jį surikiuoja
 3. Randa reikšmes kurios nesikartoja
 4. Jas atspausdina

*/

inline void generuotiMasyva(Masyvas &masyvas) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(MIN_GEN_SK, MAX_GEN_SK);

    for (int &reiksme: masyvas) {
        reiksme = dist(mt);
    }
}

inline void spausdintiNesikartojanciasReiksmes(const Masyvas &masyvas) {
    auto praeitaReiksme = masyvas.begin();
    auto it = masyvas.begin() + 1;

    for (; it < masyvas.end(); ++it) {
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

inline void spausdintiMasyva(const Masyvas& masyvas) {
    for (int reiksme : masyvas) {
        std::cout << reiksme << std::endl;
    }
}

int main() {
    Masyvas masyvas{};

    generuotiMasyva(masyvas);

    std::sort(masyvas.begin(), masyvas.end());

    std::cout << "Masyvas:" << std::endl;
    spausdintiMasyva(masyvas);
    std::cout << std::endl;

    std::cout << "Nesikartojančios reikšmės:" << std::endl;
    spausdintiNesikartojanciasReiksmes(masyvas);

    return 0;
}
