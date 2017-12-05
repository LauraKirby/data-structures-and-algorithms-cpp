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
 Given a binary tree:
    1. write a method named "isBST" to check whether the given tree is a binary search tree.
    2. discuss the time complexity of your method as a comment in your program.
        - You may use any procedure to figure this out.
    3. Test your program:
        - Create a BST and Non BST created from the array, {4, 1, 5, 2, 9, 8, 7, 0, 3, 6} in a driver program
*/


int getMaxValue(BinaryNode<int>* leftTree){
    if (leftTree->right() == NULL) {
        return leftTree->element();
    } else {
        return getMaxValue(leftTree->right());
    }
}

int getMinValue(BinaryNode<int>* rightTree){
    if (rightTree->left() == NULL) {
        return rightTree->element();
    } else {
        return getMinValue(rightTree->left());
    }
}


// Returns true if a binary tree is a binary search tree.
// BinaryTreeNode<Key,E>* getroot() { return root; }
bool isBST(BinaryNode<int>* node) {
    if (node == NULL)
        return(true);

    // false if the max of the left is > than us
    if (node->left() != NULL && getMaxValue(node->left()) > node->element())
        return(false);


    // false if the min of the right is <= than us
    if (node->right() != NULL && getMinValue(node->right()) <= node->element())
        return(false);


    // false if, recursively, the left or right is not a BST
    if (!isBST(node->left()) || !isBST(node->right()))
        return(false);

    return(true);
}



int main(int argc, const char * argv[]) {
    int keysAndValues[10] =  {4, 1, 5, 2, 9, 8, 7, 0, 3, 6};

// CREATE A BINARY TREE
    BinaryTree<int, int> testBT;

    for (unsigned int i = 0; i < 10; i++){
        // add keys and values to instance of BinaryTree
        // note: for simplicity, keys and the values are aet to the same value
        testBT.insert(keysAndValues[i], keysAndValues[i]);

    }

// TEST: PRINT INSTANCE OF BINARY TREE
    cout << "\n\n-------------------------------\n1. print BT keys & their levels \n-------------------------------\n";
    testBT.print();

// TEST: GET ROOT
    cout << "\n\n---------------------\n2. print root \n---------------------\n";
    BinaryTreeNode<int,int>* rootBT = testBT.getroot();
    cout << "getroot w/i main.cpp: " << rootBT->element() << "\n";


// TEST: MIN AND MAX VALUE FUNCTIONS
    cout << "\n\n---------------------------\n3. print max value using node \n---------------------------\n";
    int max = getMaxValue(testBT.getroot());
    cout << "getMaxValue w/i main.cpp: " << max << "\n";


// TEST: IS_BST
    cout << "\n\n---------------------------------\n4. determine if 'testBST' is a BST \n---------------------------------\n";

    bool result = isBST(testBT.getroot());

    // print a message that corresponds with the result of calling isBST
    if (result == true)
        cout << "is a BST";
    else
        cout << "is not a BST";


// CREATE A BINARY SEARCH TREE
    int nums[11] = {11,6,4,5,8,10,19,17,43,31,49};

    BST<int, int> tree;

    // add multiple items to "tree" using a for-loop
    for(int i = 0; i < 11; i++){
        tree.insert(nums[i], nums[i]);
    }

    cout << "\n\n--------------------- \n5. print BST \n---------------------\n";
    tree.print();

    cout << "\n\n--------------------------------- \n6. determine if 'tree' is a BST \n---------------------------------\n";

    result = isBST(tree.getroot());

    // print a message that corresponds with the result of calling isBST
    if (result == true)
        cout << "is a BST";
    else
        cout << "is not a BST";

    cout << "\n\nSize: " << tree.size() << "\n";
    tree.clear();

    cout << "Size: " << tree.size() << "\n\n\n";

    return 0;
}
