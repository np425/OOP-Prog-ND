#include <iostream>

/*

3.2 Užduotis:
 - Klasė atlyginimas:
   - darbo vietos kaina
   - darbdavio sumokami mokesčiai:
     - skaičiuojami nuo darbo vietos kainos
     - SODRA: 31,17%
   - darbuotojo sumokami mokesčiai:
     - skaičiuojami nuo likusios darbdavio mokesčių dalies
     - pajamų mokėstis: 15%
	 - SODRA: 9%
   - darbuotojo gaunama pinigų suma
 - Klasė darbuotojas, su privačiais duomenimis:
   - amžius
   - darbo patirtis
   - atlyginimas (klasė atlyginimas)
 - Įrašo į darbuotojo objektą duomenis
 - Atspausdina darbuotojo objekto duomenis

*/

class Atlyginimas {
public:
    constexpr static double DARBDAVIO_SODRA = 0.3117;
    constexpr static double DARBUOTOJO_SODRA = 0.15;
    constexpr static double DARBUOTOJO_PAJAM_MOKESC = 0.09;
    constexpr static double DARBUOTOJO_MOKESC = DARBUOTOJO_SODRA + DARBUOTOJO_PAJAM_MOKESC;

private:
    double darboKaina_;
    double darbdavioMokesciai_;
    double darbuotojoMokesciai_;
    double darbuotojoPajamos_;

public:
    explicit Atlyginimas(double darboKaina) : darboKaina_(darboKaina) {
        darbdavioMokesciai_ = darboKaina * DARBDAVIO_SODRA;
        darbuotojoMokesciai_ = (darboKaina - darbdavioMokesciai_) * DARBUOTOJO_MOKESC;
        darbuotojoPajamos_ = darboKaina - darbdavioMokesciai_ - darbuotojoMokesciai_;
    }

    void spausdintiAtlyginima() const {
        std::cout << "Atlyginimas ant popieriaus: " << darboKaina_ << std::endl;
        std::cout << "Darbdavio mokesčiai: " << darbdavioMokesciai_ << std::endl;
        std::cout << "Darbuotojo mokesčiai: " << darbuotojoMokesciai_ << std::endl;
        std::cout << "Atlyginimas į rankas: " << darbuotojoPajamos_ << std::endl;
    }
};

class Darbuotojas {
    unsigned amzius_;
    unsigned darboPatirtis_;
    Atlyginimas atlyginimas_;

public:
    Darbuotojas(unsigned amzius, unsigned darboPatirtis, unsigned darboKaina)
        : amzius_(amzius), darboPatirtis_(darboPatirtis), atlyginimas_(darboKaina) {
    }

public:
    void spausdintiDuomenis() {
        std::cout << "Amžius: " << amzius_ << std::endl;
        std::cout << "Darbo patirtis: " << darboPatirtis_ << std::endl;
        atlyginimas_.spausdintiAtlyginima();
    }
};

int main() {
    unsigned amzius;
    unsigned darboPatirtis;
    unsigned darboKaina;

    std::cout << "Amžius: ";
    std::cin >> amzius;

    std::cout << "Darbo patirtis: ";
    std::cin >> darboPatirtis;

    std::cout << "Atlyginimas ant popieriaus: ";
    std::cin >> darboKaina;

    Darbuotojas darbuotojas(amzius, darboPatirtis, darboKaina);

    darbuotojas.spausdintiDuomenis();

    return 0;
}
