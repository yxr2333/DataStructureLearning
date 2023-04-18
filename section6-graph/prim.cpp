/**
 * @file prim.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ʹ��Prim�㷨�����С������
 * @version 0.1
 * @date 2023-04-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100
// ʹ��Prim�㷨�����С������
int _map[N + 1][N + 1]; // �ڽӾ���
int lowcost[N + 1];     // ���㵽���ϵ���СȨֵ
int closest[N + 1];     // ���㵽���ϵ���СȨֵ�Ķ���
using namespace std;
/**
 * �ú���ͨ��������ֵ����Ϊ 0 Ȼ������û����������ض�ֵ����ʼ����ʾ��ͼ�Ķ�ά���顣
 *
 * @param n ͼ�еĽڵ�����
 * @param m ������m����ʾͼ�еı�����
 */
void initMap(int n, int m)
{
    int i, j, k, w;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            _map[i][j] = 0;
        }
    }
    for (k = 1; k <= m; k++)
    {
        cin >> i >> j >> w;
        _map[i][j] = w;
        _map[j][i] = w;
    }
}
/**
 * �ú���ʵ���� Prim �㷨�Բ��Ҹ���ͼ����С��������
 *
 * @param n ͼ�еĶ�������
 */
void prim(int n)
{
    int i, j, k, min;
    for (i = 2; i <= n; i++)
    {
        lowcost[i] = _map[1][i]; // �������㵽��С���������ϵ���СȨֵ
        closest[i] = 1;          // �������㵽��С��������������Ķ���
    }
    for (i = 2; i <= n; i++) // ѡ��n-1����
    {
        min = INT_MAX;
        for (j = 2; j <= n; j++) // �ҵ�����С������������СȨֵ�Ķ���
        {
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j]; // ��¼��С��Ȩֵ
                k = j;            // ��¼��СȨֵ�Ķ���
            }
        }
        cout << k << " " << closest[k] << endl; // �����С��������һ����
        lowcost[k] = 0;                         // ������k������С����������
        for (j = 2; j <= n; j++)
        {
            if (_map[k][j] != 0 && _map[k][j] < lowcost[j]) // �����������㵽��С���������ϵ���СȨֵ
            {
                lowcost[j] = _map[k][j]; // ������СȨֵ
                closest[j] = k;          // ������СȨֵ�Ķ���
            }
        }
    }
}
int main()
{
    int n, m; // n�����㣬m����
    cin >> n >> m;
    initMap(n, m);
    prim(n);
    system("pause");
    return 0;
}