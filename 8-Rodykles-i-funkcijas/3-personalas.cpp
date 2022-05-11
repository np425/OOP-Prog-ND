#include "meniu/personalo.h"

/*

8.3 Užduotis:
 - Klasė Personalas:
   - 10 darbuotoju
   - filtravimo pagal pasirinktiną duomenį funkcija (tik pagal amžių, patirtį ar atlyginimą)

   - Pagal Pasirinkimo Enumeraciją, galima dinamiškai pasirinkti kuriuos duomenis įrašyti bei spausdinti

 - Leidžia pasirinkti kuriuos duomenis įrašyti ar keisti (visi duomenys turi būti užpildyti)
 - Įrašo į darbuotojo objektą pasirinktinus duomenis
 - Kai baigiama rašyti, galima pakeisti atspausdinimo tvarką
 - Leidžia pasirinkti filtravimą palei duomenį (tik amžių, patirti ar atlyginimą) su min ir max ribomis, arba tiesiog leidžia parodyti visus darbuotojus
*/

int main() {
    Personalas personalas(gautiPradiniusDarbuotojus());
    Darbuotojas::DuomenuPasirinkimas spausdinimoTvarka(Darbuotojas::PRADINE_DUOMENU_PASIRINKIMO_TVARKA);

    PersonaloIvestiesMeniu personaloIvestiesMeniu(personalas);
    PersonaloFiltravimoMeniu personaloFiltravimoMeniu(personalas, spausdinimoTvarka);
    DarbuotojoDuomenuTvarkosSpausdinimoMeniu spausdinimoTvarkosMeniu(spausdinimoTvarka);

    personaloIvestiesMeniu.aptarnauti();
    spausdinimoTvarkosMeniu.aptarnauti();
    personaloFiltravimoMeniu.aptarnauti();

    return 0;
}
