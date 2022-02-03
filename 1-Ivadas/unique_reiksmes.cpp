#include <iostream> // std::cout, std::endl
#include <climits> // INT_MIN, INT_MAX
#include <cstdlib> // std::srand, std::rand
#include <ctime> // std::time
#include <algorithm> // std::sort

#define MASYVO_DYDIS 100000
#define MAX_SK INT_MAX

/*

1.7 užduotis:
 1. Sudeda atsitiktines reikšmes (palei dabartinį laiką) į masyvą nuo 0 iki MAX_SK
 2. Jį surikiuoja
 3. Randa reikšmes kurios nesikartoja
 4. Jas atspausdina

*/

void randomiseArr(int* it, int* end) {
	while (it != end) {
		*it = std::rand() % MAX_SK;
		++it;
	}
}

void printArr(const int* it, const int* end) {
	while (it != end) {
		std::cout << *it << std::endl;
		++it;
	}
}

int main() {
	int arr[MASYVO_DYDIS];
	// Naudoja dabartinį laiką kaip seed atsitiktiniams skaičiams kurti
	std::srand(std::time(nullptr));
	
	// Sudeda atsitiktines reikšmes į masyvą
	randomiseArr(arr, arr+MASYVO_DYDIS);

	if (MASYVO_DYDIS == 1) {
		std::cout << arr[0] << std::endl;
		return 0;
	}

	// Jį surikiuoja
	std::sort(arr, arr+MASYVO_DYDIS);

	//printArr(arr, arr+MASYVO_DYDIS);

	//std::cout << std::endl << std::endl;

	int i = 1;
	if (arr[i-1] < arr[i]) {
		std::cout << arr[i-1] << std::endl;
	}
	for (; i < MASYVO_DYDIS-1; ++i) {
		if (arr[i-1] < arr[i] && arr[i] < arr[i+1]) {
			std::cout << arr[i] << std::endl;
		}
	}
	if (arr[i-1] < arr[i]) {
		std::cout << arr[i] << std::endl;
	}

	return 0;
}
