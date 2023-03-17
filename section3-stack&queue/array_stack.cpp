#include <bits/stdc++.h>
#define N 5
#define MAX_SIZE 5
using namespace std;
typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;
void initStack(Stack *stack)
{
    stack->top = -1;
}
void push(Stack *stack, int val)
{
    if (stack->top == MAX_SIZE - 1)
    {
        cout << "ջ�����޷���ջ" << endl;
        return;
    }
    stack->data[++stack->top] = val;
    cout << "��ջ�ɹ�" << endl;
}
/**
 * ���ջΪ�գ����ӡ������Ϣ������-1�����򣬷���ջ��Ԫ�ز��ݼ�ջ��ָ��
 *
 * @param stack Ҫ������ջ
 *
 * @return ջ��Ԫ�ء�
 */
int pop(Stack *stack)
{
    if (stack->top == -1)
    {
        cout << "ջ�գ��޷���ջ" << endl;
        return -1;
    }
    return stack->data[stack->top--];
}
/**
 * ���ջ������-1����ջΪ��
 *
 * @param stack Ҫ���Ķ�ջ��
 *
 * @return ջ��
 */
bool empty(Stack *stack)
{
    return stack->top == -1;
}
void destroy(Stack *stack)
{
    free(stack);
}
int main()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    initStack(stack);
    for (int i = 0; i < 10; i++)
    {
        push(stack, i + 1);
    }
    while (!empty(stack))
    {
        cout << pop(stack) << endl;
    }
    destroy(stack);
    system("pause");
    return 0;
}