#include <bits/stdc++.h>
#define N 100
using namespace std;
int main()
{
    vector<int> v;
    v.resize(5, -1);
    cout << "====================>" << endl;
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl
         << "====================>" << endl;

    v.push_back(1);
    v.push_back(2);
    cout << "====================>" << endl;
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl
         << "====================>" << endl;

    v.resize(4);

    cout << "====================>" << endl;
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl
         << "====================>" << endl;
    system("pause");
    return 0;
}
