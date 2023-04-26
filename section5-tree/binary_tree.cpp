/**
 * @file binary_tree.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 二叉树的链式实现
 * @version 0.1
 * @date 2023-04-25
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <binary_tree.hpp>
#include <bits/stdc++.h>
#define N 100
using namespace std;
void insert(unique_ptr<TreeNode> &root, int val)
{
    if (root == nullptr)
    {
        root = make_unique<TreeNode>(val);
        return;
    }
    if (val < root->val)
    {
        insert(root->left, val);
    }
    else
    {
        insert(root->right, val);
    }
}

void remove(unique_ptr<TreeNode> &root, int val)
{
    if (root == nullptr)
    {
        return;
    }
    else if (root->val > val)
    {
        remove(root->left, val);
    }
    else if (root->val < val)
    {
        remove(root->right, val);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            root.reset();
        }
        else if (root->left == nullptr || root->right == nullptr)
        {
            root = move((root->left == nullptr) ? root->right : root->left);
        }
        else
        {
            TreeNode *temp = root->right.get();
            while (temp->left != nullptr)
            {
                temp = temp->left.get();
            }
            root->val = temp->val;
            remove(root->right, temp->val);
        }
    }
}
void preOrder(const unique_ptr<TreeNode> &root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(const unique_ptr<TreeNode> &root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(const unique_ptr<TreeNode> &root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

void levelOrder(const unique_ptr<TreeNode> &root)
{
    queue<TreeNode *> q;
    q.push(root.get());
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left)
            q.push(temp->left.get());
        if (temp->right)
            q.push(temp->right.get());
    }
}
int main()
{
    unique_ptr<TreeNode> root;
    vector<int> a = {4, 2, 6, 1, 3, 5, 7};
    for (int i = 0; i < a.size(); i++)
    {
        insert(root, a[i]);
    }
    cout << "preOrder: " << endl;
    preOrder(root);
    cout << endl;
    cout << "inOrder: " << endl;
    inOrder(root);
    cout << endl;
    cout << "postOrder: " << endl;
    postOrder(root);
    cout << endl;
    cout << "levelOrder: " << endl;
    levelOrder(root);
    cout << endl;
    system("pause");
    return 0;
}
