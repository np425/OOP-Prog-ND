#include <iostream>

/*

6.1 Užduotis:
 - Klasė stačiakampis <T1,T2>
   - ilgis (T1)
   - plotis (T2)
   - plotas (T2)
 - Sukuria trys stačiakampio objektus:
   1. <int,int>
   2. <double,double>
   3. <int,double>
 - Juos nuskaito
 - Atspausdina kiekvieno stačiakampio plotą
*/

template<class IlgioTipas, class PlocioTipas, class PlotoTipas = PlocioTipas>
class Staciakampis {
    IlgioTipas ilgis_;
    PlocioTipas plotis_;
    PlotoTipas plotas_;

    inline PlotoTipas skaiciuotiPlota() const {
        return ilgis_ * plotis_;
    }

public:
    Staciakampis(IlgioTipas ilgis, PlocioTipas plotis) : ilgis_(ilgis), plotis_(plotis) {
        plotas_ = skaiciuotiPlota();
    }

    PlotoTipas gautiPlota() const {
        return plotas_;
    }
};

template<class IlgioTipas, class PlocioTipas, class PlotoTipas = PlocioTipas>
inline Staciakampis<IlgioTipas, PlocioTipas> nuskaitytiStaciakampi() {
    IlgioTipas ilgis;
    PlocioTipas plotis;

    std::cout << "Įveskite stačiakampio ilgį: ";
    std::cin >> ilgis;

    std::cout << "Įveskite stačiakampio plotį: ";
    std::cin >> plotis;

    return Staciakampis<IlgioTipas, PlocioTipas, PlotoTipas>(ilgis, plotis);
}

int main() {
    std::cout << "1. ilgis, plotis ir plotas - sveikieji skaičiai" << std::endl;
    auto staciakampis1 = nuskaitytiStaciakampi<int, int>();
    std::cout << "Plotas: " << staciakampis1.gautiPlota() << std::endl;

    std::cout << "2. ilgis, plotis ir plotas - realieji skaičiai" << std::endl;
    auto staciakampis2 = nuskaitytiStaciakampi<double, double>();
    std::cout << "Plotas: " << staciakampis2.gautiPlota() << std::endl;

    std::cout << "3. ilgis - sveikasis skaičius, plotis ir plotas - realieji skaičiai" << std::endl;
    auto staciakampis3 = nuskaitytiStaciakampi<int, double>();
    std::cout << "Plotas: " << staciakampis3.gautiPlota() << std::endl;

    return 0;
}
