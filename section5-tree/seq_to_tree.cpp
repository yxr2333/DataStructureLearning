/**
 * @file seq_to_tree.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 根据遍历序列恢复二叉树
 * 可以通过先序+中序、后序+中序、层序+中序这三种方式来恢复二叉树
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &idx_map, int in_left, int in_right, int &pre_idx)
{
    if (in_left > in_right)
    {
        return nullptr;
    }
    int root_val = preorder[pre_idx++];
    TreeNode *root = new TreeNode(root_val);
    int in_idx = idx_map[root_val];
    root->left = buildTree(preorder, inorder, idx_map, in_left, in_idx - 1, pre_idx);
    root->right = buildTree(preorder, inorder, idx_map, in_idx + 1, in_right, pre_idx);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
    {
        return nullptr;
    }
    unordered_map<int, int> idx_map;
    for (int i = 0; i < inorder.size(); i++)
    {
        idx_map[inorder[i]] = i;
    }
    int pre_idx = 0;
    return buildTree(preorder, inorder, idx_map, 0, inorder.size() - 1, pre_idx);
}

void levelOrder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            auto node = q.front();
            q.pop();
            cout << node->val;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
            if (i < n - 1)
            { // 不是当前层的最后一个节点
                cout << " ";
            }
        }
        cout << endl;
    }
}

void printTree(TreeNode *root, int depth)
{
    if (!root)
    {
        return;
    }
    const int SPACE_COUNT = 4;
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth * SPACE_COUNT; i++)
    {
        cout << " ";
    }
    cout << root->val << endl;
    printTree(root->left, depth + 1);
}

int main()
{
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    TreeNode *root = buildTree(preorder, inorder);
    levelOrder(root); // 1 2 3 4 5 6 7
    cout << endl;
    printTree(root, 0);
    system("pause");
    return 0;
}