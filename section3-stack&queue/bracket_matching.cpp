#include <bits/stdc++.h>
#define N 100
using namespace std;
/*
This function takes in a string and checks if the brackets inside the string are balanced.
It uses a stack to store the opening brackets and pops them off as it encounters closing brackets.
If the top of the stack is not the corresponding opening bracket, we return false.
If the stack is empty at the end, we return true.
*/
bool check(string &str)
{
    stack<char> s;
    for (auto &ch : str)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch); // if the character is a opening bracket, push it into the stack
        }
        else
        {
            if (s.empty()) // if the stack is empty, return false
                return false;
            char t = s.top();          // get the top character of the stack
            s.pop();                   // pop the top character off the stack
            if (ch == ')' && t != '(') // if the current character is a closing bracket and the top character is not the corresponding opening bracket, return false
                return false;
            if (ch == ']' && t != '[')
                return false;
            if (ch == '}' && t != '{')
                return false;
        }
    }
    return s.empty(); // if the stack is empty, return true
}

bool check(string &str)
{
    stack<char> s;
    for (auto &ch : str)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch); // if the character is a opening bracket, push it into the stack
        }
        else
        {
            if (s.empty()) // if the stack is empty, return false
                return false;
            char t = s.top();          // get the top character of the stack
            s.pop();                   // pop the top character off the stack
            if (ch == ')' && t != '(') // if the current character is a closing bracket and the top character is not the corresponding opening bracket, return false
                return false;
            if (ch == ']' && t != '[')
                return false;
            if (ch == '}' && t != '{')
                return false;
        }
    }
    return s.empty(); // if the stack is empty, return true
}
int main()
{
    cout << "ÇëÊäÈë×Ö·û´®£º";
    string str;
    cin >> str;
    cout << (check(str) ? "Æ¥Åä³É¹¦" : "Æ¥ÅäÊ§°Ü") << endl;
    system("pause");
    return 0;
}