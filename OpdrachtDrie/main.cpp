#include <ostream>
#include <iostream>

#include "main.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree<int> *bin = new BinaryTree<int>();
    int a = 1;
    int b = 8;
    int c = 3;
    int d = 4;
    int e = 10;

    bin->insertAtTree(a);
    bin->insertAtTree(b);
    bin->insertAtTree(c);
    bin->insertAtTree(d);
    bin->insertAtTree(e);
    bin->insertAtTree(e);

    cout << "=======================================" << endl;
    cout << "Printing out the tree" << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << "Size: " << bin->getSize() << endl;

    BinaryTree<int>::iterator it;
    for(BinaryTree<int>::iterator it = bin->begin(); it != bin->end(); it++)
    {
        //cout << *it << endl;
    }

    cout << endl;
    delete bin;
}
