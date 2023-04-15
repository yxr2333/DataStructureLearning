/**
 * @file simple_DFS.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ʹ���ڽӾ���洢ͼ��������������ȱ���
 * @version 0.1
 * @date 2023-04-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100
using namespace std;
// ʹ���ڽӾ���洢ͼ��������������ȱ���
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
    // ��ʼ���ڽӾ���
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
 * �ú�����ָ�����㿪ʼ��ͼִ���������������
 * �������������˼���ǣ�����ʼ���㿪ʼ�����ȷ������һ���ڽӵ㣬Ȼ���ٷ��ʸ��ڽӵ�ĵ�һ���ڽӵ㡣
 * �Դ����ƣ�ֱ�����ʵ�û���ڽӵ�Ķ��㣬Ȼ����ݵ���һ�����㣬��������һ���ڽӵ㡣
 * �Դ����ƣ�ֱ�����������ж��㡣
 * @param graph ͼ
 * @param start ��ʼ����
 */
void DFS(Graph &graph, int start = 0)
{
    // ����ʼ���㿪ʼ�����ȷ������һ���ڽӵ�
    for (int i = 0; i < graph.vex_num; i++)
    {
        if (graph.matrix[start][i] != 0 && visited[i] == 0)
        {
            // ���ʸ��ڽӵ�
            cout << i << " ";
            visited[i] = 1;
            // �ݹ���ʸ��ڽӵ���ڽӵ�
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
    // �Ӷ���0��ʼִ�������������
    DFS(graph);
    system("pause");
    return 0;
}