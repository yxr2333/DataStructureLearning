/**
 * @file Dijkstra.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief  使用Dijkstra算法求解最短路径
 * @version 0.1
 * @date 2023-04-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100

using namespace std;

int n, m;               // n个顶点，m条边
int _map[N + 1][N + 1]; // 邻接矩阵
int dist[N + 1];        // dist数组，记录源点到各个顶点的最短距离
int path[N + 1];        // path数组，记录源点到各个顶点的最短路径

/**
 * 该函数使用最大整数值初始化一个二维数组，并根据用户输入将特定值分配给某些索引。
 */
void initMap()
{
    int i, j, k, w;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            _map[i][j] = INT_MAX;
        }
    }
    for (i = 1; i <= m; i++)
    {
        cin >> j >> k >> w;
        _map[j][k] = w;
    }
}

/**
 * 该函数实现了 Dijkstra 算法，以在由邻接矩阵表示的图中找到从起始顶点到所有其他顶点的最短路径。
 *
 * 1. 使用邻接矩阵和带权的邻接表存储图的信息时，求解最短路径的时间复杂度都是 O(V^2)。
 * 2. 由于求解源点到另外一个点的最短路径与求解源点到其他所有点的最短路径是同样复杂的，因此他们的时间复杂度都是O(V^2)。
 * 3. Dijkstra算法不能求解负权图的最短路径问题。
 * @param v_start 要找到最短路径的起始顶点。
 */
void dijkstra(int v_start)
{
    int i, j, k;
    bool visited[N + 1]; // 记录顶点是否被访问过
    memset(visited, false, sizeof(visited));
    visited[v_start] = true;
    for (i = 1; i <= n; i++)
    {
        dist[i] = _map[v_start][i]; // 最开始的时候，源点到各个顶点的最短距离就是邻接矩阵中的值
        if (dist[i] != INT_MAX)
        {
            path[i] = v_start; // 如果源点到顶点i有边，则顶点i的前驱就是源点
        }
    }
    for (i = 1; i <= n; i++)
    {
        int min = INT_MAX;
        for (j = 1; j <= n; j++)
        {
            if (!visited[j] && dist[j] < min) // 找到未访问的节点中距离源点距离最近的节点
            {
                min = dist[j];
                k = j;
            }
        }
        visited[k] = true; // 标记为已访问
        for (j = 1; j <= n; j++)
        {
            if (!visited[j] && _map[k][j] < INT_MAX) // 如果顶点j未被访问过，并且顶点k到顶点j有边
            {
                if (dist[j] > dist[k] + _map[k][j]) // 如果通过节点k中转，源点到顶点j的距离比原来的距离短
                {
                    dist[j] = dist[k] + _map[k][j]; // 更新源点到顶点j的距离
                    path[j] = k;                    // 更新顶点j的前驱
                }
            }
        }
    }
}

int main()
{
    int v_start = 1;
    cin >> n >> m;
    initMap();
    dijkstra(v_start);
    int i;
    for (i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "INF ";
        }
        else
        {
            cout << dist[i] << " ";
        }
    }
    cout << endl;
    system("pause");
    return 0;
}