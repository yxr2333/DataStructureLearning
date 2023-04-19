/**
 * @file linear_search.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 线性查找顺序表和链表
 * @version 0.1
 * @date 2023-04-19
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100
using namespace std;

int find_v(vector<int> &v, int val)
{
    for (const auto &i : v)
    {
        if (i == val)
        {
            return i;
        }
    }
    return INT_MIN;
}

int find_l(list<int> &l, int val)
{
    for (const auto &i : l)
    {
        if (i == val)
        {
            return i;
        }
    }
    return INT_MIN;
}
void init(vector<int> &v, list<int> &l, int n)
{
    for (int i = 0; i < n; i++)
    {
        v.push_back(i + 1);
        l.push_back(i + 1);
    }
}
int main()
{
    vector<int> v;
    list<int> l;
    int n = 0;
    cout << "请输入元素的个数：" << endl;
    cin >> n;
    init(v, l, n);
    int val_v = find_v(v, 5);
    int val_l = find_l(l, 5);
    if (val_v == INT_MIN)
    {
        cout << "顺序表中没有该元素" << endl;
    }
    else
    {
        cout << "顺序表中有该元素" << endl;
    }
    if (val_l == INT_MIN)
    {
        cout << "链表中没有该元素" << endl;
    }
    else
    {
        cout << "链表中有该元素" << endl;
    }
    system("pause");
    return 0;
}