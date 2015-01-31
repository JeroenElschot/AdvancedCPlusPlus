#include <ostream>
#include <iostream>

#include "main.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree<int> *bin = new BinaryTree<int>();

   // int numberlist [5] = { 1,8, 3, 4, 10 };
    int numberlist [9] = { 2,1,3,7,10,5,8,6,4 };
    //int numberlist [15] = { 1,8, 3, 4, 10,11,14,29,21,2,5,6,7,30,31 };
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

    BinaryTree<int>::iterator it;
    for(BinaryTree<int>::iterator it = bin->begin(); it != bin->end(); it++)
    {
        //cout << *it << endl;
    }

    cout << endl;
    delete bin;
}
