#include <stdio.h>
#include "Stack.h"
#include <string.h>
int main() {
    char frase[MAX];
    printf("Digite uma frase: ");
    scanf("%[^\n]", frase);
    
    inverter_frase(frase);
    
    return 0;
}