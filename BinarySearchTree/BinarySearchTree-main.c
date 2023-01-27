#include "BinarySearchTree.h"

int main() {
    Node root = createNode(18);
    insert(root, 10);
    insert(root, 7);
    insert(root, 15);
    insert(root, 9);
    insert(root, 20);
     inOrder(root);
    printf("%d\n",find(root,9)->element);
    printf("%d\n",findMax(root)->element);
}