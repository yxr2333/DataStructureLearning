/**
 * @file simple_double_linked_list.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 双向链表（不带尾指针）的基本实现
 * @version 0.1
 * @date 2023-04-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <bits/stdc++.h>
#define N 100
using namespace std;
typedef struct Node
{
    int data;
    struct Node *prior;
    struct Node *next;
} Node, *LinkList;

/**
 * 此函数通过创建一个新节点并将其 prior 和 next 指针设置为 NULL 来初始化双向链表。
 *
 * @param L 对 LinkList 类型指针的引用，它是 struct Node* 的类型定义
 *
 * @return 一个布尔值。如果链表初始化成功则返回 true，如果失败则返回 false（即第一个节点的内存分配失败）。
 */
bool initList(LinkList &list)
{
    list = new Node;
    if (list == NULL)
    {
        return false;
    }
    list->prior = NULL;
    list->next = NULL;
    return true;
}

/**
 * 此函数在双向链表的末尾插入一个具有给定值的新节点。
 *
 * @param list 参数“list”是对 LinkList 的引用，它很可能是使用节点实现的链表数据结构。
 * @param val 要插入到链表中的值。
 *
 * @return 一个布尔值。如果插入具有给定值的新节点成功，则返回 true，如果失败则返回 false（例如，如果没有足够的内存来分配新节点）。
 */
bool insert(LinkList &list, int val)
{
    Node *p = list;
    while (p->next != NULL)
    {
        p = p->next;
    }
    Node *q = new Node;
    if (q == NULL)
    {
        return false;
    }
    q->data = val;
    q->next = NULL;
    q->prior = p;
    p->next = q;
    return true;
}

/**
 * 此函数在双向链表的指定位置插入一个具有给定值的新节点。
 *
 * @param list 对 LinkList 的引用，它是一个链表数据结构。
 * @param pos 应在链表中插入值为“val”的新节点的位置。
 * @param val 要插入到链表中的值。
 *
 * @return 一个布尔值，true 或 false，取决于插入是否成功。
 */
bool insert(LinkList &list, int pos, int val)
{
    if (pos < 0)
    {
        cout << "插入位置不合法" << endl;
        return false;
    }
    Node *p = list;
    for (int i = 0; i < pos; i++)
    {
        p = p->next;
        if (p == NULL)
        {
            cout << "插入位置不合法" << endl;
            return false;
        }
    }
    Node *q = new Node;
    if (q == NULL)
    {
        return false;
    }
    q->data = val;
    q->next = p->next;
    q->prior = p;
    p->next = q;
    if (q->next != NULL)
    {
        q->next->prior = q;
    }
    return true;
}

void printList(LinkList list)
{
    Node *p = list->next;
    while (p != NULL)
    {
        if (p->next != NULL)
        {
            cout << p->data << "->";
        }
        else
        {
            cout << p->data;
        }
        p = p->next;
    }
    cout << endl;
}

int main()
{
    LinkList list;
    initList(list);
    insert(list, 1);
    insert(list, 3);
    insert(list, 2);
    insert(list, 5);
    insert(list, 4);
    printList(list);
    system("pause");
    return 0;
}