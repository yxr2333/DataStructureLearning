#include <RBTree.hpp>

// ¹¹Ôìº¯Êý
template <typename T>
RBTree<T>::RBTree() : mRoot(nullptr) {}

// Îö¹¹º¯Êý
template <typename T>
RBTree<T>::~RBTree()
{
    destroy(mRoot);
}

// Ïú»ÙºìºÚÊ÷
template <typename T>
void RBTree<T>::destroy(RBTreeNode<T> *&tree)
{
    if (tree == nullptr)
    {
        return;
    }

    if (tree->left != nullptr)
    {
        destroy(tree->left);
    }
    if (tree->right != nullptr)
    {
        destroy(tree->right);
    }

    delete tree;
    tree = nullptr;
}

// ×óÐý²Ù×÷
template <typename T>
void RBTree<T>::left_rotate(RBTreeNode<T> *&root, RBTreeNode<T> *x)
{
    RBTreeNode<T> *y = x->right;

    x->right = y->left;
    if (y->left != nullptr)
    {
        y->left->parent = x;
    }

    y->parent = x->parent;
    if (x->parent == nullptr)
    {
        root = y;
    }
    else
    {
        if (x->parent->left == x)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
    }

    y->left = x;
    x->parent = y;
}

// ÓÒÐý²Ù×÷
template <typename T>
void RBTree<T>::right_rotate(RBTreeNode<T> *&root, RBTreeNode<T> *y)
{
    RBTreeNode<T> *x = y->left;

    y->left = x->right;
    if (x->right != nullptr)
    {
        x->right->parent = y;
    }

    x->parent = y->parent;
    if (y->parent == nullptr)
    {
        root = x;
    }
    else
    {
        if (y == y->parent->right)
        {
            y->parent->right = x;
        }
        else
        {
            y->parent->left = x;
        }
    }

    x->right = y;
    y->parent = x;
}

// ²åÈë²Ù×÷
template <typename T>
void RBTree<T>::insert(T key)
{
    RBTreeNode<T> *node = new RBTreeNode<T>(key, RED, nullptr, nullptr, nullptr);
    if (node != nullptr)
    {
        insert(mRoot, node);
    }
}

// ²åÈë¸¨Öúº¯Êý
template <typename T>
void RBTree<T>::insert(RBTreeNode<T> *&root, RBTreeNode<T> *node)
{
    RBTreeNode<T> *y = nullptr;
    RBTreeNode<T> *x = root;

    while (x != nullptr)
    {
        y = x;
        if (node->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == nullptr)
    {
        root = node;
    }
    else
    {
        if (node->key < y->key)
        {
            y->left = node;
        }
        else
        {
            y->right = node;
        }
    }

    insert_fixup(root, node);
}

// ²åÈëÐÞ¸´²Ù×÷
template <typename T>
void RBTree<T>::insert_fixup(RBTreeNode<T> *&root, RBTreeNode<T> *node)
{
    RBTreeNode<T> *parent, *gparent;

    while ((parent = node->parent) && parent->color == RED)
    {
        gparent = parent->parent;

        if (parent == gparent->left)
        {
            RBTreeNode<T> *uncle = gparent->right;
            if (uncle && uncle->color == RED)
            {
                uncle->color = BLACK;
                parent->color = BLACK;
                gparent->color = RED;
                node = gparent;
            }
            else
            {
                if (parent->right == node)
                {
                    left_rotate(root, parent);
                    std::swap(parent, node);
                }

                parent->color = BLACK;
                gparent->color = RED;
                right_rotate(root, gparent);
            }
        }
        else
        {
            RBTreeNode<T> *uncle = gparent->left;
            if (uncle && uncle->color == RED)
            {
                uncle->color = BLACK;
                parent->color = BLACK;
                gparent->color = RED;
                node = gparent;
            }
            else
            {
                if (parent->left == node)
                {
                    right_rotate(root, parent);
                    std::swap(parent, node);
                }

                parent->color = BLACK;
                gparent->color = RED;
                left_rotate(root, gparent);
            }
        }
    }

    root->color = BLACK;
}

// É¾³ý²Ù×÷
template <typename T>
void RBTree<T>::remove(T key)
{
    RBTreeNode<T> *node = search(mRoot, key);

    if (node)
    {
        remove(mRoot, node);
    }
}

// É¾³ý¸¨Öúº¯Êý
template <typename T>
void RBTree<T>::remove(RBTreeNode<T> *&root, RBTreeNode<T> *node)
{
    RBTreeNode<T> *child, *parent;
    Color color;

    if (node->left != nullptr && node->right != nullptr)
    {
        RBTreeNode<T> *replace = node->right;
        while (replace->left != nullptr)
        {
            replace = replace->left;
        }

        if (node->parent)
        {
            if (node->parent->left == node)
            {
                node->parent->left = replace;
            }
            else
            {
                node->parent->right = replace;
            }
        }
        else
        {
            root = replace;
        }

        child = replace->right;
        parent = replace->parent;
        color = replace->color;

        if (parent == node)
        {
            parent = replace;
        }
        else
        {
            if (child)
            {
                child->parent = parent;
            }
            parent->left = child;

            replace->right = node->right;
            node->right->parent = replace;
        }

        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;

        if (color == BLACK)
        {
            remove_fixup(root, child, parent);
        }

        delete node;
        return;
    }

    if (node->left != nullptr)
    {
        child = node->left;
    }
    else
    {
        child = node->right;
    }

    parent = node->parent;
    color = node->color;

    if (child)
    {
        child->parent = parent;
    }

    if (parent)
    {
        if (parent->left == node)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
    }
    else
    {
        root = child;
    }

    if (color == BLACK)
    {
        remove_fixup(root, child, parent);
    }

    delete node;
}

// É¾³ýÐÞ¸´²Ù×÷
template <typename T>
void RBTree<T>::remove_fixup(RBTreeNode<T> *&root, RBTreeNode<T> *node, RBTreeNode<T> *parent)
{
    RBTreeNode<T> *other;

    while ((!node || node->color == BLACK) && node != root)
    {
        if (parent->left == node)
        {
            other = parent->right;
            if (other->color == RED)
            {
                other->color = BLACK;
                parent->color = RED;
                left_rotate(root, parent);
                other = parent->right;
            }

            if ((!other->left || other->left->color == BLACK) &&
                (!other->right || other->right->color == BLACK))
            {
                other->color = RED;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (!other->right || other->right->color == BLACK)
                {
                    other->left->color = BLACK;
                    other->color = RED;
                    right_rotate(root, other);
                    other = parent->right;
                }

                other->color = parent->color;
                parent->color = BLACK;
                other->right->color = BLACK;
                left_rotate(root, parent);
                node = root;
                break;
            }
        }
        else
        {
            other = parent->left;
            if (other->color == RED)
            {
                other->color = BLACK;
                parent->color = RED;
                right_rotate(root, parent);
                other = parent->left;
            }

            if ((!other->left || other->left->color == BLACK) &&
                (!other->right || other->right->color == BLACK))
            {
                other->color = RED;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (!other->left || other->left->color == BLACK)
                {
                    other->right->color = BLACK;
                    other->color = RED;
                    left_rotate(root, other);
                    other = parent->left;
                }

                other->color = parent->color;
                parent->color = BLACK;
                other->left->color = BLACK;
                right_rotate(root, parent);
                node = root;
                break;
            }
        }
    }

    if (node)
    {
        node->color = BLACK;
    }
}

// ËÑË÷²Ù×÷
template <typename T>
RBTreeNode<T> *RBTree<T>::search(T key)
{
    return search(mRoot, key);
}

// ËÑË÷¸¨Öúº¯Êý
template <typename T>
RBTreeNode<T> *RBTree<T>::search(RBTreeNode<T> *x, T key)
{
    if (x == nullptr || x->key == key)
    {
        return x;
    }

    if (key < x->key)
    {
        return search(x->left, key);
    }
    else
    {
        return search(x->right, key);
    }
}

int main()
{
    RBTree<int> rbtree;

    // ²åÈë½Úµã
    rbtree.insert(10);
    rbtree.insert(40);
    rbtree.insert(30);
    rbtree.insert(60);
    rbtree.insert(90);
    rbtree.insert(25);
    rbtree.insert(65);
    rbtree.insert(12);
    rbtree.insert(18);
    rbtree.insert(50);

    // ËÑË÷½Úµã
    int key_to_search = 30;
    RBTreeNode<int> *node = rbtree.search(key_to_search);
    if (node != nullptr)
    {
        std::cout << "Found key " << key_to_search << " in the tree." << std::endl;
    }
    else
    {
        std::cout << "Key " << key_to_search << " not found in the tree." << std::endl;
    }

    // É¾³ý½Úµã
    int key_to_remove = 60;
    rbtree.remove(key_to_remove);
    node = rbtree.search(key_to_remove);
    if (node == nullptr)
    {
        std::cout << "Successfully removed key " << key_to_remove << " from the tree." << std::endl;
    }
    else
    {
        std::cout << "Failed to remove key " << key_to_remove << " from the tree." << std::endl;
    }

    system("pause");

    return 0;
}