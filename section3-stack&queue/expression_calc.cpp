#include <bits/stdc++.h>
#define N 100
using namespace std;
stack<char> s;
/**
 * ��������ʽ��ֵ��
 *
 * @param expression �������Ǹ�������+��-��*��/ ������Ϳո�ı��ʽ�ַ�������������Ӧ�ض�Ϊ�㡣
 *
 * @return ���ʽ�Ľ����
 */
double calcExpression(string expression)
{
    for (auto &ch : expression)
    {
        // �ж�ch�ǲ�������
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