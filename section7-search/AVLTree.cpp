/**
 * @file AVL_tree.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 平衡二叉树的实现和基本操作
 * @version 0.1
 * @date 2023-04-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <AVLTree.hpp>
/**
 * 该函数返回给定二叉树节点的高度。
 *
 * @param root 二叉树的根节点。
 *
 * @return 给定二叉树节点的高度。如果节点为 NULL，则返回 0。
 */
int getHeight(AVLTreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

/**
 * 此函数计算二叉树节点的平衡因子。
 *
 * @param root 指向二叉树根节点的指针。
 *
 * @return 返回给定二叉树节点的平衡因子。
 * 平衡因子计算为左子树的高度与右子树的高度之间的差值。
 * 如果平衡因子为正，则表示左子树比右子树高，如果为负，则表示右子树比左子树高。
 */
int getBalanceFactor(AVLTreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

/**
 * 该函数根据其左右子树的高度更新二叉树节点的高度。
 *
 * @param root 指向二叉树根节点的指针。
 */
void updateHeight(AVLTreeNode *root)
{
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

/**
 * 此函数对二叉搜索树执行右旋转。
 *
 * @param root 指向二叉搜索树根节点的指针。
 *
 * @return 执行右旋转后指向子树新根的指针。
 */
AVLTreeNode *rightRotate(AVLTreeNode *root)
{
    AVLTreeNode *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

/**
 * 此函数对二叉搜索树执行左旋转。
 *
 * @param root 指向需要左旋转的子树的根节点的指针。
 *
 * @return 执行左旋转后指向子树新根的指针。
 */
AVLTreeNode *leftRotate(AVLTreeNode *root)
{
    AVLTreeNode *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

/**
 * 该函数通过根据根节点的平衡因子来执行旋转操作从而平衡 AVL 树。
 *
 * @param root 指向需要平衡的 AVL 树的根节点的指针。
 *
 * @return 一个 AVLTreeNode 指针，它是执行必要的平衡调整后 AVL 树的根。
 */
AVLTreeNode *balanceAVL(AVLTreeNode *root)
{
    // 计算平衡因子
    int balanceFactor = getBalanceFactor(root);

    // 进行平衡调整
    if (balanceFactor > 1)
    {
        if (getBalanceFactor(root->left) >= 0)
        {
            // LL型，右旋操作
            root = rightRotate(root);
        }
        else
        {
            // LR型，先对左子节点进行左旋操作，再对根节点进行右旋操作
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
    }
    else if (balanceFactor < -1)
    {
        if (getBalanceFactor(root->right) <= 0)
        {
            // RR型，左旋操作
            root = leftRotate(root);
        }
        else
        {
            // RL型，先对右子节点进行右旋操作，再对根节点进行左旋操作
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
    }

    return root;
}

/**
 * 此函数将具有给定值的新节点插入到 AVL 树中，并在必要时平衡树。
 *
 * @param root 指向 AVL 树的根节点的指针。
 * @param val 要插入到 AVL 树中的值。
 *
 * @return 指向 AVLTreeNode 的指针，它是插入具有给定值的新节点后 AVL 树的根。
 */
AVLTreeNode *insertAVL(AVLTreeNode *root, int val)
{
    if (root == NULL)
    {
        return new AVLTreeNode(val);
    }
    if (val < root->val)
    {
        root->left = insertAVL(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = insertAVL(root->right, val);
    }
    else
    {
        return root;
    }
    // 更新节点高度
    updateHeight(root);
    root = balanceAVL(root);
    return root;
}

/**
 * 该函数在 AVL 树中搜索具有给定值的节点。
 *
 * @param root 指向 AVL 树的根节点的指针。
 * @param val val 是一个整数值，表示我们在 AVL 树中搜索的值。函数 searchAVL 接收指向 AVL
 * 树根节点的指针，并递归搜索具有给定值的节点。
 * 如果找到节点，则返回指向该节点的指针，否则返回 NULL。
 * @return 此函数返回指向 AVLTreeNode 的指针，该节点包含 AVL 树中的给定值“val”。如果在树中找不到该值，则返回 NULL。
 */
AVLTreeNode *searchAVL(AVLTreeNode *root, int val)
{
    if (root == NULL || root->val == val)
    {
        return root;
    }
    if (val < root->val)
    {
        return searchAVL(root->left, val);
    }
    else
    {
        return searchAVL(root->right, val);
    }
}

/**
 * 该函数从 AVL 树中删除具有给定值的节点并平衡树。
 *
 * @param root AVL 树的根节点。
 * @param val 需要从 AVL 树中删除的节点的值。
 *
 * @return 删除具有给定值的节点并平衡树后指向 AVL 树根的指针。
 */
AVLTreeNode *deleteAVL(AVLTreeNode *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (val < root->val)
    {
        root->left = deleteAVL(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = deleteAVL(root->right, val);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL)
        {
            AVLTreeNode *tmp = root->right ? root->right : root->left;
            delete root;
            return tmp;
        }
        else
        {
            AVLTreeNode *cur = root->right;
            while (cur->left != NULL)
            {
                cur = cur->left;
            }
            root->val = cur->val;
            root->right = deleteAVL(root->right, cur->val);
        }
    }
    // 更新节点高度
    updateHeight(root);
    root = balanceAVL(root);
    return root;
}

// 中序遍历
void inorderTraversalAVL(AVLTreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversalAVL(root->left);
        cout << root->val << " ";
        inorderTraversalAVL(root->right);
    }
}
// int main()
// {
//     AVLTreeNode *root = NULL;

//     // 插入节点
//     root = insertAVL(root, 6);
//     root = insertAVL(root, 2);
//     root = insertAVL(root, 8);
//     root = insertAVL(root, 1);
//     root = insertAVL(root, 4);
//     root = insertAVL(root, 3);
//     root = insertAVL(root, 5);
//     root = insertAVL(root, 7);
//     root = insertAVL(root, 9);

//     inorderTraversalAVL(root); // 输出1 2 3 4 5 6 7 8 9
//     cout << endl;

//     // 查找节点
//     AVLTreeNode *node1 = searchAVL(root, 5);
//     cout << node1->val << endl; // 输出5

//     AVLTreeNode *node2 = searchAVL(root, 10);
//     if (node2 == NULL)
//     {
//         cout << "未找到节点10" << endl; // 输出未找到节点10
//     }

//     // 删除节点
//     root = deleteAVL(root, 9);

//     // 中序遍历
//     inorderTraversalAVL(root); // 输出1 2 3 4 5 6 7 8
//     system("pause");
//     return 0;
// }