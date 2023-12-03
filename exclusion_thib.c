#include "header.h"
void exclusion_constraint() {
    int operations[][2] = {
            {1, 4}, {1, 17}, {1, 20}, {2, 11}, {3, 24},
            {4, 15}, {5, 22}, {6, 24}, {8, 21}, {9, 22},
            {10, 15}, {11, 31}, {12, 13}, {12, 20}, {15, 17},
            {16, 17}, {22, 26}, {30, 33}, {31, 32}, {33, 3}
    };
    int num_operations = sizeof(operations) / sizeof(operations[0]);

    int nbstations = 10;
    int graph[MAX_OPERATIONS][MAX_OPERATIONS] = {0};
    int couleurs[MAX_OPERATIONS] = {0};


    for (int i = 0; i < num_operations; i++) {
        int op1 = operations[i][0];
        int op2 = operations[i][1];
        graph[op1][op2] = 1;
        graph[op2][op1] = 1;
    }


    for (int node = 1; node <= num_operations; node++) {
        int voisins[MAX_OPERATIONS] = {0};
        int couleur_util[MAX_OPERATIONS] = {0};


        int num_voisin = 0;
        for (int i = 1; i <= num_operations; i++) {
            if (graph[node][i]) {
                voisins[num_voisin++] = i;
            }
        }


        for (int i = 0; i < num_voisin; i++) {
            int voisin = voisins[i];
            if (couleurs[voisin] != 0) {
                couleur_util[couleurs[voisin]] = 1;
            }
        }


        for (int couleur = 1; couleur <= num_operations; couleur++) {
            if (!couleur_util[couleur]) {
                couleurs[node] = couleur;
                break;
            }
        }
    }


    printf("Repartition par station:\n");
    for (int station = 1; station <= nbstations; station++) {
        printf("Station %d: ", station);
        for (int op = 1; op <= num_operations; op++) {
            if (couleurs[op] == station) {
                printf("%d ", op);
            }
        }
        printf("\n");
    }
}

