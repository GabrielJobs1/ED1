#include "Stack.h"
#include <stdio.h>

int main(){
    Stack *P1 = create();
    Stack *P2 = create();

    push(P1, 54);
    push(P1, 45);
    push(P1, 67);

    trans_elementos(P1,P2);

    printar(P2);

    destroy(P1);
    destroy(P2);

    return 0;
}