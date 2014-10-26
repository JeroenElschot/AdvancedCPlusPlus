#ifndef TREE_H
#define TREE_H


#include <iostream>


using namespace std;


template<class T>
class BinaryTree
{
struct Node
    {
        T data;
        Node* lChildptr;
        Node* rChildptr;

        Node(T dataNew)
        {
            data = dataNew;
            lChildptr = NULL;
            rChildptr = NULL;
        }
    };
private:
    Node* root;

        void Insert(T newData, Node* &theRoot)
        {
            if(theRoot == NULL)
            {
                theRoot = new Node(newData);
                return;
            }

            if(newData < theRoot->data)
                Insert(newData, theRoot->lChildptr);
            else
                Insert(newData, theRoot->rChildptr);;
        }

        void PrintTree(Node* theRoot)
        {
            if(theRoot != NULL)
            {
                PrintTree(theRoot->lChildptr);
                cout<< theRoot->data<<" ";;
                PrintTree(theRoot->rChildptr);
            }
        }

    public:
        BinaryTree()
        {
            root = NULL;
        }

        void AddItem(T newData)
        {
            Insert(newData, root);
        }

        void PrintTree()
        {
            PrintTree(root);
        }
    };

    int main()
    {
        cout << "hhaha" << endl;
        BinaryTree<int> *myBT = new BinaryTree();
        myBT->AddItem(1);
        myBT->AddItem(7);
        myBT->AddItem(1);
        myBT->AddItem(10);
        myBT->AddItem(4);
        myBT->PrintTree();
    }

#endif // TREE_H
