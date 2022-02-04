#include <iostream> // std::cout, std::endl

/*

1.5 užduotis:
 - Išveda visų, iki nurodyto skaičiaus, sveikųjų skaičių kvadratus.

*/

int main() {
	int n;
	std::cout << "Įveskite skaičių: ";
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cout << "Skaičiaus " << i << " kvadratas yra " << i*i << ";" << std::endl;
	}
	return 0;
}

