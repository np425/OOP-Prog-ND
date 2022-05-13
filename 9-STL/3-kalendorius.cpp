//
// Created by nerpo on 2022-05-12.
//

/*
 * 9.4 užduotis
 * Kiekviena diena turi savo užduočių sąrašą
 * Sąryšis tarp dienos pavadinimo ir užduočių sąrašo laikomas kaip žemėlapis/žodynas (map)
 * Užduočių sąrašas laikomas kaip sąrašas (list)
 * Užduotis yra jos aprašas bei užduoties atlikimo pažymėjimas (padaryta arba ne)
 *
 * Galima pasirinkti dieną, kurios užduočių sąrašą keisti, arba parašyti "baigti", kad nutraukti programą
 * Užduočių sąrašas yra keičiamas per meniu, kuris leidžia pridėti naujas užduotis bei jas redaguoti
 * Pasirinkus užduotį, atidaromas jos meniu, kuris leidžia keisti jos aprašą, atlikimo pažymėjimą, bei ją pašalinti
 * */

#include "kalendorius.h"
#include "meniu/kalendoriaus.h"
#include <algorithm>

void keistiTekstaMazosiom(std::string &tekstas) {
    std::transform(tekstas.begin(), tekstas.end(), tekstas.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
}

int main() {
    Kalendorius kalendorius = {
        {"pirmadienis",  {}},
        {"antradienis",  {}},
        {"treciadienis", {}},
        {
         "ketvirtadienis",
                         {
                             {"Pavedžioti šunį"},
                             {"Nueiti į paskaitas"},
                             {"Atlikti programavimo užduotis"}
                         }},
        {"penktadienis", {}},
        {"sestadienis",  {}},
        {"sekmadienis",  {}}
    };

    while (true) {
        std::string ivestis;

        std::cout << "Įveskite dienos pavadinimą (arba baigti)" << std::endl;
        std::getline(std::cin, ivestis);

        keistiTekstaMazosiom(ivestis);

        if (ivestis == "baigti") {
            break;
        }

        auto diena = kalendorius.find(ivestis);
        if (diena == kalendorius.end()) {
            std::cout << "Nėra tokios dienos" << std::endl;
            continue;
        }

        DienosMeniu(diena->second).aptarnauti();
    }

    return 0;
}