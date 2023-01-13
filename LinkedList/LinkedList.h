#include <stdio.h>
#include <stdlib.h>

typedef int E;
struct ListNode {
    E element;
    struct ListNode *next;
};

typedef struct ListNode *Node;

void initList(Node node);

int insertList(Node head, E element, int index);

int deleteList(Node head, int index, E *element);

int sizeList(Node head);

E* getList(Node head, int index);

int findList(Node head, E element);

void printList(Node head);