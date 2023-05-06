/**
 * @file hash_list2.hpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 使用拉链法作为解决冲突的方法的散列表
 * @version 0.1
 * @date 2023-05-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HASH_CHAIN_LIST
#define HASH_CHAIN_LIST
#include <bits/stdc++.h>
using namespace std;
class HashTable
{
private:
    std::vector<std::list<int>> table; // 散列表
    int capacity;                      // 散列表容量
    int size;                          // 散列表元素个数
    int hash(int key);                 // 散列函数

public:
    HashTable(int capacity);
    bool insert(int key);
    bool search(int key);
    bool remove(int key);
    void print();
    bool isPrime(int n);
    int nextPrime(int n);
};
#endif