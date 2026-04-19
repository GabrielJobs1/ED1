#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

struct _stack{
    int data[MAX];
    int topo;
};

Stack* create(){
    Stack* s = malloc(sizeof(Stack));
    if(s != NULL){
        s->topo = -1;
        return s;
    }
}

void push(Stack *s, int n){
    if(s != NULL && s->topo < MAX-1){
        s->topo++;
        s->data[s->topo] = n;
    }
}

void pop(Stack *s){
    if(s != NULL && s->topo >= 0){
        s->topo--;
    }
}

void destroy(Stack *s){
    free(s);
}

void trans_elementos(Stack *s, Stack *c){
    Stack *aux = create();
    
    for(int i = 0; i <= s->topo; i++){
        push(aux,s->data[i]);
    }
    while(s->topo >= 0){
        pop(s);
    }

    for(int j = 0; j <= aux->topo;j++){
        push(c,aux->data[j]);  
    }
    
    free(aux);

}

void printar(Stack *s){
    while(s->topo >= 0){
        printf("%d\n", s->data[s->topo]);
        s->topo--;
    }
}