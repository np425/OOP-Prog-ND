#include <iostream>
#include <string>
#include <algorithm>

#include "darbuotojas.h"
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


int main() {
	//Darbuotojas darb;
    Darbuotojas darb("Nerijus", "Pocevičius", "IT Inžinierius", 19, 5, 200);

    Darbuotojas::DuomenuPasirinkimas spausdinimoTvarka(Darbuotojas::PRADINE_DUOMENU_PASIRINKIMO_TVARKA);

    DarbuotojoIvestiesMeniu ivestiesMeniu(darb);
    DarbuotojoDuomenuTvarkosSpausdinimoMeniu spausdinimoTvarkosMeniu(spausdinimoTvarka);

    ivestiesMeniu.aptarnauti();
    spausdinimoTvarkosMeniu.aptarnauti();

    darb.spausdintiDuomenis(spausdinimoTvarka);

	return 0;
}
