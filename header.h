//
// Created by MAJ on 14/11/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_2_HEADER_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_2_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#define MAX_OPERATIONS 100
void exclusion_constraint();
typedef struct {
    int op1;
    int op2;
} OperationPair;

struct taches
{
    float Numero;
    float temps;
    float precedent1;
    float precedent2;
    int couleur;
    int nbstation;
};

typedef struct taches* ptaches;


void lirefichier_temps (char *  nomFichier, ptaches lesTaches);
//void lirefichier_exclu (char *  nomFichier, ptaches lesTaches);
void lirefichier_precedent (char *  nomFichier, ptaches lesTaches, int nbprec, int nbtaches);
int nbTaches ();
int nbprecedences ();
void prec_temps (ptaches lesTaches, int nbtaches);



#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_ING2_TG_2023_2024_2_2_HEADER_H
