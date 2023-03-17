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
    // ��ʼ����ͷָ��ĵ�����
    list->head = (Node *)malloc(sizeof(Node));
    list->head->next = NULL;
    list->length = 0;
}
void insert(LinkedList *list, int pos, int data)
{
    // �ڵ�����ĵ�pos��λ�ò���Ԫ��data
    if (pos < 0 || pos > list->length)
    {
        cout << "����λ�ò��Ϸ�" << endl;
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
    // �ڵ������ĩβ����Ԫ��data
    Node *p = list->head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = data;
    q->next = NULL;
    p->next = q;
    list->length++;
}

void remove(LinkedList *list, int pos)
{
    // ɾ��������ĵ�pos��λ�õ�Ԫ��
    if (pos < 0 || pos >= list->length)
    {
        cout << "ɾ��λ�ò��Ϸ�" << endl;
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
    // ��ӡ������
    Node *p = list->head->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

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
        curHead->next = p->next;
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
    // �����ӡ������
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