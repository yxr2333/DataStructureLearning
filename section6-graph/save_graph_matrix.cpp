#include <bits/stdc++.h>
#define N 100
using namespace std;
// �ڽӾ���洢ͼ
typedef char VertexType; // ��������
typedef int EdgeType;    // ���ϵ�Ȩֵ����
typedef struct Graph
{
    VertexType vertex[N];   // ����
    EdgeType edge[N][N];    // ��
    int vertexNum, edgeNum; // ������������
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
    // ���붥�����ͱ���
    cin >> graph.vertexNum >> graph.edgeNum;
    // ���붥����Ϣ
    for (int i = 0; i < graph.vertexNum; i++)
    {
        cin >> graph.vertex[i];
    }
    // ��ʼ���ڽӾ���
    initMatrix(graph);
    // �������Ϣ(����ͼ)
    for (int i = 0; i < graph.edgeNum; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph.edge[v1][v2] = 1;
        graph.edge[v2][v1] = 1;
    }
    // ��ӡ�ڽӾ���
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