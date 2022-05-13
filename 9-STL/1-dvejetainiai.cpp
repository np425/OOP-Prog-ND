//
// Created by nerpo on 2022-05-12.
//

/*
 * 9.1 užduotis
 * Verčia dešimtainius skaičius į dvejetainius naudojant stacką
 * */

#include <stack>
#include <iostream>

int main() {
    unsigned skaicius;
    std::stack<bool> dvejetainiaiSkaitmenys;

    std::cout << "Įveskite skaičių: ";
    std::cin >> skaicius;

    for (; skaicius; skaicius /= 2) {
        dvejetainiaiSkaitmenys.push(skaicius % 2);
    }

    while (!dvejetainiaiSkaitmenys.empty()) {
        std::cout << dvejetainiaiSkaitmenys.top();
        dvejetainiaiSkaitmenys.pop();
    }
    std::cout << std::endl;

    return 0;
}