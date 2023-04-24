/**
 * @file BST_tree.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ������������ʵ�ֺͻ�������
 * @version 0.1
 * @date 2023-04-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <BSTTree.hpp>

/**
 * �ú��������и���ֵ���½ڵ���뵽�����������С�
 *
 * @param root ��ָ��������������ڵ��ָ������á�
 * @param val Ҫ���뵽�����������е�ֵ��
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
 * �ú����ڶ��������������������ض�ֵ�Ľڵ㣬����ҵ��򷵻ظýڵ㣬���򷵻�NULL��
 *
 * @param root ָ��������������ڵ��ָ�롣
 * @param val val �������ڶ�����������������ֵ��
 *
 * @return
 * ������searchBST������һ��ָ��BSTTreeNode����ָ�룬������������ԡ�root��Ϊ���Ķ����������У����ָ���ֵΪ��val��������������Ҳ�����val������ú������ء�NULL����
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
 * �ú����Ӷ�����������ɾ�����и���ֵ�Ľڵ㡣
 *
 * @param root ָ��������������ڵ��ָ�롣
 * @param val ��Ҫ�Ӷ�����������ɾ���Ľڵ��ֵ��
 *
 * @return һ�� BSTTreeNode ָ�룬����ʾɾ������ָ��ֵ�Ľڵ����µĶ����������ĸ���
 */
BSTTreeNode *deleteBST(BSTTreeNode *root, DATATYPE val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == val)
    {
        // �ҵ���Ҫɾ���Ľڵ�
        if (root->left == NULL && root->right == NULL)
        {
            // ���1��Ҫɾ���Ľڵ�ΪҶ�ӽڵ㣬ֱ��ɾ������
            delete root;
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL)
        {
            // ���2��Ҫɾ���Ľڵ�ֻ��һ���ӽڵ㣬���ӽڵ����Ҫɾ���Ľڵ㼴��
            BSTTreeNode *tmp = root->left ? root->left : root->right;
            delete root;
            return tmp;
        }
        else
        {
            // ���3��Ҫɾ���Ľڵ��������ӽڵ㣬�ҵ���ɾ���ڵ����������ֵ��С�Ľڵ㣬���������ɾ���ڵ��ֵ��Ȼ�����������еݹ�ɾ���ýڵ�
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
 * �ú���ִ�ж������������������ӡÿ���ڵ��ֵ��
 *
 * @param root �������ĸ��ڵ㡣
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

//     // ����ڵ�
//     insertBST(root, 6);
//     insertBST(root, 2);
//     insertBST(root, 8);
//     insertBST(root, 1);
//     insertBST(root, 4);
//     insertBST(root, 3);
//     insertBST(root, 5);
//     insertBST(root, 7);
//     insertBST(root, 9);

//     // �������
//     inorderTraversalBST(root);
//     cout << endl;

//     // ���ҽڵ�
//     BSTTreeNode *node1 = searchBST(root, 5);
//     cout << node1->val << endl; // ���5

//     DATATYPE val = 10;
//     BSTTreeNode *node2 = searchBST(root, val);
//     if (node2 == NULL)
//     {
//         cout << "δ�ҵ��ڵ�" << to_string(val) << endl; // ���δ�ҵ��ڵ�val
//     }

//     // ɾ���ڵ�
//     root = deleteBST(root, 9);
//     // �������
//     inorderTraversalBST(root); // ���1 2 3 4 5 6 7 8

//     system("pause");
//     return 0;
// }