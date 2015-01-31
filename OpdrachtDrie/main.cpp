#include <ostream>
#include <iostream>

#include "main.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree<int> *bin = new BinaryTree<int>();

    int numberlist [9] = { 8,3,1,6,4,7,10,14,13 };
    for ( int n=0 ; n<9 ; ++n )
    {
        bin->insert(numberlist[n]);
    }

    cout << "=======================================" << endl;
    cout << "Printing out the tree" << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << "Size: " << bin->getSize() << endl;
    bin->prettyPrint();

    //BinaryTree<int>::iterator it;
    //for(BinaryTree<int>::iterator it = bin->begin(); it != bin->end(); it++)
    //{
        //cout << *it << endl;
    //}

    //cout << endl;
    delete bin;
}
