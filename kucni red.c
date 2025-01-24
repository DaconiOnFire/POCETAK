#include <stdio.h>

int main() {
    int sat;
    
    // Унос сата
    scanf("%d", &sat);
    
    // Проверити да ли је дозвољено прављење буке
    if (sat >= 6 && sat < 13 || sat >= 17 && sat < 22) {
        printf("moze\n");
    } else {
        printf("ne moze\n");
    }
    
    return 0;
}
