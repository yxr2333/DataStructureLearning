/**
 * @file Dijkstra.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief  ʹ��Dijkstra�㷨������·��
 * @version 0.1
 * @date 2023-04-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100

using namespace std;

int n, m;               // n�����㣬m����
int _map[N + 1][N + 1]; // �ڽӾ���
int dist[N + 1];        // dist���飬��¼Դ�㵽�����������̾���
int path[N + 1];        // path���飬��¼Դ�㵽������������·��

/**
 * �ú���ʹ���������ֵ��ʼ��һ����ά���飬�������û����뽫�ض�ֵ�����ĳЩ������
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
 * �ú���ʵ���� Dijkstra �㷨���������ڽӾ����ʾ��ͼ���ҵ�����ʼ���㵽����������������·����
 *
 * 1. ʹ���ڽӾ���ʹ�Ȩ���ڽӱ�洢ͼ����Ϣʱ��������·����ʱ�临�Ӷȶ��� O(V^2)��
 * 2. �������Դ�㵽����һ��������·�������Դ�㵽�������е�����·����ͬ�����ӵģ�������ǵ�ʱ�临�Ӷȶ���O(V^2)��
 * 3. Dijkstra�㷨������⸺Ȩͼ�����·�����⡣
 * @param v_start Ҫ�ҵ����·������ʼ���㡣
 */
void dijkstra(int v_start)
{
    int i, j, k;
    bool visited[N + 1]; // ��¼�����Ƿ񱻷��ʹ�
    memset(visited, false, sizeof(visited));
    visited[v_start] = true;
    for (i = 1; i <= n; i++)
    {
        dist[i] = _map[v_start][i]; // �ʼ��ʱ��Դ�㵽�����������̾�������ڽӾ����е�ֵ
        if (dist[i] != INT_MAX)
        {
            path[i] = v_start; // ���Դ�㵽����i�бߣ��򶥵�i��ǰ������Դ��
        }
    }
    for (i = 1; i <= n; i++)
    {
        int min = INT_MAX;
        for (j = 1; j <= n; j++)
        {
            if (!visited[j] && dist[j] < min) // �ҵ�δ���ʵĽڵ��о���Դ���������Ľڵ�
            {
                min = dist[j];
                k = j;
            }
        }
        visited[k] = true; // ���Ϊ�ѷ���
        for (j = 1; j <= n; j++)
        {
            if (!visited[j] && _map[k][j] < INT_MAX) // �������jδ�����ʹ������Ҷ���k������j�б�
            {
                if (dist[j] > dist[k] + _map[k][j]) // ���ͨ���ڵ�k��ת��Դ�㵽����j�ľ����ԭ���ľ����
                {
                    dist[j] = dist[k] + _map[k][j]; // ����Դ�㵽����j�ľ���
                    path[j] = k;                    // ���¶���j��ǰ��
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