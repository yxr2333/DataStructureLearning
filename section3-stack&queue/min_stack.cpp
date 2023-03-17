#include <bits/stdc++.h>
#define N 100
using namespace std;
struct MinStack
{
    stack<int> normal_stack;
    stack<int> min_stack;
    MinStack()
    {
        normal_stack = stack<int>();
        min_stack = stack<int>();
    }
    void push(int x)
    {
        normal_stack.push(x);
        if (min_stack.empty() || x <= min_stack.top())
        {
            min_stack.push(x);
        }
        else
        {
            min_stack.push(min_stack.top());
        }
    }
    void pop()
    {
        normal_stack.pop();
        min_stack.pop();
    }
    int top()
    {
        return normal_stack.top();
    }
    int getMin()
    {
        return min_stack.top();
    }
};
int main()
{
    // 随机数
    srand((unsigned)time(NULL));
    MinStack minStack = MinStack();
    for (int i = 0; i < 10; i++)
    {
        int x = rand() % 100;
        minStack.push(x);
        cout << "元素 " << x << " 入栈" << endl;
        cout << "当前最小值为 " << minStack.getMin() << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "元素 " << minStack.top() << " 出栈" << endl;
        minStack.pop();
        cout << "当前最小值为 " << minStack.getMin() << endl;
    }
    system("pause");
    return 0;
}