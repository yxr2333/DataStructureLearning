/**
 * @file array_stack.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 顺序栈：使用数组实现的栈
 * @version 0.1
 * @date 2023-04-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 5
#define MAX_SIZE 5
using namespace std;
typedef struct
{
    int data[MAX_SIZE];
    int top; // 栈顶指针
} Stack;
void initStack(Stack *stack)
{
    stack->top = -1;
}
/**
 * 函数“push”将一个整数值添加到堆栈数据结构中，并打印一条消息指示操作是否成功。
 *
 * @param stack 指向 Stack 结构的指针，它包含一个整数数组和一个指示堆栈顶部索引的变量。
 * @param val val 是需要压入堆栈的整数值。
 *
 * @return 如果条件 `stack->top == MAX_SIZE - 1` 为真，函数返回而不将值压入堆栈。否则，该函数会将值压入堆栈并打印一条成功消息，但不会显式返回任何内容。
 */
void push(Stack *stack, int val)
{
    if (stack->top == MAX_SIZE - 1)
    {
        cout << "栈满，无法入栈" << endl;
        return;
    }
    stack->data[++(stack->top)] = val;
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
    return stack->data[(stack->top)--];
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