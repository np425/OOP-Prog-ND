#ifndef OOP_PROG_ND_DARBUOTOJAS_H
#define OOP_PROG_ND_DARBUOTOJAS_H

#include <algorithm>
#include <array>
#include <iostream>
#include <string>

class Darbuotojas {
public:
    constexpr static unsigned DUOMENU_KIEKIS = 6;

    enum DuomensPasirinkimas {
        D_VARDAS = 0,
        D_PAVARDE,
        D_SPECIALYBE,
        D_AMZIUS,
        D_PATIRTIS,
        D_ATLYGINIMAS
    };

    static constexpr const char *const DuomenuPasirinkimoPavadinimas[DUOMENU_KIEKIS] = {
        "Vardas",
        "Pavardė",
        "Specialybė",
        "Amžius",
        "Patirtis",
        "Atlyginimas"
    };

    typedef std::array<DuomensPasirinkimas, DUOMENU_KIEKIS> DuomenuPasirinkimas;

    static constexpr DuomenuPasirinkimas PRADINE_DUOMENU_PASIRINKIMO_TVARKA = {
        D_VARDAS,
        D_PAVARDE,
        D_SPECIALYBE,
        D_AMZIUS,
        D_PATIRTIS,
        D_ATLYGINIMAS
    };

private:
    std::string vardas_;
    std::string pavarde_;
    std::string specialybe_;
    unsigned amzius_ = 0;
    unsigned patirtis_ = 0;
    unsigned atlyginimas_ = 0;

public:
    Darbuotojas() = default;

    Darbuotojas(std::string vardas, std::string pavarde, std::string specialybe, unsigned amzius, unsigned patirtis,
                unsigned atlyginimas)
        : vardas_(std::move(vardas)), pavarde_(std::move(pavarde)), specialybe_(std::move(specialybe)), amzius_(amzius),
        patirtis_(patirtis), atlyginimas_(atlyginimas) {
    }

    inline bool duomenysUzpildyti() const {
        return !vardas_.empty() && !pavarde_.empty() && !specialybe_.empty() && amzius_ && patirtis_ && atlyginimas_;
    }

    void keistiVarda() {
        std::cout << "Įveskite vardą: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, vardas_);
    }

    void keistiPavarde() {
        std::cout << "Įveskite pavardę: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, pavarde_);
    }

    void keistiSpecialybe() {
        std::cout << "Įveskite specialybę: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, specialybe_);
    }

    void keistiAmziu() {
        std::cout << "Įveskite amžių: " << std::endl;
        std::cin >> amzius_;
    }

    void keistiPatirti() {
        std::cout << "Įveskite darbo patirtį: " << std::endl;
        std::cin >> patirtis_;
    }

    void keistiAtlyginima() {
        std::cout << "Įveskite atlyginimą: " << std::endl;
        std::cin >> atlyginimas_;
    }

    inline void keistiPasirinkima(const DuomensPasirinkimas pasirinkimas) {
        constexpr void (Darbuotojas::*keitimai[Darbuotojas::DUOMENU_KIEKIS])() = {
            &Darbuotojas::keistiVarda, &Darbuotojas::keistiPavarde, &Darbuotojas::keistiSpecialybe,
            &Darbuotojas::keistiAmziu, &Darbuotojas::keistiPatirti, &Darbuotojas::keistiAtlyginima
        };

        (this->*keitimai[pasirinkimas])();
    }

    std::string gautiVarda() const {
        return vardas_;
    }

    std::string gautiPavarde() const {
        return pavarde_;
    }

    std::string gautiSpecialybe() const {
        return specialybe_;
    }

    unsigned gautiAmziu() const {
        return amzius_;
    }

    unsigned gautiPatirti() const {
        return patirtis_;
    }

    unsigned gautiAtlyginima() const {
        return atlyginimas_;
    }

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
        std::cout << "Vardas: " << vardas_ << std::endl;
    }

    void spausdintiPavarde() const {
        std::cout << "Pavardė: " << pavarde_ << std::endl;
    }

    void spausdintiSpecialybe() const {
        std::cout << "Specialybė: " << specialybe_ << std::endl;
    }

    void spausdintiAmziu() const {
        std::cout << "Amžius: " << amzius_ << std::endl;
    }

    void spausdintiPatirti() const {
        std::cout << "Patirtis: " << patirtis_ << std::endl;
    }

    void spausdintiAtlyginima() const {
        std::cout << "Atlyginimas: " << atlyginimas_ << std::endl;
    }

    inline void
    spausdintiDuomenis(const DuomenuPasirinkimas spausdinimoTvarka = PRADINE_DUOMENU_PASIRINKIMO_TVARKA) const {
        constexpr void (Darbuotojas::*spausdinimai[DUOMENU_KIEKIS])() const = {
            &Darbuotojas::spausdintiVarda, &Darbuotojas::spausdintiPavarde, &Darbuotojas::spausdintiSpecialybe,
            &Darbuotojas::spausdintiAmziu, &Darbuotojas::spausdintiPatirti, &Darbuotojas::spausdintiAtlyginima
        };

        for (unsigned i = 0; i < DUOMENU_KIEKIS; ++i) {
            //spausdintiPasirinkima(spausdinimoTvarka[i]);
            (this->*spausdinimai[spausdinimoTvarka[i]])();
        }
    }
};

constexpr const char *const Darbuotojas::DuomenuPasirinkimoPavadinimas[DUOMENU_KIEKIS];

#endif//OOP_PROG_ND_DARBUOTOJAS_H
