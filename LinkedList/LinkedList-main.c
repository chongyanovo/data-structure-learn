#include "LinkedList.h"

int main() {
    struct ListNode head;
    initList(&head);
    insertList(&head, 100, 1);
    insertList(&head, 200, 2);
    insertList(&head, 300, 3);
    insertList(&head, 400, 4);
    insertList(&head, 500, 5);
    printList(&head);
    printf("\n");
    printf("%d", *getList(&head, 2));
    printf("\n================\n");
    printf("%d",findList(&head,400));
    printf("\n================\n");
    printf("%d",sizeList(&head));


//    int del;
//    deleteList(&head,2,&del);
//    printf("%d",del);
//    printf("\n");
//    printList(&head);
}