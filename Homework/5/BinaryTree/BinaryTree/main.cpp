//
//  main.cpp
//  BinaryTree
//
//  Created by Laura Kirby on 10/25/17.
//  Copyright © 2017 LK. All rights reserved.
//
/*
 
Given an array of integers, implement a binary tree based algorithm in C++
 to print the array in sorted order. Here you will have to use some 
 inherent properties of the suitable type of the binary tree and the 
 appropriate tree traversal method. Complete the following:

 1. Write a function called BTSort
 2. Write a driver program to test out your method for the array 
    {4, 1, 5, 2, 9, 8, 7, 0, 3, 6}
 3. Analyze the time complexity of your program for the best and worst 
    cases. Write your findings as a comment in your BTSort function.

*/

#include <iostream>
#include "BST.h"
#include "BinNode.h"
#include "BSTNode.h"
#include "dictionary.h"
#include "book.h"

using namespace std;

int main(int argc, const char * argv[]) {

    BST<int, Int*> tree;

    cout << "Size: " << tree.size() << "\n";

    tree.print();

    cout << "Size: " << tree.size() << "\n";

    int unsortedList[10] =  {4, 1, 5, 2, 9, 8, 7, 0, 3, 6};

    for (int i = 0; i < 10; i++ ) {
        cout << "\n\nenter preferred value into tree." << endl;
        tree.insert(unsortedList[i], new Int(unsortedList[i]));
        cout << "value added to BST: " << unsortedList[i] << endl;
    }

    tree.print();

    return 0;
}
