#include <bits/stdc++.h>
#define N 100
using namespace std;
typedef struct ListNode
{
    int val;               // ������
    struct ListNode *next; // ָ����һ���ڵ��ָ��
} ListNode;

typedef struct CircularList
{
    ListNode *head; // ָ��ͷ�ڵ��ָ��
    int length;     // ������
} CircularList;
void initList(CircularList *list)
{
    list->head = (ListNode *)malloc(sizeof(ListNode)); // ����ͷ�ڵ�
    list->head->next = list->head;                     // ��ͷ�ڵ��ָ����ָ���Լ�
    list->length = 0;                                  // ������Ϊ0
}
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
void insert(CircularList *list, int val)
{
    ListNode *p = list->head;
    while (p->next != list->head)
    {
        p = p->next;
    }
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = list->head; // ���½ڵ��ָ����ָ��ͷ�ڵ㣬��֤������ѭ����
    p->next = node;
    list->length++;
}
void deleteAt(CircularList *list, int pos)
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
    free(q);
    list->length--;
}
int get(CircularList *list, int pos)
{
    if (pos < 0 || pos >= list->length)
    {
        cout << "��ѯλ�ò��Ϸ�" << endl;
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
    cout << "������Ԫ�صĸ�����";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val = 0;
        cout << "�������" << i + 1 << "��Ԫ�أ�";
        cin >> val;
        insert(list, val);
    }
    printList(list);
    // �����������λ�ã�Ȼ���ѯ
    srand(time(NULL));
    int pos1 = rand() % list->length;
    int pos2 = rand() % list->length;
    cout << "��" << pos1 + 1 << "��Ԫ��Ϊ��" << get(list, pos1) << endl;
    cout << "��" << pos2 + 1 << "��Ԫ��Ϊ��" << get(list, pos2) << endl;
    // �������һ��λ�ã�Ȼ��ɾ��
    int pos3 = rand() % list->length;
    cout << "ɾ����" << pos3 + 1 << "��Ԫ��" << endl;
    deleteAt(list, pos3);
    printList(list);
    destroyList(list);
    free(list);
    system("pause");
    return 0;
}