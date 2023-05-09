#include <chrono>
#include <exchange_sort.hpp>
#define N 10
using namespace std;
using namespace std::chrono;
void ExchangeSort::bubble_sort(vector<int> &data, int size)
{
    // 假设我们现在需要的是升序排序
    for (int i = 0; i < size - 1; i++)
    {
        // 每一次冒泡都将当前最小的元素移到序列的最前面
        bool flag = false;
        for (int j = size - 1; j > i; j--)
        {
            if (data[j - 1] > data[j])
            {
                swap(data[j - 1], data[j]);
                flag = true;
            }
        }
        if (!flag)
            return;
    }
}
/**
 * 该函数实现了双向冒泡排序算法来对整数向量进行排序。
 *
 * @param data 对将使用双冒泡排序算法排序的整数向量的引用。
 */
void ExchangeSort::dual_bubble_sort(vector<int> &data)
{
    int n = data.size();
    int l = 0, r = n - 1;
    while (l < r)
    {
        for (int i = l; i < r; i++)
        {
            if (data[i] > data[i + 1])
                swap(data[i], data[i + 1]);
        }
        r--;
        for (int j = r; j > l; j--)
        {
            if (data[j] < data[j - 1])
                swap(data[j], data[j - 1]);
        }
        l++;
    }
}
void ExchangeSort::quick_sort(vector<int> &data, int low, int high)
{
    // 假设我们现在需要的是升序排序
    if (low < high)
    {
        int l = low, h = high;
        int pivot = data[l];
        while (l < h)
        {
            while (l < h && data[h] >= pivot)
                h--;
            data[l] = data[h];
            while (l < h && data[l] <= pivot)
                l++;
            data[h] = data[l];
        }
        data[l] = pivot;
        quick_sort(data, low, l - 1);
        quick_sort(data, l + 1, high);
    }
}
void ExchangeSort::print(vector<int> &data)
{
    for (const auto &num : data)
    {
        cout << num << " ";
    }
    cout << endl;
}
int main()
{
    ExchangeSort es;
    vector<int> num;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    for (int i = 0; i < N; i++)
    {
        num.push_back(dis(gen));
    }
    cout << "==========before sort=========>" << endl;
    es.print(num);
    cout << "==============================>" << endl;
    // es.bubble_sort(num, 5);
    es.dual_bubble_sort(num);
    // es.quick_sort(num, 0, num.size() - 1);
    cout << "==========after sort=========>" << endl;
    es.print(num);
    cout << "==============================>" << endl;
    system("pause");
    return 0;
}