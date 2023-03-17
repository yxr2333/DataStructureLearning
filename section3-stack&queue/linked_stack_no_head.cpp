#include <bits/stdc++.h>
#define N 100
using namespace std;
// 不带头结点的链栈
typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode, LinkStack;

/**
 * 它初始化堆栈。
 *
 * @param stack 要初始化的栈
 */
void initStack(LinkStack *&stack)
{
    stack = NULL;
}

/**
 * 将值压入堆栈。
 *
 * @param stack 堆栈指针
 * @param val 要压入堆栈的值
 */
void push(LinkStack *&stack, int val)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = val;
    p->next = stack;
    stack = p;
    cout << "元素：" << val << "入栈成功" << endl;
}

/**
 * 上面的函数弹出栈顶元素。
 *
 * @param stack 要弹出的堆栈
 *
 * @return 栈顶元素的值。
 */
int pop(LinkStack *&stack)
{
    if (stack == NULL)
    {
        cout << "栈空，无法出栈" << endl;
        return -1;
    }
    StackNode *p = stack;
    stack = p->next;
    int val = p->data;
    free(p);
    return val;
}

/**
 * 如果堆栈为空，则返回 true。否则返回假
 *
 * @param stack 要判断的栈
 *
 * @return 一个布尔值。
 */
bool empty(LinkStack *stack)
{
    return stack == NULL;
}

/**
 * 它破坏了堆栈。
 *
 * @param stack 要销毁的堆栈
 */
void destory(LinkStack *&stack)
{
    while (stack != NULL)
    {
        StackNode *p = stack;
        stack = p->next;
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
        cout << "出栈元素：" << pop(stack) << endl;
    }
    destory(stack);
    system("pause");
    return 0;
}