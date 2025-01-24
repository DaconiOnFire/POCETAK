#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Konstantne za dimenzije lavirinta
#define REDOVI 10
#define KOLONE 10

// Simboli u lavirintu
#define PRAZNO ' '
#define ZID '#'
#define IGRAC 'P'
#define IZLAZ 'E'
#define ZAMKA 'X'
#define NAGRADA '*'

// Funkcija za ispis lavirinta
void ispisiLavirint(char lavirint[REDOVI][KOLONE]) {
    for (int i = 0; i < REDOVI; i++) {
        for (int j = 0; j < KOLONE; j++) {
            printf("%c ", lavirint[i][j]);
        }
        printf("\n");
    }
}

// Glavni program
int main() {
    char lavirint[REDOVI][KOLONE];
    int igracX = 0, igracY = 0; // Početna pozicija igrača
    int izlazX, izlazY;
    int poeni = 0;
    int potezi = 50; // Maksimalan broj poteza

    srand(time(0));

    // Generisanje lavirinta
    for (int i = 0; i < REDOVI; i++) {
        for (int j = 0; j < KOLONE; j++) {
            if (rand() % 5 == 0) {
                lavirint[i][j] = ZID; // Nasumični zidovi
            } else if (rand() % 10 == 0) {
                lavirint[i][j] = ZAMKA; // Zamke
            } else if (rand() % 8 == 0) {
                lavirint[i][j] = NAGRADA; // Nagrade
            } else {
                lavirint[i][j] = PRAZNO; // Prazan prostor
            }
        }
    }

    // Postavljanje igrača i izlaza
    lavirint[igracX][igracY] = IGRAC;
    do {
        izlazX = rand() % REDOVI;
        izlazY = rand() % KOLONE;
    } while (lavirint[izlazX][izlazY] != PRAZNO);
    lavirint[izlazX][izlazY] = IZLAZ;

    printf("Dobrodošli u avanturu u lavirintu!\n");
    printf("Vaš cilj je da dođete do izlaza (E) i izbegnete zamke (X).\n");
    printf("Nagrade (*) donose poene. Imate %d poteza.\n", potezi);

    // Glavna petlja igre
    while (potezi > 0) {
        ispisiLavirint(lavirint);
        printf("Poeni: %d | Preostali potezi: %d\n", poeni, potezi);
        printf("Unesite potez (W-gore, A-levo, S-dole, D-desno): ");
        char potez;
        scanf(" %c", &potez);

        int noviX = igracX;
        int noviY = igracY;

        // Obrada poteza
        if (potez == 'W' || potez == 'w') noviX--;
        else if (potez == 'A' || potez == 'a') noviY--;
        else if (potez == 'S' || potez == 's') noviX++;
        else if (potez == 'D' || potez == 'd') noviY++;

        // Provera granica i prepreka
        if (noviX >= 0 && noviX < REDOVI && noviY >= 0 && noviY < KOLONE) {
            if (lavirint[noviX][noviY] == ZID) {
                printf("Udario si u zid!\n");
            } else {
                // Ažuriranje pozicije
                lavirint[igracX][igracY] = PRAZNO;
                igracX = noviX;
                igracY = noviY;

                if (lavirint[igracX][igracY] == ZAMKA) {
                    printf("Upao si u zamku! Gubiš 10 poena.\n");
                    poeni -= 10;
                } else if (lavirint[igracX][igracY] == NAGRADA) {
                    printf("Pronašao si nagradu! Dobijaš 20 poena.\n");
                    poeni += 20;
                } else if (lavirint[igracX][igracY] == IZLAZ) {
                    printf("Čestitamo! Pronašao si izlaz!\n");
                    printf("Ukupan skor: %d poena\n", poeni);
                    return 0;
                }

                lavirint[igracX][igracY] = IGRAC;
            }
        } else {
            printf("Potez van granica lavirinta!\n");
        }

        potezi--;
    }

    printf("Istekli su potezi! Kraj igre. Ukupan skor: %d\n", poeni);
    return 0;
}
