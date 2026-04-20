#include "Queue.h"
#include <stdlib.h>

struct _queue{
    int head, tail, qty;
    int data[MAX];
};

Queue* create(){
    Queue* q = malloc(sizeof(Queue));
    if(q != NULL){
        q->head = 0;
        q->tail = 0;
        q->qty = 0;
        return q;
    }
}

void destroy(Queue *q){
    free(q);
}

bool enqueue(Queue* q, int value){
    if(q->qty == MAX){
        return false;
    }
    q->data[q->tail] = value;
    q->tail = (q->tail + 1) % MAX;
    q->qty++;
    return true;
}

bool dequeue(Queue *q){
    if(q->qty == 0){
        return false;
    }
    q->head = (q->head +1)% MAX;
    q->qty--;
    return true;
}

void printar(Queue* q){
    for(int i = 0; i < q->qty; i++){
        int index = (q->head + i) % MAX;
        printf("%d ", q->data[index]);
    }
    printf("\n");
}

void Reverso(Queue* q){
    if(q->qty == 0){
        return;
    }
    int head = q->head;
    int tail = (q->head + q->qty - 1) % MAX;
    while(head < tail){
        int temp = q->data[head];
        q->data[head] = q->data[tail];
        q->data[tail] = temp;
        head = (head + 1) % MAX;
        tail = (tail - 1 + MAX) % MAX;
    }

}