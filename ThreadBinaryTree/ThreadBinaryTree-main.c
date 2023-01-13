#include "ThreadBinaryTree.h"

int main() {
    Node a = createNode('A');
    Node b = createNode('B');
    Node c = createNode('C');
    Node d = createNode('D');
    Node e = createNode('E');

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;

    //preOrderThreaded(a);
    //preOrder(a);

    inOrderThreaded(a);
    inOrder(a);
}
