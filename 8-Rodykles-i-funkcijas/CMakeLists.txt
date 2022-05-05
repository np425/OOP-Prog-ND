cmake_minimum_required(VERSION 3.22)
project(OOP_Prog_ND)

set(CMAKE_CXX_STANDARD 14)

add_executable(8.1-darbuotojas 1-darbuotojas.cpp darbuotojas.h meniu/meniu.h meniu/darbuotojo.h)
add_executable(8.2-personalas 2-personalas.cpp darbuotojas.h personalas.h meniu/meniu.h meniu/personalo.h)
add_executable(8.3-personalas 3-personalas.cpp darbuotojas.h personalas.h meniu/meniu.h meniu/personalo.h)
