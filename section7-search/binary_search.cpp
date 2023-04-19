/**
 * @file binary_search.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 二分查找顺序表
 * @version 0.1
 * @date 2023-04-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <bits/stdc++.h>
#define N 100
using namespace std;

/**
 * 这是一个二分搜索函数，它将一个排序的整数向量和一个目标整数作为输入，如果存在则返回目标整数在向量中的索引，如果不存在则返回 -1。
 *
 * @param list 对整数向量的常量引用，表示我们要在其中搜索目标值的排序列表。
 * @param target 我们在向量中搜索的值。
 *
 * @return 如果找到，则为输入向量中目标元素的索引；如果未找到，则为 -1。
 */
int binary_search(const std::vector<int> &list, int target)
{
    int left = 0, right = list.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (list[mid] == target)
        {
            return mid;
        }
        else if (list[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> list = {1, 3, 5, 7, 9, 11};
    int target = 5;
    int pos = binary_search(list, target);
    if (pos != -1)
    {
        std::cout << "Target " << target << " found at position " << pos << std::endl;
    }
    else
    {
        std::cout << "Target " << target << " not found" << std::endl;
    }
    system("pause");
    return 0;
}