#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Stack.h"

struct Stack{
    char str[40];
    int topo;
};

Stack* CriarPilha(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if(s != NULL){
        s->topo = -1;
        return s;
    }
}

void LerString(Stack *s, char c[]){
    for(int i=0; i < strlen(c);i++){
        if(s->topo < 39){
            if(c[i] == '.'){
                break;
            }
            s->topo++;
            s->str[s->topo] = c[i];
        }else{
            printf("pilha cheia!\n");
            break;
        }
    }
}


void PrintarInverso(Stack *s){
    printf("Palavra invertida:\n");
    while(s->topo >= 0){
        printf("%c", s->str[s->topo]);
        s->topo--;
    }
    printf("\n");
    free(s);
}