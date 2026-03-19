#ifndef PILHA_H
#define PILHA_H
#include <stdbool.h>

typedef struct _pilha Pilha;

Pilha* criarPilha();

void Push(Pilha *p, int value);

void PushSilencioso(Pilha *p, int value);

void Pop(Pilha *p);

void PopSilencioso(Pilha *p);

int AcessoTopo(Pilha *p);

char ObterTopoSilencioso(Pilha *p);

Pilha* DestruirPilha(Pilha *p);

int VerTamanho(Pilha *p);

void VerCapacidade(Pilha *p);

bool VParenteses(Pilha *p);

#endif