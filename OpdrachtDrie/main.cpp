#include <ostream>
#include <iostream>

#include "main.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree<int> *bin = new BinaryTree<int>();

    int a = 1;
    int b = 3;
    int c = 1;
    int d = 9;
    int e = 10;
    int f = 5;
    int g = 4;
    int h = 2;

    bin->insertAtTree(a);
    bin->insertAtTree(b);
    bin->insertAtTree(c);
    bin->insertAtTree(d);
    bin->insertAtTree(e);
    bin->insertAtTree(f);
    bin->insertAtTree(g);
    bin->insertAtTree(h);

    cout << endl;
    cout << "=======================================" << endl;
    cout << "Printing out the tree" << endl;
    cout << "=======================================" << endl;
    //bin->prettyPrint();
    BinaryTree<int>::iterator it;
    for(BinaryTree<int>::iterator it = bin->begin(); it != bin->end(); ++it)
    {
        cout << *it << endl;
    }

    cout << endl;
    cout << "=======================================" << endl;
    cout << "Printing out information about the tree" << endl;
    cout << "=======================================" << endl;

    int size = bin->getSize();
    cout << "size: " << size << endl;


    bin->clear();

    delete bin;
}
