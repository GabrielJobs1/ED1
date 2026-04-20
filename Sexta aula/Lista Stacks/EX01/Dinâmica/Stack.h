#ifndef STACK_H
#define STACK_H
#define MAX 120
typedef struct _stack Stack;

Stack* stack_create();

void push(Stack*, char);

char pop(Stack*);

void inverter_frase(char*);

#endif