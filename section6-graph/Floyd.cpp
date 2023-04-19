/**
 * @file Floyd.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 使用Floyd算法求解最短路径
 * @version 0.1
 * @date 2023-04-19
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define MAX 100
using namespace std;
// 邻接矩阵存储有向带权图
struct Graph
{
    int V;             // 顶点数
    int E;             // 边数
    int adj[MAX][MAX]; // 邻接矩阵
};

void initGraph(Graph &G)
{
    cout << "请输入顶点数和边数：" << endl;
    cin >> G.V >> G.E;

    // 初始化邻接矩阵
    for (int i = 0; i < G.V; i++)
    {
        for (int j = 0; j < G.V; j++)
        {
            if (i == j)
                G.adj[i][j] = 0;
            else
                G.adj[i][j] = INT_MAX;
        }
    }

    // 添加边
    cout << "请输入每条边的起点、终点和权重：" << endl;
    for (int i = 0; i < G.E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G.adj[u][v] = w;
    }
}

// 打印最短路径
void printSolution(int dist[][MAX], int n)
{
    cout << "最短路径为：" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INT_MAX)
                cout << "INF"
                     << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

/**
 * 该函数实现了 Floyd 算法，以找到图中所有顶点对之间的最短路径。
 * Floyd 算法的时间复杂度为 O(V^3)，其中 V 表示顶点数。
 * Floyd 算法可以求解负权图中的最短路径问题，但是不能求解负权回路。
 * @param G 对 Graph 对象的引用，表示我们要为其找到最短路径的图。
 * @param dist 存储图中任意两个顶点之间的最短距离的二维数组。
 */
void floyd(Graph &G, int dist[][MAX])
{
    int n = G.V;

    // 初始化dist数组
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = G.adj[i][j];
        }
    }

    /*
        逐步更新dist数组
        k, i, j分别表示中间顶点、起点、终点
    */
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                {
                    continue;
                }
                else if (dist[i][j] > dist[i][k] + dist[k][j]) // 如果通过节点k中转可以减少i到j的距离
                {
                    dist[i][j] = dist[i][k] + dist[k][j]; // 则更新dist[i][j]
                }
            }
        }
    }

    // 打印最短路径
    printSolution(dist, n);
}
/**
 * @brief 主函数
 * 测试输入：
 * 4 5
 * 0 1 2
 * 0 2 6
 * 1 2 3
 * 1 3 8
 * 2 3 1
 * 测试输出：
 * 0       2       5       6
 * INF     0       3       4
 * INF     INF     0       1
 * INF     INF     INF     0
 *
 * @return int
 */
int main()
{
    Graph G;
    int dist[MAX][MAX]; // 存储最短路径的数组
    initGraph(G);
    // 使用Floyd算法求解最短路径
    floyd(G, dist);
    system("pause");
    return 0;
}