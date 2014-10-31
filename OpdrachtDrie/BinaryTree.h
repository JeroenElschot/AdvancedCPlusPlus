#include <ostream>
#include "SBTNode.h"
#ifndef BINARYTREE_H
#define BINARYTREE_H

using namespace std;

template <class T>
class BinaryTree
{
public:

    BinaryTree()
    {
        root = NULL;
    };

    ~BinaryTree()
    {

    };

    void insertAtTree(T &value)
    {
        SBTNode<T> *fn = find(root, value);
        if(fn == NULL){
            insert(root,NULL,value);
        }
    }

    bool empty()
    {
        return root == NULL;
    }

    bool erase(T &value)
    {
        return remove(root, value);
    }

    void clear()
    {
        destroy(root);
    };

    int getSize()
    {
        return size(root);
    };

    void prettyPrint()
    {
        print(root);
    };

    bool operator<(BinaryTree<T> &value)
    {
        return (root->data < value.first()->data);
    }

    void operator= (BinaryTree<T> &value)
    {
        equals(root,value.first());
    };

    SBTNode<T>*& first()
    {
        return root;
    }

protected: // functions need to be virtual if inheritance is used

    SBTNode<T> *root;

    SBTNode<T> getRoot()
    {
        return root;
    }

    void equals(SBTNode<T>*& node, SBTNode<T>* value)
    {
        if(value != NULL)
        {
            node = new SBTNode<T>();
            *node = *value;
            if(value->left != NULL)
                equals(node->left, value->left);
            if(value->right != NULL)
                equals(node->right, value->right);
        }
    };

    void destroy(SBTNode<T>* node)
    {
        if(node != NULL)
        {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }

        root = NULL;
    };

    void insert(SBTNode<T> *&node, SBTNode<T> *parent, T &value)
    {
        if(node == NULL)
        {
            node = new SBTNode<T>();
            *node = value;
            node->parent = parent;
        }
        else if(value < node->data)
        {
            insert(node->left, node,value);
        }
        else
        {
            insert(node->right, node, value);
        }
    };

    SBTNode<T>* find(SBTNode<T> *&node, T &value)
    {
        if(node == NULL)
            return NULL;
        else if(value == node->data)
            return node;
        else if(value < node->data)
            return find(node->left, value);
        else
            return find(node->right, value);
    };

    bool remove(SBTNode<T> *node, T &value)
    {
        SBTNode<T> *fn = find(node, value);

        if(fn == NULL)
        {
            return false;
        }
        else
        {
            SBTNode<T> *parent = fn->parent;
            bool left = false;
            if(parent->left == fn)
                left = true;
            if(fn->left != NULL && fn->right != NULL)
            {
                if(parent->left == NULL || parent->right == NULL)
                {
                }
                else
                {
                    if(left)
                    {
                        parent->left = fn->left;
                    }
                    else
                    {
                        parent->right = fn->left;
                    }
                    T data = fn->right->data;
                    delete fn;
                    insert(root,NULL,data);
                }
            }
            else if(fn->left != NULL)
            {
                if(left)
                    parent->left = fn->left;
                else
                    parent->right = fn->left;
            }
            else if(fn->right != NULL)
            {
                if(left)
                    parent->left = fn->right;
                else
                    parent->right = fn->right;
            }
            else
            {
                if(left)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            return true;
        };
    };

    int size(SBTNode<T> *&myRoot) const
    {
        if(!myRoot)
        {
            return 0;
        }
        else
        {
            return size(myRoot->left) + 1 + size(myRoot->right); // current + 1
        }
    };

    void print(SBTNode<T> *&myRoot)
    {
        if(myRoot)
        {
            print(myRoot->left);
            print(myRoot->right);
            cout << myRoot->data << endl;
        }
    };


public:
    class iterator
    {

    private:
        SBTNode<T>* current;
        BinaryTree* tree;

    public:

        iterator(SBTNode<T>* c = NULL, BinaryTree* t = NULL) : current(c), tree(t) {}

        iterator(const iterator& other) : current(other.current), tree(other.tree) {}

        T& operator*()
        {
            return current->data;
        }

        const T& operator*() const
        {
            return current->data;
        }

        T* operator->()
        {
            return &(current->data);
        }

        const T* operator->() const
        {
            return &(current->data);
        }

        iterator left()
        {
            return iterator(current->left, tree);
        }

        iterator right()
        {
            return iterator(current->right, tree);
        }

        iterator up()
        {
            return iterator(current->parent, tree);
        }

        iterator operator++()
        {

            if (hasRightChild())
            {
                *this = right();
                while (hasLeftChild())
                    *this = left();
            }
            else
            {
                while (!isRoot() && (up().right() == *this))
                    *this = up();
                *this = up();
            }
            return *this;
        }

        iterator erase(iterator it)
        {
            delete this;
        }

        iterator operator++(int dummy)
        {
            iterator temp = *this;
            if (hasRightChild())
            {
                *this = right();
                while (hasLeftChild())
                    *this = left();
            }
            else
            {
                while (!isRoot() && (up().right() == *this))
                    *this = up();
                *this = up();
            }
            return temp;
        }

        bool isRoot()
        {
            return (current == tree->root);
        }

        bool operator==(const iterator& other)
        {
            return (current == other.current) && (tree == other.tree);
        }

        bool operator!=(const iterator& other)
        {
            return (current != other.current) || (tree != other.tree);
        }

        bool hasLeftChild()
        {
            return current->left != NULL;
        }

        bool hasRightChild()
        {
            return current->right != NULL;
        }

    };

    iterator begin()
    {
        SBTNode<T>* theCurrent = root;
        return iterator(theCurrent,this);
    }

    iterator end()
    {
        return iterator(NULL, this);
    }

};

#endif // BINARYTREE_H
