/**
 * @file simple_double_linked_list(2).cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ˫��������βָ�룩�Ļ���ʵ��
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
 * ���Ǿ����������ݵ�˫������ڵ�Ľṹ���塣
 * @property {int} data - һ������ֵ����ʾ�洢�ڽڵ��е����ݡ�
 * @property prior - ��prior��������ָ��˫��������ǰһ���ڵ��ָ�롣�����������������Ͻ��и�Ч������
 * @property next - Node �ṹ�ġ�next��������ָ����������һ���ڵ��ָ�롣������ͨ��ָ���б��е���һ���ڵ����������������ǰ�ڵ����б��е����һ���ڵ㣬����һ�������Խ�����Ϊ
 */
typedef struct Node
{
    int data;
    struct Node *prior;
    struct Node *next;
} Node;

/**
 * DoubleLinkedList �ṹ��һ�����ݽṹ����������˫������ʵ�ֵ�ͷָ���βָ���Լ����ȱ�����
 * @property {Node} head - ָ��˫�����е�һ���ڵ��ָ�롣
 * @property {Node} tail - DoubleLinkedList �ṹ�еġ�tail��������ָ�����������һ���ڵ��ָ�롣�����ڸ����б��ĩβ�����ɵؽ��½ڵ���ӵ�ĩβ��
 * @property {int} length - DoubleLinkedList �ṹ�е� length ���Ա�ʾ�����еĽڵ����������ڸ����б�Ĵ�С�����ҿ������б�����ӻ�ɾ���ڵ�ʱ���и��¡�
 */
typedef struct DoubleLinkedList
{
    Node *head;
    Node *tail;
    int length;
} DoubleLinkedList;

/**
 * �ú���ʹ��ͷ�ڵ��ʼ��˫������
 *
 * @param list ָ�� DoubleLinkedList ����ָ���ָ�룬����ζ�����Ƕ� DoubleLinkedList ָ���ַ�����á����������޸���Ϊ�������ݵ�ԭʼָ�롣
 */
void init(DoubleLinkedList *&list)
{
    // ��ʼ����ͷָ���˫������
    list->head = (Node *)malloc(sizeof(Node));
    list->tail = (Node *)malloc(sizeof(Node));
    list->head->next = list->tail;
    list->tail->prior = list->head;
    list->head->prior = NULL;
    list->tail->next = NULL;
    list->length = 0;
}
/**
 * �˺�����˫�������ĩβ����һ�����и���ֵ���½ڵ㡣
 *
 * @param list ָ�� DoubleLinkedList �ṹ��ָ�룬�������й��������Ϣ���������ĳ��Ⱥ�ָ��ͷ�ڵ��β�ڵ��ָ�롣
 * @param val ����Ҫ����˫�������ֵ��
 *
 * @return һ������ֵ��true �� false��ȡ���ڲ�������Ƿ�ɹ���
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