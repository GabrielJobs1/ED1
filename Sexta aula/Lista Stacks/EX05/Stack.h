#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_MAX 100

typedef struct _stack Stack;

Stack* create(void);
bool push(Stack *s, int value);
bool pop(Stack *s, int *value);
bool pilhas_iguais(Stack *p1, Stack *p2);
void destroy(Stack *s);

#endif
