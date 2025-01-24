#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Strukture za heroja i čudovište
typedef struct {
    char ime[20];
    int zdravlje;
    int napad;
    int magija;
    int nivo;
} Heroj;

typedef struct {
    char ime[20];
    int zdravlje;
    int napad;
} Cudoviste;

// Funkcija za borbu
void borba(Heroj *heroj, Cudoviste *cudoviste) {
    printf("\nPočinje borba sa čudovištem: %s!\n", cudoviste->ime);
    while (heroj->zdravlje > 0 && cudoviste->zdravlje > 0) {
        printf("\nHeroj (%d zdravlje) VS %s (%d zdravlje)\n", heroj->zdravlje, cudoviste->ime, cudoviste->zdravlje);
        printf("Izaberite potez:\n1. Napad\n2. Specijalni napad (koristi magiju)\n3. Izlečenje (koristi magiju)\n");
        int izbor;
        scanf("%d", &izbor);

        if (izbor == 1) {
            printf("Napadate čudovište i nanosite %d štete!\n", heroj->napad);
            cudoviste->zdravlje -= heroj->napad;
        } else if (izbor == 2 && heroj->magija >= 10) {
            printf("Koristite specijalni napad i nanosite %d štete!\n", heroj->napad * 2);
            cudoviste->zdravlje -= heroj->napad * 2;
            heroj->magija -= 10;
        } else if (izbor == 3 && heroj->magija >= 5) {
            printf("Izlečite se za 20 zdravlja!\n");
            heroj->zdravlje += 20;
            heroj->magija -= 5;
        } else {
            printf("Nemate dovoljno magije za ovaj potez!\n");
        }

        if (cudoviste->zdravlje > 0) {
            printf("%s napada vas i nanosi %d štete!\n", cudoviste->ime, cudoviste->napad);
            heroj->zdravlje -= cudoviste->napad;
        }
    }

    if (heroj->zdravlje > 0) {
        printf("\nPobedili ste %s!\n", cudoviste->ime);
        heroj->nivo++;
        heroj->napad += 5;
        heroj->zdravlje += 20;
        heroj->magija += 10;
        printf("Vaš nivo je sada: %d. Zdravlje: %d, Napad: %d, Magija: %d\n", heroj->nivo, heroj->zdravlje, heroj->napad, heroj->magija);
    } else {
        printf("\nIzgubili ste borbu... Igra je završena.\n");
    }
}

// Glavna igra
int main() {
    srand(time(0));

    // Kreiranje heroja
    Heroj heroj;
    printf("Dobrodošli u RPG avanturu!\n");
    printf("Izaberite klasu:\n1. Ratnik (Visoko zdravlje, srednji napad)\n2. Mag (Nisko zdravlje, visoka magija)\n3. Strijelac (Balansirani atributi)\n");
    int izborKlase;
    scanf("%d", &izborKlase);

    if (izborKlase == 1) {
        sprintf(heroj.ime, "Ratnik");
        heroj.zdravlje = 150;
        heroj.napad = 15;
        heroj.magija = 10;
    } else if (izborKlase == 2) {
        sprintf(heroj.ime, "Mag");
        heroj.zdravlje = 100;
        heroj.napad = 10;
        heroj.magija = 30;
    } else {
        sprintf(heroj.ime, "Strijelac");
        heroj.zdravlje = 120;
        heroj.napad = 12;
        heroj.magija = 20;
    }
    heroj.nivo = 1;

    printf("\nIzabrali ste klasu: %s. Zdravlje: %d, Napad: %d, Magija: %d\n", heroj.ime, heroj.zdravlje, heroj.napad, heroj.magija);

    // Kreiranje čudovišta
    Cudoviste cudovista[] = {
        {"Goblin", 80, 10},
        {"Trol", 120, 15},
        {"Zmaj", 200, 20}
    };

    int brojCudovista = sizeof(cudovista) / sizeof(cudovista[0]);

    // Glavna petlja igre
    for (int i = 0; i < brojCudovista; i++) {
        borba(&heroj, &cudovista[i]);
        if (heroj.zdravlje <= 0) {
            break;
        }
    }

    if (heroj.zdravlje > 0) {
        printf("\nČestitamo! Pobijedili ste sva čudovišta i završili igru kao šampion!\n");
    }

    return 0;
}
