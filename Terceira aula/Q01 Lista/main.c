#include <stdio.h>
#include "Ex01.h"

int main() {
    FR *f1, *f2, *r;
    int op,opc;
    
    printf("\n-----RACIONAL 1-----\n");
    f1 = CriarRacional();
    printf("Racional 1: %d/%d\n",obter_numerador(f1),obter_denominador(f1));
    
    printf("\n-----RACIONAL 2-----\n");
    f2 = CriarRacional();
    printf("Racional 2: %d/%d\n",obter_numerador(f2),obter_denominador(f2));
    
    printf("\nOque deseja fazer?(1 = Somar, 2 = Multiplicar,3 = testar equivalencia)\n");
    scanf("%d", &op);
    
    switch(op){
        case 1:
        r = SomarRacionais(f1,f2);
        if (r != NULL) {
        printf("\nResultado da soma: %d/%d\n", obter_numerador(r), obter_denominador(r));
        }
        printf("deseja simplificar o resultado?(1 = sim, 2 = nao)\n");
        scanf("%d",&opc);
        switch(opc){
            case 1: SimplificarRacional(r);
            printf("Valor Simplificado: %d/%d",obter_numerador(r),obter_denominador(r));
            break;
            case 2: break;
        }
        destruir_racional(f1);
        destruir_racional(f2);
        destruir_racional(r);
        break;
        
        case 2:
        r = MultiplicarRacional(f1, f2);
        if (r != NULL) {
        printf("\nResultado da soma: %d/%d\n", obter_numerador(r), obter_denominador(r));
        }
        printf("deseja simplificar o resultado?(1 = sim, 2 = nao)\n");
        scanf("%d",&opc);
        switch(opc){
            case 1: SimplificarRacional(r);
            printf("Valor Simplificado: %d/%d",obter_numerador(r),obter_denominador(r));
            break;
            case 2: break;
        }
        destruir_racional(f1);
        destruir_racional(f2);
        destruir_racional(r);
        break;
        
        case 3:
        TestarIgualdade(f1, f2);
        destruir_racional(f1);
        destruir_racional(f2);
        break;
        
        default:
        printf("opçao invalida!!!");
        break;
    }
    
    
    return 0;
}