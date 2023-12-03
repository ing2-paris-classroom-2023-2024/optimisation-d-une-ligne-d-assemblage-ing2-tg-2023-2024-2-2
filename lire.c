//
// Created by MAJ on 03/12/2023.
//
#include "header.h"

int nbTaches (){ // lit le nombre de lignes pour savoir le nombre de taches
    FILE *fc2 = fopen ("./operations.txt", "r");
    int c;
    int nLignes = 0;
    while((c=fgetc(fc2)) != EOF)
    {
        if(c=='\n')
            nLignes++;
    }
    fclose (fc2), fc2 = NULL;
    return nLignes;
}
int nbprecedences (){ // lit le nombre de lignes pour savoir le nombre de précedences
    FILE *fc2 = fopen ("./precedences.txt", "r");
    int c;
    int nPrecedences = 0;
    while((c=fgetc(fc2)) != EOF)
    {
        if(c=='\n')
            nPrecedences++;
    }
    fclose (fc2), fc2 = NULL;
    return nPrecedences;
}

void lirefichier_temps (char * nomFichier, ptaches lesTaches){       // liste des taches et leur temps

    FILE *fp = fopen (nomFichier, "r");                // ouvre le fichier



    if (fp != NULL)
    {
        char line[128];
        int i=0;
        while (fgets (line, sizeof line, fp) != NULL)
        {
            char *p = line;

            int valeur=1;                   // pour savoir si c'est le premier nombre de la ligne ou le second
            while (*p != '\n' && *p != 0)
            {

                char *pend;
                float val = strtod (p, &pend); // pour séparer les deux nombres lut sur la ligne

                if (*p != 0 && pend != p)
                {
                    if (valeur==1){
                        lesTaches[i].Numero=val; // le numero de la taches

                    }
                    if (valeur==2){
                        lesTaches[i].temps=val; // le temps que prend la tache

                    }

                }
                p = pend + 1;
                valeur++;

            }
            i++;
        }
        fclose (fp), fp = NULL; // ferme le fichier
    }
    else
    {
        perror (nomFichier); // si le fichier ne s'ouvre pas
    }
}




void lirefichier_precedent (char *  nomFichier, ptaches lesTaches, int nbprec, int nbtaches){ // Lit les différentes précédences

    FILE *fp = fopen (nomFichier, "r"); // ouvre le fichier

    for (int i = 0; i < nbtaches; ++i) { // initialise les structures des taches
        lesTaches[i].precedent1=0;
        lesTaches[i].precedent2=0;
        lesTaches[i].couleur=0;
    }


    if (fp != NULL)
    {
        char line[128];
        int i=0;
        while (fgets (line, sizeof line, fp) != NULL)
        {
            char *p = line;


            int valeur=1; // pareil que pour l'autre, ppour différencier les deux valeurs
            float precedent;
            while (*p != '\n' && *p != 0)
            {

                char *pend;
                float val = strtod (p, &pend);


                if (*p != 0 && pend != p)
                {
                    if (valeur==1){ // donne la tache qui precède
                        precedent=val;

                    }
                    if (valeur==2){
                        for (int j = 0; j < nbtaches; ++j) {
                            if (lesTaches[j].Numero==val){
                                if (lesTaches[j].precedent1!=0){ // s'il y a déjà une première précédence
                                    lesTaches[j].precedent2=precedent;
                                }
                                else{
                                    lesTaches[j].precedent1=precedent;
                                }

                            }
                        }

                    }


                }
                p = pend + 1;
                valeur++;

            }
            i++;
        }
        fclose (fp), fp = NULL; // ferme le fichier
    }
    else
    {
        perror (nomFichier); // si le fichier ne s'ouvre pas
    }
}
