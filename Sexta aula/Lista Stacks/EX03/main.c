#include <stdio.h>
#include "Stack.h"

int main(void) {
    char eq[MAX];

    printf("Digite uma equacao para ser verificada:\n");
    scanf("%[^\n]", eq);

    if (!verificar_parenteses(eq)) {
        printf("Incorreto!");
    } else {
        printf("Correto!");
    }

    return 0;
}