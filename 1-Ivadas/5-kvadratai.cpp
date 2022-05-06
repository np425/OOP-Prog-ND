#include <iostream>

/*

1.5 užduotis:
 - Išveda visų, iki nurodyto skaičiaus, sveikųjų skaičių kvadratus.

*/

int main() {
    unsigned skaiciuKiekis;

    std::cout << "Įveskite skaičių: ";
    std::cin >> skaiciuKiekis;

    for (unsigned i = 1; i <= skaiciuKiekis; ++i) {
        std::cout << "Skaičiaus " << i << " kvadratas yra " << i * i << ";" << std::endl;
    }

    return 0;
}

