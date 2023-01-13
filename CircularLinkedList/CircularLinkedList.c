#include "CircularLinkedList.h"

void initList(Node head) {
    head->next = head;
}

int insertList(Node head, int index, E element) {
    if (index < 1) return 1;
    while (--index) {
        head = head->next;
    }
    Node node = malloc(sizeof(struct CircularLinkedList));
    if (node == NULL) return 1;
    node->element=element;
    node->next = head->next;
    head->next = node;
    return 0;
}