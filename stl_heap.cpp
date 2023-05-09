#include <bits/stdc++.h>
#define N 100
using namespace std;
int main()
{
    vector<int> num = {2, 3, 1, 5, 4};
    make_heap(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
    for (int i = num.size() - 1; i > 0; i--)
    {
        swap(num[0], num[i]);
        make_heap(num.begin(), num.begin() + i);
    }
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << " ";
    }
    system("pause");
    return 0;
}