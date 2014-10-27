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

    void insertAtTree(T &value){
        insert(root,NULL,value);
    }

    bool empty(){
        return root == NULL;
    }

    bool erase(T &value){
        return remove(root, value);
    }

    void clear(){
        destroy(root);
    };

    int getSize() {
       return size(root);
    };

    void prettyPrint(){
        print(root);
    };

    bool operator<(BinaryTree<T> &value){
        return (root->data < value.first()->data);
    }

    void operator= (BinaryTree<T> &value){
        equals(root,value.first());
    };

    SBTNode<T>*& first(){
        return root;
    }

protected:

    SBTNode<T> *root;

    SBTNode<T> getRoot(){
        return root;
    }

    void equals(SBTNode<T>*& node, SBTNode<T>* value){
        if(value != NULL){
            node = new SBTNode<T>();
            *node = *value;
            if(value->left != NULL)
                equals(node->left, value->left);
            if(value->right != NULL)
                equals(node->right, value->right);
        }
    };

    void destroy(SBTNode<T>* node){
        if(node != NULL){
            destroy(node->left);
            destroy(node->right);
            delete node;
        }

        root = NULL;
    };

    void insert(SBTNode<T> *&node, SBTNode<T> *parent, T &value)
    {
        if(node == NULL){
            node = new SBTNode<T>();
            *node = value;
            node->parent = parent;
        } else if(value < node->data){
            insert(node->left, node,value);
        } else {
            insert(node->right, node, value);
        }
    };

    SBTNode<T>* find(SBTNode<T> *node, T &value){
        if(node == NULL)
            return NULL;
        else if(value == node->data)
            return node;
        else if(value < node->data)
            return find(node->left, value);
        else
            return find(node->right, value);
    };

    bool remove(SBTNode<T> *node, T &value){
        SBTNode<T> *fn = find(node, value);

        if(fn == NULL){
            return false;
        } else {
            SBTNode<T> *parent = fn->parent;
            bool left = false;
            if(parent->left == fn)
                left = true;
            if(fn->left != NULL && fn->right != NULL){
                if(parent->left == NULL || parent->right == NULL){

                } else {
                    if(left){
                        parent->left = fn->left;
                    } else {
                        parent->right = fn->left;
                    }
                    T data = fn->right->data;
                    delete fn;
                    insert(root,NULL,data);
                }
            } else if(fn->left != NULL){
                if(left)
                    parent->left = fn->left;
                else
                    parent->right = fn->left;
            } else if(fn->right != NULL){
                if(left)
                    parent->left = fn->right;
                else
                    parent->right = fn->right;
            } else {
                if(left)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            return true;
        };
    };

    int size(SBTNode<T> *&myRoot) const {
       if(!myRoot) {
            return 0;
       } else {
            return size(myRoot->left) + 1 + size(myRoot->right);
        }
    };

    void print(SBTNode<T> *&myRoot)
    {
        if(myRoot){
            cout <<myRoot->data << endl;
            print(myRoot->left);
            print(myRoot->right);
        }
    };

    //iterator
    public:
        class iterator {

      private:
	SBTNode<T>* _current; 	//pointer to current node
	BinaryTree* _tree;	//pointer to tree I belong to

      public:

	//constructor for iterator
	iterator(SBTNode<T>* c = NULL, BinaryTree* t = NULL) : _current(c), _tree(t) {}

	//copy constructor
	iterator(const iterator& other) : _current(other._current), _tree(other._tree) {}

	//returns const reference to data
	T& operator*() const {
	  return _current->data;
	}

	//returns const pointer to data
	T* operator->() const {
	  return &(_current->data);
	}

	//Returns an interator to the left child of the iterator
	iterator left() {
	  return iterator(_current->left, _tree);
	}

	//Returns an interator to the right child of the iterator
	iterator right() {
	  return iterator(_current->right, _tree);
	}

	//Returns an iterator to the parent
	iterator up() {
	  return iterator(_current->parent, _tree);
	}

	//Returns iterator to next node in inorder traversal - it++
	iterator operator++() {

	  //If there is a right child, go right, then left as much as possible
	  if (hasRightChild()) {
	    *this = right();
	    //_current = _current->_right;
	    while (hasLeftChild())
	      *this = left();
	  }
	  else { //go up as long as we're the right child, then up one more
	    while (!isRoot() && (up().right() == *this))
	      *this = up();
	    *this = up();
	  }
	  return *this;
	}

	iterator erase(){

	}

	iterator operator++(int dummy) {
	  iterator temp = *this;
          if (hasRightChild()) {
            *this = right();
            while (hasLeftChild())
              *this = left();
          }
          else {
            while (!isRoot() && (up().right() == *this))
              *this = up();
            *this = up();
          }
	  return temp;
	}


	//Returns true if the iterator points to the root
	bool isRoot() {
	  return (_current == _tree->root);
	}

	//Returns true if the iterator points to a leaf node
	bool isLeaf() {
	  return (_current->_left == NULL) && (_current->_right == NULL);
	}

	//Returns true if the iterators point to the same thing
	bool operator==(const iterator& other) {
	  return (_current == other._current) && (_tree == other._tree);
	}

	//Returns true if the 2 iterators are NOT equal
	bool operator!=(const iterator& other) {
	  return (_current != other._current) || (_tree != other._tree);
	}

	//Returns true if the iterator has a left child
	bool hasLeftChild() {
	  return _current->left != NULL;
	}

	//Returns true if the iterator has a right child
	 bool hasRightChild() {
	  return _current->right != NULL;
	}

    };

    iterator begin(){
        SBTNode<T>* current = root;

        return iterator(current,this);
	}

	iterator end(){
        return iterator(NULL, this);
	}

};

#endif // BINARYTREE_H
