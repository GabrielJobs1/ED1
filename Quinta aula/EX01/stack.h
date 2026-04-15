#ifndef STACK_H
#define STACK_H
#include<stdbool.h>

#define MAX 10

typedef struct Stack Stack;

Stack* CriarStack();

bool Push(Stack*,int);

int Pop(Stack*);

void RemoverCarro(Stack*,int);

#endif