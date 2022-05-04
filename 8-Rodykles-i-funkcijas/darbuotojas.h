#ifndef OOP_PROG_ND_DARBUOTOJAS_H
#define OOP_PROG_ND_DARBUOTOJAS_H

#include <algorithm>
#include <array>
#include <iostream>
#include <string>

class Darbuotojas {
public:
    constexpr static unsigned DuomenuKiekis = 6;

    enum DuomensPasirinkimas {
        D_VARDAS = 0,
        D_PAVARDE,
        D_SPECIALYBE,
        D_AMZIUS,
        D_PATIRTIS,
        D_ATLYGINIMAS
    };

    static constexpr const char *const DuomenuPasirinkimoPav[DuomenuKiekis] = {
        "Vardas",
        "Pavardė",
        "Specialybė",
        "Amžius",
        "Patirtis",
        "Atlyginimas"
    };

    typedef std::array<DuomensPasirinkimas, DuomenuKiekis> DuomenuPasirinkimas;

    // typedef DuomensPasirinkimas DuomenuPasirinkimas[DuomenuKiekis];

    static constexpr DuomenuPasirinkimas PRADINE_DUOMENU_PASIRINKIMO_TVARKA = {
        D_VARDAS,
        D_PAVARDE,
        D_SPECIALYBE,
        D_AMZIUS,
        D_PATIRTIS,
        D_ATLYGINIMAS
    };

private:
    std::string vardas;
    std::string pavarde;
    std::string specialybe;
    unsigned amzius = 0;
    unsigned patirtis = 0;
    unsigned atlyginimas = 0;

public:
    Darbuotojas() = default;

    Darbuotojas(std::string vardas, std::string pavarde, std::string specialybe, unsigned amzius, unsigned patirtis,
                unsigned atlyginimas)
        : vardas(std::move(vardas)), pavarde(std::move(pavarde)), specialybe(std::move(specialybe)), amzius(amzius),
          patirtis(patirtis), atlyginimas(atlyginimas) {
    }

    inline bool duomenysUzpildyti() const {
        return !vardas.empty() && !pavarde.empty() && !specialybe.empty() && amzius && patirtis && atlyginimas;
    }

    void keistiVarda() {
        std::cout << "Įveskite vardą: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, vardas);
    }

    void keistiPavarde() {
        std::cout << "Įveskite pavardę: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, pavarde);
    }

    void keistiSpecialybe() {
        std::cout << "Įveskite specialybę: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, specialybe);
    }

    void keistiAmziu() {
        std::cout << "Įveskite amžių: " << std::endl;
        std::cin >> amzius;
    }

    void keistiPatirti() {
        std::cout << "Įveskite darbo patirtį: " << std::endl;
        std::cin >> patirtis;
    }

    void keistiAtlyginima() {
        std::cout << "Įveskite atlyginimą: " << std::endl;
        std::cin >> atlyginimas;
    }

    inline void keistiPasirinkima(const DuomensPasirinkimas pasirinkimas) {
        constexpr void (Darbuotojas::*keitimai[Darbuotojas::DuomenuKiekis])() = {
            &Darbuotojas::keistiVarda, &Darbuotojas::keistiPavarde, &Darbuotojas::keistiSpecialybe,
            &Darbuotojas::keistiAmziu, &Darbuotojas::keistiPatirti, &Darbuotojas::keistiAtlyginima
        };

        (this->*keitimai[pasirinkimas])();
    }

    std::string gautiVarda() const { return vardas; }

    std::string gautiPavarde() const { return pavarde; }

    std::string gautiSpecialybe() const { return specialybe; }

    unsigned gautiAmziu() const { return amzius; }

    unsigned gautiPatirti() const { return patirtis; }

    unsigned gautiAtlyginima() const { return atlyginimas; }

    inline unsigned gautiPasirinkima(const DuomensPasirinkimas pasirinkimas) const {
        switch (pasirinkimas) {
            case D_AMZIUS:
                return gautiAmziu();
            case D_PATIRTIS:
                return gautiPatirti();
            case D_ATLYGINIMAS:
                return gautiAtlyginima();
            default:
                throw std::runtime_error("Kito tipo duomenys nepalaikomi");
        }
    }

    void spausdintiVarda() const {
        std::cout << "Vardas: " << vardas << std::endl;
    }

    void spausdintiPavarde() const {
        std::cout << "Pavardė: " << pavarde << std::endl;
    }

    void spausdintiSpecialybe() const {
        std::cout << "Specialybė: " << specialybe << std::endl;
    }

    void spausdintiAmziu() const {
        std::cout << "Amžius: " << amzius << std::endl;
    }

    void spausdintiPatirti() const {
        std::cout << "Patirtis: " << patirtis << std::endl;
    }

    void spausdintiAtlyginima() const {
        std::cout << "Atlyginimas: " << atlyginimas << std::endl;
    }

    inline void
    spausdintiDuomenis(const DuomenuPasirinkimas spausdinimoTvarka = PRADINE_DUOMENU_PASIRINKIMO_TVARKA) const {
        constexpr void (Darbuotojas::*spausdinimai[DuomenuKiekis])() const = {
            &Darbuotojas::spausdintiVarda, &Darbuotojas::spausdintiPavarde, &Darbuotojas::spausdintiSpecialybe,
            &Darbuotojas::spausdintiAmziu, &Darbuotojas::spausdintiPatirti, &Darbuotojas::spausdintiAtlyginima
        };

        for (unsigned i = 0; i < DuomenuKiekis; ++i) {
            //spausdintiPasirinkima(spausdinimoTvarka[i]);
            (this->*spausdinimai[spausdinimoTvarka[i]])();
        }
    }
};

constexpr const char *const Darbuotojas::DuomenuPasirinkimoPav[DuomenuKiekis];

#endif//OOP_PROG_ND_DARBUOTOJAS_H
