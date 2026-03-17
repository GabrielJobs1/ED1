#include <stdio.h>
#include <stdlib.h> 
#include "Ex01.h"

struct _fr {
    int num;
    int den;
};

FR* CriarRacional() {
    FR *novo = (FR*) malloc(sizeof(FR));
    if (novo != NULL) {
        printf("Digite o numerador: ");
        scanf("%d", &novo->num); 
        printf("Insira o denominador: ");
        scanf("%d", &novo->den); 
    }
    return novo;
}

FR* SomarRacionais(FR *f1, FR *f2){
    FR *res = (FR*)malloc(sizeof(FR));
    if(res != NULL){
        res->num = (f1->num * f2->den) + (f2->num * f1->den);
        res->den = f1->den * f2->den;
    }
    return res;
}

FR* MultiplicarRacional(FR *f1, FR *f2){
    FR *res = (FR*)malloc(sizeof(FR));
    if(res != NULL){
        res->num = f1->num * f2->num;
        res->den = f1->den * f2->den;
    }
    return res;
}

void TestarIgualdade(FR *f1, FR *f2){
    if((f1->num * f2->den) == (f1 ->den * f2->num)){
        printf("As fraçoes sao equivalentes!");
    }else{
        printf("As fraçoes nao sao equivalentes!");
    }
}

int CalcularMDC(int a, int b){
    a = abs(a);
    b = abs(b);
    while(b != 0){
        int res = a % b;
        a = b;
        b = res;
    }
    return a;
}

void SimplificarRacional(FR *r){
    if( r == NULL || r ->den == 0) return;
    
    int comum = CalcularMDC(r->num,r->den);
    r->num = r->num / comum;
    r->den = r->den / comum;
    
}
int obter_numerador(FR *f) { return f->num; }

int obter_denominador(FR *f) { return f->den; }

void destruir_racional(FR *f) {
    free(f);
}