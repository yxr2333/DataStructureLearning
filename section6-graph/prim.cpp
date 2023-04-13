#include <bits/stdc++.h>
#define N 100
// 使用Prim算法求解最小生成树
int _map[N + 1][N + 1]; // 邻接矩阵
int lowcost[N + 1];     // 顶点到集合的最小权值
int closest[N + 1];     // 顶点到集合的最小权值的顶点
using namespace std;
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
int main()
{
    int n, m; // n个顶点，m条边
    cin >> n >> m;
    initMap(n, m);
    int i, j, k, min;
    for (i = 2; i <= n; i++)
    {
        lowcost[i] = _map[1][i];
        closest[i] = 1;
    }
    for (i = 2; i <= n; i++)
    {
        min = INT_MAX;
        for (j = 2; j <= n; j++)
        {
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
        }
        cout << k << " " << closest[k] << endl;
        lowcost[k] = 0;
        for (j = 2; j <= n; j++)
        {
            if (_map[k][j] != 0 && _map[k][j] < lowcost[j])
            {
                lowcost[j] = _map[k][j];
                closest[j] = k;
            }
        }
    }
    system("pause");
    return 0;
}