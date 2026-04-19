#include "Stack.h"
#include <stdlib.h>

struct _stack {
    int data[STACK_MAX];
    int top;
};

Stack* create(void) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    if (s != NULL) {
        s->top = -1;
    }
    
    return s;
}

bool push(Stack *s, int value) {
    if (s == NULL || s->top >= STACK_MAX - 1) {
        return false;
    }

    s->top++;
    s->data[s->top] = value;
    return true;
}

bool pop(Stack *s, int *value) {
    if (s == NULL || value == NULL || s->top < 0) {
        return false;
    }

    *value = s->data[s->top];
    s->top--;
    return true;
}

bool pilhas_iguais(Stack *p1, Stack *p2) {
    if (p1 == NULL || p2 == NULL) {
        return false;
    }

    if (p1->top != p2->top) {
        return false;
    }

    for (int i = 0; i <= p1->top; i++) {
        if (p1->data[i] != p2->data[i]) {
            return false;
        }
    }

    return true;
}

void destroy(Stack *s) {
    if (s != NULL) {
        free(s);
    }
}
