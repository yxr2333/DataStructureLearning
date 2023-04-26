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
 * 此函数在使用向量实现的二叉树中的指定位置插入一个值。
 *
 * @param pos 二叉树中应插入值的位置。
 * @param val val 是一个整数值，表示要插入到二叉树中的值。
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
 * 此函数返回序列二叉树中给定位置的值。
 *
 * @param pos pos 是一个整数参数，表示我们要检索其值的序列二叉树中节点的位置。
 *
 * @return 函数 get 返回一个整数值。如果 pos 参数大于或等于 data 向量的大小，则函数返回 0。否则，它返回 data 向量中指定位置的值。
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
