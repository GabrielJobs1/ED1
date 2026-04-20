#include <stdio.h>
#include "Queue.h"

int main(){
    Queue* q = create();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printar(q);
    Reverso(q);
    printar(q);
    destroy(q);
    return 0;
}