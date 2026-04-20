#ifndef STACK_H
#define STACK_H
#define MAX 10
#include <stdbool.h>

typedef struct _stack Stack;

Stack* create();

void push(Stack*,char);

char pop(Stack*);

bool verificar_palindromo(Stack*);

#endif