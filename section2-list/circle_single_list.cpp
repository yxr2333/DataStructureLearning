/**
 * @file circle_single_list.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ѭ��������Ļ�������
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
    int val;               // ������
    struct ListNode *next; // ָ����һ���ڵ��ָ��
} ListNode;

/**
 * CircularList �ṹ��һ�����ݽṹ������ָ��ͷ�ڵ��ָ���ѭ������ĳ��ȡ�
 * ѭ���������е����һ���ڵ��ָ�벻��ָ��NULL������ָ��ͷ�ڵ㡣
 * @property {ListNode} head - ָ��ѭ������ͷ�ڵ��ָ�롣
 * @property {int} length - ��CircularList���ṹ�ġ�length�����Ա�ʾѭ�������еĽڵ�����
 */
typedef struct CircularList
{
    ListNode *head; // ָ��ͷ�ڵ��ָ��
    int length;     // ������
} CircularList;

/**
 * �ú���ͨ��Ϊͷ�ڵ�����ڴ桢����ָ������Ϊ����������������Ϊ 0 ����ʼ��ѭ������
 *
 * @param list ָ�� CircularList �ṹ��ָ�룬���а����й�ѭ���������Ϣ��
 */
void initList(CircularList *list)
{
    list->head = (ListNode *)malloc(sizeof(ListNode)); // ����ͷ�ڵ�
    list->head->next = list->head;                     // ��ͷ�ڵ��ָ����ָ���Լ�
    list->length = 0;                                  // ������Ϊ0
}

/**
 * �ú���ͨ���ͷ������нڵ��ͷ�ڵ�������ѭ������
 *
 * @param list ָ�� CircularList �ṹ��ָ�룬���а����й�ѭ���������Ϣ������ָ��ͷ�ڵ��ָ�������ĳ��ȡ�
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
 * �˺��������и���ֵ���½ڵ�ʹ��β�巨���뵽ѭ�������С�
 *
 * @param list ָ�� CircularList �ṹ��ָ�룬�������й�ѭ���������Ϣ��������ͷ�ڵ�ͳ��ȡ�
 * @param val Ҫ���뵽ѭ�������е�ֵ��
 */
void insert(CircularList *list, int val)
{
    ListNode *p = list->head;
    while (p->next != list->head) // �ҵ���ǰ�����е����һ���ڵ�
    {
        p = p->next;
    }
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = list->head; // ���½ڵ��ָ����ָ��ͷ�ڵ㣬��֤������ѭ����
    p->next = node;
    list->length++;
}

/**
 * �ú���ɾ��ѭ��������ָ��λ�õĽڵ㡣
 *
 * @param list ָ�� CircularList �ṹ��ָ�룬����ʾ����Ҫ����ɾ���ڵ��ѭ������
 * @param pos pos��һ�����Ͳ�������ʾҪɾ���Ľڵ���ѭ�������е�λ�á�
 *
 * @return �ú���û�з���ֵ��������void��
 */
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