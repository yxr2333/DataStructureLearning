#include <bits/stdc++.h>
#define N 100
using namespace std;
// ����ͷ������ջ
typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode, LinkStack;

/**
 * ����ʼ����ջ��
 *
 * @param stack Ҫ��ʼ����ջ
 */
void initStack(LinkStack *&stack)
{
    stack = NULL;
}

/**
 * ��ֵѹ���ջ��
 *
 * @param stack ��ջָ��
 * @param val Ҫѹ���ջ��ֵ
 */
void push(LinkStack *&stack, int val)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = val;
    p->next = stack;
    stack = p;
    cout << "Ԫ�أ�" << val << "��ջ�ɹ�" << endl;
}

/**
 * ����ĺ�������ջ��Ԫ�ء�
 *
 * @param stack Ҫ�����Ķ�ջ
 *
 * @return ջ��Ԫ�ص�ֵ��
 */
int pop(LinkStack *&stack)
{
    if (stack == NULL)
    {
        cout << "ջ�գ��޷���ջ" << endl;
        return -1;
    }
    StackNode *p = stack;
    stack = p->next;
    int val = p->data;
    free(p);
    return val;
}

/**
 * �����ջΪ�գ��򷵻� true�����򷵻ؼ�
 *
 * @param stack Ҫ�жϵ�ջ
 *
 * @return һ������ֵ��
 */
bool empty(LinkStack *stack)
{
    return stack == NULL;
}

/**
 * ���ƻ��˶�ջ��
 *
 * @param stack Ҫ���ٵĶ�ջ
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
        cout << "��ջԪ�أ�" << pop(stack) << endl;
    }
    destory(stack);
    system("pause");
    return 0;
}