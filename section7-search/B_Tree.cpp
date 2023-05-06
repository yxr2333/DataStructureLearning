/**
 * @file B_Tree.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief B树的简介
 * @version 0.1
 * @date 2023-05-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <B_Tree.hpp>
#define N 100
using namespace std;
// 创建一个新节点
BNode *createNode()
{
    BNode *node = new BNode;
    node->n = 0;
    node->leaf = true;
    for (int i = 0; i < ORDER; i++)
    {
        node->children[i] = NULL;
    }
    return node;
}

// 在B树中查找一个关键字
BNode *search(BNode *node, int key)
{
    int i = 0;
    while (i < node->n && key > node->keys[i])
    {
        i++;
    }
    if (i < node->n && key == node->keys[i])
    {
        return node;
    }
    if (node->leaf)
    {
        return NULL;
    }
    return search(node->children[i], key);
}
// 分裂节点
void split(BNode *node, int i, BNode *child)
{
    BNode *newNode = createNode();
    newNode->n = ORDER / 2 - 1;
    for (int j = 0; j < ORDER / 2 - 1; j++)
    {
        newNode->keys[j] = child->keys[j + ORDER / 2];
    }
    if (!child->leaf)
    {
        for (int j = 0; j < ORDER / 2; j++)
        {
            newNode->children[j] = child->children[j + ORDER / 2];
        }
    }
    child->n = ORDER / 2 - 1;
    for (int j = node->n; j >= i + 1; j--)
    {
        node->children[j + 1] = node->children[j];
    }
    node->children[i + 1] = newNode;
    for (int j = node->n - 1; j >= i; j--)
    {
        node->keys[j + 1] = node->keys[j];
    }
    node->keys[i] = child->keys[ORDER / 2 - 1];
    node->n++;
}

// 插入一个关键字到B树中
void insert(BNode *&root, int key)
{
    if (root == NULL)
    {
        root = createNode();
        root->keys[0] = key;
        root->n = 1;
        return;
    }
    if (search(root, key) != NULL)
    {
        return;
    }
    if (root->n == ORDER - 1)
    {
        BNode *newNode = createNode();
        newNode->leaf = false;
        newNode->children[0] = root;
        split(newNode, 0, root);
        int i = 0;
        if (newNode->keys[0] < key)
        {
            i++;
        }
        insert(newNode->children[i], key);
        root = newNode;
    }
    else
    {
        int i = root->n - 1;
        if (root->leaf)
        {
            while (i >= 0 && key < root->keys[i])
            {
                root->keys[i + 1] = root->keys[i];
                i--;
            }
            root->keys[i + 1] = key;
            root->n++;
        }
        else
        {
            while (i >= 0 && key < root->keys[i])
            {
                i--;
            }
            i++;
            if (root->children[i]->n == ORDER - 1)
            {
                split(root, i, root->children[i]);
                if (root->keys[i] < key)
                {
                    i++;
                }
            }
            insert(root->children[i], key);
        }
    }
}

// 删除B树中的一个关键字
void remove(BNode *&root, int key)
{
    if (root == NULL)
    {
        return;
    }
    if (search(root, key) == NULL)
    {
        return;
    }
    if (root->n == 1)
    {
        if (root->leaf)
        {
            delete root;
            root = NULL;
        }
        else
        {
            BNode *child1 = root->children[0];
            BNode *child2 = root->children[1];
            if (child1->n == ORDER / 2 - 1 && child2->n == ORDER / 2 - 1)
            {
                merge(root, 0, child1, child2);
                deleteNode(root, 1);
                remove(child1, key);
            }
            else
            {
                remove(root->children[key < root->keys[0] ? 0 : 1], key);
            }
        }
    }
    else
    {
        if (root->leaf)
        {
            deleteNode(root, findKey(root, key));
        }
        else
        {
            BNode *child = root->children[findKey(root, key)];
            if (child->n == ORDER / 2 - 1)
            {
                BNode *left = NULL;
                BNode *right = NULL;
                int index = findChild(root, child);
                if (index > 0)
                {
                    left = root->children[index - 1];
                }
                if (index < root->n)
                {
                    right = root->children[index + 1];
                }
                if (left && left->n > ORDER / 2 - 1)
                {
                    rotateRight(root, index - 1, left, child);
                }
                else if (right && right->n > ORDER / 2 - 1)
                {
                    rotateLeft(root, index, child, right);
                }
                else if (left)
                {
                    merge(root, index - 1, left, child);
                    child = left;
                }
                else
                {
                    merge(root, index, child, right);
                }
            }
            remove(child, key);
        }
    }
}

// 查找关键字在节点中的位置
int findKey(BNode *node, int key)
{
    int index = 0;
    while (index < node->n && node->keys[index] < key)
    {
        index++;
    }
    return index;
}

// 查找节点在父节点中的位置
int findChild(BNode *parent, BNode *child)
{
    int index = 0;
    while (index <= parent->n && parent->children[index] != child)
    {
        index++;
    }
    return index;
}

// 删除节点中的一个关键字
void deleteNode(BNode *node, int index)
{
    for (int i = index; i < node->n - 1; i++)
    {
        node->keys[i] = node->keys[i + 1];
    }
    node->n--;
}

// 合并两个节点
void merge(BNode *parent, int index, BNode *left, BNode *right)
{
    left->keys[left->n] = parent->keys[index];
    for (int i = 0; i < right->n; i++)
    {
        left->keys[left->n + 1 + i] = right->keys[i];
    }
    if (!left->leaf)
    {
        for (int i = 0; i <= right->n; i++)
        {
            left->children[left->n + 1 + i] = right->children[i];
        }
    }
    deleteNode(parent, index);
    parent->children[index] = left;
    for (int i = index + 1; i < parent->n; i++)
    {
        parent->children[i] = parent->children[i + 1];
    }
    parent->children[parent->n] = NULL;
    parent->n--;
    delete right;
}

// 向右旋转节点
void rotateRight(BNode *parent, int index, BNode *left, BNode *right)
{
    right->children[right->n + 1] = right->children[right->n];
    for (int i = right->n - 1; i >= 0; i--)
    {
        right->keys[i + 1] = right->keys[i];
        right->children[i + 1] = right->children[i];
    }
    right->n++;
    right->keys[0] = parent->keys[index];
    right->children[0] = left->children[left->n];
    parent->keys[index] = left->keys[left->n - 1];
    left->n--;
}

// 向左旋转节点
void rotateLeft(BNode *parent, int index, BNode *left, BNode *right)
{
    left->n++;
    left->keys[left->n - 1] = parent->keys[index];
    left->children[left->n] = right->children[0];
    parent->keys[index] = right->keys[0];
    for (int i = 1; i < right->n; i++)
    {
        right->keys[i - 1] = right->keys[i];
        right->children[i - 1] = right->children[i];
    }
    right->children[right->n - 1] = right->children[right->n];
    right->n--;
}

// 打印B树中的关键字
void print(BNode *root)
{
    if (root != NULL)
    {
        for (int i = 0; i < root->n; i++)
        {
            cout << root->keys[i] << " ";
        }
        if (!root->leaf)
        {
            for (int i = 0; i <= root->n; i++)
            {
                print(root->children[i]);
            }
        }
    }
}

// 测试B树的基本操作
int main()
{
    BNode *root = NULL;
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        insert(root, arr[i]);
    }
    cout << "B树中的关键字为：";
    print(root);
    cout << endl;
    remove(root, 50);
    cout << "删除50后，B树中的关键字为：";
    print(root);
    cout << endl;
    remove(root, 70);
    cout << "删除70后，B树中的关键字为：";
    print(root);
    cout << endl;
    system("pause");
    return 0;
}
