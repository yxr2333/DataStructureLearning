#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;
// 实现共享栈
typedef struct Stack
{
    int data[MAX_SIZE];
    int top1;
    int top2;
} ShareStack;

void initStack(ShareStack *stack)
{
    stack->top1 = -1;
    stack->top2 = MAX_SIZE;
}

void push(ShareStack *stack, int val, int stackNumber)
{
    if (stack->top1 + 1 == stack->top2)
    {
        cout << "栈满，无法入栈" << endl;
        return;
    }
    if (stackNumber == 1)
    {
        stack->data[++stack->top1] = val;
    }
    else if (stackNumber == 2)
    {
        stack->data[--stack->top2] = val;
    }
    else
    {
        cout << "请输入正确的栈号" << endl;
    }
}

void pop(ShareStack *stack, int stackNumber)
{
    if (stackNumber == 1)
    {
        if (stack->top1 == -1)
        {
            cout << "栈1空，无法出栈" << endl;
            return;
        }
        cout << "栈1出栈元素：" << stack->data[stack->top1--] << endl;
    }
    else if (stackNumber == 2)
    {
        if (stack->top2 == MAX_SIZE)
        {
            cout << "栈2空，无法出栈" << endl;
            return;
        }
        cout << "栈2出栈元素：" << stack->data[stack->top2++] << endl;
    }
    else
    {
        cout << "请输入正确的栈号" << endl;
    }
}

int main()
{
    ShareStack *stack = (ShareStack *)malloc(sizeof(ShareStack));
    initStack(stack);
    for (int i = 0; i < 10; i++)
    {
        push(stack, i, 1);
    }
    for (int i = 0; i < 10; i++)
    {
        push(stack, i, 2);
    }
    for (int i = 0; i < 10; i++)
    {
        pop(stack, 1);
    }
    for (int i = 0; i < 10; i++)
    {
        pop(stack, 2);
    }
    system("pause");
    return 0;
}