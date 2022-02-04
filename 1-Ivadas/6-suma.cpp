#include <iostream> // std::cout, std::endl
#include <cmath> // abs

/*

1.6 užduotis:
 - Susumuoja įvesto sveikojo skaičiaus skaitmenų sumą

*/

int main() {
	int n, s=0;
	std::cout << "Įveskite skaičių: ";
	std::cin >> n;
	int i = abs(n); // negali skaitmenų suma būti neigiama
	do {
		s += i % 10;
	} while (i /= 10);
	std::cout << "Skaičiaus " << n << " skaitmenų suma lygi " << s << std::endl;
	return 0;
}
