#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct TreeNode {
    E element;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
} *Node;

Node createNode(E element);

int max(int a, int b);

int getHeight(Node root);

Node leftRotation(Node root);

Node rightRotation(Node root);

Node leftRightRotation(Node root);

Node rightLeftRightRotation(Node root);

Node insert(Node root, E element);

void inOrder(Node root);