#include <bits/stdc++.h>
#define N 100
using namespace std;
/**
 * �������ַ�����ģʽ�ַ������бȽϣ���������򷵻�ģʽ�ַ����ĵ�һ���ַ������ַ����е����������򷵻�-1
 *
 * @param mainStr Ҫ�������ַ�����
 * @param str Ҫ�������ַ���
 *
 * @return ���ַ��������ַ����ĵ�һ���ַ���������
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