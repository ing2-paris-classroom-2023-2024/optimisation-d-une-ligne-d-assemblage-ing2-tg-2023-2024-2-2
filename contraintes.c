//
// Created by MAJ on 03/12/2023.
//
#include "header.h"

void prec_temps (ptaches lesTaches, int nbtaches){ // Algo avec la contrainte du temps et de la précédence
    int station=1;
    float temps=5;
    float temps2=0;
    int nbattribuees =0;
    int pasdetemps=0;

    while (nbattribuees!=nbtaches){ // tant que toutes les taches n'ont pas été attribuée

        if(pasdetemps=(nbtaches-nbattribuees )){ // si il n'y a plus de place dans une station

            station=station+1;
            temps2=0;
        }
        for (int i = 0; i < nbtaches; ++i) {
            if (lesTaches[i].couleur!=1){ // si la tache n'a pas déjà été attribuée

                if ((lesTaches[i].temps+temps2)<temps){ // si la tache n'est pas trop longue

                    if (lesTaches[i].precedent1==0 && lesTaches[i].precedent2==0){ // si la tache n'a pas de predécesseurs

                        lesTaches[i].nbstation=station;
                        lesTaches[i].couleur=1;
                        temps2=temps2+lesTaches[i].temps;
                        nbattribuees=nbattribuees+1;

                    }
                    else {

                        if (lesTaches[i].precedent1!=0 && lesTaches[i].precedent2==0){ // si la tache n'a qu'un seul predécesseur

                            float prec = lesTaches[i].precedent1;
                            for (int j = 0; j < nbtaches; ++j) {
                                if(lesTaches[j].Numero==prec && lesTaches[j].couleur==1){

                                    lesTaches[i].nbstation=station;
                                    lesTaches[i].couleur=1;
                                    temps2=temps2+lesTaches[i].temps;
                                    nbattribuees=nbattribuees+1;

                                }

                            }
                        }
                        else { // si elle en a deux

                            float prec = lesTaches[i].precedent1;
                            for (int j = 0; j < nbtaches; ++j) {
                                if(lesTaches[j].Numero==prec && lesTaches[j].couleur==1){ // la première tache est effectuée
                                    prec = lesTaches[i].precedent2;
                                    for (int k = 0; k < nbtaches; ++k) {
                                        if(lesTaches[k].Numero==prec && lesTaches[k].couleur==1){ // la seconde tache également

                                            lesTaches[i].nbstation=station;
                                            lesTaches[i].couleur=1;
                                            temps2=temps2+lesTaches[i].temps;
                                            nbattribuees=nbattribuees+1;

                                        }

                                    }
                                }

                            }
                        }

                    }


                }
                else { // s'il n'y a plus assez de temps pour faire la tache dans cette station

                    pasdetemps=pasdetemps+1;

                }
            }


        }
    }
    for (int i = 1; i < station; ++i) { // affiche les différentes taches dans les différentes stations
        printf("\n------------------------------------------- \n");
        printf("\n STATION %d\n\n", i);
        for (int j = 0; j < nbtaches; ++j) {
            if(lesTaches[j].nbstation==i+1){
                printf("%.0f   ", lesTaches[j].Numero);
            }
        }
    }

}
