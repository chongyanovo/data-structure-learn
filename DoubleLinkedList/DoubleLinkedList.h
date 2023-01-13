#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct DoubleListNode{
    E element;
    struct DoubleListNode* next;
    struct DoubleListNode* prev;
};

typedef struct DoubleListNode* Node;

void initList(Node head);

int insertList(Node head,E element,int index);

int deleteList(Node head,int index,E *element);

void printList(Node head);