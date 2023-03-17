#include <bits/stdc++.h>
#define N 100
using namespace std;
typedef struct ListNode
{
    int val;               // ������
    struct ListNode *prev; // ָ��ǰһ���ڵ��ָ��
    struct ListNode *next; // ָ����һ���ڵ��ָ��
} ListNode;

typedef struct DoubleCircularList
{
    ListNode *head; // ָ��ͷ�ڵ��ָ��
    int length;     // ������
} DoubleCircularList;
/**
 * It initializes a double circular list.
 *
 * @param list The list to be initialized.
 */
void initList(DoubleCircularList *list)
{
    list->head = (ListNode *)malloc(sizeof(ListNode)); // ����ͷ�ڵ�
    list->head->next = list->head;                     // ��ͷ�ڵ��ָ����ָ���Լ�
    list->head->prev = list->head;                     // ��ͷ�ڵ��ָ����ָ���Լ�
    list->length = 0;                                  // ������Ϊ0
}
/**
 * ��ɾ���б�
 *
 * @param list Ҫ���ٵ��嵥
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
        cout << "ɾ��λ�ò��Ϸ�" << endl;
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
        cout << "��ѯλ�ò��Ϸ�" << endl;
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
    cout << "ɾ����0��Ԫ��:" << endl;
    deleteAt(list, 0);
    cout << "list:" << endl;
    printList(list);
    cout << "��ѯ��0��Ԫ��:";
    getAt(list, 0);
    destroyList(list);
    system("pause");
    return 0;
}