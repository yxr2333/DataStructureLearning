#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode;
typedef struct LinkQueue
{
    LinkNode *front, *rear;
} LinkQueue;
void initQueue(LinkQueue *queue)
{
    queue->front = queue->rear = (LinkNode *)malloc(sizeof(LinkNode));
    queue->front->next = NULL;
}
void push(LinkQueue *queue, int val)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = val;
    s->next = NULL;
    queue->rear->next = s;
    queue->rear = s;
    cout << "Ԫ��: " << val << " �Ѳ������" << endl;
}
bool isEmpty(LinkQueue *queue)
{
    return queue->front == queue->rear;
}
int pop(LinkQueue *queue)
{
    if (isEmpty(queue))
    {
        cout << "����Ϊ�գ����ܳ���" << endl;
        return -1;
    }
    LinkNode *s = queue->front->next;
    int ans = s->data;
    queue->front->next = s->next;
    if (queue->rear == s) // ���������ֻ��һ��Ԫ�أ����Ӻ����Ϊ�գ���Ҫ�޸Ķ�βָ��
    {
        queue->front = queue->rear;
    }
    free(s);
    return ans;
}
/**
 * ��ӡ�����е�Ԫ�ء�
 *
 * @param queue Ҫ��ӡ�Ķ���
 */
void printQueue(LinkQueue *queue)
{
    if (!isEmpty(queue))
    {
        LinkNode *s = queue->front->next;
        while (s != NULL)
        {
            cout << s->data << " ";
            s = s->next;
        }
        cout << endl;
    }
    else
    {
        cout << "����Ϊ��" << endl;
    }
}
/**
 * ����ĺ������ٶ��С�
 *
 * @param queue Ҫ���ٵĶ���
 */
void destroyQueue(LinkQueue *queue)
{
    // ���ٶ��У��ظ����Ӳ�����ֱ������Ϊ��
    while (!isEmpty(queue))
    {
        pop(queue);
    }
}
int main()
{
    LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
    initQueue(queue);
    cout << "�����Ƿ�Ϊ�գ�" << isEmpty(queue) << endl;
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    // ����bool��ʽ��������Ƿ�Ϊ�գ�
    cout << "�����Ƿ�Ϊ�գ�" << isEmpty(queue) << endl;
    printQueue(queue);
    cout << "����Ԫ�أ�" << pop(queue) << endl;
    cout << "����Ԫ�أ�" << pop(queue) << endl;
    cout << "����Ԫ�أ�" << pop(queue) << endl;
    cout << "�����Ƿ�Ϊ�գ�" << isEmpty(queue) << endl;
    printQueue(queue);
    destroyQueue(queue);
    cout << "�����Ƿ�Ϊ�գ�" << isEmpty(queue) << endl;
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    // ����bool��ʽ��������Ƿ�Ϊ�գ�
    cout << "�����Ƿ�Ϊ�գ�" << isEmpty(queue) << endl;
    printQueue(queue);
    system("pause");
    return 0;
}