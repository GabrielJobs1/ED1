#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

typedef struct _stack {
    char letras[MAX];
    int topo;
} Stack;


Stack* create_stack() {
    Stack* s = malloc(sizeof(Stack));
    if(s != NULL) {
        s->topo = -1;
    }
    return s;
}

void push(Stack *s, char c) {
    if (s->topo < MAX - 1) {
        s->topo++;
        s->letras[s->topo] = c;
    }
}

char pop(Stack *s) {
    if (s->topo != -1) {
       return s->letras[s->topo--];
    }
    return '\0';
}

void inverter_frase(char frase[]) {
    Stack *aux = create_stack();
    
    printf("Frase Invertida: ");
    
    for (int i = 0; i <= strlen(frase); i++) {
        if (frase[i] == ' ' || frase[i] == '\0' || frase[i] == '.') {
            while (aux->topo != -1) {
                printf("%c", pop(aux));
            }
            if (frase[i] == ' ') printf(" ");
            if (frase[i] == '.') {
                printf(".");
                break;
            }
        } else {
            push(aux, frase[i]);
        }
    }
    printf("\n");
    free(aux);
}
