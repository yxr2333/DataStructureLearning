#include <bits/stdc++.h>
#define N 100
using namespace std;
// 邻接矩阵存储图
typedef char VertexType; // 顶点类型
typedef int EdgeType;    // 边上的权值类型
typedef struct Graph
{
    VertexType vertex[N];   // 顶点
    EdgeType edge[N][N];    // 边
    int vertexNum, edgeNum; // 顶点数，边数
} Graph;
void initMatrix(Graph &graph)
{
    for (int i = 0; i < graph.vertexNum; i++)
    {
        for (int j = 0; j < graph.vertexNum; j++)
        {
            graph.edge[i][j] = 0;
        }
    }
}
int main()
{
    Graph graph;
    // 读入顶点数和边数
    cin >> graph.vertexNum >> graph.edgeNum;
    // 读入顶点信息
    for (int i = 0; i < graph.vertexNum; i++)
    {
        cin >> graph.vertex[i];
    }
    // 初始化邻接矩阵
    initMatrix(graph);
    // 读入边信息(无向图)
    for (int i = 0; i < graph.edgeNum; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph.edge[v1][v2] = 1;
        graph.edge[v2][v1] = 1;
    }
    // 打印邻接矩阵
    for (int i = 0; i < graph.vertexNum; i++)
    {
        for (int j = 0; j < graph.vertexNum; j++)
        {
            cout << graph.edge[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}