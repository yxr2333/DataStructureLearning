/**
 * @file linked_stack_head.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ��ͷ���ĵ�����ʵ�ֵ���ջ
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
 * �������Ͷ�����һ����ջ�ڵ�ṹ�����а����������ݺ�ָ����һ���ڵ��ָ�롣
 * @property {int} data - һ�����ͱ������洢ջ�нڵ�����ݡ�
 * @property next - ��next����ָ����������һ���ڵ��ָ�롣����������£���ָ���ջ�е���һ���ڵ㡣
 */
typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode, LinkStack;

/**
 * ��ʼ����ջ��
 *
 * @param stack Ҫ��ʼ����ջ
 */
void initStack(LinkStack *stack)
{
    stack->next = NULL;
}

/**
 * ��ֵѹ���ջ��
 *
 * @param stack Ҫѹ���ջ
 * @param val Ҫѹ���ջ��ֵ
 */
void push(LinkStack *stack, int val)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = val;
    p->next = stack->next;
    stack->next = p;
    cout << "Ԫ�أ�" << val << "��ջ�ɹ�" << endl;
}

/**
 * ������pop�������ӵĶ�ջ��ɾ������Ԫ�أ������ջΪ���򷵻ش�����Ϣ��
 *
 * @param stack ָ�����Ӷ�ջ�Ķ����ڵ��ָ�롣
 *
 * @return ʲô��û�У���Ч����
 */
void pop(LinkStack *stack)
{
    if (stack->next == NULL)
    {
        cout << "ջ�գ��޷���ջ" << endl;
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
 * �ú���ͨ���ͷ������нڵ����������Ӷ�ջ��
 *
 * @param stack ָ�� LinkStack �ṹ��ָ�룬����ʾ��ջ������ʵ�֡�
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