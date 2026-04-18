#include "Stack.h"
#include <stdlib.h>
#include <stdbool.h>

struct _stack{
    char eq[MAX];
    int topo;
};

Stack* create(){
    Stack *s = malloc(sizeof(Stack));
    if( s != NULL){
        s->topo = -1;
    }
    return s;
}

void push(Stack *s, char c){
    if(s->topo < MAX - 1 ){
        s->topo++;
        s->eq[s->topo] = c;
    }
}

void pop(Stack *s){
    if(s->topo >= 0){
        s->topo--;
    }
}

bool verificar_parenteses(const char *eq){
    Stack *s = create();
    for(int i = 0;eq[i] != '\0'; i++){
        if(eq[i] == '('){
            push(s,eq[i]);
        }else if(eq[i] == ')'){
            if(s->topo == -1){
                return false;
            }
            pop(s);
        }
    }
    if(s->topo == -1){
        return true;
    }else{
        return false;
    }
}