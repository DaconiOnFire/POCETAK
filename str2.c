#include <stdio.h>
#include <ctype.h>
//nizovi znakova//
//delovi stringa//
int main() {
    char c;//znak,ascii kod,najmanji deo stringa//
    scanf("%c",&c);
    printf("%c",c);
//da li je taj znak cifra//
    if (isdigit(c)) printf("it is a digit");
    else printf("it is not a digit");
    //isdigit je formula da li je cifra//
}