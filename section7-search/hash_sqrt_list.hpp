/**
 * @file hash_sqrt_list.hpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ʹ��ƽ��̽�ⷨ��Ϊ�����ͻ�ķ�����ɢ�б�Ķ���
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
    int capacity; // ɢ�б������
    int *table;   // ɢ�б������ָ��
public:
    HashTable(int size);  // ���캯��
    void insert(int key); // ����ؼ���
    bool search(int key); // ���ҹؼ���
    void remove(int key); // ɾ���ؼ���
    void print();         // ���ɢ�б�
    ~HashTable();         // ��������
};

#endif