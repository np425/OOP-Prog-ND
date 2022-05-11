#include "meniu/darbuotojo.h"

/*

8.1 Užduotis:
 - Klasė darbuotojas:
   - vardas
   - pavardė
   - specialybė
   - amžius
   - darbo patirtis
   - atlyginimas

   - Pagal Pasirinkimo Enumeraciją, galima dinamiškai pasirinkti kuriuos duomenis įrašyti bei spausdinti

 - Leidžia pasirinkti kuriuos duomenis įrašyti ar keisti (visi duomenys turi būti užpildyti)
 - Įrašo į darbuotojo objektą pasirinktinus duomenis
 - Kai baigiama rašyti, galima pakeisti atspausdinimo tvarką
*/


int main() {
    //Darbuotojas darbuotojas;
    Darbuotojas darbuotojas("Nerijus", "Pocevičius", "IT Inžinierius", 19, 5, 200);

    Darbuotojas::DuomenuPasirinkimas spausdinimoTvarka(Darbuotojas::PRADINE_DUOMENU_PASIRINKIMO_TVARKA);

    DarbuotojoIvestiesMeniu ivestiesMeniu(darbuotojas);
    DarbuotojoDuomenuTvarkosSpausdinimoMeniu spausdinimoTvarkosMeniu(spausdinimoTvarka);

    ivestiesMeniu.aptarnauti();
    spausdinimoTvarkosMeniu.aptarnauti();

    darbuotojas.spausdintiDuomenis(spausdinimoTvarka);

    return 0;
}
