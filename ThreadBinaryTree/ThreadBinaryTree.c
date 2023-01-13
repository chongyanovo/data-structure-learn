#include "ThreadBinaryTree.h"

Node createNode(E element) {
    Node node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->leftTag = node->rightTag = 0;
    node->element = element;
    return node;
}

Node pre = NULL;

void preOrderThreaded(Node root) {
    if (root == NULL) return;
    if (root->left == NULL) {
        root->left = pre;
        root->leftTag = 1;
    }
    if (pre && pre->right == NULL) {
        pre->right = root;
        pre->rightTag = 1;
    }
    pre = root;
    if (root->leftTag == 0) preOrderThreaded(root->left);
    if (root->rightTag == 0) preOrderThreaded(root->right);
}

void preOrder(Node root) {
    while (root) {
        printf("%c", root->element);
        if (root->leftTag == 0) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
}

Node in = NULL;

void inOrderThreaded(Node root) {
    if (root == NULL) return;
    if (root->leftTag == 0) inOrderThreaded(root->left);

    if (root->left == NULL) {
        root->left = in;
        root->leftTag = 1;
    }
    if (in && in->right == NULL) {
        in->right = root;
        in->rightTag = 1;
    }

    in = root;
    if (root->rightTag == 0) inOrderThreaded(root->right);
}


void inOrder(Node root) {
    while (root) {
        while (root && root->leftTag == 0)
            root = root->left;
        printf("%c", root->element);
        while (root && root->rightTag == 1) {
            root = root->right;
            printf("%c", root->element);
        }
        root = root->right;
    }
}

Node post = NULL;
void postOrderThreaded(Node root) {
    if (root == NULL) return;
    if (root->leftTag == 0) inOrderThreaded(root->left);
    if (root->rightTag == 0) inOrderThreaded(root->right);
    if (root->left == NULL) {
        root->left = in;
        root->leftTag = 1;
    }
    if (post && post->right == NULL) {
        in->right = root;
        in->rightTag = 1;
    }
    post = root;
}
