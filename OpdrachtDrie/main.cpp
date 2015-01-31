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
    intTree();
    stringTree();
    return 0;
}

void intTree(){

    BinaryTree<int> *bin = new BinaryTree<int>();
    int numberlist [10] = { 5,4,7,6,2,19,3,1,9,20 }; // http://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/220px-Binary_search_tree.svg.png
    for ( int n=0 ; n<10 ; ++n )
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

    BinaryTree<int>::iterator it;
    for(BinaryTree<int>::iterator it = bin->begin(); it != bin->end(); it++)
    {
        cout << *it << endl;
    }

    cout << endl;
    delete bin;
}

void charTree(){

    BinaryTree<char> *bin = new BinaryTree<char>();
    char numberlist[] = { 'd','a','c','z','n','b','m'};
    for ( int n=0 ; n<7 ; ++n )
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

    BinaryTree<char>::iterator it;
    for(BinaryTree<char>::iterator it = bin->begin(); it != bin->end(); it++)
    {
        cout << *it << endl;
    }

    cout << endl;
    delete bin;

}

void stringTree(){

    BinaryTree<string> *bin = new BinaryTree<string>();
    string numberlist[7] = { "jan","piet", "klaas","aap","kip","koe","varken"};
    for ( int n=0 ; n<7 ; ++n )
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

    BinaryTree<string>::iterator it;
    for(BinaryTree<string>::iterator it = bin->begin(); it != bin->end(); it++)
    {
        cout << *it << endl;
    }

    cout << endl;

    delete bin;

}
