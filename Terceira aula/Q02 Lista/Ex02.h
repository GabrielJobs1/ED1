#ifndef CONJUNTO_H
#define CONJUNTO_H

#define MAX 100

typedef struct _conjunto Conjunto;


Conjunto* CriarConjunto();

void destruir_conjunto(Conjunto *c);

int InserirElemento(Conjunto *c, int elemento);

int removerElemento(Conjunto *c);

Conjunto* IntersecaoConjuntos(Conjunto *c1, Conjunto *c2);

Conjunto* DiferencaConjuntos(Conjunto *c1, Conjunto *c2);

Conjunto* UnirConjuntos(Conjunto *c1, Conjunto *c2);

int MaiorValor(Conjunto *c);

int MenorValor(Conjunto *c);

void TestarIgualdade(Conjunto *c1, Conjunto *c2);

void VerificarTamanho(Conjunto *c);

void VerificarVazio(Conjunto *c);

void MostrarConjunto(Conjunto *c);

#endif