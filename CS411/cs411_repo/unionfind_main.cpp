// unionfind_main.cpp
// Glenn G. Chappell
// 13 Nov 2015
//
// For CS 411/611 Fall 2015
// Simple main program for class UnionFind

#include "unionfind.h"  // for class UnionFind
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


// Main program
// Use all operations for class UnionFind.
int main()
{
    UnionFind uf;  // Our Union-Find object

    // Do some operations
    cout << "Doing Make-Set: 1 2 3 4 5 6 7 8 9"
         << endl;
    uf.makeSet(1);
    uf.makeSet(2);
    uf.makeSet(3);
    uf.makeSet(4);
    uf.makeSet(5);
    uf.makeSet(6);
    uf.makeSet(7);
    uf.makeSet(8);
    uf.makeSet(9);
    cout << endl;
    
    cout << "Doing Union: (1,7) (3,8) (2,6) (1,6) (5,8) (6,9)"
         << endl;
    uf.unionx(1, 7);
    uf.unionx(3, 8);
    uf.unionx(2, 6);
    uf.unionx(1, 6);
    uf.unionx(5, 8);
    uf.unionx(6, 9);
    cout << endl;

    // Check values of find
    cout << "The following should all be equal:"
         << endl;
    cout << "Find(1): " << uf.find(1) << endl;
    cout << "Find(2): " << uf.find(2) << endl;
    cout << "Find(6): " << uf.find(6) << endl;
    cout << "Find(7): " << uf.find(7) << endl;
    cout << "Find(9): " << uf.find(9) << endl;
    cout << endl;

    cout << "These should also be equal, but different from above:"
         << endl;
    cout << "Find(3): " << uf.find(3) << endl;
    cout << "Find(5): " << uf.find(5) << endl;
    cout << "Find(8): " << uf.find(8) << endl;
    cout << endl;

    cout << "Again: equal, but different from each of the above:"
         << endl;
    cout << "Find(4): " << uf.find(4) << endl;
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

