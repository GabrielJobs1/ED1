#include "Stack.h"
#include <stdlib.h>

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

void push(Stack* s, char c){
    TNo* aux = malloc(sizeof(TNo));
    if(aux != NULL){
        aux->letra = c;
        aux->prox = s->topo;
        s->topo = aux;
        s->qty++;
    }
}

char pop(Stack* s){
    if(s->topo != NULL){
        char letra = s->topo->letra;
        TNo* oldTop = s->topo;
        s->topo = s->topo->prox;
        free(oldTop);
        s->qty--;
        return letra;
    }

    return '\0';
}

bool verificar_palindromo(Stack* s){
    if(s == NULL){
        return false;
    }

    if(s->qty < 2){
        return true;
    }

    char *letras = malloc(s->qty * sizeof(char));
    if(letras == NULL){
        return false;
    }

    TNo *atual = s->topo;
    for(unsigned int i = 0; i < s->qty; i++){
        letras[i] = atual->letra;
        atual = atual->prox;
    }

    for(unsigned int i = 0; i < s->qty / 2; i++){
        if(letras[i] != letras[s->qty - 1 - i]){
            free(letras);
            return false;
        }
    }

    free(letras);
    return true;
}