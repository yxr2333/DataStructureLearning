#include <bits/stdc++.h>
#include <stack>
#define N 100
using namespace std;
// ʹ������ջʵ���������޵�˫�˶���
typedef struct InputRestrictQueue
{
    stack<int> inputStack;
    stack<int> outputStack;
} MyQueue;
/**
 * ���������������ջ��
 *
 * @param obj ����Ҫ��ʼ���Ķ���
 */
void initQueue(MyQueue *obj)
{
    while (!obj->inputStack.empty())
    {
        obj->inputStack.pop();
    }
    while (!obj->outputStack.empty())
    {
        obj->outputStack.pop();
    }
}
void push(MyQueue *obj, int x)
{
    obj->inputStack.push(x);
}
/**
 * ������ջΪ�գ�������ջ�е�����Ԫ�ص�����ѹ�����ջ
 *
 * @param obj ������һ���д����Ķ��С�
 *
 * @return �����ջ�Ķ���Ԫ�ء�
 */
int pop(MyQueue *obj)
{
    if (obj->outputStack.empty())
    {
        while (!obj->inputStack.empty())
        {
            obj->outputStack.push(obj->inputStack.top());
            obj->inputStack.pop();
        }
    }
    int res = obj->outputStack.top();
    obj->outputStack.pop();
    return res;
}
int top(MyQueue *obj)
{
    if (obj->outputStack.empty())
    {
        while (!obj->inputStack.empty())
        {
            obj->outputStack.push(obj->inputStack.top());
            obj->inputStack.pop();
        }
    }
    return obj->outputStack.top();
}
bool empty(MyQueue *obj)
{
    return obj->inputStack.empty() && obj->outputStack.empty();
}
void freeQueue(MyQueue *obj)
{
    while (!obj->inputStack.empty())
    {
        obj->inputStack.pop();
    }
    while (!obj->outputStack.empty())
    {
        obj->outputStack.pop();
    }
}
int main()
{
    InputRestrictQueue *queue = new InputRestrictQueue();
    initQueue(queue);
    for (int i = 0; i < 10; i++)
    {
        push(queue, i + 1);
    }
    // printQueue(queue);
    cout << "top 1: " << top(queue) << endl;
    cout << "pop 1: " << pop(queue) << endl;
    cout << "top 2: " << top(queue) << endl;
    cout << "pop 2: " << pop(queue) << endl;
    system("pause");
    return 0;
}