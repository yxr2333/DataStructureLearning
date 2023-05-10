#include <bits/stdc++.h>
#define N 100
using namespace std;
int main()
{
    vector<int> a1 = {1, 3, 5, 4};
    vector<int> a2 = {2, 6, 7, 8, 9};
    int n1 = a1.size();
    int n2 = a2.size();
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
            ans.push_back(a1[i++]);
        else
            ans.push_back(a2[j++]);
    }
    while (i < n1)
        ans.push_back(a1[i++]);
    while (j < n2)
        ans.push_back(a2[j++]);
    for (const auto &num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}