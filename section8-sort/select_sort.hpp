/**
 * @file select_sort.hpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief —°‘Ò≈≈–Ú
 * @version 0.1
 * @date 2023-05-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
using namespace std;
class SelectSort
{
public:
    void normal_select_sort(vector<int> &data);
    void heap_sort(vector<int> &data);
    void heap_adjust_down(vector<int> &data, int start, int len);
    void heap_adjust_up(vector<int> &data, int start, int len);
    void establish_heap(vector<int> &data);
    void insert_into_heap(vector<int> &data, int value);
    void delete_from_heap(vector<int> &data, int index);
    void print(vector<int> &data);
};