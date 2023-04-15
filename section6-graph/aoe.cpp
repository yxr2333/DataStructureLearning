#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100;
int n, m;                                   // n is the number of events, m is the number of activities
int adjMatrix[MAXN][MAXN];                  // adjacency matrix to store the AOE network
int EST[MAXN], LFT[MAXN], totalFloat[MAXN]; // arrays to store the EST, LFT, and total float for each event
bool visited[MAXN];                         // array to mark visited events
vector<int> adjList[MAXN];                  // adjacency list to store the AOE network
int inDegree[MAXN], outDegree[MAXN];        // arrays to store the in-degree and out-degree of each event

// function to read in the AOE network from input
void readInput()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjMatrix[u][v] = w;
        inDegree[v]++;
        outDegree[u]++;
    }
}

// function to convert the adjacency matrix to an adjacency list
void convertToAdjList()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adjMatrix[i][j] > 0)
            {
                adjList[i].push_back(j);
            }
        }
    }
}

// function to perform a topological sort of the events
void topologicalSort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            EST[i] = 0;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adjList[u].size(); i++)
        {
            int v = adjList[u][i];
            EST[v] = max(EST[v], EST[u] + adjMatrix[u][v]);
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
}

// function to calculate the LFT for each event
void calculateLFT()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (outDegree[i] == 0)
        {
            q.push(i);
            LFT[i] = EST[i];
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adjList[u].size(); i++)
        {
            int v = adjList[u][i];
            LFT[u] = min(LFT[u], LFT[v] - adjMatrix[u][v]);
            outDegree[u]--;
            if (outDegree[u] == 0)
            {
                q.push(u);
            }
        }
    }
}

/**
 * 该函数使用最早开始时间 (EST)、最晚完成时间 (LFT) 和邻接矩阵计算项目中每个活动的总浮动时间。
 */
void calculateTotalFloat()
{
    for (int i = 1; i <= n; i++)
    {
        totalFloat[i] = LFT[i] - EST[i] - adjMatrix[i][i];
    }
}

// helper function for findCriticalPath
void findCriticalPathHelper(int u)
{
    visited[u] = true;
    for (int i = 0; i < adjList[u].size(); i++)
    {
        int v = adjList[u][i];
        if (!visited[v])
        {
            findCriticalPathHelper(v);
        }
    }
    cout << u << " ";
}

// function to find the critical path
void findCriticalPath()
{
    for (int u = 1; u <= n; u++)
    {
        if (totalFloat[u] == 0)
        {
            visited[u] = true;
            for (int i = 0; i < adjList[u].size(); i++)
            {
                int v = adjList[u][i];
                if (!visited[v])
                {
                    findCriticalPathHelper(v);
                }
            }
            cout << u << " ";
            return;
        }
    }
}

int main()
{
    readInput();
    convertToAdjList();
    topologicalSort();
    calculateLFT();
    calculateTotalFloat();
    findCriticalPath();
    cout << endl;
    system("pause");
    return 0;
}