#include <bits/stdc++.h>
using namespace std;
typedef int DATATYPE; // 为整数数据类型定义了一个新名称，称为 DATATYPE。
/**
 * 这是一个二叉树节点的结构，其值类型为 DATATYPE 并指向左右子节点。
 * @property {DATATYPE} val - val 是一个 DATATYPE 类型的变量，它存储二叉树中节点的值。
 * @property {BSTTreeNode} left - 指向二叉树中当前节点的左子节点的指针。如果没有左孩子，则指针设置为 NULL。
 * @property {BSTTreeNode} right - BSTTreeNode 结构的“right”属性是指向另一个 TreeNode结构的指针，该结构表示当前节点的右子节点。换句话说，它指向二叉树数据结构中位于当前节点右侧的 BSTTreeNode。
 */
struct BSTTreeNode
{
    DATATYPE val;
    BSTTreeNode *left;
    BSTTreeNode *right;
    BSTTreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insertBST(BSTTreeNode *&root, int val);
BSTTreeNode *searchBST(BSTTreeNode *root, DATATYPE val);
BSTTreeNode *deleteBST(BSTTreeNode *root, DATATYPE val);
void inorderTraversalBST(BSTTreeNode *root);