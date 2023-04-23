/**
 * @file blocked_search.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ��̬���ұ�ķֿ����
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
 * ��������Ͷ�����һ����Ϊ IndexBlock �Ľṹ�����������������ֶΣ�key��start �� end��
 * @property {int} key - ����ÿ���������Ψһ��ʶ���������ڴ������������ͼ�����Ӧ�Ŀ顣
 * @property {int} start - ���ݿ����ļ����ڴ��е���ʼλ�á��ڴ˽ṹ���������У�������ָ���ǽϴ��ļ������ݽṹ�����ݿ����ʼλ�á�
 * @property {int} end - IndexBlock �ṹ�еġ�end�����Կ��ܱ�ʾ�ļ����������ݽṹ�����ݿ�Ľ���λ�á��������롰��ʼ�����Խ��ʹ�ã��Զ����ļ������������Ӧ�����ݷ�Χ��
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
 * ���˳����ң�����˳����ҡ�
 *
 * @param arr ��ʾҪ�������������������
 * @param index index ������ IndexBlock �ṹ����������ʾ�������㷨�������顣ÿ�� IndexBlock �ṹ����ԭʼ�����п����ʼ�ͽ����������Լ��������һ��Ԫ�صļ�ֵ��
 * @param key ��������ʹ�ÿ������㷨�ڸ���������������ֵ��
 *
 * @return һ������ֵ����ʾ�������ƥ�������������arr����Ԫ�ص������������������δ�ҵ��ü�����ú������� -1��
 */
int blockSearchLinear(const vector<int> &arr, const vector<IndexBlock> &index, int key)
{
    int i = 0;
    int total = 0;                                 // ��¼�Ƚϴ���
    while (i < index.size() && key > index[i].key) // ���˳�����
    {
        i++;
        total++;
    }
    if (i >= index.size())
    {
        return -1;
    }
    for (int j = index[i].start; j <= index[i].end; j++) // ����˳�����
    {
        if (arr[j] == key)
        {
            cout << "�Ƚϴ���: " << total << endl;
            return j;
        }
        total++;
    }
    return -1;
}

/**
 * @brief �����ֲ��ң�����˳�����
 *
 * @param arr �����ҵ�����
 * @param index �������
 * @param key �ؼ��֣������ҵ�ֵ��
 * @return int ���عؼ��ֵ�λ��
 */
int blockSearchBinary(const vector<int> &arr, const vector<IndexBlock> &index, int key)
{
    // �����ֲ���
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
        ����˳�����
        �������������Ŀ��ؼ��֣���ô����ͣ��low > high
        Ҫ��low��ָ���������м�������Ŀ��ؼ���
    */
    for (int j = index[low].start; j <= index[low].end; j++)
    {
        total++;
        if (arr[j] == key)
        {
            cout << "�Ƚϴ���: " << total << endl;
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