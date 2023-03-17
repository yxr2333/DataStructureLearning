#include <bits/stdc++.h>
#define N 100
using namespace std;
typedef struct ListNode
{
    int val;               // 数据域
    struct ListNode *next; // 指向下一个节点的指针
} ListNode;

typedef struct CircularList
{
    ListNode *head; // 指向头节点的指针
    int length;     // 链表长度
} CircularList;
void initList(CircularList *list)
{
    list->head = (ListNode *)malloc(sizeof(ListNode)); // 申请头节点
    list->head->next = list->head;                     // 将头节点的指针域指向自己
    list->length = 0;                                  // 链表长度为0
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
    node->next = list->head; // 将新节点的指针域指向头节点，保证链表是循环的
    p->next = node;
    list->length++;
}
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