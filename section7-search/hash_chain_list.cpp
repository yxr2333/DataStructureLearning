/**
 * @file hash_chain_list.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 使用拉链法作为解决冲突的方法的散列表
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
 * 该函数初始化一个具有给定容量的哈希表，确保容量为质数。
 *
 * @param capacity 哈希表的初始容量。
 */
HashTable::HashTable(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    table.resize(capacity);
}

/**
 * 如果有空间并且该键不存在于表中，则此函数将键插入到哈希表中。
 *
 * @param key 键是一个整数值，需要插入到哈希表中。
 *
 * @return 一个布尔值，指示给定键的插入是否成功。如果哈希表的大小已经达到其容量，则该函数返回 false。如果该键已经存在于哈希表中，则该函数返回 true
 * 而无需再次插入该键。否则，键被插入哈希表，函数返回真。
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
        return true; // 元素已存在
    }
    lst.insert(iter, key);
    size++;
    return true;
}

/**
 * 此函数从哈希表中删除具有给定键的元素。
 *
 * @param key 需要从哈希表中移除的元素的键。
 *
 * @return 一个布尔值，指示指定键的删除是否成功。如果找到并删除了密钥，该函数将返回 true。如果在哈希表中找不到该键，则该函数返回 false。
 */
bool HashTable::remove(int key)
{
    int index = hash(key);
    auto &lst = table[index];
    auto iter = find(lst.begin(), lst.end(), key);
    if (iter == lst.end())
    {
        return false; // 元素不存在
    }
    lst.erase(iter);
    size--;
    if (lst.empty())
    {
        // 如果链表为空，则将其从哈希表中删除
        table.erase(table.begin() + index);
        capacity--;
    }
    return true;
}

/**
 * 该函数在哈希表中搜索键，如果找到该键则返回 true，否则返回 false。
 *
 * @param key 键是要在哈希表中搜索的值。它用于计算值可能存储在哈希表中的索引。
 *
 * @return 一个布尔值，指示给定键是否存在于哈希表中。如果找到密钥，则函数返回 true，否则返回 false。
 */
bool HashTable::search(int key)
{
    int index = hash(key);
    auto &lst = table[index];
    auto iter = find(lst.begin(), lst.end(), key);
    if (iter != lst.end())
    {
        return true; // 元素存在
    }
    return false; // 元素不存在
}

/**
 * 此函数使用当前容量或大于当前容量的下一个质数计算给定键的哈希值。
 *
 * @param key 键是需要散列的值。在哈希表中，键用于索引和检索值。
 *
 * @return 函数“hash”返回一个整数值，它是三元运算符的结果。如果 isPrime(capacity) 返回 true，则返回 key % capacity 的值，否则返回 key %
 * nextPrime(capacity) 的值。
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
 * 此函数打印哈希表的内容。
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