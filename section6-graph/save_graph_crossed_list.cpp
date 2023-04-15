/**
 * @file save_graph_crossed_list.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ʹ��ʮ�������洢ͼ��ֻ����������ͼ��
 * @version 0.1
 * @date 2023-04-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100
using namespace std;
// ʮ�������洢ͼ
typedef struct Edge
{
    int tail_vex_num; // ��β�������
    int head_vex_num; // ��ͷ�������
    Edge *hlink;      // ָ��ͷ��ͬ����һ����
    Edge *tlink;      // ָ��β��ͬ����һ����
} Edge;
typedef struct VexNode
{
    int id;
    Edge *first_in;  // �Ա��idΪ��ͷ�ĵ�һ����
    Edge *first_out; // �Ա��idΪ��β�ĵ�һ����
} VexNode, VexNodeList[N + 1];
typedef struct
{
    VexNodeList vexNodeList;
    int vexNum, edgeNum;
} Graph;
int main()
{
    Graph graph;
    cin >> graph.vexNum >> graph.edgeNum;
    for (int i = 1; i <= graph.vexNum; i++)
    {
        graph.vexNodeList[i].id = i;
        graph.vexNodeList[i].first_in = NULL;
        graph.vexNodeList[i].first_out = NULL;
    }

    // ʹ��ʮ�������洢����ͼ
    for (int i = 0; i < graph.edgeNum; i++)
    {
        int from, to;
        cin >> from >> to;
        Edge *edge = new Edge;
        edge->tail_vex_num = from;
        edge->head_vex_num = to;
        edge->hlink = graph.vexNodeList[to].first_in;    // ���»����뻡ͷ��ͬ�Ļ�������
        edge->tlink = graph.vexNodeList[from].first_out; // ���»����뻡β��ͬ�Ļ�������(ͷ�巨)
        graph.vexNodeList[to].first_in = edge;
        graph.vexNodeList[from].first_out = edge;
    }

    // show the graph
    for (int i = 1; i <= graph.vexNum; i++)
    {
        cout << graph.vexNodeList[i].id << ": ";
        Edge *edge = graph.vexNodeList[i].first_out;
        while (edge != NULL)
        {
            cout << edge->head_vex_num << " ";
            edge = edge->tlink;
        }
        cout << endl;
    }
    system("pause");
    return 0;
}