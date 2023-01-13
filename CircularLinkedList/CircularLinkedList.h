#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct CircularLinkedList{
    E element;
    struct CircularLinkedList * next;
};

typedef struct CircularLinkedList * Node;

void initList(Node head);

int insertList(Node head,int index,E element);