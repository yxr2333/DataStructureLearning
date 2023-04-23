/**
 * @file blocked_search.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 静态查找表的分块查找
 * @version 0.1
 * @date 2023-04-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
/**
 * 上面的类型定义了一个名为 IndexBlock 的结构，它具有三个整数字段：key、start 和 end。
 * @property {int} key - 键是每个索引块的唯一标识符。它用于从索引中搜索和检索相应的块。
 * @property {int} start - 数据块在文件或内存中的起始位置。在此结构的上下文中，它可能指的是较大文件或数据结构中数据块的起始位置。
 * @property {int} end - IndexBlock 结构中的“end”属性可能表示文件或其他数据结构中数据块的结束位置。它可以与“开始”属性结合使用，以定义文件中与给定键对应的数据范围。
 */
typedef struct IndexBlock
{
    int key;
    int start;
    int end;
} IndexBlock;

void initIndexList(vector<int> &arr, vector<IndexBlock> &index)
{
    IndexBlock block = {10, 0, 1};
    index.push_back(block);
    block = {20, 2, 5};
    index.push_back(block);
    block = {30, 6, 8};
    index.push_back(block);
    block = {40, 9, 10};
    index.push_back(block);
    block = {50, 11, 13};
    index.push_back(block);
}

/**
 * 块间顺序查找，块内顺序查找。
 *
 * @param arr 表示要搜索的数组的整数向量
 * @param index index 参数是 IndexBlock 结构的向量，表示块搜索算法的索引块。每个 IndexBlock 结构包含原始数组中块的起始和结束索引，以及块中最后一个元素的键值。
 * @param key 键是我们使用块搜索算法在给定数组中搜索的值。
 *
 * @return 一个整数值，表示与输入键匹配的输入向量“arr”中元素的索引。如果在向量中未找到该键，则该函数返回 -1。
 */
int blockSearchLinear(const vector<int> &arr, const vector<IndexBlock> &index, int key)
{
    int i = 0;
    int total = 0;                                 // 记录比较次数
    while (i < index.size() && key > index[i].key) // 块间顺序查找
    {
        i++;
        total++;
    }
    if (i >= index.size())
    {
        return -1;
    }
    for (int j = index[i].start; j <= index[i].end; j++) // 块内顺序查找
    {
        if (arr[j] == key)
        {
            cout << "比较次数: " << total << endl;
            return j;
        }
        total++;
    }
    return -1;
}

/**
 * @brief 块间二分查找，块内顺序查找
 *
 * @param arr 待查找的数组
 * @param index 索引块表
 * @param key 关键字（待查找的值）
 * @return int 返回关键字的位置
 */
int blockSearchBinary(const vector<int> &arr, const vector<IndexBlock> &index, int key)
{
    // 块间二分查找
    int low = 0, high = index.size() - 1;
    int total = 0;
    while (low <= high)
    {
        total++;
        int mid = (low + high) / 2;
        if (key < index[mid].key)
        {
            high = mid - 1;
        }
        else if (key > index[mid].key)
        {
            low = mid + 1;
        }
        else
        {
            low = mid;
            break;
        }
        if (high < 0)
        {
            break;
        }
    }
    /*
        块内顺序查找
        如果索引表不包含目标关键字，那么最终停在low > high
        要在low所指的索引块中继续查找目标关键字
    */
    for (int j = index[low].start; j <= index[low].end; j++)
    {
        total++;
        if (arr[j] == key)
        {
            cout << "比较次数: " << total << endl;
            return j;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {7, 10, 13, 19, 16, 20, 27, 22, 30, 40, 36, 43, 50, 48};
    vector<IndexBlock> index;
    initIndexList(arr, index);
    for (int i = 0; i < index.size(); i++)
    {
        cout << "key: " << index[i].key << " start: " << index[i].start << " end: " << index[i].end << endl;
    }
    int key = 30;
    int pos = blockSearchLinear(arr, index, key);
    if (pos == -1)
    {
        cout << "Not found!" << endl;
    }
    else
    {
        cout << "Found " << key << " at position " << pos << endl;
    }
    cout << "---------------------" << endl;
    pos = blockSearchBinary(arr, index, key);
    if (pos == -1)
    {
        cout << "Not found!" << endl;
    }
    else
    {
        cout << "Found " << key << " at position " << pos << endl;
    }
    system("pause");
    return 0;
}