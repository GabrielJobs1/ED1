#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _no{
    char letra;
    struct _no *prox;
}TNo;

struct _stack{
    unsigned int qty;
    TNo *topo;
};

Stack* create(){
    Stack *s = malloc(sizeof(Stack));
    if(s != NULL){
        s->qty = 0;
        s->topo = NULL;
    }
    return s;
}

void push(Stack *s, char c){
    TNo* aux = malloc(sizeof(TNo));
    if(aux != NULL){
      aux->letra = c;
      aux->prox = s->topo;
      s->topo = aux;
      s->qty++;
    }
    free(aux);
}

char pop(Stack *s){
    if(s == NULL || s->topo == NULL){
        return '\0';
    }
    TNo* oldTop = s->topo;
    char letra = oldTop->letra;
    s->topo = oldTop->prox;
    free(oldTop);
    s->qty--;

    return letra;
}

void inverter_frase(char frase[]){
    Stack* aux = create();

    printf("Frase Invertida:");

    for(int i = 0; i < strlen(frase);i++){
        if(frase[i] == ' ' || frase[i] == '\0' || frase[i] == '.'){
            while(aux->topo != NULL){
                printf("%c", pop(aux));
            }
            if(frase[i] == ' ') printf(" ");
            if(frase[i] == '.') {
            printf("."); 
            break;
        }
        }else{
            push(aux,frase[i]);
        }
    }

    printf("\n");
    free(aux);
}