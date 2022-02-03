#include <iostream>
#include <cmath> // sqrt
#define POW_2(x) (x*x)

/*

5 Užduotis:
 - Klasė taškas, susidea iš viešų duomenų:
   - pradžios koordinatės
   - pabaigos koordinatės
 - Klasė atkarpa, susideda iš
   - Viešų duomenų:
     - Atkarpos pradžia (taškas)
     - Atkarpos pabaiga (taškas)
   - Viešų funkcijų:
     - atkarpos ilgio skaičiavimas

4 Užduotis:
 - Klasė darbuotojas, su privačiais duomenimis: - amžius
   - darbo patirtis
   - atlyginimas
   - mokesčiai
 - Leidžia priskirti pradinius duomenis, sukūrimo metu
 - Skaičiuoja mokesčius
 - Juos atspausdina
 - Įrašo į darbuotojo objektą duomenis
 - Atspausdina darbuotojo objekto duomenis

*/

class Taskas {
public:
	int x;
	int y;
};

class Atkarpa {
public:
	Taskas pradzia;
	Taskas pabaiga;
	unsigned skaiciuotiAts() {
		return sqrt(POW_2(pabaiga.x-pradzia.x)+POW_2(pabaiga.y-pradzia.y));
	}
};

int main() {
	Atkarpa atk;
	std::cout << "Įveskite atkarpos pradžios koordinates (x y): ";
	std::cin >> atk.pradzia.x >> atk.pradzia.y;
	std::cout << "Įveskite atkarpos pabaigos koordinates (x y): ";
	std::cin >> atk.pabaiga.x >> atk.pabaiga.y;
	std::cout << "Atstumas tarp dviejų taškų: " << atk.skaiciuotiAts() << std::endl;
}
