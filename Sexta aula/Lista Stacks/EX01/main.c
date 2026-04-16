#include <stdio.h>
#include "Stack.h"

int main() {
    Stack *s = CriarPilha();
    char c[40];

    printf("Digite uma palavra:\n");
    scanf("%[^\n]", c);

    LerString(s, c);
    PrintarInverso(s);

    return 0;
}
