#include <iostream>
#include "BTree.h"
int main()
{
    BTree<int> tree;
    tree.add(5);
    tree.add(15);
    tree.add(4);
    tree.add(3);
    tree.add(8);
    tree.add(7);
    tree.add(2);
    tree.add(1);
    tree.add(10);
    tree.print();
    //cout << "Min: " << tree.min() << endl;
    //cout << "Max: " << tree.max() << endl;
    //cout << "Find 46: " << boolalpha << tree.find(46) << endl;
    //cout << "Find 10: " << boolalpha << tree.find(10) << endl;
    //tree.clear();
    //tree.print();
    //tree.printRange(9, 20);
    tree.removeSubTree(8);
    tree.print();
}
