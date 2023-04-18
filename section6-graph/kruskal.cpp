/**
 * @file kruskal.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ʹ��Kruskal�㷨�����С������
 * @version 0.1
 * @date 2023-04-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 100
// ʹ���ڽӾ���洢ͼ��ʹ��Kruskal�㷨���ͼ����С������
using namespace std;

/**
 * ��������Ϊͼ�еı߶�����һ���ṹ��Դ���㡢Ŀ�궥���Ȩ�ص�����ֵ��
 * @property {int} u - �ߵĵ�һ�����㡣
 * @property {int} v - Struct Edge �еı�����v����ʾ�ɱ����ӵĶ���֮һ��
 * @property {int} w - Edge �ṹ�еı�����w����ʾͼ���������㡰u���͡�v��֮��ıߵ�Ȩ�ػ�ɱ���
 */
struct Edge
{
    int u;
    int v;
    int w;
};

int n, m; // n�����㣬m����
int father[N + 1];
Edge edge[N + 1];       // �ߵ�����
int _map[N + 1][N + 1]; // �ڽӾ���

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
        cin >> edge[i].u >> edge[i].v >> w; // ��ȡ����ͼ�ı�
        _map[edge[i].u][edge[i].v] = w;
        _map[edge[i].v][edge[i].u] = w;
    }
}

/**
 * ������cmp���Ƚ������ߵ�Ȩ�ء�
 *
 * @param a a �� Edge ���͵ı���
 * @param b b �� Edge ���͵ı���
 *
 * @return ������cmp������һ������ֵ�����Ƚ�������Edge�����͵Ķ��������һ������a����Ȩ��С�ڵڶ�������b����Ȩ�أ��򷵻ء�true�������򷵻ء�false����
 */
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

/**
 * �ú����ݹ���ڲ��ཻ�ļ������ݽṹ�в��Ҹ����ڵ�ĸ����ڵ㡣
 *
 * @param x x ��һ����������ʾ��Ҫ�������ཻ�������ݽṹ���ҵ��丸�ڵ����ڵ�Ľڵ��Ԫ�ء�
 *
 * @return ������findFather������Ԫ�ء�x���������ϵĸ��ڵ�����Ԫ�ء�
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
 * �ú���ͨ�����������ཻ�ļ��ϵĸ��ڵ�����Ϊ��ͬ���ϲ����ǡ�
 *
 * @param a ������a����һ����������ʾ��Ҫ����һ��Ԫ�غϲ���Ԫ��֮һ��
 * @param b ������b����һ����������ʾ�������ݽṹ�е���һ��Ԫ�غϲ���Ԫ��֮һ��
 */
void merge(int a, int b)
{
    father[findFather(a)] = findFather(b);
}

/**
 * �ú���ʵ���� Kruskal �㷨�Բ���ͼ����С��������
 * ������Ҫ�ж����������Ƿ���ͬһ����ͨ���У������Ҫʹ�ò��鼯��
 * һ��ʹ�ö����洢Kruskal�㷨�еıߣ��������ڱߵ��������٣���˿���ʹ������������ѡ�
 * Kruskal�㷨�ʺϱ�ϡ�������϶��ͼ
 *
 * @return ������kruskal()�����ظ���ͼ����С����������Ȩ�ء�
 */
int kruskal()
{
    int i, cnt = 0, ans = 0;
    sort(edge + 1, edge + m + 1, cmp); // ����Ȩ��С��������
    for (i = 1; i <= n; i++)           // ��ʼ�����鼯
    {
        father[i] = i;
    }
    for (i = 1; i <= m; i++)
    {
        int fau = findFather(edge[i].u);
        int fav = findFather(edge[i].v);
        if (fau != fav) // �������һ����ͨ���У��ͼ�����С��������
        {
            ans += edge[i].w;
            cnt++;
            merge(fau, fav);
        }
        if (cnt == n - 1) // ��С�������ı���Ϊn-1
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
