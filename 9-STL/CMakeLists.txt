cmake_minimum_required(VERSION 3.22)
project(OOP_Prog_ND)

set(CMAKE_CXX_STANDARD 14)

add_executable(9.1-dvetainiai 1-dvejetainiai.cpp)
add_executable(9.2-skaiciu-seka 2-skaiciu-seka.cpp)
add_executable(9.3-kalendorius 3-kalendorius.cpp meniu/meniu.h meniu/kalendoriaus.h kalendorius.h)

