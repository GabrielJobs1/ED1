#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

#define MAX 120 

typedef struct _stack Stack;

Stack* create();

void push(Stack*, char);

void pop(Stack*);

bool verificar_parenteses(const char*);


#endif