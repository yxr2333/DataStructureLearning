/**
 * @file simple_single_linked_list.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 单链表的基本操作
 * @version 0.1
 * @date 2023-04-15
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
    struct Node *next;
} Node;
typedef struct LinkedList
{
    Node *head;
    int length;
} LinkedList;
void init(LinkedList *list)
{
    // 初始化带头指针的单链表
    list->head = (Node *)malloc(sizeof(Node));
    list->head->next = NULL;
    list->length = 0;
}
/**
 * 该函数在链表的指定位置插入一个元素。
 *
 * @param list 指向将插入元素的链表的指针
 * @param pos 给定数据的新节点需要插入到链表中的位置。
 * @param data 要插入链表指定位置的数据。
 *
 * @return 该函数没有返回语句，因此它不返回任何内容。
 */
void insert(LinkedList *list, int pos, int data)
{
    // 在单链表的第pos个位置插入元素data
    if (pos < 0 || pos > list->length)
    {
        cout << "插入位置不合法" << endl;
        return;
    }
    Node *p = list->head;
    for (int i = 0; i < pos; i++)
    {
        p = p->next;
    }
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = data;
    q->next = p->next;
    p->next = q;
    list->length++;
}

void insert(LinkedList *list, int data)
{
    // 在单链表的末尾插入元素data
    Node *p = list->head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = data;
    q->next = NULL;
    p->next = q; // 使用尾插法插入元素
    list->length++;
}

void remove(LinkedList *list, int pos)
{
    // 删除单链表的第pos个位置的元素
    if (pos < 0 || pos >= list->length)
    {
        cout << "删除位置不合法" << endl;
        return;
    }
    Node *p = list->head;
    for (int i = 0; i < pos; i++)
    {
        p = p->next;
    }
    Node *q = p->next;
    p->next = q->next;
    free(q);
    list->length--;
}

void printList(LinkedList *list)
{
    // 打印单链表
    Node *p = list->head->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

/**
 * 此函数使用递归从链表中删除具有给定值的所有节点。
 *
 * @param list 指向 LinkedList 结构的指针
 * @param curHead 指向链表当前头节点的指针
 * @param val 需要从链表中移除的整数值。
 *
 * @return 此函数中没有显式返回任何内容。但是，当达到基本情况时（当 p 为 NULL 时），该函数会将控制权返回给调用函数。
 */
void removeVal(LinkedList *list, Node *curHead, int val)
{
    Node *p = curHead->next;
    if (p == NULL) // base case
    {
        return;
    }
    if (p->data == val) // if we find the value
    {
        Node *q = p;
        curHead->next = p->next; // 删除节点就是将前一个节点的next指向当前节点的next
        free(q);
        list->length--;
        removeVal(list, curHead, val); // recursion
    }
    else
    {
        removeVal(list, curHead->next, val);
    }
}
void reversePrintList(Node *node)
{
    // 逆序打印单链表
    if (node->next == NULL)
    {
        return;
    }
    reversePrintList(node->next);
    cout << node->next->data << " ";
}
int main()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    init(list);
    for (int i = 0; i < 10; i++)
    {
        insert(list, i + 1);
    }
    for (int i = 0; i < 10; i++)
    {
        insert(list, 100);
    }
    printList(list);
    removeVal(list, list->head, 100);
    printList(list);
    reversePrintList(list->head);
    system("pause");
    return 0;
}