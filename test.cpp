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
    cout << "������������ҵ��˵�id: ";
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
        cout << "�ҵ��ˣ����������ǣ�" << it->name << endl;
    }
    else
    {
        cout << "û�ҵ�" << endl;
    }
    system("pause");
    return 0;
}