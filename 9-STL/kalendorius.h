//
// Created by nerpo on 2022-05-13.
//

#ifndef OOP_PROG_ND_KALENDORIUS_H
#define OOP_PROG_ND_KALENDORIUS_H

#include <map>
#include <string>
#include <list>

struct Uzduotis {
    std::string aprasas;
    bool baigta = false;
};

typedef std::list<Uzduotis> UzduociuSarasas;
typedef std::map<std::string, UzduociuSarasas> Kalendorius;

#endif //OOP_PROG_ND_KALENDORIUS_H
