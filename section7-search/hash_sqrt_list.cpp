/**
 * @file hash_sqrt_list.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 使用平方探测法作为解决冲突的方法的散列表的实现
 * @version 0.1
 * @date 2023-05-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <hash_sqrt_list.hpp>
#include <iostream>
using namespace std;

// 构造函数
HashTable::HashTable(int size)
{
    capacity = size;
    table = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
        table[i] = -1;
    }
}

// 插入关键字
void HashTable::insert(int key)
{
    int index = key % capacity;
    int i = 1;
    while (table[index] != -1)
    { // 发生冲突
        index = (key + i * i) % capacity;
        i++;
    }
    table[index] = key;
}

// 查找关键字
bool HashTable::search(int key)
{
    int index = key % capacity;
    int i = 1;
    while (table[index] != -1)
    { // 发生冲突
        if (table[index] == key)
        {
            return true;
        }
        index = (key + i * i) % capacity;
        i++;
    }
    return false;
}

// 删除关键字
void HashTable::remove(int key)
{
    int index = key % capacity;
    int i = 1;
    while (table[index] != -1)
    { // 发生冲突
        if (table[index] == key)
        {
            table[index] = -1;
            return;
        }
        index = (key + i * i) % capacity;
        i++;
    }
}

// 输出散列表
void HashTable::print()
{
    for (int i = 0; i < capacity; i++)
    {
        if (table[i] != -1)
        {
            cout << i << ": " << table[i] << endl;
        }
    }
}

// 析构函数
HashTable::~HashTable()
{
    delete[] table;
}
int main()
{
    HashTable ht(10);
    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.print();
    cout << ht.search(15) << endl;
    ht.remove(15);
    ht.print();
    cout << ht.search(15) << endl;
    system("pause");
    return 0;
}