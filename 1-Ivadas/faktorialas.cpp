#include <iostream> // std::cout, std::endl

/*

1.9 užduotis:
 - Funkcija, kuri gražina skaičiaus faktorialą
 - Taip pat jį atspausdina nuo įvesto skaičiaus


*/

int factorial(int n) {
	int res = n;
	n = abs(n); // Leidžia skaičiuoti faktorialą nuo neigiamo skaičiaus

	--n;
	while (n > 0) {
		res *= n--;
	}

	return res;
}

int main() {
	int n;
	std::cout << "Įveskite skaičių: ";
	std::cin >> n;
	std::cout << factorial(n) << std::endl;
	return 0;
}

