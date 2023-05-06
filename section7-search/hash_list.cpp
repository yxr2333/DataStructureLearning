/**
 * @file hash_list.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 线性探测法处理哈希冲突的散列表的实现
 * @version 0.1
 * @date 2023-05-07
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <hash_list.hpp>
#include <iostream>

using namespace std;

HashTable::HashTable(int capacity)
{
    this->capacity = capacity;
    table.resize(capacity, -1);
    size = 0;
}

bool HashTable::insert(int key)
{
    bool flag = false;
    if (size == capacity)
    {
        return false;
    }
    int index = hash(key);
    while (table[index] != -1)
    {
        flag = true;
        auto s = "插入" + to_string(key) + "时发生冲突，冲突位置为" + to_string(index) + "，正在尝试下一个位置:" + to_string((index + 1) % capacity) + "...";
        cout << s << endl;
        index = (index + 1) % capacity; // 使用线性探测法处理冲突
    }
    if (!flag)
    {
        cout << "插入" << key << "时未发生哈希冲突，插入成功" << endl;
    }
    table[index] = key;
    size++;
    return true;
}

bool HashTable::search(int key)
{
    int index = hash(key);
    while (table[index] != -1)
    {
        if (table[index] == key)
        {
            return true;
        }
        index = (index + 1) % capacity;
    }
    return false;
}

bool HashTable::remove(int key)
{
    int index = hash(key);
    while (table[index] != -1)
    {
        if (table[index] == key)
        {
            table[index] = -2; // 标记删除
            size--;
            return true;
        }
        index = (index + 1) % capacity;
    }
    return false;
}

void HashTable::print()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << table[i] << " ";
    }
    cout << endl;
}

int HashTable::hash(int key)
{
    return key % capacity;
}

int main()
{
    HashTable ht(30);
    vector<int> nums = {37, 23, 16, 94, 11, 81, 26, 19, 72, 84, 77, 62, 35, 98, 53, 67, 29, 92, 10, 44};

    ht.insert(1);
    ht.insert(11);
    ht.insert(21);
    for (int i = 0; i < nums.size(); i++)
    {
        ht.insert(nums[i]);
    }
    ht.print();
    cout << ht.search(1) << endl;
    cout << ht.search(11) << endl;
    cout << ht.search(21) << endl;
    ht.remove(11);
    ht.print();
    cout << ht.search(11) << endl;
    system("pause");
    return 0;
}