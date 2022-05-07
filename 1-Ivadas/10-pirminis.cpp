#include <iostream>
#include <cmath>

/*

1.10 užduotis:
 - Funkcija, kuri patikrina ar duotas skaičius yra pirminis
 - Taip pat jį atspausdina nuo įvesto skaičiaus


*/

bool arPirminis(int n) {
    // Leidžia skaičiuoti pirminį skaičių nuo neigiamo skaičiaus
	n = abs(n);

	if (n < 2) {
		// Pirmasis pirminis skaičius yra 2
		return false;
	}

	for (int i = 2; i <= n/2; ++i) {
		if (n % i == 0) {
            return false;
        }
	}

	return true;
}

int main() {
	int n;

	std::cout << "Įveskite skaičių: ";
	std::cin >> n;

    std::cout << "Skaičius " << n << " yra " << (arPirminis(n) ? "pirminis" : "ne pirminis") << std::endl;

	return 0;
}

