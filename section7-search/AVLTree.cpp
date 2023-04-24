/**
 * @file AVL_tree.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ƽ���������ʵ�ֺͻ�������
 * @version 0.1
 * @date 2023-04-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <AVLTree.hpp>
/**
 * �ú������ظ����������ڵ�ĸ߶ȡ�
 *
 * @param root �������ĸ��ڵ㡣
 *
 * @return �����������ڵ�ĸ߶ȡ�����ڵ�Ϊ NULL���򷵻� 0��
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
 * �˺�������������ڵ��ƽ�����ӡ�
 *
 * @param root ָ����������ڵ��ָ�롣
 *
 * @return ���ظ����������ڵ��ƽ�����ӡ�
 * ƽ�����Ӽ���Ϊ�������ĸ߶����������ĸ߶�֮��Ĳ�ֵ��
 * ���ƽ������Ϊ�������ʾ���������������ߣ����Ϊ�������ʾ���������������ߡ�
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
 * �ú������������������ĸ߶ȸ��¶������ڵ�ĸ߶ȡ�
 *
 * @param root ָ����������ڵ��ָ�롣
 */
void updateHeight(AVLTreeNode *root)
{
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

/**
 * �˺����Զ���������ִ������ת��
 *
 * @param root ָ��������������ڵ��ָ�롣
 *
 * @return ִ������ת��ָ�������¸���ָ�롣
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
 * �˺����Զ���������ִ������ת��
 *
 * @param root ָ����Ҫ����ת�������ĸ��ڵ��ָ�롣
 *
 * @return ִ������ת��ָ�������¸���ָ�롣
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
 * �ú���ͨ�����ݸ��ڵ��ƽ��������ִ����ת�����Ӷ�ƽ�� AVL ����
 *
 * @param root ָ����Ҫƽ��� AVL ���ĸ��ڵ��ָ�롣
 *
 * @return һ�� AVLTreeNode ָ�룬����ִ�б�Ҫ��ƽ������� AVL ���ĸ���
 */
AVLTreeNode *balanceAVL(AVLTreeNode *root)
{
    // ����ƽ������
    int balanceFactor = getBalanceFactor(root);

    // ����ƽ�����
    if (balanceFactor > 1)
    {
        if (getBalanceFactor(root->left) >= 0)
        {
            // LL�ͣ���������
            root = rightRotate(root);
        }
        else
        {
            // LR�ͣ��ȶ����ӽڵ���������������ٶԸ��ڵ������������
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
    }
    else if (balanceFactor < -1)
    {
        if (getBalanceFactor(root->right) <= 0)
        {
            // RR�ͣ���������
            root = leftRotate(root);
        }
        else
        {
            // RL�ͣ��ȶ����ӽڵ���������������ٶԸ��ڵ������������
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
    }

    return root;
}

/**
 * �˺��������и���ֵ���½ڵ���뵽 AVL ���У����ڱ�Ҫʱƽ������
 *
 * @param root ָ�� AVL ���ĸ��ڵ��ָ�롣
 * @param val Ҫ���뵽 AVL ���е�ֵ��
 *
 * @return ָ�� AVLTreeNode ��ָ�룬���ǲ�����и���ֵ���½ڵ�� AVL ���ĸ���
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
    // ���½ڵ�߶�
    updateHeight(root);
    root = balanceAVL(root);
    return root;
}

/**
 * �ú����� AVL �����������и���ֵ�Ľڵ㡣
 *
 * @param root ָ�� AVL ���ĸ��ڵ��ָ�롣
 * @param val val ��һ������ֵ����ʾ������ AVL ����������ֵ������ searchAVL ����ָ�� AVL
 * �����ڵ��ָ�룬���ݹ��������и���ֵ�Ľڵ㡣
 * ����ҵ��ڵ㣬�򷵻�ָ��ýڵ��ָ�룬���򷵻� NULL��
 * @return �˺�������ָ�� AVLTreeNode ��ָ�룬�ýڵ���� AVL ���еĸ���ֵ��val��������������Ҳ�����ֵ���򷵻� NULL��
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
 * �ú����� AVL ����ɾ�����и���ֵ�Ľڵ㲢ƽ������
 *
 * @param root AVL ���ĸ��ڵ㡣
 * @param val ��Ҫ�� AVL ����ɾ���Ľڵ��ֵ��
 *
 * @return ɾ�����и���ֵ�Ľڵ㲢ƽ������ָ�� AVL ������ָ�롣
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
    // ���½ڵ�߶�
    updateHeight(root);
    root = balanceAVL(root);
    return root;
}

// �������
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

//     // ����ڵ�
//     root = insertAVL(root, 6);
//     root = insertAVL(root, 2);
//     root = insertAVL(root, 8);
//     root = insertAVL(root, 1);
//     root = insertAVL(root, 4);
//     root = insertAVL(root, 3);
//     root = insertAVL(root, 5);
//     root = insertAVL(root, 7);
//     root = insertAVL(root, 9);

//     inorderTraversalAVL(root); // ���1 2 3 4 5 6 7 8 9
//     cout << endl;

//     // ���ҽڵ�
//     AVLTreeNode *node1 = searchAVL(root, 5);
//     cout << node1->val << endl; // ���5

//     AVLTreeNode *node2 = searchAVL(root, 10);
//     if (node2 == NULL)
//     {
//         cout << "δ�ҵ��ڵ�10" << endl; // ���δ�ҵ��ڵ�10
//     }

//     // ɾ���ڵ�
//     root = deleteAVL(root, 9);

//     // �������
//     inorderTraversalAVL(root); // ���1 2 3 4 5 6 7 8
//     system("pause");
//     return 0;
// }