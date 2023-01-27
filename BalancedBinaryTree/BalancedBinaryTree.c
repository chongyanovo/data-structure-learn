#include "BalancedBinaryTree.h"

Node createNode(E element) {
    Node node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->element = element;
    node->height = 1;
    return node;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int getHeight(Node root) {
    if (root == NULL) return 0;
    return root->height;
}

/**
 *
 * <img src="https://chongyandocs-1304373775.cos.ap-nanjing.myqcloud.com/chongyandocs/gcjMQ5.png" />
 * 左旋操作
 * @param root 根节点
 * @return
 */
Node leftRotation(Node root) {
    Node newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
    return newRoot;
}

/**
 *
 * <img src="https://chongyandocs-1304373775.cos.ap-nanjing.myqcloud.com/chongyandocs/8Dtg8o.png" />
 * 右旋操作
 * @param root 根节点
 * @return
 */
Node rightRotation(Node root) {
    Node newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
    return newRoot;
}

/**
 *
 * <img src="https://chongyandocs-1304373775.cos.ap-nanjing.myqcloud.com/chongyandocs/ezwS29.png" />
 * 先左旋再右旋操作
 * @param root 根节点
 * @return
 */
Node leftRightRotation(Node root) {
    root->left = leftRotation(root->left);
    return rightRotation(root);
}

/**
 *
 * <img src="https://chongyandocs-1304373775.cos.ap-nanjing.myqcloud.com/chongyandocs/2HOoXp.png" />
 * 先右旋再左旋操作
 * @param root 根节点
 * @return
 */
Node rightLeftRightRotation(Node root) {
    root->right = rightRotation(root->right);
    return leftRotation(root);
}

Node insert(Node root, E element) {
    if (root == NULL) {
        root = createNode(element);
    } else if (root->element > element) {
        // 判断大小找到对应插入位置
        root->left = insert(root->left, element);
        // 计算平衡因子,查看 AVL 树是否失衡
        if (getHeight(root->left) - getHeight(root->right) > 1) {
            // 判断插入左子树位置
            if (root->left->element > element) {
                // LL 型需要进行左旋操作得到新节点
                root = rightRotation(root);
            } else {
                // LR 型需要进行先右旋再左旋操作得到新节点
                root = leftRightRotation(root);
            }
        }
    } else if (root->element < element) {
        root->right = insert(root->right, element);
        if (getHeight(root->left) - getHeight(root->right) < -1) {
            if (root->right->element < element) {
                // RR 型需要进行右旋操作得到新节点
                root = leftRotation(root);
            } else {
                // RL 型需要进行先左旋再右旋操作得到新节点
                root = rightLeftRightRotation(root);
            }
        }
    }
    // 更新树的高度
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}

/**
 * 中序遍历
 * @param root 根节点
 */
void inOrder(Node root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->element);
    inOrder(root->right);
}