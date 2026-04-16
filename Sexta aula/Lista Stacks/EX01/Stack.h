#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

Stack* CriarPilha(void);
void LerString(Stack *s, char c[]);
void PrintarInverso(Stack *s);

#endif


