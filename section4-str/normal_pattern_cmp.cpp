#include <bits/stdc++.h>
#define N 100
using namespace std;
/**
 * 它将主字符串与模式字符串进行比较，如果存在则返回模式字符串的第一个字符在主字符串中的索引，否则返回-1
 *
 * @param mainStr 要搜索的字符串。
 * @param str 要搜索的字符串
 *
 * @return 主字符串中子字符串的第一个字符的索引。
 */
int normalPatternCompare(string mainStr, string str)
{
    int k = 0;
    int i = k, j = 0;
    while (i < mainStr.length() && j < str.length())
    {
        if (mainStr[i] == str[j])
        {
            i++;
            j++;
        }
        else
        {
            k += 1;
            i = k;
            j = 0;
        }
    }
    if (j == str.length())
    {
        return k;
    }
    else
    {
        return -1;
    }
}
int main()
{
    string mainStr = "hello world";
    string str = "world";
    cout << normalPatternCompare(mainStr, str) << endl;
    system("pause");
    return 0;
}