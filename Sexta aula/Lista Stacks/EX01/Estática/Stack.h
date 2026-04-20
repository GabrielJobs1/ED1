#ifndef STACK_H
#define STACK_H
#define MAX 120

typedef struct _stack Stack;

Stack* create_stack();

void push(Stack*, char);

char pop(Stack*);

void inverter_frase(char*);

void printar_frase(Stack*);

#endif