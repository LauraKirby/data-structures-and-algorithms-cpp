//
//  main.cpp
//  BinaryTreeQ6Traverse
//
//  Created by Laura Kirby on 11/29/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
#include "BST.h"
#include "BinNode.h"
#include "BSTNode.h"
#include "dictionary.h"

/* 
 Write three methods to do the following on a binary tree:

 1. traverse along the left side of the tree and print the values: printLeft
 2. traverse along the right side of the tree and print the values: printRight
 3. print only the leaves of a tree: printLeaves
 4. in each of the above cases, analyse the time complexity of your program for the best and worst cases in terms of the height, h of the tree and write it as a comment in your method
*/

int main(int argc, const char * argv[]) {
    int nums[10] = {3,6,10,12,5,1,4,9,16,25};

    BST<int, int*> tree;

    cout << "Size: " << tree.size() << "\n";

    // add one item to tree, the key is 100 the value is the address for the hi variable
    int hi = 100;
    tree.insert(hi, &hi);

    // add multiple items to "tree" using a for-loop
    for(int i = 0; i < 10; i++){
        tree.insert(nums[i], &nums[i]);
    }

    tree.print();

    cout << "Size: " << tree.size() << "\n";



    return 0;
}
