#ifndef STACK_H
#define STACK_H

#define STACK_MAX 100

typedef struct _stack Stack;

Stack* create(void);
void push(Stack *s, int n);
void pop(Stack *s);
void printar_inverso(Stack *s);

#endif