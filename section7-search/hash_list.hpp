/**
 * @file hash_list.hpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 线性探测法处理哈希冲突的散列表的定义
 * @version 0.1
 * @date 2023-05-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <bits/stdc++.h>
using namespace std;
class HashTable
{
private:
    std::vector<int> table; // 散列表
    int capacity;           // 散列表容量
    int size;               // 散列表元素个数
    int hash(int key);      // 散列函数

public:
    HashTable(int capacity);
    bool insert(int key);
    bool search(int key);
    bool remove(int key);
    void print();
};
#endif