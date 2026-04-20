#include "Stack.h"
#include <stdlib.h>
#include <string.h>

struct _stack{
    char data[10];
    int topo;
};

Stack* stack_create(){
    Stack* s = malloc(sizeof(Stack));
    s->topo = -1;
    return s;
}

bool stack_push(Stack* s, char c){
    if(s->topo < 9){
        s->topo++;
        s->data[s->topo] = c;
        return true;
    }
    return false;
}

bool stack_pop(Stack* s){
    if(s->topo >= 0){
        s->topo--;
        return true;
    }
    return false;
}

bool verificar_palindromo(Stack* s){
    int i = 0;
    while(i < s->topo){
        if(s->data[i]!=s->data[s->topo - i]){
            return false;
        }        
        i++;
    }
    return true;
}

