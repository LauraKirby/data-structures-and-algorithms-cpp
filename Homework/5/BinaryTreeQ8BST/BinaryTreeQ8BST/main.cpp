//
//  main.cpp
//  BinaryTreeQ8BST
//
//  Created by Laura Kirby on 12/3/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
// ADTs
#include "dictionary.h"
#include "BinaryNode.h"
// Implementation
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "BinaryTreeNode.h"
#include "BinarySearchTreeNode.h"

using namespace std;

/*
 Given a binary tree
    1. write a method named "isBST" to check whether the given tree is a binary search tree.
    2. discuss the time complexity of your method as a comment in your program.
        - You may use any procedure to figure this out.
    3. Test your program:
        - Create a BST and Non BST created from the array, {4, 1, 5, 2, 9, 8, 7, 0, 3, 6} in a driver program
 */


int main(int argc, const char * argv[]) {
    int keysAndValues[10] =  {4, 1, 5, 2, 9, 8, 7, 0, 3, 6};

    // Create of an empty tree
    BinaryTree<int, int> testBT;

    for (unsigned int i = 0; i < 10; i++){
        // add keys and values to instance of BinaryTree
        // note: for simplicity, keys and the values are aet to the same value
        testBT.insert(keysAndValues[i], keysAndValues[i]);

    }

    cout << "Printing keys along with the respective levels "   << endl; // prints

    testBT.print(); // prints the values


    int nums[11] = {11,6,4,5,8,10,19,17,43,31,49};

    BST<int, int> tree;

    cout << "Size: " << tree.size() << "\n";

    // add multiple items to "tree" using a for-loop
    for(int i = 0; i < 11; i++){
        tree.insert(nums[i], nums[i]);
    }

    tree.print();
    tree.printLeft();
    tree.printRight();
    tree.printLeaves();
    
    cout << "\n\nSize: " << tree.size() << "\n";
    tree.clear();
    
    cout << "Size: " << tree.size() << "\n\n\n";
    
    return 0;
}
