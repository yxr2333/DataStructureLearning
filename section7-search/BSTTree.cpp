/**
 * @file BST_tree.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 二叉排序树的实现和基本操作
 * @version 0.1
 * @date 2023-04-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <BSTTree.hpp>

/**
 * 该函数将具有给定值的新节点插入到二叉搜索树中。
 *
 * @param root 对指向二叉搜索树根节点的指针的引用。
 * @param val 要插入到二叉搜索树中的值。
 */
void insertBST(BSTTreeNode *&root, int val)
{
    if (root == NULL)
    {
        root = new BSTTreeNode(val);
    }
    if (val < root->val)
    {
        insertBST(root->left, val);
    }
    else if (val > root->val)
    {
        insertBST(root->right, val);
    }
}

/**
 * 该函数在二叉搜索树中搜索具有特定值的节点，如果找到则返回该节点，否则返回NULL。
 *
 * @param root 指向二叉搜索树根节点的指针。
 * @param val val 是我们在二叉搜索树中搜索的值。
 *
 * @return
 * 函数“searchBST”返回一个指向“BSTTreeNode”的指针，如果它存在于以“root”为根的二叉搜索树中，则该指针的值为“val”。如果在树中找不到“val”，则该函数返回“NULL”。
 */
BSTTreeNode *searchBST(BSTTreeNode *root, DATATYPE val)
{
    if (root == NULL || root->val == val)
    {
        return root;
    }
    if (val < root->val)
    {
        return searchBST(root->left, val);
    }
    else
    {
        return searchBST(root->right, val);
    }
}

/**
 * 该函数从二叉搜索树中删除具有给定值的节点。
 *
 * @param root 指向二叉搜索树根节点的指针。
 * @param val 需要从二叉搜索树中删除的节点的值。
 *
 * @return 一个 BSTTreeNode 指针，它表示删除具有指定值的节点后更新的二叉搜索树的根。
 */
BSTTreeNode *deleteBST(BSTTreeNode *root, DATATYPE val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == val)
    {
        // 找到了要删除的节点
        if (root->left == NULL && root->right == NULL)
        {
            // 情况1：要删除的节点为叶子节点，直接删除即可
            delete root;
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL)
        {
            // 情况2：要删除的节点只有一个子节点，让子节点替代要删除的节点即可
            BSTTreeNode *tmp = root->left ? root->left : root->right;
            delete root;
            return tmp;
        }
        else
        {
            // 情况3：要删除的节点有两个子节点，找到被删除节点的右子树中值最小的节点，用它替代被删除节点的值，然后在右子树中递归删除该节点
            BSTTreeNode *cur = root->right;
            while (cur->left != NULL)
            {
                cur = cur->left;
            }
            root->val = cur->val;
            root->right = deleteBST(root->right, cur->val);
            return root;
        }
    }
    else if (root->val > val)
    {
        root->left = deleteBST(root->left, val);
    }
    else
    {
        root->right = deleteBST(root->right, val);
    }
    return root;
}

/**
 * 该函数执行二叉树的中序遍历并打印每个节点的值。
 *
 * @param root 二叉树的根节点。
 */
void inorderTraversalBST(BSTTreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversalBST(root->left);
        cout << root->val << " ";
        inorderTraversalBST(root->right);
    }
}
// int main()
// {
//     BSTTreeNode *root = NULL;

//     // 插入节点
//     insertBST(root, 6);
//     insertBST(root, 2);
//     insertBST(root, 8);
//     insertBST(root, 1);
//     insertBST(root, 4);
//     insertBST(root, 3);
//     insertBST(root, 5);
//     insertBST(root, 7);
//     insertBST(root, 9);

//     // 中序遍历
//     inorderTraversalBST(root);
//     cout << endl;

//     // 查找节点
//     BSTTreeNode *node1 = searchBST(root, 5);
//     cout << node1->val << endl; // 输出5

//     DATATYPE val = 10;
//     BSTTreeNode *node2 = searchBST(root, val);
//     if (node2 == NULL)
//     {
//         cout << "未找到节点" << to_string(val) << endl; // 输出未找到节点val
//     }

//     // 删除节点
//     root = deleteBST(root, 9);
//     // 中序遍历
//     inorderTraversalBST(root); // 输出1 2 3 4 5 6 7 8

//     system("pause");
//     return 0;
// }