/**
 * @file select_sort.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 选择排序的代码实现
 * @version 0.1
 * @date 2023-05-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <select_sort.hpp>
#include <cassert>
#include <iostream>
#define N 10
using namespace std;
void SelectSort::normal_select_sort(vector<int> &data)
{
    int n = data.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        int j = i + 1;
        while (j < n)
        {
            if (data[j] < data[min_index])
                min_index = j;
            j++;
        }
        swap(data[i], data[min_index]);
    }
}
void SelectSort::heap_sort(vector<int> &data)
{
    int len = data.size();
    establish_heap(data);
    for (int i = len - 1; i > 0; i--)
    {
        swap(data[0], data[i]);
        heap_adjust_down(data, 0, i);
    }
}
void SelectSort::establish_heap(vector<int> &data)
{
    int len = data.size();
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        heap_adjust_down(data, i, len);
    }
}
void SelectSort::heap_adjust_down(vector<int> &data, int start, int len)
{
    int temp = data[start];
    for (int i = 2 * start + 1; i < len; i = 2 * i + 1)
    {
        if (i + 1 < len && data[i] < data[i + 1])
        {
            i++;
        }
        if (temp > data[i])
            break;
        else
        {
            data[start] = data[i];
            start = i;
        }
    }
    data[start] = temp;
}
/**
 * @brief 对大根堆向上调整
 *
 * @param data
 * @param start
 * @param len
 */
void SelectSort::heap_adjust_up(vector<int> &data, int start, int len)
{
    int temp = data[start];
    int i = start;
    for (int j = (i - 1) / 2; i > 0; i = j, j = (i - 1) / 2)
    {
        if (data[j] < temp)
        {
            data[i] = data[j];
        }
        else
        {
            break;
        }
    }
    data[i] = temp;
}

/**
 * @brief 往大根堆中插入元素
 *
 * @param data
 * @param value
 */
void SelectSort::insert_into_heap(vector<int> &data, int value)
{
    data.push_back(value);
    int len = data.size();
    heap_adjust_up(data, len - 1, len);
}

void SelectSort::delete_from_heap(vector<int> &data, int index)
{
    int len = data.size();
    if (index < 0 || index >= len)
    {
        cout << "index out of range" << endl;
        return;
    }
    swap(data[index], data[len - 1]); // 将被删除元素交换到最后
    data.pop_back();
    heap_adjust_down(data, index, len - 1); // 然后从index位置开始向下调整
}

void SelectSort::print(vector<int> &data)
{
    cout << "======================" << endl;
    for (const auto &num : data)
    {
        cout << num << " ";
    }
    cout << endl
         << "======================" << endl;
}
int main()
{
    SelectSort ss;
    vector<int> num;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < N; i++)
    {
        num.push_back(dis(gen));
    }
    ss.print(num);
    // ss.normal_select_sort(num);
    ss.insert_into_heap(num, 1000);
    assert(num.front() == 1000);
    ss.print(num);
    ss.delete_from_heap(num, 3);
    assert(num.size() == N);
    ss.print(num);
    ss.heap_sort(num);
    ss.print(num);
    system("pause");
    return 0;
}