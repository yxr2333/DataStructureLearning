/**
 * @file simple_BFS.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 广度优先搜索示例
 * @version 0.1
 * @date 2023-04-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
// 使用邻接矩阵存储图，并进行广度优先遍历
int visited[MAX_N];
queue<int> q;

typedef struct Graph
{
    int vex_num;
    int edge_num;
    int matrix[MAX_N][MAX_N];
} Graph;
void initGraph(Graph &graph, int vex_num, int eage_num)
{
    graph.vex_num = vex_num;
    graph.edge_num = eage_num;
    // 初始化邻接矩阵
    for (int i = 0; i < graph.vex_num; i++)
    {
        for (int j = 0; j < graph.vex_num; j++)
        {
            graph.matrix[i][j] = 0;
        }
    }
}
void initMatrix(Graph &graph)
{
    for (int i = 0; i < graph.edge_num; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph.matrix[from][to] = weight;
        graph.matrix[to][from] = weight;
    }
}
void showGraph(Graph &graph)
{
    for (int i = 0; i < graph.vex_num; i++)
    {
        for (int j = 0; j < graph.vex_num; j++)
        {
            cout << graph.matrix[i][j] << " ";
        }
        cout << endl;
    }
}
/**
 * 该函数从指定顶点开始对图执行广度优先搜索。
 * 广度优先搜索的思想是：从起始顶点开始，首先访问其所有邻接点，然后再访问邻接点的邻接点。
 * 需要借助队列来实现。
 * 在广度优先遍历过程中，我们可以得到一颗遍历树，称为广度优先生成树。
 * 如果是连通图，那么就是一棵生成树。
 * 如果是非连通图，那么就是一棵森林。
 *
 * @param graph 对 Graph 对象的引用，它表示要遍历的图。
 * @param start BFS 遍历的起始顶点。如果不指定，默认值为0，表示从图中的第一个顶点开始遍历。
 */
void BFS(Graph &graph, int start = 0)
{
    // 从顶点0开始进行广度优先遍历
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int i = 0; i < graph.vex_num; i++)
        {
            if (graph.matrix[cur][i] != 0 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}
int main()
{
    Graph graph;
    cin >> graph.vex_num >> graph.edge_num;
    cout << "graph.vex_num: " << graph.vex_num << endl
         << "graph.edge_num: " << graph.edge_num << endl;

    // 初始化图
    initGraph(graph, graph.vex_num, graph.edge_num);

    // 邻接矩阵法读取无向图边的信息
    initMatrix(graph);

    // 输出图对应的邻接矩阵
    showGraph(graph);

    // 从顶点0开始进行广度优先遍历
    BFS(graph);
    system("pause");
    return 0;
}