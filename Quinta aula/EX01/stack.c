#include "stack.h"
#include<stdlib.h>
#include<stdio.h>
struct Stack{
    int ID[10];
    int qtd;
};

Stack* CriarStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if(s != NULL){
        s->qtd = 0;
    }
    return s;
}

bool Push(Stack* s, int n){
    if(s->qtd >= MAX){
        return false;
    }else{
        s->ID[s->qtd] = n;
        s->qtd++;
        return true;
    }
}

int Pop(Stack *s) {
    if (s->qtd > 0) {
        int id = s->ID[s->qtd - 1];
        s->qtd--;
        return id;
    } else {
        return -1;
    }
}

void RemoverCarro(Stack *s,int n){
    Stack *aux = CriarStack();
    bool encontrado = false;
    bool primeiro = true;
    
    if(s->qtd == 0){
        printf("underflow\n");
        free(aux);
        return;
    }
    
    while(s->qtd > 0){
        int atual = Pop(s);
        
        if(!primeiro) printf(",");
        printf("%d", atual);
        primeiro = false;
        
        if(atual == n){
            encontrado = true;
            break;
        }else{
            Push(aux,atual);
        }
    }
    if(!encontrado){
        printf(",underflow\n");
    }else{
        printf("\n");
    }
    
    while(aux->qtd > 0){
        Push(s, Pop(aux));
    }
    
    free(aux);
}