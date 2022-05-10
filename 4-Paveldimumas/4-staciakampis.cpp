#include <iostream>

#define POW_2(x) (x*x)

/*

4.4 Užduotis:
 - Klasė geometrinė figūra:
   - perimentras (p)
   - plotas (s)
 - Klasė stačiakampis (kilęs iš klasės geometrinė figūra):
   - ilgis
   - plotis
 - Klasė stačiakampis gretasienis (kilęs iš klasės stačiakampis):
   - aukštis
   - turis
 - Įrašo į stačiakampį gretasienį duomenis per konstruktorius
 - Apskaičiuoja plotą, perimetrą
 - Atspausdina visą informaciją 
*/

class GeometrineFigura {
protected:
    double plotas_{};
    double perimetras_{};

public:
    virtual void skaiciuotiPlota() = 0;
    virtual void skaiciuotiPerimetra() = 0;

    virtual void skaiciuotiDuomenis() {
        skaiciuotiPlota();
        skaiciuotiPerimetra();
    };

    friend std::ostream &operator<<(std::ostream &os, const GeometrineFigura &figura) {
        os << "Plotas: " << figura.plotas_ << std::endl;
        os << "Perimetras: " << figura.perimetras_;
        return os;
    }
};

class Staciakampis : public GeometrineFigura {
protected:
    double ilgis_;
    double plotis_;

public:
    Staciakampis(double ilgis, double plotis) : GeometrineFigura(), ilgis_(ilgis), plotis_(plotis) {
    }

    inline void skaiciuotiPerimetra() override {
        perimetras_ = 2 * (ilgis_ + plotis_);
    }

    inline void skaiciuotiPlota() override {
        plotas_ = ilgis_ * plotis_;
    }

    friend std::ostream &operator<<(std::ostream &os, const Staciakampis &staciakampis) {
        os << (const GeometrineFigura &) staciakampis << std::endl;
        os << "Ilgis: " << staciakampis.ilgis_ << std::endl;
        os << "Plotis: " << staciakampis.plotis_;
        return os;
    }
};

class StaciakampisGretasienis : public Staciakampis {
protected:
    double aukstis_;
    double turis_{};

public:
    StaciakampisGretasienis(double ilgis, double plotis, double aukstis)
        : Staciakampis(ilgis, plotis), aukstis_(aukstis) {
    }

    inline void skaiciuotiTuri() {
        turis_ = plotas_ * aukstis_;
    }

    inline void skaiciuotiPerimetra() override {
        Staciakampis::skaiciuotiPerimetra();
        perimetras_ = perimetras_ * 2 + aukstis_ * 4;
    }

    void skaiciuotiDuomenis() override {
        Staciakampis::skaiciuotiDuomenis();
        skaiciuotiTuri();
    }

    friend std::ostream &operator<<(std::ostream &os, const StaciakampisGretasienis &staciakampisGretasienis) {
        os << (const Staciakampis &) staciakampisGretasienis << std::endl;
        os << "Aukštis: " << staciakampisGretasienis.aukstis_ << std::endl;
        os << "Tūris: " << staciakampisGretasienis.turis_;
        return os;
    }
};

int main() {
    double ilgis, aukstis, plotis;

    std::cout << "Įveskite ilgį: ";
    std::cin >> ilgis;

    std::cout << "Įveskite plotį: ";
    std::cin >> plotis;

    std::cout << "Įveskite aukštį: ";
    std::cin >> aukstis;

    StaciakampisGretasienis staciakampisGretasienis(ilgis, plotis, aukstis);

    staciakampisGretasienis.skaiciuotiDuomenis();

    std::cout << staciakampisGretasienis << std::endl;

    return 0;
}
