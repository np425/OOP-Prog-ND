#include <iostream>
#include <string>
#include <algorithm>

#include "darbuotojas.h"
#include "personalas.h"
#include "meniu.h"

/*

1 Užduotis:
 - Klasė darbuotojas:
   - vardas
   - pavardė
   - specialybė
   - amžius
   - darbo patirtis
   - atlyginimas

   - Pagal Pasirinkimo Enumeraciją, galima dinamiškai pasirinkti kuriuos duomenis spausdinti

 - Leidžia pasirinkti kuriuos duomenis įrašyti ar keisti (visi duomenys turi būti užpildyti)
 - Įrašo į darbuotojo objektą pasirinktinus duomenis
 - Kai baigiama rašyti, galima pakeisti atspausdinimo tvarką
*/

const std::array<Darbuotojas, Personalas::DARBUOTOJU_KIEKIS> PRADINIAI_DARBUOTOJAI = {
    Darbuotojas("Donald", "Duck", "Duck", 10, 10, 2),
    Darbuotojas("Rick", "Astley", "Singer", 40, 10, 30000),
    Darbuotojas("Elon", "Musk", "Engineer", 50, 30, 100000),
    Darbuotojas("John", "Cena", "Wrestler", 45, 30, 50000),
    Darbuotojas("Robert", "Downey Jr.", "Actor", 57, 40, 70000),
    Darbuotojas("Dwayne", "Johnson", "Actor", 49, 20, 65000),
    Darbuotojas("Leonardo", "DiCaprio", "Actor", 47, 30, 65000),
    Darbuotojas("Ryan", "Reynolds", "Actor", 45, 30, 50000),
    Darbuotojas("Keanu", "Reeves", "Actor", 57, 30, 35000),
    Darbuotojas("Steven", "Spielberg", "Film Director", 75, 40, 55000)
};

int main() {
    Personalas personalas(PRADINIAI_DARBUOTOJAI);
    Darbuotojas::DuomenuPasirinkimas spausdinimoTvarka(Darbuotojas::PRADINE_DUOMENU_PASIRINKIMO_TVARKA);

    PersonaloIvestiesMeniu personaloIvestiesMeniu(personalas);
    PersonaloFiltravimoMeniu personaloFiltravimoMeniu(personalas, spausdinimoTvarka);
    DarbuotojoDuomenuTvarkosSpausdinimoMeniu spausdinimoTvarkosMeniu(spausdinimoTvarka);

    personaloIvestiesMeniu.aptarnauti();
    spausdinimoTvarkosMeniu.aptarnauti();
    personaloFiltravimoMeniu.aptarnauti();

	return 0;
}
