#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 1000;
int N;                 // �ڵ�����
int adj[MAX_N][MAX_N]; // �ڽӾ���
int inDegree[MAX_N];   // �洢��ȵ�����
vector<int> sorted;    // �洢��������õ�������

void topologicalSort()
{
    queue<int> q;
    for (int i = 0; i < N; i++)
    { // ���ձ�Ŵ�С�����˳�򣬲������Ϊ0�Ľڵ�������
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        sorted.push_back(u); // ���ڵ�u�������������������

        for (int v = 0; v < N; v++)
        {
            if (adj[u][v] == 1)
            {
                inDegree[v]--; // ��u�����г��ߵ��յ�����-1
                if (inDegree[v] == 0)
                {
                    q.push(v); // ������Ϊ0���������
                }
            }
        }
    }
}

int main()
{
    cin >> N;

    // Read adjacency matrix
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 1)
            { // i -> j��j�����+1
                inDegree[j]++;
            }
        }
    }

    topologicalSort();

    // Output sorted order
    for (int i : sorted)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}