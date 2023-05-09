/**
 * @file hash_sqrt_list.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief ʹ��ƽ��̽�ⷨ��Ϊ�����ͻ�ķ�����ɢ�б��ʵ��
 * @version 0.1
 * @date 2023-05-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <hash_sqrt_list.hpp>
#include <iostream>
using namespace std;

// ���캯��
HashTable::HashTable(int size)
{
    capacity = size;
    table = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
        table[i] = -1;
    }
}

// ����ؼ���
void HashTable::insert(int key)
{
    int index = key % capacity;
    int i = 1;
    while (table[index] != -1)
    { // ������ͻ
        index = (key + i * i) % capacity;
        i++;
    }
    table[index] = key;
}

// ���ҹؼ���
bool HashTable::search(int key)
{
    int index = key % capacity;
    int i = 1;
    while (table[index] != -1)
    { // ������ͻ
        if (table[index] == key)
        {
            return true;
        }
        index = (key + i * i) % capacity;
        i++;
    }
    return false;
}

// ɾ���ؼ���
void HashTable::remove(int key)
{
    int index = key % capacity;
    int i = 1;
    while (table[index] != -1)
    { // ������ͻ
        if (table[index] == key)
        {
            table[index] = -1;
            return;
        }
        index = (key + i * i) % capacity;
        i++;
    }
}

// ���ɢ�б�
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

// ��������
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