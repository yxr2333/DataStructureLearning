#include <bits/stdc++.h>
using namespace std;
enum Color
{
    RED,
    BLACK
};

template <typename T>
class RBTreeNode
{
public:
    T key;
    Color color;
    RBTreeNode *left, *right, *parent;

    RBTreeNode(T value, Color col, RBTreeNode *l, RBTreeNode *r, RBTreeNode *p) : key(value), color(col), left(l), right(r), parent(p) {}
};

template <typename T>
class RBTree
{
public:
    RBTree();
    ~RBTree();

    void insert(T key);
    void remove(T key);
    RBTreeNode<T> *search(T key);

private:
    void insert(RBTreeNode<T> *&root, RBTreeNode<T> *node);
    void remove(RBTreeNode<T> *&root, RBTreeNode<T> *node);
    RBTreeNode<T> *search(RBTreeNode<T> *x, T key);
    void destroy(RBTreeNode<T> *&tree);
    void left_rotate(RBTreeNode<T> *&root, RBTreeNode<T> *x);
    void right_rotate(RBTreeNode<T> *&root, RBTreeNode<T> *y);
    void insert_fixup(RBTreeNode<T> *&root, RBTreeNode<T> *node);
    void remove_fixup(RBTreeNode<T> *&root, RBTreeNode<T> *node, RBTreeNode<T> *parent);

private:
    RBTreeNode<T> *mRoot;
};