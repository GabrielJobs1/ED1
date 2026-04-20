#include <stdio.h>
#include "Stack.h"
#include <string.h>
int main() {
    char frase[MAX];
    printf("Digite uma frase: ");
    if (fgets(frase, MAX, stdin) == NULL) {
        return 1;
    }

    frase[strcspn(frase, "\n")] = '\0';
    
    inverter_frase(frase);
    
    return 0;
}