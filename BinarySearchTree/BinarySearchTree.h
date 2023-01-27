#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct TreeNode {
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
} * Node;

Node createNode(E element);

Node insert(Node root, E element);

void inOrder(Node root);

Node find(Node root, E target);

Node findMax(Node root);

Node delete(Node root, E target);