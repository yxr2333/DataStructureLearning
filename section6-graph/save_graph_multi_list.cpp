/**
 * @file save_graph_multi_list.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ʹ���ڽӶ��ر��洢����ͼ������������ͼ��
 * @version 0.1
 * @date 2023-04-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100
using namespace std;
// ʹ���ڽӶ��ر��洢����ͼ
typedef struct Edge
{
    int ivex;
    int jvex;
    Edge *ilink;
    Edge *jlink;
} Edge;

typedef struct Node
{
    int id;
    Edge *first_edge;
} Node, NodeList[N + 1];

typedef struct Graph
{
    NodeList nodeList;
    int vex_num, edge_num;
} Graph;

int main()
{
    Graph graph;
    cin >> graph.vex_num >> graph.edge_num;
    cout << "graph.vex_num: " << graph.vex_num << " graph.edge_num: " << graph.edge_num << endl;
    for (int i = 1; i <= graph.vex_num; i++)
    {
        graph.nodeList[i].id = i;
        graph.nodeList[i].first_edge = NULL;
    }
    // �ڽӶ��ر���ȡ����ͼ�ߵ���Ϣ
    for (int i = 0; i < graph.edge_num; i++)
    {
        int ivex, jvex;
        cin >> ivex >> jvex;
        Edge *edge = new Edge;
        edge->ivex = ivex;
        edge->jvex = jvex;
        edge->ilink = graph.nodeList[ivex].first_edge;
        edge->jlink = graph.nodeList[jvex].first_edge;
        graph.nodeList[ivex].first_edge = edge;
        graph.nodeList[jvex].first_edge = edge;
    }
    // ouput the graph
    for (int i = 1; i <= graph.vex_num; i++)
    {
        cout << graph.nodeList[i].id << ": ";
        Edge *edge = graph.nodeList[i].first_edge;
        while (edge != NULL)
        {
            cout << edge->jvex << " ";
            edge = edge->ilink;
        }
        cout << endl;
    }
    system("pause");
    return 0;
}