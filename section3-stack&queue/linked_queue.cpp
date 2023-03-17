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
    cout << "元素: " << val << " 已插入队列" << endl;
}
bool isEmpty(LinkQueue *queue)
{
    return queue->front == queue->rear;
}
int pop(LinkQueue *queue)
{
    if (isEmpty(queue))
    {
        cout << "队列为空，不能出队" << endl;
        return -1;
    }
    LinkNode *s = queue->front->next;
    int ans = s->data;
    queue->front->next = s->next;
    if (queue->rear == s) // 如果队列中只有一个元素，出队后队列为空，需要修改队尾指针
    {
        queue->front = queue->rear;
    }
    free(s);
    return ans;
}
/**
 * 打印队列中的元素。
 *
 * @param queue 要打印的队列
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
        cout << "队列为空" << endl;
    }
}
/**
 * 上面的函数销毁队列。
 *
 * @param queue 要销毁的队列
 */
void destroyQueue(LinkQueue *queue)
{
    // 销毁队列：重复出队操作，直到队列为空
    while (!isEmpty(queue))
    {
        pop(queue);
    }
}
int main()
{
    LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
    initQueue(queue);
    cout << "队列是否为空：" << isEmpty(queue) << endl;
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    // 按照bool格式输出队列是否为空：
    cout << "队列是否为空：" << isEmpty(queue) << endl;
    printQueue(queue);
    cout << "出队元素：" << pop(queue) << endl;
    cout << "出队元素：" << pop(queue) << endl;
    cout << "出队元素：" << pop(queue) << endl;
    cout << "队列是否为空：" << isEmpty(queue) << endl;
    printQueue(queue);
    destroyQueue(queue);
    cout << "队列是否为空：" << isEmpty(queue) << endl;
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    // 按照bool格式输出队列是否为空：
    cout << "队列是否为空：" << isEmpty(queue) << endl;
    printQueue(queue);
    system("pause");
    return 0;
}