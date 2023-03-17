#include <bits/stdc++.h>
#define N 100
using namespace std;
int _next[N + 1];
int kmpPatternCmp(string mainStr, string patterStr)
{
    int n = mainStr.length();
    int m = patterStr.length();
    if (m == 0)
        return 0;

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (j == -1 || mainStr[i] == patterStr[j])
        {
            i++;
            j++;
        }
        else
        {
            j = _next[j];
        }
    }
    if (j == m)
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}
void getNext(string patterStr)
{
    int i = 0, j = -1;
    _next[0] = -1;
    while (i < patterStr.length())
    {
        if (j == -1 || patterStr[i] == patterStr[j])
        {
            i++;
            j++;
            _next[i] = j;
        }
        else
        {
            j = _next[j];
        }
    }
}
int main()
{
    string mainStr = "goollegoogle";
    string patternStr = "google";
    getNext(patternStr);
    cout << kmpPatternCmp(mainStr, patternStr) << endl;
    system("pause");
    return 0;
}