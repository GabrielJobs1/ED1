#ifndef STACK_H
#define STACK_H

#define MAX 120

typedef struct _stack Stack;

Stack* create();

void push(Stack*,int);

void pop(Stack*);

void destroy(Stack*);

void trans_elementos(Stack*,Stack*);

void printar(Stack*);

#endif  