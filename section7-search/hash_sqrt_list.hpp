/**
 * @file hash_sqrt_list.hpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 使用平方探测法作为解决冲突的方法的散列表的定义
 * @version 0.1
 * @date 2023-05-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <bits/stdc++.h>
using namespace std;
class HashTable
{
private:
    int capacity; // 散列表的容量
    int *table;   // 散列表的数组指针
public:
    HashTable(int size);  // 构造函数
    void insert(int key); // 插入关键字
    bool search(int key); // 查找关键字
    void remove(int key); // 删除关键字
    void print();         // 输出散列表
    ~HashTable();         // 析构函数
};

#endif