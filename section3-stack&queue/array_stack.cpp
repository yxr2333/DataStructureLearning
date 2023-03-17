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
        cout << "栈满，无法入栈" << endl;
        return;
    }
    stack->data[++stack->top] = val;
    cout << "入栈成功" << endl;
}
/**
 * 如果栈为空，则打印错误信息并返回-1；否则，返回栈顶元素并递减栈顶指针
 *
 * @param stack 要操作的栈
 *
 * @return 栈顶元素。
 */
int pop(Stack *stack)
{
    if (stack->top == -1)
    {
        cout << "栈空，无法出栈" << endl;
        return -1;
    }
    return stack->data[stack->top--];
}
/**
 * 如果栈顶等于-1，则栈为空
 *
 * @param stack 要检查的堆栈。
 *
 * @return 栈顶
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