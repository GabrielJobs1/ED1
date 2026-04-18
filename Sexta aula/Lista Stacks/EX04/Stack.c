#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>

struct _stack {
    int data[STACK_MAX];
    int top;
    int size;
};

static int peek(Stack *s, int *value) {
    if (s == NULL || s->top < 0) return 0;
    *value = s->data[s->top];
    return 1;
}

static int is_full(Stack *s) {
    return (s != NULL && s->top >= STACK_MAX - 1);
}

Stack* create(void) {
    Stack *s = (Stack*) malloc(sizeof(Stack));
    if (s != NULL) {
        s->top = -1;
        s->size = 0;
    }
    return s;
}

void push(Stack *s, int n) {
    if (s == NULL || is_full(s)) return;

    s->data[++s->top] = n;
    s->size++;
}

void pop(Stack *s) {
    if (s == NULL || s->top < 0) return;

    s->top--;
    s->size--;
}

void printar_inverso(Stack *s) {
    if (s == NULL) return;

    Stack *aux = create();
    int v;

    if (aux == NULL) return;

    printf("Antes:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }

    while (peek(s, &v)) {
        push(aux, v);
        pop(s);
    }

    printf("Depois:\n");
    for (int i = aux->top; i >= 0; i--) {
        printf("%d\n", aux->data[i]);
    }

    while (peek(aux, &v)) {
        push(s, v);
        pop(aux);
    }

    free(aux);
}