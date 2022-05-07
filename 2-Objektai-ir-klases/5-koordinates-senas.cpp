#include <iostream>
#include <cmath>

#define POW_2(x) ((x)*(x))

/*

2.5 Užduotis:
 - Klasė taškas, susidea iš viešų duomenų:
   - pradžios koordinatės
   - pabaigos koordinatės
 - Klasė atkarpa, susideda iš
   - Viešų duomenų:
     - Atkarpos pradžia (taškas)
     - Atkarpos pabaiga (taškas)
   - Viešų funkcijų:
     - atkarpos ilgio skaičiavimas
*/

class Taskas {
public:
    int x;
    int y;

    friend std::istream &operator>>(std::istream &is, Taskas &taskas) {
        return is >> taskas.x >> taskas.y;
    }
};

class Atkarpa {
public:
    Taskas pradzia;
    Taskas pabaiga;

    inline unsigned skaiciuotiAtstuma() {
        return std::sqrt(POW_2(pabaiga.x - pradzia.x) + POW_2(pabaiga.y - pradzia.y));
    }
};

int main() {
    Atkarpa atk;

    std::cout << "Įveskite atkarpos pradžios koordinates (x y): ";
    std::cin >> atk.pradzia;

    std::cout << "Įveskite atkarpos pabaigos koordinates (x y): ";
    std::cin >> atk.pabaiga;

    std::cout << "Atstumas tarp dviejų taškų: " << atk.skaiciuotiAtstuma() << std::endl;
}
