#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;
// ʵ�ֹ���ջ
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
        cout << "ջ�����޷���ջ" << endl;
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
        cout << "��������ȷ��ջ��" << endl;
    }
}

void pop(ShareStack *stack, int stackNumber)
{
    if (stackNumber == 1)
    {
        if (stack->top1 == -1)
        {
            cout << "ջ1�գ��޷���ջ" << endl;
            return;
        }
        cout << "ջ1��ջԪ�أ�" << stack->data[stack->top1--] << endl;
    }
    else if (stackNumber == 2)
    {
        if (stack->top2 == MAX_SIZE)
        {
            cout << "ջ2�գ��޷���ջ" << endl;
            return;
        }
        cout << "ջ2��ջԪ�أ�" << stack->data[stack->top2++] << endl;
    }
    else
    {
        cout << "��������ȷ��ջ��" << endl;
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