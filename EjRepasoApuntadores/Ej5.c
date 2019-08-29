#include <stdio.h>

int main() {
    char caracter = 0;
    int entero = 0;
    float flotante = 0;
    long largo = 0;
    double doble = 0;

    char * pcaracter;
    printf("basura: %p\n", pcaracter);
    pcaracter = &caracter;
    printf("%p = ", pcaracter);
    printf("%p\n", &caracter);
    return 0;
}