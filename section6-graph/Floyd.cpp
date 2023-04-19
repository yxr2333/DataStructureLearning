/**
 * @file Floyd.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ʹ��Floyd�㷨������·��
 * @version 0.1
 * @date 2023-04-19
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define MAX 100
using namespace std;
// �ڽӾ���洢�����Ȩͼ
struct Graph
{
    int V;             // ������
    int E;             // ����
    int adj[MAX][MAX]; // �ڽӾ���
};

void initGraph(Graph &G)
{
    cout << "�����붥�����ͱ�����" << endl;
    cin >> G.V >> G.E;

    // ��ʼ���ڽӾ���
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

    // ��ӱ�
    cout << "������ÿ���ߵ���㡢�յ��Ȩ�أ�" << endl;
    for (int i = 0; i < G.E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G.adj[u][v] = w;
    }
}

// ��ӡ���·��
void printSolution(int dist[][MAX], int n)
{
    cout << "���·��Ϊ��" << endl;
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
 * �ú���ʵ���� Floyd �㷨�����ҵ�ͼ�����ж����֮������·����
 * Floyd �㷨��ʱ�临�Ӷ�Ϊ O(V^3)������ V ��ʾ��������
 * Floyd �㷨������⸺Ȩͼ�е����·�����⣬���ǲ�����⸺Ȩ��·��
 * @param G �� Graph ��������ã���ʾ����ҪΪ���ҵ����·����ͼ��
 * @param dist �洢ͼ��������������֮�����̾���Ķ�ά���顣
 */
void floyd(Graph &G, int dist[][MAX])
{
    int n = G.V;

    // ��ʼ��dist����
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = G.adj[i][j];
        }
    }

    /*
        �𲽸���dist����
        k, i, j�ֱ��ʾ�м䶥�㡢��㡢�յ�
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
                else if (dist[i][j] > dist[i][k] + dist[k][j]) // ���ͨ���ڵ�k��ת���Լ���i��j�ľ���
                {
                    dist[i][j] = dist[i][k] + dist[k][j]; // �����dist[i][j]
                }
            }
        }
    }

    // ��ӡ���·��
    printSolution(dist, n);
}
/**
 * @brief ������
 * �������룺
 * 4 5
 * 0 1 2
 * 0 2 6
 * 1 2 3
 * 1 3 8
 * 2 3 1
 * ���������
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
    int dist[MAX][MAX]; // �洢���·��������
    initGraph(G);
    // ʹ��Floyd�㷨������·��
    floyd(G, dist);
    system("pause");
    return 0;
}