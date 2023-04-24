#include <AVLTree.cpp>
#include <BSTTree.cpp>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 生成随机数
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

    // 随机选取查询集合
    vector<int> query(M);
    for (int i = 0; i < M; i++)
    {
        query[i] = rand() % N;
    }

    // 在 BST 树和 AVL 树中查找每个元素，并记录时间
    double bst_time = 0;
    double avl_time = 0;
    for (int i = 0; i < M; i++)
    {
        int val = v[query[i]];

        // 在 BST 树中查找
        auto bst_start = chrono::high_resolution_clock::now();
        searchBST(bst_root, val);
        auto bst_end = chrono::high_resolution_clock::now();
        bst_time += chrono::duration_cast<chrono::milliseconds>(bst_end - bst_start).count();

        // 在 AVL 树中查找
        auto avl_start = chrono::high_resolution_clock::now();
        searchAVL(avl_root, val);
        auto avl_end = chrono::high_resolution_clock::now();
        avl_time += chrono::duration_cast<chrono::milliseconds>(avl_end - avl_start).count();
    }

    // 输出结果
    cout << "BST total search time: " << bst_time << " ms" << endl;
    cout << "AVL total search time: " << avl_time << " ms" << endl;

    cout << "BST avarage search time: " << bst_time / M << " ms" << endl;
    cout << "AVL avarage search time: " << avl_time / M << " ms" << endl;

    system("pause");
    return 0;
}