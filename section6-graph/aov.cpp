#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 1000;
int N;                 // 节点数量
int adj[MAX_N][MAX_N]; // 邻接矩阵
int inDegree[MAX_N];   // 存储入度的数组
vector<int> sorted;    // 存储拓扑排序得到的序列

void topologicalSort()
{
    queue<int> q;
    for (int i = 0; i < N; i++)
    { // 按照编号从小到大的顺序，查找入度为0的节点加入队列
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        sorted.push_back(u); // 将节点u加入拓扑排序的序列中

        for (int v = 0; v < N; v++)
        {
            if (adj[u][v] == 1)
            {
                inDegree[v]--; // 将u的所有出边的终点的入度-1
                if (inDegree[v] == 0)
                {
                    q.push(v); // 如果入度为0，加入队列
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
            { // i -> j，j的入度+1
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