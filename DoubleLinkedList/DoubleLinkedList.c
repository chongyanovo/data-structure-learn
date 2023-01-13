#include "DoubleLinkedList.h"

void initList(Node head) {
    head->next = NULL;
    head->prev = NULL;
}

int insertList(Node head, E element, int index) {
    if (index < 1) return 1;
    while (--index) {
        head = head->next;
        if(head == NULL) return 0;
    }
    Node node = malloc(sizeof(struct DoubleListNode));
    if (node == NULL) return 1;
    node->element = element;

    if (head->next != NULL) {
        head->next->prev = node;
        node->next = head->next;
    } else {
        node->next = NULL;
    }
    head->next = node;
    node->prev = head;
    return 0;
}

int deleteList(Node head, int index, E *element) {
    if (index < 1) return 1;
    while (--index) {
        head = head->next;
    }
    *element = head->next->element;
    head->next = head->next->next;
    head->next->prev = head;
}

void printList(Node head) {
    Node node = head;
    do {
        node = node->next;
        printf("%d -> ", node->element);
    } while (node->next != NULL);

}