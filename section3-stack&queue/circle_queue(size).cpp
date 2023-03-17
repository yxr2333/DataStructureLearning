#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;
typedef struct
{
    int data[MAX_SIZE];
    int front, rear;
    int size;
} CircleQueue;
void initQueue(CircleQueue *q)
{
    q->front = q->rear = 0;
    q->size = 0;
}
bool push(CircleQueue *q, int val)
{
    if (q->size == MAX_SIZE)
    {
        cout << "队列已满" << endl;
        return false;
    }
    q->data[q->rear] = val;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->size++;
    return true;
}
int pop(CircleQueue *q)
{
    if (q->size == 0)
    {
        cout << "队列为空" << endl;
        return INT_MIN;
    }
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return val;
}
int getLength(CircleQueue *q)
{
    return q->size;
}
void destoryQueue(CircleQueue *q)
{
    free(q);
}
bool isEmpty(CircleQueue *q)
{
    return q->size == 0;
}
int main()
{
    CircleQueue *q = (CircleQueue *)malloc(sizeof(CircleQueue));
    initQueue(q);
    cout << "队列是否为空：" << isEmpty(q) << endl;
    for (int i = 1; i <= 3; i++)
    {
        if (push(q, i))
        {
            cout << "元素：" << i << " 入队成功" << endl;
        }
        else
        {
            cout << "元素：" << i << " 入队失败" << endl;
        }
    }
    cout << "队列是否为空：" << isEmpty(q) << endl;
    cout << "队列长度：" << getLength(q) << endl;
    for (int i = 0; i < 4; i++)
    {
        int val = pop(q);
        if (val != INT_MIN)
        {
            cout << "元素：" << val << " 出队成功" << endl;
        }
        else
        {
            cout << "元素：" << val << " 出队失败" << endl;
        }
    }
    cout << "队列是否为空：" << isEmpty(q) << endl;
    cout << "队列长度：" << getLength(q) << endl;
    destoryQueue(q);
    system("pause");
    return 0;
}