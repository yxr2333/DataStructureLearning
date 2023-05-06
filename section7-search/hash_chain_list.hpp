/**
 * @file hash_list2.hpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ʹ����������Ϊ�����ͻ�ķ�����ɢ�б�
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
    std::vector<std::list<int>> table; // ɢ�б�
    int capacity;                      // ɢ�б�����
    int size;                          // ɢ�б�Ԫ�ظ���
    int hash(int key);                 // ɢ�к���

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