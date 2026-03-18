#ifndef PILHA_H
#define PILHA_H

typedef struct _pilha Pilha;

Pilha* criarPilha();

void Push(Pilha *p, int value);

void Pop(Pilha *p);

int AcessoTopo(Pilha *p);

Pilha* DestruirPilha(Pilha *p);

void VerTamanho(Pilha *p);

void VerCapacidade(Pilha *p);

#endif