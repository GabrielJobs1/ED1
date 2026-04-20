#ifndef QUEUE_H
#define QUEUE_H
#define MAX 5
#include <stdbool.h>
#include <stdio.h>

typedef struct _queue Queue;

Queue* create();

void destroy(Queue*);

bool enqueue(Queue*,int);

bool dequeue(Queue*);

void printar(Queue*);

void Reverso(Queue*);

#endif