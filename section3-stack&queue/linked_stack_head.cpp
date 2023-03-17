#include <bits/stdc++.h>
#define N 100
using namespace std;
// 链栈的结构体
typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode, LinkStack;

/**
 * 初始化堆栈。
 *
 * @param stack 要初始化的栈
 */
void initStack(LinkStack *stack)
{
    stack->next = NULL;
}

/**
 * 将值压入堆栈。
 *
 * @param stack 要压入的栈
 * @param val 要压入堆栈的值
 */
void push(LinkStack *stack, int val)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = val;
    p->next = stack->next;
    stack->next = p;
    cout << "元素：" << val << "入栈成功" << endl;
}

void pop(LinkStack *stack)
{
    if (stack->next == NULL)
    {
        cout << "栈空，无法出栈" << endl;
        return;
    }
    StackNode *p = stack->next;
    stack->next = p->next;
    free(p);
}

bool empty(LinkStack *stack)
{
    return stack->next == NULL;
}

void destroy(LinkStack *stack)
{
    while (stack->next != NULL)
    {
        StackNode *p = stack->next;
        stack->next = p->next;
        free(p);
    }
}
int main()
{
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
    initStack(stack);
    for (int i = 0; i < 10; i++)
    {
        push(stack, i);
    }
    while (!empty(stack))
    {
        cout << stack->next->data << endl;
        pop(stack);
    }
    destroy(stack);
    system("pause");
    return 0;
}