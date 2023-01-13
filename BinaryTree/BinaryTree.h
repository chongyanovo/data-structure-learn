#include <stdio.h>
#include <stdlib.h>

typedef char E;

struct TreeNode {
    E element;
    struct TreeNode *left, *right;
};

typedef struct TreeNode *BinaryTree;

void initTree(BinaryTree root);

void preOrder(BinaryTree root);

void inOrder(BinaryTree root);

void postOrder(BinaryTree root);

void levelOrder(BinaryTree root);

typedef struct TreeNode * T;

struct QueueNode {
    T element;
    struct QueueNode *next;
};

typedef struct QueueNode* QNode;

struct Queue {
    QNode front, rear;
};

typedef struct Queue *LinkedQueue;

int initQueue(LinkedQueue queue);

int offer(LinkedQueue queue, T element);

T poll(LinkedQueue queue);

int isEmpty(LinkedQueue queue);

void printQueue(LinkedQueue queue);