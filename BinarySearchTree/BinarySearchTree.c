#include "BinarySearchTree.h"

Node createNode(E element) {
    Node node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->element = element;
    return node;
}


/**
 * 插入二叉查找树节点
 * <img src="https://chongyandocs-1304373775.cos.ap-nanjing.myqcloud.com/chongyandocs/WjPAet.png"/>
 * @param root 根节点
 * @param element 节点元素
 * @return 插入完成后的二叉查找树
 */
Node insert(Node root, E element) {
    if (root) {
        if (root->element > element) root->left = insert(root->left, element);
        else if (root->element < element) root->right = insert(root->right, element);
    } else {
        root = createNode(element);
    }
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

/**
 * 查找二叉查找树
 * @param root 根节点
 * @param target 查找目标值
 * @return
 */
Node find(Node root, E target) {
    while (root) {
        if (root->element > target) root = root->left;
        else if (root->element < target) root = root->right;
        else return root;
    }
    return NULL;
}

Node findMax(Node root) {
    while (root && root->right)
        root = root->right;
    return root;
}

/**
 * 1. 要删除的结点是叶子结点
 *      直接删除
 * 2. 要删除的结点是只有一个孩子结点
 *      将孩子结点连接
 * 3. 要删除的结点有两个孩子结点
 *      选取其左子树中最大结点上位
 *      选择其右子树中最小结点上位
 * @param root
 * @param target
 * @return
 */
Node delete(Node root, E target) {
    if (root == NULL) return NULL;
    if (root->element > target) root->left = delete(root->left, target);
    else if (root->element < target) root->right = delete(root->right, target);
    else {
        if (root->left && root->right) {
            Node max = findMax(root);
            root->element = max->element;
            root->left = delete(root->left, root->element);
        } else {
            Node tmp = root;
            if (root->right) {
                root = root->right;
            } else {
                root = root->left;
            }
            free(tmp);
        }
    }
    return root;
}