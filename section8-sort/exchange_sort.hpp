#include <bits/stdc++.h>
using namespace std;
class ExchangeSort
{
public:
    void bubble_sort(vector<int> &data, int size);
    void dual_bubble_sort(vector<int> &data);
    void quick_sort(vector<int> &data, int low, int high);
    void print(vector<int> &data);
};