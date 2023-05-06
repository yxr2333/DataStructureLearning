/**
 * @file hash_chain_list.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ʹ����������Ϊ�����ͻ�ķ�����ɢ�б�
 * @version 0.1
 * @date 2023-05-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <hash_chain_list.hpp>
#include <iostream>
#include <random>
using namespace std;

/**
 * �ú�����ʼ��һ�����и��������Ĺ�ϣ��ȷ������Ϊ������
 *
 * @param capacity ��ϣ��ĳ�ʼ������
 */
HashTable::HashTable(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    table.resize(capacity);
}

/**
 * ����пռ䲢�Ҹü��������ڱ��У���˺����������뵽��ϣ���С�
 *
 * @param key ����һ������ֵ����Ҫ���뵽��ϣ���С�
 *
 * @return һ������ֵ��ָʾ�������Ĳ����Ƿ�ɹ��������ϣ��Ĵ�С�Ѿ��ﵽ����������ú������� false������ü��Ѿ������ڹ�ϣ���У���ú������� true
 * �������ٴβ���ü������򣬼��������ϣ�����������档
 */
bool HashTable::insert(int key)
{
    if (size == capacity)
    {
        return false;
    }
    int index = hash(key);
    auto &lst = table[index];
    auto iter = lst.begin();
    while (iter != lst.end() && *iter < key)
    {
        iter++;
    }
    if (iter != lst.end() && *iter == key)
    {
        return true; // Ԫ���Ѵ���
    }
    lst.insert(iter, key);
    size++;
    return true;
}

/**
 * �˺����ӹ�ϣ����ɾ�����и�������Ԫ�ء�
 *
 * @param key ��Ҫ�ӹ�ϣ�����Ƴ���Ԫ�صļ���
 *
 * @return һ������ֵ��ָʾָ������ɾ���Ƿ�ɹ�������ҵ���ɾ������Կ���ú��������� true������ڹ�ϣ�����Ҳ����ü�����ú������� false��
 */
bool HashTable::remove(int key)
{
    int index = hash(key);
    auto &lst = table[index];
    auto iter = find(lst.begin(), lst.end(), key);
    if (iter == lst.end())
    {
        return false; // Ԫ�ز�����
    }
    lst.erase(iter);
    size--;
    if (lst.empty())
    {
        // �������Ϊ�գ�����ӹ�ϣ����ɾ��
        table.erase(table.begin() + index);
        capacity--;
    }
    return true;
}

/**
 * �ú����ڹ�ϣ����������������ҵ��ü��򷵻� true�����򷵻� false��
 *
 * @param key ����Ҫ�ڹ�ϣ����������ֵ�������ڼ���ֵ���ܴ洢�ڹ�ϣ���е�������
 *
 * @return һ������ֵ��ָʾ�������Ƿ�����ڹ�ϣ���С�����ҵ���Կ���������� true�����򷵻� false��
 */
bool HashTable::search(int key)
{
    int index = hash(key);
    auto &lst = table[index];
    auto iter = find(lst.begin(), lst.end(), key);
    if (iter != lst.end())
    {
        return true; // Ԫ�ش���
    }
    return false; // Ԫ�ز�����
}

/**
 * �˺���ʹ�õ�ǰ��������ڵ�ǰ��������һ����������������Ĺ�ϣֵ��
 *
 * @param key ������Ҫɢ�е�ֵ���ڹ�ϣ���У������������ͼ���ֵ��
 *
 * @return ������hash������һ������ֵ��������Ԫ������Ľ������� isPrime(capacity) ���� true���򷵻� key % capacity ��ֵ�����򷵻� key %
 * nextPrime(capacity) ��ֵ��
 */
int HashTable::hash(int key)
{
    return isPrime(capacity) ? key % capacity : key % nextPrime(capacity);
}

bool HashTable::isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int HashTable::nextPrime(int n)
{
    while (!isPrime(n))
    {
        n++;
    }
    return n;
}

/**
 * �˺�����ӡ��ϣ������ݡ�
 */
void HashTable::print()
{
    for (int i = 0; i < capacity; i++)
    {
        auto &lst = table[i];
        cout << "Bucket " << i << ": ";
        for (auto iter = lst.begin(); iter != lst.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
}

int main()
{
    HashTable ht(10);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    for (int i = 0; i < 20; i++)
    {
        int num = dis(gen);
        ht.insert(num);
        cout << "Insert [" << i << "] " << num << endl;
    }
    ht.print();
    int key = 50;
    if (ht.search(key))
    {
        cout << "Find " << key << endl;
    }
    else
    {
        cout << "Cannot find " << key << endl;
    }
    if (ht.remove(key))
    {
        cout << "Remove " << key << endl;
    }
    else
    {
        cout << "Cannot remove " << key << endl;
    }
    ht.print();
    system("pause");
    return 0;
}