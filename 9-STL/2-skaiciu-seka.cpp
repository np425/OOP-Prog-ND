//
// Created by nerpo on 2022-05-12.
//

/*
 * 9.2 užduotis
 * Skaičiuojami skaičių eilutės paskutiniai 5 skaičių vidurkiai naudojant eilę
 * Taip pat laikomi paskutiniai 4 apskaičiuoti vidurkiai (naujausią įskaitant) naudojant sąrąšą
 * Skaičių eilutė užbaigiama 0
 * */

#include <queue>
#include <stack>
#include <iostream>
#include <list>

constexpr unsigned VIDURKIU_KIEKIS = 4;
constexpr unsigned SKAICIU_KIEKIS = 5;

int main() {
    std::queue<int> skaiciai;
    std::list<double> seniVidurkiai;

    double vidurkis = 0;
    int skaicius;

    std::cout << "Įveskite skaičius (0 indikuoja pabaigą): " << std::endl;

    while (true) {
        std::cin >> skaicius;
        skaiciai.push(skaicius);

        vidurkis += skaicius;

        if (!skaicius) {
            break;
        }

        if (skaiciai.size() != SKAICIU_KIEKIS) {
            continue;
        }

        seniVidurkiai.push_back(vidurkis / SKAICIU_KIEKIS);

        for (double senasVidurkis: seniVidurkiai) {
            std::cout << senasVidurkis << " ";
        }
        std::cout << std::endl;

        if (seniVidurkiai.size() == VIDURKIU_KIEKIS) {
            seniVidurkiai.erase(seniVidurkiai.begin());
        }

        vidurkis -= skaiciai.front();

        skaiciai.pop();
    }

    return 0;
}
