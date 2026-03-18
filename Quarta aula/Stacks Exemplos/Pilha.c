#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct _pilha {
    int vetor[4];
    int topo;

};

Pilha* criarPilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if (p != NULL) {
       p->topo = -1;
       return p;
    }
    
}

void Push(Pilha *p, int value){
    if(p->topo < 3){
        p->topo++;
        p->vetor[p->topo] = value;
        printf("O valor %d foi inserido na stack!\n", value);
    } else {
        printf("Pilha cheia\n");
    }
}

void Pop(Pilha *p){
    if(p->topo >= 0){
        printf("O valor %d foi removido da Stack!\n",p->vetor[p->topo]);
        p->topo--;
    } else {
        printf("Pilha vazia\n");
    }
}

int AcessoTopo(Pilha *p){
    if(p->topo >= 0){
        printf("O valor no topo da stack é %d!\n", p->vetor[p->topo]);
        return(p->vetor[p->topo]);
    }else{
        printf("Pilha vazia\n");
        return -1;
    }
}

Pilha* DestruirPilha(Pilha *p){
    printf("Pilha destruída. Saindo...\n");
    free(p);
    return NULL;
}

void VerTamanho(Pilha *p){
    if(p != NULL){
        printf("O tamanho da stack é %d!\n",p->topo + 1);
    }else{
        printf("Pilha vazia\n");
    }
}

void VerCapacidade(Pilha *p){
   if(p->topo < 0){
        printf("A pilha esta atualmente vazia, a capacidade é de 4 elementos!\n");
    } else if(p->topo < 3){
        printf("A pilha esta atualmente com %d elementos, a capacidade é de 4 elementos!\n", p->topo + 1);
    } else {
        printf("A pilha esta cheia, a capacidade é de 4 elementos!\n");
    }
}