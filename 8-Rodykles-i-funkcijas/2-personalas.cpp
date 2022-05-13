#include "meniu/personalo.h"

/*

8.2 Užduotis:
 - Klasė Personalas:
   - 10 darbuotoju
   - filtravimo palei amžių funkcija

   - Pagal Pasirinkimo Enumeraciją, galima dinamiškai pasirinkti kuriuos duomenis įrašyti bei spausdinti

 - Leidžia pasirinkti kuriuos duomenis įrašyti ar keisti (visi duomenys turi būti užpildyti)
 - Įrašo į darbuotojo objektą pasirinktinus duomenis
 - Kai baigiama rašyti, galima pakeisti atspausdinimo tvarką
 - Leidžia pasirinkti filtravimą palei amžiaus grupę, arba tiesiog leidžia parodyti visus darbuotojus
*/


int main() {
    Personalas personalas(gautiPradiniusDarbuotojus());
    Darbuotojas::DuomenuPasirinkimas spausdinimoTvarka(Darbuotojas::PRADINE_DUOMENU_PASIRINKIMO_TVARKA);

    PersonaloIvestiesMeniu(personalas).aptarnauti();
    PersonaloFiltravimoMeniuPagalAmziu(personalas, spausdinimoTvarka).aptarnauti();
    DarbuotojoDuomenuTvarkosSpausdinimoMeniu(spausdinimoTvarka).aptarnauti();

    return 0;
}
