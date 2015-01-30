#include <ostream>
#include <iostream>

#include "main.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree<int> *bin = new BinaryTree<int>();

    int numberlist [5] = { 1,8, 3, 4, 10 };
    for ( int n=0 ; n<5 ; ++n )
    {
        bin->insertAtTree(numberlist[n]);
    }

    cout << "=======================================" << endl;
    cout << "Printing out the tree" << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << "Size: " << bin->getSize() << endl;
    bin->prettyPrint();

    BinaryTree<int>::iterator it;
    for(BinaryTree<int>::iterator it = bin->begin(); it != bin->end(); it++)
    {
        //cout << *it << endl;
    }

    cout << endl;
    delete bin;
}
