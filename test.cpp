#include <bits/stdc++.h>
#define N 100
using namespace std;
typedef struct Person
{
    int id;
    string name;
} Person;
vector<Person> L;
int main()
{
    int id;
    cout << "请输入你想查找的人的id: ";
    cin >> id;
    for (int i = 0; i < id; i++)
    {
        Person p;
        p.id = i + 1;
        p.name = "icecreamovo" + to_string(i + 1);
        L.push_back(p);
    }
    auto it = find_if(L.begin(), L.end(), [id](const Person &p)
                      { return p.id == id; });
    if (it != L.end())
    {
        cout << "找到了，他的名字是：" << it->name << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }
    system("pause");
    return 0;
}