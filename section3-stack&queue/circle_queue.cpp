#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;
typedef struct
{
    int data[MAX_SIZE];
    int front, rear;
} CircleQueue;
/**
 * 该函数将队列的前后指针初始化为0。
 *
 * @param queue 要初始化的队列。
 */
void initQueue(CircleQueue *queue)
{
    queue->front = queue->rear = 0;
}
void push(CircleQueue *queue, int x)
{
    // 队列满的条件是：(rear + 1) % MAX_SIZE == front
    if ((queue->rear + 1) % MAX_SIZE == queue->front)
    {
        printf("队列已满\n");
        return;
    }
    queue->data[queue->rear] = x;
    queue->rear = (queue->rear + 1) % MAX_SIZE; // 先赋值，再移动指针
    cout << "元素：" << x << " 入队成功" << endl;
}
void pop(CircleQueue *queue)
{
    if (queue->front == queue->rear)
    {
        printf("队列为空\n");
        return;
    }
    cout << "元素：" << queue->data[queue->front] << " 出队成功" << endl;
    queue->front = (queue->front + 1) % MAX_SIZE; // 队头指针向前移动一位
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
    cout << "队列是否为空：" << isEmpty(queue) << endl;
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    cout << "队列是否为空：" << isEmpty(queue) << endl;
    cout << "队列长度：" << getLength(queue) << endl;
    pop(queue);
    cout << "队列长度：" << getLength(queue) << endl;
    destoryQueue(queue);
    system("pause");
    return 0;
}