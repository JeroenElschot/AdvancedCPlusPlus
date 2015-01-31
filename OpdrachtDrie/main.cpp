#include <ostream>
#include <iostream>
#include <string>

#include "main.h"
#include "BinaryTree.h"

using namespace std;

void charTree();
void intTree();
void stringTree();

int main()
{
    charTree();
    //intTree();
    //stringTree();
    return 0;
}

void intTree(){

    BinaryTree<int> *bin = new BinaryTree<int>();
    int numberlist [9] = { 8,3,1,6,4,7,10,14,13 }; // http://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/220px-Binary_search_tree.svg.png
    for ( int n=0 ; n<9 ; ++n )
    {
        bin->insert(numberlist[n]);
    }

    cout << "=======================================" << endl;
    cout << "Printing out the tree" << endl;
    cout << "Turn your head or screen to read the tree" << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << "Size: " << bin->size() << endl;
    bin->prettyPrint();
    cout << endl;
    cout << "=======================================" << endl;

    //BinaryTree<int>::iterator it;
    //for(BinaryTree<int>::iterator it = bin->begin(); it != bin->end(); it++)
    //{
    //    cout << *it << endl;
    //}

    //cout << endl;
    delete bin;
}

void charTree(){

    BinaryTree<char> *bin = new BinaryTree<char>();
    char numberlist[] = { 'a','b','c','d','z'};
    for ( int n=0 ; n<5 ; ++n )
    {
        bin->insert(numberlist[n]);
    }

    cout << "=======================================" << endl;
    cout << "Printing out the tree" << endl;
    cout << "Turn your head or screen to read the tree" << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << "Size: " << bin->size() << endl;
    bin->prettyPrint();
    cout << endl;
    cout << "=======================================" << endl;

    delete bin;

}

void stringTree(){

    BinaryTree<string> *bin = new BinaryTree<string>();
    string numberlist[5] = { "aap","mies", "boot","twix","rofl"};
    for ( int n=0 ; n<5 ; ++n )
    {
        bin->insert(numberlist[n]);
    }

    cout << "=======================================" << endl;
    cout << "Printing out the tree" << endl;
    cout << "Turn your head or screen to read the tree" << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << "Size: " << bin->size() << endl;
    bin->prettyPrint();
    cout << endl;
    cout << "=======================================" << endl;

    delete bin;

}
