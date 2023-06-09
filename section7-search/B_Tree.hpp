/*
 * 一棵m阶B树是空树或者是满足以下特性的m叉树：
 * 1. 树中每个节点至多有m棵子树，也就是最多有m-1个关键字
 * 2. 若根节点不是叶子节点，则至少有两棵子树
 * 3. 除根节点外，其他每个非叶子节点至少有ceil(m/2)棵子树，也就是至少有ceil(m/2)-1个关键字
 * 4. 所有的叶子节点都在同一层，并且不带有信息（可以看作是外部节点或者查询失败的节点）
 *
 * 假设现在有一棵包含n个关键字、高度为h、阶数为m的B树，那么：
 * 树的高度h满足：logm(n+1) <= h <= log(ceil(m/2))((n+1)/2)+1
 * 例如一棵三阶B树共有8个关键字，那么其高度范围是：log3(8+1) <= h <= log2(4.5)+1，即2 <= h <= 3
 *
 * B树的查找过程：
 * 在B树中进行查找与二叉查找树很相似，只是每个节点都是多个关键字的有序表
 * B树的查找包含两个基本操作：
 *  1. 在B树中查找节点
 *  2. 在节点内寻找关键字
 * 而B树一般是存储在磁盘上的，所以第一个操作一般是磁盘I/O操作，而第二个操作是内存操作
 * 在找到目标节点以后，将节点信息读入到内存，然后在内存中使用顺序查找法或者折半查找法
 *
 * B树的插入过程：
 * 相比于二叉查找树，B树的插入操作要复杂的多，在B树中查找到插入的位置以后，并不能简单的将其添加到终端
 * 节点中，因为此时可能会导致整棵树不再满足B树的定义要求，相关操作如下：
 *  1. 定位。利用查找算法，在B树中找到插入该关键字的最底层中的某个非叶节点（注意：插入位置一定是最底层中的某个非叶节点）
 *  2. 插入。由于每个非失败节点的关键字个数都在区间[ceil(m/2)-1, m-1]之间。插入后的节点关键字个数小于m，可以直接插入。当插入后的
 *     节点关键字个数大于m-1时，需要进行分裂操作。
 *
 * 分裂操作：
 * 1. 将该节点中的关键字从中间位置ceil(m/2)分成左右两个部分，左部分包含的关键字放在原节点中，右部分包含的关键字放在新节点中。
 * 2. 中间位置的节点插入原节点的父节点。
 * 3. 如果导致父节点关键字个数大于m-1，则需要继续分裂，直到这个过程传到根节点为止，进而导致树的高度增加1。
 *
 *
 * B树的删除过程：
 * 删除后的节点中的关键字个数要>=ceil(m/2)-1，否则需要进行合并操作。
 * 1. 当被删除的关键字k不在终端节点时，可以用k的直接前驱（或者直接后继）k'来替代k，然后在某个终端节点中删除k'。进而转化为删除终端节点中的关键字的问题。
 * 2. 当被删除关键字在终端节点时，有下列三种情况：
 *   2.1 可以直接删除关键字。若被删关键字所在节点的关键字个数>=ceil(m/2)，则直接删除即可。
 *   2.2 兄弟够借。若被删关键字所在节点的关键字个数=ceil(m/2)-1，则需要向兄弟节点借关键字。若兄弟节点的关键字个数>ceil(m/2)-1，
 *       则可以从兄弟节点中借一个关键字，放入父亲节点中，然后将父节点中的某个关键字下移至被删关键字所在节点中。
 *   2.3 兄弟不够借。若被删关键字所在节点的关键字个数=ceil(m/2)-1，且左右兄弟节点的关键字个数均为ceil(m/2)-1，则需要进行合并操作。
 *       将关键字删除后与左（或右）兄弟节点以及双亲节点中的关键字进行合并，形成一个新的节点。如果新节点中的关键字个数大于m-1，则需要继续分裂操作。
 */
#ifndef BTREE_HPP
#define BTREE_HPP
#include <bits/stdc++.h>
using namespace std;

const int ORDER = 3;

// B树节点类
struct BNode
{
    int n;                  // 节点中关键字的数量
    int keys[ORDER - 1];    // 节点中存储的关键字
    BNode *children[ORDER]; // 节点的子节点
    bool leaf;              // 是否为叶子节点
};
// 创建一个新节点
BNode *createNode();

// 在B树中查找一个关键字
BNode *search(BNode *root, int key);

// 向B树中插入一个关键字
void insert(BNode *&root, int key);

// 删除B树中的一个关键字
void remove(BNode *&root, int key);

// 查找关键字在节点中的位置
int findKey(BNode *node, int key);

// 查找节点在父节点中的位置
int findChild(BNode *parent, BNode *child);

// 删除节点中的一个关键字
void deleteNode(BNode *node, int index);

// 合并两个节点
void merge(BNode *parent, int index, BNode *left, BNode *right);

// 向右旋转节点
void rotateRight(BNode *parent, int index, BNode *left, BNode *right);

// 向左旋转节点
void rotateLeft(BNode *parent, int index, BNode *left, BNode *right);

// 打印B树中的关键字
void print(BNode *root);

#endif // BTREE_HPP