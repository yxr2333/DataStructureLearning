#include <bits/stdc++.h>
#define N 100
using namespace std;
typedef struct ListNode
{
    int val;               // 数据域
    struct ListNode *prev; // 指向前一个节点的指针
    struct ListNode *next; // 指向下一个节点的指针
} ListNode;

typedef struct DoubleCircularList
{
    ListNode *head; // 指向头节点的指针
    int length;     // 链表长度
} DoubleCircularList;
/**
 * It initializes a double circular list.
 *
 * @param list The list to be initialized.
 */
void initList(DoubleCircularList *list)
{
    list->head = (ListNode *)malloc(sizeof(ListNode)); // 申请头节点
    list->head->next = list->head;                     // 将头节点的指针域指向自己
    list->head->prev = list->head;                     // 将头节点的指针域指向自己
    list->length = 0;                                  // 链表长度为0
}
/**
 * 它删除列表。
 *
 * @param list 要销毁的清单
 */
void destroyList(DoubleCircularList *list)
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
void insert(DoubleCircularList *list, int val)
{
    ListNode *p = list->head;
    while (p->next != list->head)
    {
        p = p->next;
    }
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = list->head;
    node->prev = p;
    p->next = node;
    list->head->prev = node;
    list->length++;
}
void deleteAt(DoubleCircularList *list, int pos)
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
    q->next->prev = p;
    free(q);
    list->length--;
}
void printList(DoubleCircularList *list)
{
    ListNode *p = list->head->next;
    while (p != list->head)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
void getAt(DoubleCircularList *list, int pos)
{
    if (pos < 0 || pos >= list->length)
    {
        cout << "查询位置不合法" << endl;
        return;
    }
    ListNode *p = list->head;
    for (int i = 0; i < pos; i++)
    {
        p = p->next;
    }
    cout << p->next->val << endl;
}
int main()
{
    DoubleCircularList *list = (DoubleCircularList *)malloc(sizeof(DoubleCircularList));
    initList(list);
    for (int i = 0; i < 10; i++)
    {
        insert(list, i);
    }
    cout << "list:" << endl;
    printList(list);
    cout << "删除第0个元素:" << endl;
    deleteAt(list, 0);
    cout << "list:" << endl;
    printList(list);
    cout << "查询第0个元素:";
    getAt(list, 0);
    destroyList(list);
    system("pause");
    return 0;
}