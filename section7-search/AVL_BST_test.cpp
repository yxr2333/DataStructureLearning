#include <AVLTree.cpp>
#include <BSTTree.cpp>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ���������
    const int N = 1000000;
    const int M = 1000000; // 10000
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        v[i] = i;
    }
    shuffle(v.begin(), v.end(), default_random_engine(0));

    BSTTreeNode *bst_root = NULL;
    AVLTreeNode *avl_root = NULL;
    cout << "v[0]:" << v[0] << endl;
    for (int i = 0; i < N; i++)
    {
        insertBST(bst_root, v[i]);
        avl_root = insertAVL(avl_root, v[i]);
    }

    cout << avl_root->val << endl;
    // inorderTraversalAVL(avl_root);
    // cout << endl;

    // ���ѡȡ��ѯ����
    vector<int> query(M);
    for (int i = 0; i < M; i++)
    {
        query[i] = rand() % N;
    }

    // �� BST ���� AVL ���в���ÿ��Ԫ�أ�����¼ʱ��
    double bst_time = 0;
    double avl_time = 0;
    for (int i = 0; i < M; i++)
    {
        int val = v[query[i]];

        // �� BST ���в���
        auto bst_start = chrono::high_resolution_clock::now();
        searchBST(bst_root, val);
        auto bst_end = chrono::high_resolution_clock::now();
        bst_time += chrono::duration_cast<chrono::milliseconds>(bst_end - bst_start).count();

        // �� AVL ���в���
        auto avl_start = chrono::high_resolution_clock::now();
        searchAVL(avl_root, val);
        auto avl_end = chrono::high_resolution_clock::now();
        avl_time += chrono::duration_cast<chrono::milliseconds>(avl_end - avl_start).count();
    }

    // ������
    cout << "BST total search time: " << bst_time << " ms" << endl;
    cout << "AVL total search time: " << avl_time << " ms" << endl;

    cout << "BST avarage search time: " << bst_time / M << " ms" << endl;
    cout << "AVL avarage search time: " << avl_time / M << " ms" << endl;

    system("pause");
    return 0;
}