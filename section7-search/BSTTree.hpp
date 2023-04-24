#include <bits/stdc++.h>
using namespace std;
typedef int DATATYPE; // Ϊ�����������Ͷ�����һ�������ƣ���Ϊ DATATYPE��
/**
 * ����һ���������ڵ�Ľṹ����ֵ����Ϊ DATATYPE ��ָ�������ӽڵ㡣
 * @property {DATATYPE} val - val ��һ�� DATATYPE ���͵ı��������洢�������нڵ��ֵ��
 * @property {BSTTreeNode} left - ָ��������е�ǰ�ڵ�����ӽڵ��ָ�롣���û�����ӣ���ָ������Ϊ NULL��
 * @property {BSTTreeNode} right - BSTTreeNode �ṹ�ġ�right��������ָ����һ�� TreeNode�ṹ��ָ�룬�ýṹ��ʾ��ǰ�ڵ�����ӽڵ㡣���仰˵����ָ����������ݽṹ��λ�ڵ�ǰ�ڵ��Ҳ�� BSTTreeNode��
 */
struct BSTTreeNode
{
    DATATYPE val;
    BSTTreeNode *left;
    BSTTreeNode *right;
    BSTTreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insertBST(BSTTreeNode *&root, int val);
BSTTreeNode *searchBST(BSTTreeNode *root, DATATYPE val);
BSTTreeNode *deleteBST(BSTTreeNode *root, DATATYPE val);
void inorderTraversalBST(BSTTreeNode *root);