/**
 * @file insert_sort.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ��������Ķ���
 * @version 0.1
 * @date 2023-05-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <insert_sort.hpp>
#include <chrono>
using namespace std;
using namespace std::chrono;
/**
 * �ú���ʵ����C++�е�ֱ�Ӳ��������㷨��
 */
void InsertionSort::direct_insert_sort(vector<int> data, int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = data[i];
        int j = i - 1;
        while (j >= 0 && temp < data[j])
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
}
/**
 * binary_insert_sort ����ʵ���˶��ֲ��������㷨��ʹ�ö���������Ϊÿ��Ԫ���ҵ���ȷ��λ�á�
 */
void InsertionSort::binary_insert_sort(vector<int> data, int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = data[i];
        int low = 0, high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (temp < data[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for (int j = i - 1; j >= high + 1; j--)
        {
            data[j + 1] = data[j];
        }
        data[high + 1] = temp;
    }
}
/**
 * �˺���ʵ�� shell �����㷨�Զ����������������
 * ��ʼ����Ϊ�����С��һ�룬֮��ÿ�μ��룬ֱ������Ϊ 1��
 */
void InsertionSort::shell_sort(vector<int> data, int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = data[i];
            int j = i - gap;
            while (j >= 0 && temp < data[j])
            {
                data[j + gap] = data[j];
                j -= gap;
            }
            data[j + gap] = temp;
        }
    }
}
void InsertionSort::print(vector<int> &data, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int N = 10000; // ����������ĸ���
    vector<int> v;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    for (int i = 0; i < N; i++)
    {
        int num = dis(gen);
        v.push_back(num);
        // cout << "Insert [" << i << "] = " << num << "into vector" << endl;
    }
    InsertionSort is;
    // ��ȡ��ǰʱ���
    auto start_time = high_resolution_clock::now();
    is.direct_insert_sort(v, N);
    // ��ȡ��ǰʱ���
    auto end_time = high_resolution_clock::now();
    // ����ִ��ʱ�䣬������
    auto duration = duration_cast<milliseconds>(end_time - start_time);
    cout << "direct_insert_sort spend time: " << duration.count() << " ms" << endl;

    // ��ȡ��ǰʱ���
    start_time = high_resolution_clock::now();
    is.binary_insert_sort(v, N);
    // ��ȡ��ǰʱ���
    end_time = high_resolution_clock::now();
    // ����ִ��ʱ�䣬������
    duration = duration_cast<milliseconds>(end_time - start_time);
    cout << "binary_insert_sort spend time: " << duration.count() << " ms" << endl;

    // ��ȡ��ǰʱ���
    start_time = high_resolution_clock::now();
    is.shell_sort(v, N);
    // ��ȡ��ǰʱ���
    end_time = high_resolution_clock::now();
    // ����ִ��ʱ�䣬������
    duration = duration_cast<milliseconds>(end_time - start_time);
    cout << "shell_sort spend time: " << duration.count() << " ms" << endl;

    // is.print();
    system("pause");
    return 0;
}