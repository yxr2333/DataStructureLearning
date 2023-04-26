#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <vector>

class SeqBinaryTree
{
private:
    std::vector<int> data;

public:
    SeqBinaryTree()
    {
        data.resize(1);
    }

    void insert(int pos, int val);

    int get(int pos);

    void traverse();
};
/**
 * �˺�����ʹ������ʵ�ֵĶ������е�ָ��λ�ò���һ��ֵ��
 *
 * @param pos ��������Ӧ����ֵ��λ�á�
 * @param val val ��һ������ֵ����ʾҪ���뵽�������е�ֵ��
 */
void SeqBinaryTree::insert(int pos, int val)
{
    if (pos >= data.size())
    {
        data.resize(pos + 1);
    }
    data[pos] = val;
}

/**
 * �˺����������ж������и���λ�õ�ֵ��
 *
 * @param pos pos ��һ��������������ʾ����Ҫ������ֵ�����ж������нڵ��λ�á�
 *
 * @return ���� get ����һ������ֵ����� pos �������ڻ���� data �����Ĵ�С���������� 0������������ data ������ָ��λ�õ�ֵ��
 */
int SeqBinaryTree::get(int pos)
{
    if (pos >= data.size())
    {
        return 0;
    }
    return data[pos];
}

void SeqBinaryTree::traverse()
{
    for (int i = 1; i < data.size(); i++)
    {
        if (data[i] != 0)
        {
            std::cout << data[i] << " ";
        }
    }
    std::cout << std::endl;
}

#endif
