#include <bits/stdc++.h>
#define MAX_SIZE 10000
using namespace std;
typedef struct Node
{
    int data; // ������
    int next; // ָ����һ���ڵ��ָ��
} Node;
typedef struct StaticLinkedList
{
    Node nodes[MAX_SIZE]; // �ڵ�����
    int head;             // ͷ�ڵ��λ��
    int length;           // ������
} StaticLinkedList;

/**
 * ������ʼ������ͷΪ-1��������Ϊ0��ÿ������nextָ��ָ���������һ�����
 *
 * @param list Ҫ��ʼ�����б�
 */
void initList(StaticLinkedList *list)
{
    list->head = -1;
    list->length = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        list->nodes[i].next = i + 1;
    }
    list->nodes[MAX_SIZE - 1].next = 0;
}
void destroyList(StaticLinkedList *list)
{
    list->head = -1;
    list->length = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        list->nodes[i].next = i + 1;
    }
    list->nodes[MAX_SIZE - 1].next = -1;
}
/**
 * ���½ڵ�����б��ͷ����
 *
 * @param list Ҫ������б�
 * @param val Ҫ�����ֵ
 */
void insert(StaticLinkedList *list, int val)
{
    int p = list->head;
    int q = list->nodes[MAX_SIZE - 1].next;               // ��ȡ���нڵ��λ��
    list->nodes[MAX_SIZE - 1].next = list->nodes[q].next; // �����нڵ��ָ����ָ����һ�����нڵ�
    list->nodes[q].data = val;                            // ��������ֵ
    list->nodes[q].next = p;                              // ���½ڵ��ָ����ָ��ͷ�ڵ�
    list->head = q;                                       // ��ͷ�ڵ��λ��ָ���½ڵ㣨ͷ�巨��
    list->length++;
}

/**
 * ɾ��ָ��λ�õĽڵ㡣
 *
 * @param list Ҫ�������б�
 * @param pos Ҫɾ���Ľڵ��λ��
 */
void deleteAt(StaticLinkedList *list, int pos)
{
    if (pos < 0 || pos >= list->length)
    {
        cout << "ɾ��λ�ò��Ϸ�" << endl;
        return;
    }
    int p = list->head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = list->nodes[p].next; // �ҵ�Ҫɾ���ڵ��ǰһ���ڵ�
    }
    int q = list->nodes[p].next; // ��ȡҪɾ���ڵ��λ��
    list->nodes[p].next = list->nodes[q].next;
    list->nodes[q].next = list->nodes[MAX_SIZE - 1].next; // ��ɾ���ڵ��ָ����ָ����нڵ��ָ����
    list->nodes[MAX_SIZE - 1].next = q;                   // �����нڵ��ָ����ָ��ɾ���ڵ�
    list->length--;
}
/**
 * ����ӡ�б��нڵ�����ݡ�
 *
 * @param list ��̬�������
 */
void printList(StaticLinkedList *list)
{
    int p = list->head;
    while (p != -1)
    {
        cout << list->nodes[p].data << " ";
        p = list->nodes[p].next;
    }
    cout << endl;
}
/**
 * ��ȡָ��λ�ýڵ�����ݡ�
 *
 * @param list ָ�� StaticLinkedList ��ָ��
 * @param pos Ҫ���ʵĽڵ��λ��
 *
 * @return ָ��λ�ýڵ�����ݡ�
 */

void getAt(StaticLinkedList *list, int pos)
{
    if (pos < 0 || pos >= list->length)
    {
        cout << "�Ƿ��ķ���λ��" << endl;
        return;
    }
    int p = list->head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = list->nodes[p].next;
    }
    cout << "�� " << pos << " ���ڵ������Ϊ��" << list->nodes[p].data << endl;
}
int main()
{
    StaticLinkedList *list = (StaticLinkedList *)malloc(sizeof(StaticLinkedList));
    initList(list);
    for (int i = 0; i < 10; i++)
    {
        cout << "����� " << i + 1 << " ���ڵ�" << endl;
        insert(list, i + 1);
    }
    cout << "����������Ϊ��" << endl;
    printList(list);

    cout << "ɾ���� 5 ���ڵ�" << endl;
    deleteAt(list, 5);
    cout << "ɾ���������Ϊ��" << endl;
    printList(list);

    cout << "��ȡ�� 3 ���ڵ������" << endl;
    getAt(list, 3);

    destroyList(list);
    system("pause");
    return 0;
}