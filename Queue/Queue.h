#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct Queue{
    E * array;
    int capacity;
    int rear,front;
};

typedef struct Queue * ArrayQueue;

int initQueue(ArrayQueue queue);

int offer(ArrayQueue queue,E element);

E poll(ArrayQueue queue);

int isEmpty(ArrayQueue queue);

void printQueue(ArrayQueue queue);
