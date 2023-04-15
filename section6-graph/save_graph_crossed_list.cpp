/**
 * @file save_graph_crossed_list.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 使用十字链表法存储图（只适用于有向图）
 * @version 0.1
 * @date 2023-04-15
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100
using namespace std;
// 十字链表法存储图
typedef struct Edge
{
    int tail_vex_num; // 弧尾结点的序号
    int head_vex_num; // 弧头结点的序号
    Edge *hlink;      // 指向弧头相同的下一条弧
    Edge *tlink;      // 指向弧尾相同的下一条弧
} Edge;
typedef struct VexNode
{
    int id;
    Edge *first_in;  // 以编号id为弧头的第一条弧
    Edge *first_out; // 以编号id为弧尾的第一条弧
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

    // 使用十字链表法存储有向图
    for (int i = 0; i < graph.edgeNum; i++)
    {
        int from, to;
        cin >> from >> to;
        Edge *edge = new Edge;
        edge->tail_vex_num = from;
        edge->head_vex_num = to;
        edge->hlink = graph.vexNodeList[to].first_in;    // 将新弧插入弧头相同的弧链表中
        edge->tlink = graph.vexNodeList[from].first_out; // 将新弧插入弧尾相同的弧链表中(头插法)
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