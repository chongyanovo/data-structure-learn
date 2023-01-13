#include "Stack.h"

int main() {
    struct Stack stack;
    initStack(&stack);
    for (int i = 0; i < 20; ++i) {
        push(&stack, i * 10);
    }
    printStack(&stack);
    while (!isEmpty(&stack)){
        int tmp = pop(&stack);
        printf(" %d |",tmp);
    }

}