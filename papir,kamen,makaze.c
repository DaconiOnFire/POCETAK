#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printResult(int userChoice, int computerChoice) {
    char *choices[] = {"Kamen", "Papir", "Makaze"};
    printf("Vi: %s, Racunar: %s\n", choices[userChoice], choices[computerChoice]);

    if (userChoice == computerChoice) {
        printf("Rezultat: Nereseno!\n");
    } else if ((userChoice == 0 && computerChoice == 2) || 
               (userChoice == 1 && computerChoice == 0) || 
               (userChoice == 2 && computerChoice == 1)) {
        printf("Rezultat: Pobeda!\n");
    } else {
        printf("Rezultat: Poraz!\n");
    }
}

int main() {
    srand(time(0));
    int userScore = 0, computerScore = 0;
    char playAgain;

    do {
        printf("Izaberite: 0 = Kamen, 1 = Papir, 2 = Makaze: ");
        int userChoice;
        scanf("%d", &userChoice);

        if (userChoice < 0 || userChoice > 2) {
            printf("Neispravan unos! Pokusajte ponovo.\n");

            continue;
        }

        int computerChoice = rand() % 3;
        printResult(userChoice, computerChoice);

        if ((userChoice == 0 && computerChoice == 2) || 
            (userChoice == 1 && computerChoice == 0) || 
            (userChoice == 2 && computerChoice == 1)) {
            userScore++;
        } else if (userChoice != computerChoice) {
            computerScore++;
        }

        printf("Trenutni rezultat - Vi: %d, Racunar: %d\n", userScore, computerScore);

        printf("Igrati ponovo? (d/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'd' || playAgain == 'D');

    printf("Krajnji rezultat - Vi: %d, Racunar: %d\n", userScore, computerScore);
    printf("Hvala sto ste igrali!\n");

    return 0;
}
