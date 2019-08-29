#include <stdio.h>

int main() {
    char caracter = 0;
    int entero = 0;
    float flotante = 0;
    long largo = 0;
    double doble = 0;
    int * ap;
    printf("%p %p %p %p %p\n", &caracter, &entero, &flotante, &largo, &doble);
    printf("%d\n", sizeof(caracter));
    printf("%d\n", sizeof(entero));
    printf("%d\n", sizeof(flotante));
    printf("%d\n", sizeof(largo));
    printf("%d\n", sizeof(doble));
    printf("%d\n", sizeof(ap));
    return 0;
}