#include "BalancedBinaryTree.h"

int main() {
    Node root = createNode(18);
    root = insert(root, 13);
    root = insert(root, 20);
    root = insert(root, 17);
    root = insert(root, 21);
    root = insert(root, 25);
    printf("\n");
    inOrder(root);
}