/**
 * @file simple_double_linked_list.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ˫����������βָ�룩�Ļ���ʵ��
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
 * �˺���ͨ������һ���½ڵ㲢���� prior �� next ָ������Ϊ NULL ����ʼ��˫������
 *
 * @param L �� LinkList ����ָ������ã����� struct Node* �����Ͷ���
 *
 * @return һ������ֵ����������ʼ���ɹ��򷵻� true�����ʧ���򷵻� false������һ���ڵ���ڴ����ʧ�ܣ���
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
 * �˺�����˫�������ĩβ����һ�����и���ֵ���½ڵ㡣
 *
 * @param list ������list���Ƕ� LinkList �����ã����ܿ�����ʹ�ýڵ�ʵ�ֵ��������ݽṹ��
 * @param val Ҫ���뵽�����е�ֵ��
 *
 * @return һ������ֵ�����������и���ֵ���½ڵ�ɹ����򷵻� true�����ʧ���򷵻� false�����磬���û���㹻���ڴ��������½ڵ㣩��
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
 * �˺�����˫�������ָ��λ�ò���һ�����и���ֵ���½ڵ㡣
 *
 * @param list �� LinkList �����ã�����һ���������ݽṹ��
 * @param pos Ӧ�������в���ֵΪ��val�����½ڵ��λ�á�
 * @param val Ҫ���뵽�����е�ֵ��
 *
 * @return һ������ֵ��true �� false��ȡ���ڲ����Ƿ�ɹ���
 */
bool insert(LinkList &list, int pos, int val)
{
    if (pos < 0)
    {
        cout << "����λ�ò��Ϸ�" << endl;
        return false;
    }
    Node *p = list;
    for (int i = 0; i < pos; i++)
    {
        p = p->next;
        if (p == NULL)
        {
            cout << "����λ�ò��Ϸ�" << endl;
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