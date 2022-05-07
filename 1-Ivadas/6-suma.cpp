#include <iostream>
#include <cmath>

/*

1.6 užduotis:
 - Susumuoja įvesto sveikojo skaičiaus skaitmenų sumą

*/

int main() {
    int skaicius, skaitmenuSuma = 0;

    std::cout << "Įveskite skaičių, kurio skaitmenis susuomuoti: ";
    std::cin >> skaicius;

    for (int sk = std::abs(skaicius); sk; sk /= 10) {
        skaitmenuSuma += sk % 10;
    }

    std::cout << "Skaičiaus " << skaicius << " skaitmenų suma lygi: " << skaitmenuSuma << std::endl;

    return 0;
}
