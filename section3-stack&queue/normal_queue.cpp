#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;
typedef struct
{
    int data[MAX_SIZE];
    int front, rear;
} NormalQueue;

void initQueue(NormalQueue *queue)
{
    queue->front = queue->rear = 0;
}

void push(NormalQueue *queue, int x)
{
    if (queue->rear == MAX_SIZE)
    {
        printf("队列已满\n");
        return;
    }
    queue->data[queue->rear++] = x;
}

int pop(NormalQueue *queue)
{
    if (queue->front == queue->rear)
    {
        printf("队列为空\n");
        return -1;
    }
    return queue->data[queue->front++];
}

int main()
{
    NormalQueue *queue = (NormalQueue *)malloc(sizeof(NormalQueue));
    initQueue(queue);
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    cout << pop(queue) << endl;
    cout << pop(queue) << endl;
    system("pause");
    return 0;
}