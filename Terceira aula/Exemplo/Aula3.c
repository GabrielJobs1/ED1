#include "Aula3.h"
#include <stdio.h>
#include <stdlib.h>

struct _ponto
{
    float x;
    float y;
};

TPonto *TPonto_create(float x, float y)
{
    TPonto *novo = malloc(sizeof(TPonto));
    if (novo != NULL)
    {
        novo->x = x;
        novo->y = y;
    }
    return novo;
}

void TPonto_print(TPonto *ponto)
{
    if (ponto != NULL)
    {
        printf("%0.2f, %0.2f", ponto->x, ponto->y);
    }
}
void TPonto_get_x(TPonto *ponto, float *x)
{
    if (ponto != NULL && x != NULL)
    {
        *x = ponto->x;
    }
}

void TPonto_get_y(TPonto *ponto, float *y)
{
    if (ponto != NULL && y != NULL)
    {
        *y = ponto->y;
    }
}

void TPonto_destroy(TPonto *ponto)
{
    if (ponto != NULL)
    {
        free(ponto);
    }
}
void Tponto_modificar(TPonto *ponto)
{
    char r;
    float n;

    printf("Qual ponto deseja modificar? (x ou y)\n");
    scanf("%c", &r);
    if(r == 'x'){
        printf("Qual o valor do ponto X?");
        scanf("%f", &n);
        ponto->x = n;
    }
    else if(r == 'y'){
        printf("Qual o valor do ponto Y?");
        scanf("%f", &n);
        ponto->y = n;
    }else{
        printf("Ponto não encontrado!");
    }
}
