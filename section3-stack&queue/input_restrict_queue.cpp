#include <bits/stdc++.h>
#include <stack>
#define N 100
using namespace std;
// 使用两个栈实现输入受限的双端队列
typedef struct InputRestrictQueue
{
    stack<int> inputStack;
    stack<int> outputStack;
} MyQueue;
/**
 * 它清除输入和输出堆栈。
 *
 * @param obj 我们要初始化的队列
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
 * 如果输出栈为空，则将输入栈中的所有元素弹出，压入输出栈
 *
 * @param obj 您在上一步中创建的队列。
 *
 * @return 输出堆栈的顶部元素。
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