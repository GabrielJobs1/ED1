#include <stdio.h>
#include "Stack.h"

int main() {
    Stack *P = create();
    int n;

    do {
        printf("Insira um Elemento na Pilha (Digite -1 para sair):\n");

        if (scanf("%d", &n) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }

        if (n != -1) {
            push(P, n);
        }
    } while (n != -1);

    printar_inverso(P);

    return 0;
}