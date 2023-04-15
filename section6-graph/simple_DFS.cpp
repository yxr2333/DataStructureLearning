/**
 * @file simple_DFS.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 使用邻接矩阵存储图，并进行深度优先遍历
 * @version 0.1
 * @date 2023-04-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100
using namespace std;
// 使用邻接矩阵存储图，并进行深度优先遍历
int visited[N];
stack<int> s;
typedef struct Graph
{
    int vex_num;
    int edge_num;
    int matrix[N][N];
} Graph;
void initGraph(Graph &graph, int vex_num, int edge_num)
{
    graph.vex_num = vex_num;
    graph.edge_num = edge_num;
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
 * 该函数从指定顶点开始对图执行深度优先搜索。
 * 深度优先搜索的思想是：从起始顶点开始，首先访问其第一个邻接点，然后再访问该邻接点的第一个邻接点。
 * 以此类推，直到访问到没有邻接点的顶点，然后回溯到上一个顶点，访问其下一个邻接点。
 * 以此类推，直到访问完所有顶点。
 * @param graph 图
 * @param start 起始顶点
 */
void DFS(Graph &graph, int start = 0)
{
    // 从起始顶点开始，首先访问其第一个邻接点
    for (int i = 0; i < graph.vex_num; i++)
    {
        if (graph.matrix[start][i] != 0 && visited[i] == 0)
        {
            // 访问该邻接点
            cout << i << " ";
            visited[i] = 1;
            // 递归访问该邻接点的邻接点
            DFS(graph, i);
        }
    }
}
int main()
{
    Graph graph;
    int vex_num, edge_num;
    cin >> vex_num >> edge_num;
    initGraph(graph, vex_num, edge_num);
    initMatrix(graph);
    showGraph(graph);
    // 从顶点0开始执行深度优先搜索
    DFS(graph);
    system("pause");
    return 0;
}