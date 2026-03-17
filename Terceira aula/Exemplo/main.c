#include "Aula3.h"
#include <stdio.h>

int main(){
    TPonto* novo = TPonto_create(3,5);

    TPonto_print(novo);
    float x;
    TPonto_get_x(novo, &x);

    printf("\nValor de x: %0.2f", x);
    return 0;

    TPonto_destroy(novo);
    
    Tponto_modificar(novo);

    TPonto_print(novo);
}