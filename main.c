#include "header.h"

int main(){

    exclusion_constraint();


    int numtaches=nbTaches (); // permet de connaitre le nombre de taches
    ptaches taches = malloc(numtaches*sizeof*taches);

    int nbprece=nbprecedences();

    char nom_fichier[50]="./operations.txt";
    lirefichier_temps(nom_fichier, taches);

    char nom_fichier2[50]="./precedences.txt";
    lirefichier_precedent(nom_fichier2, taches, nbprece,numtaches);

    prec_temps(taches, numtaches);

    return 0;
}
