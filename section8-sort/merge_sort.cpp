/**
 * @file merge_sort.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief πÈ≤¢≈≈–Ú
 * @version 0.1
 * @date 2023-05-10
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define N 20
using namespace std;
void my_merge(vector<int> &data, int low, int mid, int high)
{
    vector<int> temp;
    for (const auto &num : data)
        temp.push_back(num);
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (temp[i] <= temp[j])
        {
            data[k++] = temp[i++];
        }
        else
        {
            data[k++] = temp[j++];
        }
    }
    while (i <= mid)
        data[k++] = temp[i++];
    while (j <= high)
        data[k++] = temp[j++];
}
void merge_sort(vector<int> &data, int low, int high)
{
    if (low < high)
    {
        int mid = (high - low) / 2 + low;
        merge_sort(data, low, mid);
        merge_sort(data, mid + 1, high);
        my_merge(data, low, mid, high);
    }
}
void print_to_console(vector<int> &data, string str = "")
{
    cout << "===========" << str << "============>" << endl;
    for (const auto &num : data)
    {
        cout << num << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> num;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    for (int i = 0; i < N; i++)
    {
        num.push_back(dis(gen));
    }
    print_to_console(num, "before");
    merge_sort(num, 0, num.size() - 1);
    print_to_console(num, "after");
    system("pause");
    return 0;
}