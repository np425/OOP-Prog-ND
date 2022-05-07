#include <iostream>

/*

1.5 užduotis:
 - Išveda visų, iki nurodyto skaičiaus, sveikųjų skaičių kvadratus.

*/

int main() {
    unsigned kvadratuKiekis;

    std::cout << "Įveskite skaičių kvadratų kiekį: ";
    std::cin >> kvadratuKiekis;

    for (unsigned i = 1; i <= kvadratuKiekis; ++i) {
        std::cout << "Skaičiaus " << i << " kvadratas yra " << i * i << ";" << std::endl;
    }

    return 0;
}

