//
//  main.cpp
//  BinaryTreeQ9Mirror
//
//  Created by Laura Kirby on 12/4/17.
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
 Write a C++ method to convert a binary tree to its mirror image: mirrorTree. Here you will have to swap each of the left sibling with the right sibling for all the nodes. If there is only one sibling then you convert it to its mirror image.

 1. test your method with a complete binary tree created with the following array, {4, 1, 5, 2, 9, 8, 7, 0, 3, 6}
 2. analyze the time complexity of your program as a comment in your program
 3. submit your program as a one file
 */

void mirror(BinaryNode<int>* node) {
    // I believe that the time complexity is O(N).
    if (node == NULL) {
        return;
    }
    else {
        BinaryNode<int>* temp = node;

        // do the subtrees
        mirror(node->left());
        mirror(node->right());

        // create a temporary variable for the left node
        temp = node->left();

        // swap left and right nodes
        node->setLeft(node->right());
        node->setRight(temp);

    }
}



int main(int argc, const char * argv[]) {
// CREATE A BINARY SEARCH TREE
    int nums[11] = {11,6,4,5,8,10,19,17,43,31,49};

    BST<int, int> tree;

    // add multiple items to "tree" using a for-loop
    for(int i = 0; i < 11; i++){
        tree.insert(nums[i], nums[i]);
    }

// TEST: Binary Search Tree
    cout << "\n\n--------------------------------- \n1. Print normal image of BST \n---------------------------------\n";
    tree.print();

// TEST: MIRROR
    cout << "\n\n--------------------------------- \n2. Print mirror image of BST \n---------------------------------\n";
    mirror(tree.getroot());
    tree.print();


    tree.clear();

    return 0;
}
