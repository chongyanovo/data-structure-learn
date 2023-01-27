#include "ThreadBinaryTree.h"

Node createNode(E element) {
    Node node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->leftTag = node->rightTag = 0;
    node->element = element;
    return node;
}

Node pre = NULL;

/**
 * <img src="https://chongyandocs-1304373775.cos.ap-nanjing.myqcloud.com/chongyandocs/QZ4nPb.png"/>
 * @param root
 */
void preOrderThreaded(Node root) {
    if (root == NULL) return;
    // 左边为空,开始建立线索,指向前一个节点
    if (root->left == NULL) {
        root->left = pre;
        root->leftTag = 1;
    }
    // 上一个节点右边为空,开始建立线索,上一节点的右节点为当前节点
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
        // 通过这个 while 循环找到左下节点
        while (root && root->leftTag == 0)
            root = root->left;

        printf("%c", root->element);

        // 通过线索依次打印节点
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
    if (root->leftTag == 0) {
        postOrderThreaded(root->left);
        if(root->left) root->left->parent = root;
    }
    if (root->rightTag == 0){
        postOrderThreaded(root->right);
        if(root->right) root->right->parent = root;
    }
    if (root->left == NULL) {
        root->left = post;
        root->leftTag = 1;
    }
    if (post && post->right == NULL) {
        post->right = root;
        post->rightTag = 1;
    }
    post = root;
}


void postOrder(Node root) {
    Node last = NULL, node = root;
    while (node) {
        while (node->left != last && node->leftTag == 0)    //依然是从整棵树最左边结点开始，和前面一样，只不过这里加入了防无限循环机制，看到下面就知道了
            node = node->left;
        while (node && node->rightTag == 1) {   //左边完了还有右边，如果右边是线索，那么直接一路向前，也是跟前面一样的
            printf("%c", node->element);   //沿途打印
            last = node;
            node = node->right;
        }
        if (node == root && node->right == last) {
            //上面的操作完成之后，那么当前结点左右就结束了，此时就要去寻找其兄弟结点了，我们可以
            //直接通过parent拿到兄弟结点，但是如果当前结点是根结点，需要特殊处理，因为根结点没有父结点了
            printf("%c", node->element);
            return;   //根节点一定是最后一个，所以说直接返回就完事
        }
        while (node && node->right == last) {    //如果当前结点的右孩子就是上一个遍历的结点，那么一直向前就行
            printf("%c", node->element);   //直接打印当前结点
            last = node;
            node = node->parent;
        }
        //到这里只有一种情况了，是从左子树上来的，那么当前结点的右边要么是线索要么是右子树，所以直接向右就完事
        if (node && node->rightTag == 0) {  //如果不是线索，那就先走右边，如果是，等到下一轮再说
            node = node->right;
        }
    }
}

