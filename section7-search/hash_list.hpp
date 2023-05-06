/**
 * @file hash_list.hpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ����̽�ⷨ�����ϣ��ͻ��ɢ�б�Ķ���
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
    std::vector<int> table; // ɢ�б�
    int capacity;           // ɢ�б�����
    int size;               // ɢ�б�Ԫ�ظ���
    int hash(int key);      // ɢ�к���

public:
    HashTable(int capacity);
    bool insert(int key);
    bool search(int key);
    bool remove(int key);
    void print();
};
#endif