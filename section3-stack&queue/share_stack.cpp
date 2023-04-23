#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;
// 实现共享栈
/**
 * 定义了一个名为 ShareStack 的结构，它表示一个具有两个顶部的共享堆栈。
 * @property {int} data - 存储堆栈元素的整数数组。
 * @property {int} top1 - 共享堆栈实现中第一个堆栈的顶部索引。
 * @property {int} top2 - “ShareStack”结构中的“top2”属性是共享堆栈实现中第二个堆栈的顶部指针。
 * 在共享堆栈中，两个堆栈共享同一个底层数组，“top1”和“top2”指针跟踪每个堆栈的顶部元素
 */
typedef struct Stack
{
    int data[MAX_SIZE];
    int top1;
    int top2;
} ShareStack;

/**
 * 该函数通过将顶部指针设置为 -1 和 MAX_SIZE 来初始化共享堆栈。
 *
 * @param stack 指向 ShareStack 结构的指针，其中包含两个整数变量 top1 和 top2。
 */
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