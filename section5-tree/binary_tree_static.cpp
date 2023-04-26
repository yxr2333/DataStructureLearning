/**
 * @file binary_tree_static.cpp
 * @author icecreamovo (www.icecreamovo.top)
 * @brief 基于顺序存储实现二叉树
 * @version 0.1
 * @date 2023-04-26
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <binary_tree_static.hpp>
#include <bits/stdc++.h>
#define N 100
using namespace std;

int main()
{
    SeqBinaryTree tree;
    tree.insert(1, 1);
    tree.insert(2, 2);
    tree.insert(3, 3);
    tree.insert(4, 4);
    tree.insert(5, 5);
    tree.insert(6, 6);
    tree.insert(7, 7);
    tree.traverse();
    system("pause");
    return 0;
}