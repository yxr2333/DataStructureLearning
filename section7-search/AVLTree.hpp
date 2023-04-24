#include <bits/stdc++.h>
using namespace std;

// 定义二叉树节点
typedef struct AVLTreeNode
{
    int val;
    int height; // 该节点的高度
    AVLTreeNode *left;
    AVLTreeNode *right;
    AVLTreeNode(int x) : val(x), height(1), left(NULL), right(NULL) {}
} AVLTreeNode;

int getHeight(AVLTreeNode *root);
int getBalanceFactor(AVLTreeNode *root);
void updateHeight(AVLTreeNode *root);
AVLTreeNode *rightRotate(AVLTreeNode *root);
AVLTreeNode *leftRotate(AVLTreeNode *root);
AVLTreeNode *balanceAVL(AVLTreeNode *root);
AVLTreeNode *insertAVL(AVLTreeNode *root, int val);
AVLTreeNode *searchAVL(AVLTreeNode *root, int val);
AVLTreeNode *deleteAVL(AVLTreeNode *root, int val);
void inorderTraversalAVL(AVLTreeNode *root);