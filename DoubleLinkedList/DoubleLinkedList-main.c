#include "DoubleLinkedList.h"

int main() {
    struct DoubleListNode head;
    initList(&head);
    for (int i = 1; i <= 5; ++i)
        insertList(&head, i * 100, i);

    printList(&head);
    int del;
    deleteList(&head,2,&del);
    printf("\n==========\n");
    printf("%d",del);
    printf("\n==========\n");
    printList(&head);

}

