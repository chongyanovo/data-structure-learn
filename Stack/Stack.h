#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct Stack{
    E * array;
    int capacity;
    int top;
};

typedef struct Stack* ArrayStack;

int initStack(ArrayStack stack);

int push(ArrayStack stack,E element);

E pop(ArrayStack stack);

int isEmpty(ArrayStack stack);

void printStack(ArrayStack stack);