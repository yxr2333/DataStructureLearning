#include <bits/stdc++.h>
#define N 100
using namespace std;
string convertToBack(string expression)
{
    stack<char> s;
    string backExpression;
    for (auto &ch : expression)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            backExpression += ch;
        }
        else
        {
            if (ch == '(')
            {
                s.push(ch);
            }
            else if (ch == ')')
            {
                while (s.top() != '(')
                {
                    backExpression += s.top();
                    s.pop();
                }
                s.pop();
            }
            else
            {
                while (!s.empty() && s.top() != '(')
                {
                    backExpression += s.top();
                    s.pop();
                }
                s.push(ch);
            }
        }
    }
    while (!s.empty())
    {
        backExpression += s.top();
        s.pop();
    }
    return backExpression;
}
string convertToBackNumber(string expression)
{
    stack<char> s;         // 符号栈
    string backExpression; // 后缀表达式
    for (auto &ch : expression)
    {
        if (isdigit(ch))
        {
            backExpression.push_back(ch);
        }
        else
        {
            if (ch == '(')
            {
                s.push(ch);
            }
            else if (ch == ')')
            {
                while (s.top() != '(')
                {
                    backExpression.push_back(s.top());
                    s.pop();
                }
                s.pop();
            }
            else
            {
                while (!s.empty() && s.top() != '(')
                {
                    backExpression.push_back(s.top());
                    s.pop();
                }
                s.push(ch);
            }
        }
    }
    while (!s.empty())
    {
        backExpression.push_back(s.top());
        s.pop();
    }
    return backExpression;
}
int main()
{
    string midExpression = "A+B*C+(D*E+F)*G";
    cout << convertToBack(midExpression) << endl;
    string expression = "1+2*3+(4*5+6)*7";
    cout << convertToBackNumber(expression) << endl;
    system("pause");
    return 0;
}