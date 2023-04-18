/**
 * @file kruskal.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 使用Kruskal算法求解最小生成树
 * @version 0.1
 * @date 2023-04-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100
// 使用邻接矩阵存储图，使用Kruskal算法求解图的最小生成树
using namespace std;

/**
 * 上述类型为图中的边定义了一个结构，源顶点、目标顶点和权重的整数值。
 * @property {int} u - 边的第一个顶点。
 * @property {int} v - Struct Edge 中的变量“v”表示由边连接的顶点之一。
 * @property {int} w - Edge 结构中的变量“w”表示图中两个顶点“u”和“v”之间的边的权重或成本。
 */
struct Edge
{
    int u;
    int v;
    int w;
};

int n, m; // n个顶点，m条边
int father[N + 1];
Edge edge[N + 1];       // 边的数组
int _map[N + 1][N + 1]; // 邻接矩阵

void initMap()
{
    int i, j, w;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            _map[i][j] = 0;
        }
    }
    for (i = 1; i <= m; i++)
    {
        cin >> edge[i].u >> edge[i].v >> w; // 读取无向图的边
        _map[edge[i].u][edge[i].v] = w;
        _map[edge[i].v][edge[i].u] = w;
    }
}

/**
 * 函数“cmp”比较两条边的权重。
 *
 * @param a a 是 Edge 类型的变量
 * @param b b 是 Edge 类型的变量
 *
 * @return 函数“cmp”返回一个布尔值。它比较两个“Edge”类型的对象，如果第一个对象“a”的权重小于第二个对象“b”的权重，则返回“true”，否则返回“false”。
 */
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

/**
 * 该函数递归地在不相交的集合数据结构中查找给定节点的根父节点。
 *
 * @param x x 是一个整数，表示需要在树或不相交集等数据结构中找到其父节点或根节点的节点或元素。
 *
 * @return 函数“findFather”返回元素“x”所属集合的根节点或代表元素。
 */
int findFather(int x)
{
    if (father[x] == x)
    {
        return x;
    }
    return father[x] = findFather(father[x]);
}

/**
 * 该函数通过将两个不相交的集合的父节点设置为相同来合并它们。
 *
 * @param a 参数“a”是一个整数，表示需要与另一个元素合并的元素之一。
 * @param b 参数“b”是一个整数，表示将与数据结构中的另一个元素合并的元素之一。
 */
void merge(int a, int b)
{
    father[findFather(a)] = findFather(b);
}

/**
 * 该函数实现了 Kruskal 算法以查找图的最小生成树。
 * 由于需要判断两个顶点是否在同一个连通块中，因此需要使用并查集。
 * 一般使用堆来存储Kruskal算法中的边，但是由于边的数量较少，因此可以使用排序来代替堆。
 * Kruskal算法适合边稀疏而顶点较多的图
 *
 * @return 函数“kruskal()”返回给定图的最小生成树的总权重。
 */
int kruskal()
{
    int i, cnt = 0, ans = 0;
    sort(edge + 1, edge + m + 1, cmp); // 按边权从小到大排序
    for (i = 1; i <= n; i++)           // 初始化并查集
    {
        father[i] = i;
    }
    for (i = 1; i <= m; i++)
    {
        int fau = findFather(edge[i].u);
        int fav = findFather(edge[i].v);
        if (fau != fav) // 如果不在一个连通块中，就加入最小生成树中
        {
            ans += edge[i].w;
            cnt++;
            merge(fau, fav);
        }
        if (cnt == n - 1) // 最小生成树的边数为n-1
        {
            break;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    initMap();
    int i, j;
    cout << kruskal() << endl;
    system("pause");
    return 0;
}
