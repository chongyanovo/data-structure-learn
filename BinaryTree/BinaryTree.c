#include "BinaryTree.h"

void initTree(BinaryTree root) {
    root->left = NULL;
    root->right = NULL;
}

void preOrder(BinaryTree root) {
    if (root == NULL) return;
    printf("%c", root->element);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BinaryTree root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%c", root->element);
    inOrder(root->right);
}

void postOrder(BinaryTree root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c", root->element);
}

void levelOrder(BinaryTree root) {
    struct Queue queue;
    initQueue(&queue);
    offer(&queue,root);
    while (!isEmpty(&queue)){
        BinaryTree node = poll(&queue);
        printf("%c",node->element);
        if (node->left) offer(&queue,node->left);
        if (node->right) offer(&queue,node->right);
    }
}

int initQueue(LinkedQueue queue) {
    QNode node = malloc(sizeof(struct QueueNode));
    if (node == NULL) return 1;
    queue->front = queue->rear = node;
    return 0;
}

int offer(LinkedQueue queue, T element) {
    QNode node = malloc(sizeof(struct QueueNode));
    if (node == NULL) return 1;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return 0;
}

T poll(LinkedQueue queue) {
    QNode node = queue->front->next;
    T element = node->element;
    queue->front->next = queue->front->next->next;
    if (queue->rear == node) queue->rear = queue->front;
    free(node);
    return element;
}

int isEmpty(LinkedQueue queue) {
    return queue->front == queue->rear;
}

void printQueue(LinkedQueue queue) {
    while (!isEmpty(queue)) {
        printf("%c", poll(queue));
    }
}