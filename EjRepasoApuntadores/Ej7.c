#include <stdio.h>

int main() {
    int entero = 1234567890;
    printf("%d %x", entero, entero);
    printf("\n");

    int entero2 = -1234567890;
    printf("%d %x", entero2, entero2);
    printf("\n");
    for (int i = -4; i < 5; i++) {
        printf("%d %x\n", i, i);
    }
    printf("minimo numero negativo %d\n", (1 << 31)); // 2 ^ 32, 10000...
    printf("maximo numero positivo %d\n", (1 << 31) - 1); // 2 ^ 32 - 1, 01111... 
    return 0;
}