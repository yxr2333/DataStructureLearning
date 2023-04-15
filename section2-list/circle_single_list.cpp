/**
 * @file circle_single_list.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 循环单链表的基本操作
 * @version 0.1
 * @date 2023-04-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100
using namespace std;
typedef struct ListNode
{
    int val;               // 数据域
    struct ListNode *next; // 指向下一个节点的指针
} ListNode;

/**
 * CircularList 结构是一种数据结构，包含指向头节点的指针和循环链表的长度。
 * 循环单链表中的最后一个节点的指针不是指向NULL，而是指向头节点。
 * @property {ListNode} head - 指向循环链表头节点的指针。
 * @property {int} length - “CircularList”结构的“length”属性表示循环链表中的节点数。
 */
typedef struct CircularList
{
    ListNode *head; // 指向头节点的指针
    int length;     // 链表长度
} CircularList;

/**
 * 该函数通过为头节点分配内存、将其指针设置为自身并将链表长度设置为 0 来初始化循环链表。
 *
 * @param list 指向 CircularList 结构的指针，其中包含有关循环链表的信息。
 */
void initList(CircularList *list)
{
    list->head = (ListNode *)malloc(sizeof(ListNode)); // 申请头节点
    list->head->next = list->head;                     // 将头节点的指针域指向自己
    list->length = 0;                                  // 链表长度为0
}

/**
 * 该函数通过释放其所有节点和头节点来销毁循环链表。
 *
 * @param list 指向 CircularList 结构的指针，其中包含有关循环链表的信息，包括指向头节点的指针和链表的长度。
 */
void destroyList(CircularList *list)
{
    ListNode *p = list->head->next;
    while (p != list->head)
    {
        ListNode *q = p;
        p = p->next;
        free(q);
    }
    free(list->head);
    list->length = 0;
}
/**
 * 此函数将具有给定值的新节点使用尾插法插入到循环链表中。
 *
 * @param list 指向 CircularList 结构的指针，它包含有关循环链表的信息，例如其头节点和长度。
 * @param val 要插入到循环链表中的值。
 */
void insert(CircularList *list, int val)
{
    ListNode *p = list->head;
    while (p->next != list->head) // 找到当前链表中的最后一个节点
    {
        p = p->next;
    }
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = list->head; // 将新节点的指针域指向头节点，保证链表是循环的
    p->next = node;
    list->length++;
}

/**
 * 该函数删除循环链表中指定位置的节点。
 *
 * @param list 指向 CircularList 结构的指针，它表示我们要从中删除节点的循环链表。
 * @param pos pos是一个整型参数，表示要删除的节点在循环链表中的位置。
 *
 * @return 该函数没有返回值，它返回void。
 */
void deleteAt(CircularList *list, int pos)
{
    if (pos < 0 || pos >= list->length)
    {
        cout << "删除位置不合法" << endl;
        return;
    }
    ListNode *p = list->head;
    for (int i = 0; i < pos; i++)
    {
        p = p->next;
    }
    ListNode *q = p->next;
    p->next = q->next;
    free(q);
    list->length--;
}
int get(CircularList *list, int pos)
{
    if (pos < 0 || pos >= list->length)
    {
        cout << "查询位置不合法" << endl;
        return -1;
    }
    ListNode *p = list->head->next;
    for (int i = 0; i < pos; i++)
    {
        p = p->next;
    }
    return p->val;
}
void printList(CircularList *list)
{
    ListNode *p = list->head->next;
    while (p != list->head)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    CircularList *list = (CircularList *)malloc(sizeof(CircularList));
    initList(list);
    int n = 0;
    cout << "请输入元素的个数：";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val = 0;
        cout << "请输入第" << i + 1 << "个元素：";
        cin >> val;
        insert(list, val);
    }
    printList(list);
    // 随机生成两个位置，然后查询
    srand(time(NULL));
    int pos1 = rand() % list->length;
    int pos2 = rand() % list->length;
    cout << "第" << pos1 + 1 << "个元素为：" << get(list, pos1) << endl;
    cout << "第" << pos2 + 1 << "个元素为：" << get(list, pos2) << endl;
    // 随机生成一个位置，然后删除
    int pos3 = rand() % list->length;
    cout << "删除第" << pos3 + 1 << "个元素" << endl;
    deleteAt(list, pos3);
    printList(list);
    destroyList(list);
    free(list);
    system("pause");
    return 0;
}