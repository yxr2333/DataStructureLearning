#include <bits/stdc++.h>
#define MAX_SIZE 10000
using namespace std;
typedef struct Node
{
    int data; // 数据域
    int next; // 指向下一个节点的指针
} Node;
typedef struct StaticLinkedList
{
    Node nodes[MAX_SIZE]; // 节点数组
    int head;             // 头节点的位置
    int length;           // 链表长度
} StaticLinkedList;

/**
 * 函数初始化链表头为-1，链表长度为0，每个结点的next指针指向链表的下一个结点
 *
 * @param list 要初始化的列表
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
 * 将新节点插入列表的头部。
 *
 * @param list 要插入的列表。
 * @param val 要插入的值
 */
void insert(StaticLinkedList *list, int val)
{
    int p = list->head;
    int q = list->nodes[MAX_SIZE - 1].next;               // 获取空闲节点的位置
    list->nodes[MAX_SIZE - 1].next = list->nodes[q].next; // 将空闲节点的指针域指向下一个空闲节点
    list->nodes[q].data = val;                            // 将数据域赋值
    list->nodes[q].next = p;                              // 将新节点的指针域指向头节点
    list->head = q;                                       // 将头节点的位置指向新节点（头插法）
    list->length++;
}

/**
 * 删除指定位置的节点。
 *
 * @param list 要操作的列表
 * @param pos 要删除的节点的位置
 */
void deleteAt(StaticLinkedList *list, int pos)
{
    if (pos < 0 || pos >= list->length)
    {
        cout << "删除位置不合法" << endl;
        return;
    }
    int p = list->head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = list->nodes[p].next; // 找到要删除节点的前一个节点
    }
    int q = list->nodes[p].next; // 获取要删除节点的位置
    list->nodes[p].next = list->nodes[q].next;
    list->nodes[q].next = list->nodes[MAX_SIZE - 1].next; // 将删除节点的指针域指向空闲节点的指针域
    list->nodes[MAX_SIZE - 1].next = q;                   // 将空闲节点的指针域指向删除节点
    list->length--;
}
/**
 * 它打印列表中节点的数据。
 *
 * @param list 静态链表对象
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
 * 获取指定位置节点的数据。
 *
 * @param list 指向 StaticLinkedList 的指针
 * @param pos 要访问的节点的位置
 *
 * @return 指定位置节点的数据。
 */

void getAt(StaticLinkedList *list, int pos)
{
    if (pos < 0 || pos >= list->length)
    {
        cout << "非法的访问位置" << endl;
        return;
    }
    int p = list->head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = list->nodes[p].next;
    }
    cout << "第 " << pos << " 个节点的数据为：" << list->nodes[p].data << endl;
}
int main()
{
    StaticLinkedList *list = (StaticLinkedList *)malloc(sizeof(StaticLinkedList));
    initList(list);
    for (int i = 0; i < 10; i++)
    {
        cout << "插入第 " << i + 1 << " 个节点" << endl;
        insert(list, i + 1);
    }
    cout << "插入后的链表为：" << endl;
    printList(list);

    cout << "删除第 5 个节点" << endl;
    deleteAt(list, 5);
    cout << "删除后的链表为：" << endl;
    printList(list);

    cout << "获取第 3 个节点的数据" << endl;
    getAt(list, 3);

    destroyList(list);
    system("pause");
    return 0;
}