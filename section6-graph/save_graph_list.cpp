#include <bits/stdc++.h>
#define MAX_NODE_NUM 100
using namespace std;
typedef struct Edge
{
    int to;
    int weight;
    Edge *next;
} Edge;
typedef struct Node
{
    int id;
    Edge *firstEdge;
} Node, NodeList[MAX_NODE_NUM + 1];
typedef struct
{
    NodeList nodeList;
    int nodeNum, edgeNum;
} Graph;
int main()
{
    Graph graph;
    cin >> graph.nodeNum >> graph.edgeNum;
    cout << graph.nodeNum << " " << graph.edgeNum << endl;
    // initialize the graph
    for (int i = 0; i <= graph.nodeNum; i++)
    {
        graph.nodeList[i].id = i;
        graph.nodeList[i].firstEdge = NULL;
    }
    // 邻接表法读取无向图边的信息
    for (int i = 0; i < graph.edgeNum; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        Edge *edge = new Edge;
        edge->to = to;
        edge->weight = weight;
        edge->next = graph.nodeList[from].firstEdge;
        graph.nodeList[from].firstEdge = edge;
        // 无向图的另一条边
        edge = new Edge;
        edge->to = from;
        edge->weight = weight;
        edge->next = graph.nodeList[to].firstEdge;
        graph.nodeList[to].firstEdge = edge;
    }
    // output the graph
    for (int i = 0; i <= graph.nodeNum; i++)
    {
        cout << graph.nodeList[i].id << ": ";
        Edge *edge = graph.nodeList[i].firstEdge;
        while (edge != NULL)
        {
            cout << edge->to << " ";
            edge = edge->next;
        }
        cout << endl;
    }
    system("pause");
    return 0;
}