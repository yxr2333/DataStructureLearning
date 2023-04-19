/**
 * @file simple_double_linked_list(2).cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 双向链表（带尾指针）的基本实现
 * @version 0.1
 * @date 2023-04-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <bits/stdc++.h>
#define N 100
using namespace std;
/**
 * 这是具有整数数据的双向链表节点的结构定义。
 * @property {int} data - 一个整数值，表示存储在节点中的数据。
 * @property prior - “prior”属性是指向双向链表中前一个节点的指针。它允许在两个方向上进行高效遍历。
 * @property next - Node 结构的“next”属性是指向链表中下一个节点的指针。它用于通过指向列表中的下一个节点来遍历链表。如果当前节点是列表中的最后一个节点，则“下一个”属性将设置为
 */
typedef struct Node
{
    int data;
    struct Node *prior;
    struct Node *next;
} Node;

/**
 * DoubleLinkedList 结构是一种数据结构，包含用于双向链表实现的头指针和尾指针以及长度变量。
 * @property {Node} head - 指向双链表中第一个节点的指针。
 * @property {Node} tail - DoubleLinkedList 结构中的“tail”属性是指向链表中最后一个节点的指针。它用于跟踪列表的末尾并轻松地将新节点添加到末尾。
 * @property {int} length - DoubleLinkedList 结构中的 length 属性表示链表中的节点数。它用于跟踪列表的大小，并且可以在列表中添加或删除节点时进行更新。
 */
typedef struct DoubleLinkedList
{
    Node *head;
    Node *tail;
    int length;
} DoubleLinkedList;

/**
 * 该函数使用头节点初始化双向链表。
 *
 * @param list 指向 DoubleLinkedList 类型指针的指针，这意味着它是对 DoubleLinkedList 指针地址的引用。这允许函数修改作为参数传递的原始指针。
 */
void init(DoubleLinkedList *&list)
{
    // 初始化带头指针的双向链表
    list->head = (Node *)malloc(sizeof(Node));
    list->tail = (Node *)malloc(sizeof(Node));
    list->head->next = list->tail;
    list->tail->prior = list->head;
    list->head->prior = NULL;
    list->tail->next = NULL;
    list->length = 0;
}
/**
 * 此函数在双向链表的末尾插入一个具有给定值的新节点。
 *
 * @param list 指向 DoubleLinkedList 结构的指针，它包含有关链表的信息，例如它的长度和指向头节点和尾节点的指针。
 * @param val 我们要插入双向链表的值。
 *
 * @return 一个布尔值，true 或 false，取决于插入操作是否成功。
 */
bool insert(DoubleLinkedList *&list, int val)
{
    Node *p = list->tail->prior;
    Node *q = new Node;
    if (q == NULL)
    {
        return false;
    }
    q->data = val;
    q->next = list->tail;
    q->prior = p;
    p->next = q;
    list->tail->prior = q;
    list->length++;
    return true;
}

void printList(DoubleLinkedList *&list, int start = 0)
{
    if (start < 0 || start >= list->length)
    {
        cout << "Invalid start index!" << endl;
        return;
    }
    Node *p = list->head->next;
    for (int i = 0; i < start; i++)
    {
        p = p->next;
    }
    while (p != list->tail)
    {
        if (p->next != list->tail)
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
    srand(time(NULL));
    DoubleLinkedList *list = new DoubleLinkedList;
    init(list);
    for (int i = 0; i < 10; i++)
    {
        int val = rand() % 100;
        cout << "Insert " << val << " into list." << endl;
        insert(list, val);
    }
    printList(list);
    system("pause");
    return 0;
}