#ifndef PILHA_H
#define PILHA_H
#include <stdbool.h>

typedef struct _stack Stack;

Stack* stack_create();

bool stack_push(Stack*,char);

bool stack_pop(Stack*);

bool verificar_palindromo(Stack*);

#endif