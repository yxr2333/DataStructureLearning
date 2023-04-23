/**
 * @file linked_stack_head.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 带头结点的单链表实现的链栈
 * @version 0.1
 * @date 2023-04-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100
using namespace std;

/**
 * 上述类型定义了一个堆栈节点结构，其中包含整数数据和指向下一个节点的指针。
 * @property {int} data - 一个整型变量，存储栈中节点的数据。
 * @property next - “next”是指向链表中下一个节点的指针。在这种情况下，它指向堆栈中的下一个节点。
 */
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

/**
 * 函数“pop”从链接的堆栈中删除顶部元素，如果堆栈为空则返回错误消息。
 *
 * @param stack 指向链接堆栈的顶部节点的指针。
 *
 * @return 什么都没有（无效）。
 */
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

/**
 * 该函数通过释放其所有节点来销毁链接堆栈。
 *
 * @param stack 指向 LinkStack 结构的指针，它表示堆栈的链表实现。
 */
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