#include <stdio.h>

int main() {

    char cadena[] = "ESCOM - IPN";
    char * cad = &cadena[0];
    for (int i = 0; cadena[i] != '\0'; i++) {
        printf("%c", cadena[i]);
    }
    printf("\n");
    printf("%c\n", *(cad + 4));
    while (*cad) {
        printf("%p\n", cad++);
    }
    
    printf("\n");
    return 0;
}