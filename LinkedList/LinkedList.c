#include "LinkedList.h"

void initList(Node node) {
    node->next = NULL;
}

int insertList(Node head, E element, int index) {
    if (index < 1) return 1;
    while (--index) {
        head = head->next;
        if (head == NULL) return 1;
    }
    Node node = malloc(sizeof(struct ListNode));
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 0;
}

int deleteList(Node head, int index, E *element) {
    if (index < 1) return 1;
    while (--index) {
        head = head->next;
        if (head == NULL) return 1;
    }
    if (head->next == NULL) return 1;
    Node node = head->next;
    *element = node->element;
    head->next = head->next->next;
    free(node);
    return 0;
}

int sizeList(Node head) {
    int size = 0;
    while (head->next) {
        head = head->next;
        size++;
    }
    return size;
}

E *getList(Node head, int index) {
    if (index < 1) return NULL;
    while (--index) {
        head = head->next;
        if (head == NULL) return NULL;
    }
    if (head->next == NULL) return NULL;
    return &head->next->element;
}

int findList(Node head, E element) {
    int index = 1;
    while (head->next) {
        head = head->next;
        if (head->element == element) return index;
        index++;
    }
    return -1;
}

void printList(Node head) {
    while (head->next) {
        head = head->next;
        printf("%d ", head->element);
    }
}
