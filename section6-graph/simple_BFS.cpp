/**
 * @file simple_BFS.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief �����������ʾ��
 * @version 0.1
 * @date 2023-04-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
// ʹ���ڽӾ���洢ͼ�������й�����ȱ���
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
 * �ú�����ָ�����㿪ʼ��ͼִ�й������������
 * �������������˼���ǣ�����ʼ���㿪ʼ�����ȷ����������ڽӵ㣬Ȼ���ٷ����ڽӵ���ڽӵ㡣
 * ��Ҫ����������ʵ�֡�
 * �ڹ�����ȱ��������У����ǿ��Եõ�һ�ű���������Ϊ���������������
 * �������ͨͼ����ô����һ����������
 * ����Ƿ���ͨͼ����ô����һ��ɭ�֡�
 *
 * @param graph �� Graph ��������ã�����ʾҪ������ͼ��
 * @param start BFS ��������ʼ���㡣�����ָ����Ĭ��ֵΪ0����ʾ��ͼ�еĵ�һ�����㿪ʼ������
 */
void BFS(Graph &graph, int start = 0)
{
    // �Ӷ���0��ʼ���й�����ȱ���
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

    // ��ʼ��ͼ
    initGraph(graph, graph.vex_num, graph.edge_num);

    // �ڽӾ��󷨶�ȡ����ͼ�ߵ���Ϣ
    initMatrix(graph);

    // ���ͼ��Ӧ���ڽӾ���
    showGraph(graph);

    // �Ӷ���0��ʼ���й�����ȱ���
    BFS(graph);
    system("pause");
    return 0;
}