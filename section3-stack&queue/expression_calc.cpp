#include <bits/stdc++.h>
#define N 100
using namespace std;
stack<char> s;
/**
 * 它计算表达式的值。
 *
 * @param expression 仅包含非负整数、+、-、*、/ 运算符和空格的表达式字符串。整数除法应截断为零。
 *
 * @return 表达式的结果。
 */
double calcExpression(string expression)
{
    for (auto &ch : expression)
    {
        // 判断ch是不是数字
        if (ch >= '0' && ch <= '9')
        {
            s.push(ch);
        }
        else
        {
            int num1, num2;
            switch (ch)
            {
            case '+':
                num1 = s.top() - '0';
                s.pop();
                num2 = s.top() - '0';
                s.pop();
                s.push(num1 + num2 + '0');
                break;
            case '-':
                num1 = s.top() - '0';
                s.pop();
                num2 = s.top() - '0';
                s.pop();
                s.push(num1 - num2 + '0');
                break;
            case '*':
                num1 = s.top() - '0';
                s.pop();
                num2 = s.top() - '0';
                s.pop();
                s.push(num1 * num2 + '0');
                break;
            case '/':
                num1 = s.top() - '0';
                s.pop();
                num2 = s.top() - '0';
                s.pop();
                s.push(num2 / num1 + '0');
                break;
            default:
                break;
            }
        }
    }
    return s.top() - '0';
}
int main()
{
    string expression = "321+*21+/";
    cout << "ans: " << calcExpression(expression) << endl;
    system("pause");
    return 0;
}