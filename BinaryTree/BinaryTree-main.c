#include "BinaryTree.h"

int main() {
    BinaryTree a = malloc(sizeof(struct TreeNode));
    BinaryTree b = malloc(sizeof(struct TreeNode));
    BinaryTree c = malloc(sizeof(struct TreeNode));
    BinaryTree d = malloc(sizeof(struct TreeNode));
    BinaryTree e = malloc(sizeof(struct TreeNode));
    BinaryTree f = malloc(sizeof(struct TreeNode));
    a->element = 'A';
    b->element = 'B';
    c->element = 'C';
    d->element = 'D';
    e->element = 'E';
    f->element = 'F';
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;

//    preOrder(a);
//    inOrder(a);
//    postOrder(a);
    levelOrder(a);

}
