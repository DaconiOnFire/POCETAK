#include <stdio.h>

int main() {
    int sat, minut;
    
    // Унос сата и минута
    scanf("%d", &sat);
    scanf("%d", &minut);
    
    // Проверити да ли је време у радном времену
    if ((sat > 9 || (sat == 9 && minut >= 0)) && (sat < 17 || (sat == 17 && minut == 0))) {
        printf("da\n");
    } else {
        printf("ne\n");
    }
    
    return 0;
}

