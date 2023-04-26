#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insert(TreeNode *&root, int val);

void remove(TreeNode *&root, int val);

void preOrder(TreeNode *root);

void inOrder(TreeNode *root);

void postOrder(TreeNode *root);

void levelOrder(TreeNode *root);
