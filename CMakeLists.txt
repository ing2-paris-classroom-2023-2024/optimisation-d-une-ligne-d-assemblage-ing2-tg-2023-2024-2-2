cmake_minimum_required(VERSION 3.23)
project(optimisation_d_une_ligne_d_assemblage_ing2_tg_2023_2024_2_2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(optimisation_d_une_ligne_d_assemblage_ing2_tg_2023_2024_2_2
        header.h
        main.c
        exclusion_thib.c
        lire.c
        contraintes.c)
