#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct _pilha {
    char vetor[4];
    int topo;

};

Pilha* criarPilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if (p != NULL) {
       p->topo = -1;
       return p;
    }
    return NULL;
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

void PushSilencioso(Pilha *p, int value){
    if(p->topo < 3){
        p->topo++;
        p->vetor[p->topo] = value;
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

void PopSilencioso(Pilha *p){
    if(p->topo >= 0){
        p->topo--;
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

char ObterTopoSilencioso(Pilha *p){
    if(p->topo >= 0){
        return p->vetor[p->topo];
    }
    return -1;
}

Pilha* DestruirPilha(Pilha *p){
    printf("Pilha destruída. Saindo...\n");
    free(p);
    return NULL;
}

int VerTamanho(Pilha *p){
    if(p != NULL){
        printf("O tamanho da stack é %d!\n",p->topo + 1);
        return p->topo + 1;
    }else{
        printf("Pilha vazia\n");
        return 0;
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

bool VParenteses(Pilha *p){
    char str[128];
    
    // Limpar a pilha antes de começar
    while(p->topo >= 0) {
        p->topo--;
    }
    
    printf("Digite a expressão a ser verificada: ");
    scanf("%s", str);
    
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{' ){
            PushSilencioso(p, str[i]);
        }else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
            if(p->topo < 0){
                printf("A expressão é inválida!\n");
                while(p->topo >= 0) p->topo--;
                return false;
            }
            char topo = ObterTopoSilencioso(p);
            if((str[i] == ')' && topo == '(') || (str[i] == ']' && topo == '[') || (str[i] == '}' && topo == '}')){
                PopSilencioso(p);
            } else {
                printf("A expressão é inválida!\n");
                while(p->topo >= 0) p->topo--;
                return false;
            }
        }
    }

    if(p->topo == -1){
        printf("A expressão é válida!\n");
        return true;
    } else {
        printf("A expressão é inválida!\n");
        while(p->topo >= 0) p->topo--;
        return false;
    }
}