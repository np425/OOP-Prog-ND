#ifndef PERSONALAS_H
#define PERSONALAS_H

#include <iostream>
#include <stdexcept>

#include "darbuotojas.h"

#define LINE "-------------------------------------------"

class DarbuotojoAmzius {
public:
    constexpr static unsigned AMZIU_GRUPIU_KIEKIS = 4;

    static bool jaunas(unsigned amzius) {
        return amzius >= 18 && amzius <= 30;
    }

    static bool vidutinis(unsigned amzius) {
        return amzius >= 31 && amzius <= 50;
    }

    static bool pagyvenes(unsigned amzius) {
        return amzius >= 51 && amzius <= 70;
    }

    static bool senyvas(unsigned amzius) {
        return amzius >= 71;
    }
};

class Personalas {
public:
    constexpr static unsigned DARBUOTOJU_KIEKIS = 10;

private:
   std::array<Darbuotojas, DARBUOTOJU_KIEKIS> mDarbuotojai; 

public:
   Personalas() {
   }

   Personalas(const std::array<Darbuotojas, DARBUOTOJU_KIEKIS>& darbuotojai) : mDarbuotojai(darbuotojai) {
   }

   //const Darbuotojas& gautiDarbuotoja(unsigned idx) const {
   //    return mDarbuotojai[idx];
   //}

   Darbuotojas& gautiDarbuotoja(unsigned idx) {
       return mDarbuotojai[idx];
   } 

   bool duomenysUzpildyti() const {
       for (int i = 0; i < DARBUOTOJU_KIEKIS; ++i) {
           if (!mDarbuotojai[i].duomenysUzpildyti()) {
               return false;
           }
       }
       return true;
   }

   void spausdintiDarbuotojus(const Darbuotojas::DuomenuPasirinkimas& spausdinimoTvarka) const {
       std::cout << LINE << std::endl;
       for (int i = 0; i < DARBUOTOJU_KIEKIS; ++i) {
           mDarbuotojai[i].spausdintiDuomenis(spausdinimoTvarka);
           std::cout << LINE << std::endl;
       }
   }

   // Filtravimas pagal amžių (2 užduotis)
   void filtruotiAmziu(bool (*fAmziausFiltras)(unsigned), const Darbuotojas::DuomenuPasirinkimas& spausdinimoTvarka) const {
       std::cout << LINE << std::endl;
       for (int i = 0; i < DARBUOTOJU_KIEKIS; ++i) {
           if (fAmziausFiltras(mDarbuotojai[i].gautiAmziu())) {
               mDarbuotojai[i].spausdintiDuomenis(spausdinimoTvarka);
               std::cout << LINE << std::endl;
           }
       }
   }

   // Filtravimas pagal pasirinkimą (3 užduotis)
   // Galima filtruoti tik skaičius
   void filtruotiMinMax(bool (*filtras)(unsigned reiksme, unsigned min, unsigned max), unsigned min, unsigned max, 
                  Darbuotojas::DuomensPasirinkimas duomensPasirinkimas, const Darbuotojas::DuomenuPasirinkimas& spausdinimoTvarka) const {
        if (duomensPasirinkimas != Darbuotojas::D_AMZIUS && duomensPasirinkimas != Darbuotojas::D_PATIRTIS && duomensPasirinkimas != Darbuotojas::D_ATLYGINIMAS) {
            throw std::runtime_error("Netinkamas darbuotojo duomens tipas");
        }

        std::cout << LINE << std::endl;
        for (int i = 0; i < DARBUOTOJU_KIEKIS; ++i) {
           unsigned duomuo = mDarbuotojai[i].gautiPasirinkima<unsigned>(duomensPasirinkimas);
           if (filtras(duomuo, min, max)) {
               mDarbuotojai[i].spausdintiDuomenis(spausdinimoTvarka);
               std::cout << LINE << std::endl;
           }
       }
   }
};

#endif
