#include <stdio.h>
#include "Stack.h"

int main(void) {
    Stack *P1 = create();
    Stack *P2 = create();

    if (P1 == NULL || P2 == NULL) {
        printf("Erro ao criar as pilhas.\n");
        destroy(P1);
        destroy(P2);
        return 1;
    }

    push(P1, 10);
    push(P1, 20);
    push(P1, 30);

    push(P2, 10);
    push(P2, 20);
    push(P2, 30);

    if (pilhas_iguais(P1, P2)) {
        printf("As pilhas P1 e P2 sao iguais.\n");
    } else {
        printf("As pilhas P1 e P2 sao diferentes.\n");
    }

    destroy(P1);
    destroy(P2);
    return 0;
}
