/**
 * @file prim.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 使用Prim算法求解最小生成树
 * @version 0.1
 * @date 2023-04-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100
// 使用Prim算法求解最小生成树
int _map[N + 1][N + 1]; // 邻接矩阵
int lowcost[N + 1];     // 顶点到集合的最小权值
int closest[N + 1];     // 顶点到集合的最小权值的顶点
using namespace std;
/**
 * 该函数通过将所有值设置为 0 然后根据用户输入设置特定值来初始化表示地图的二维数组。
 *
 * @param n 图中的节点数。
 * @param m 参数“m”表示图中的边数。
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
 * 该函数实现了 Prim 算法以查找给定图的最小生成树。
 *
 * @param n 图中的顶点数。
 */
void prim(int n)
{
    int i, j, k, min;
    for (i = 2; i <= n; i++)
    {
        lowcost[i] = _map[1][i]; // 其他顶点到最小生成树集合的最小权值
        closest[i] = 1;          // 其他顶点到最小生成树集合最近的顶点
    }
    for (i = 2; i <= n; i++) // 选择n-1条边
    {
        min = INT_MAX;
        for (j = 2; j <= n; j++) // 找到到最小生成树集合最小权值的顶点
        {
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j]; // 记录最小的权值
                k = j;            // 记录最小权值的顶点
            }
        }
        cout << k << " " << closest[k] << endl; // 输出最小生成树的一条边
        lowcost[k] = 0;                         // 将顶点k加入最小生成树集合
        for (j = 2; j <= n; j++)
        {
            if (_map[k][j] != 0 && _map[k][j] < lowcost[j]) // 更新其他顶点到最小生成树集合的最小权值
            {
                lowcost[j] = _map[k][j]; // 更新最小权值
                closest[j] = k;          // 更新最小权值的顶点
            }
        }
    }
}
int main()
{
    int n, m; // n个顶点，m条边
    cin >> n >> m;
    initMap(n, m);
    prim(n);
    system("pause");
    return 0;
}