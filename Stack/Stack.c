#include "Stack.h"

int initStack(ArrayStack stack) {
    stack->array = malloc(sizeof(E) * 10);
    if (stack->array == NULL) return 1;
    stack->capacity = 10;
    stack->top = -1;
    return 0;
}

int push(ArrayStack stack, E element) {
    if (stack->top + 1 == stack->capacity) {
        int newCapacity = stack->capacity + (stack->capacity >> 1);
        stack->array = realloc(stack->array, newCapacity * sizeof(E));
        if (stack->array == NULL) return 1;
        stack->capacity = newCapacity;
    }
    stack->array[++stack->top] = element;
}

E pop(ArrayStack stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}

int isEmpty(ArrayStack stack) {
    return stack->top == -1;
}

void printStack(ArrayStack stack) {
    printf("| ");
    for (int i = 0; i <= stack->top; ++i) {
        printf("%d -> ", stack->array[i]);
    }
    printf("\n");
}