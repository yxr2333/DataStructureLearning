#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;
typedef struct
{
    int data[MAX_SIZE];
    int front, rear;
} CircleQueue;
/**
 * �ú��������е�ǰ��ָ���ʼ��Ϊ0��
 *
 * @param queue Ҫ��ʼ���Ķ��С�
 */
void initQueue(CircleQueue *queue)
{
    queue->front = queue->rear = 0;
}
void push(CircleQueue *queue, int x)
{
    // �������������ǣ�(rear + 1) % MAX_SIZE == front
    if ((queue->rear + 1) % MAX_SIZE == queue->front)
    {
        printf("��������\n");
        return;
    }
    queue->data[queue->rear] = x;
    queue->rear = (queue->rear + 1) % MAX_SIZE; // �ȸ�ֵ�����ƶ�ָ��
    cout << "Ԫ�أ�" << x << " ��ӳɹ�" << endl;
}
void pop(CircleQueue *queue)
{
    if (queue->front == queue->rear)
    {
        printf("����Ϊ��\n");
        return;
    }
    cout << "Ԫ�أ�" << queue->data[queue->front] << " ���ӳɹ�" << endl;
    queue->front = (queue->front + 1) % MAX_SIZE; // ��ͷָ����ǰ�ƶ�һλ
}
int getLength(CircleQueue *queue)
{
    return (queue->rear - queue->front + MAX_SIZE) % MAX_SIZE;
}
void destoryQueue(CircleQueue *queue)
{
    free(queue);
}
bool isEmpty(CircleQueue *queue)
{
    return queue->front == queue->rear;
}
int main()
{
    CircleQueue *queue = (CircleQueue *)malloc(sizeof(CircleQueue));
    initQueue(queue);
    cout << "�����Ƿ�Ϊ�գ�" << isEmpty(queue) << endl;
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    cout << "�����Ƿ�Ϊ�գ�" << isEmpty(queue) << endl;
    cout << "���г��ȣ�" << getLength(queue) << endl;
    pop(queue);
    cout << "���г��ȣ�" << getLength(queue) << endl;
    destoryQueue(queue);
    system("pause");
    return 0;
}