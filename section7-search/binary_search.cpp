/**
 * @file binary_search.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ���ֲ���˳���
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
 * ����һ��������������������һ�����������������һ��Ŀ��������Ϊ���룬��������򷵻�Ŀ�������������е�����������������򷵻� -1��
 *
 * @param list �����������ĳ������ã���ʾ����Ҫ����������Ŀ��ֵ�������б�
 * @param target ������������������ֵ��
 *
 * @return ����ҵ�����Ϊ����������Ŀ��Ԫ�ص����������δ�ҵ�����Ϊ -1��
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