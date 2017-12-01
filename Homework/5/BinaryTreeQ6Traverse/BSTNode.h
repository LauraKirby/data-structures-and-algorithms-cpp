//
//  BSTNode.h
//  BinaryTree
//
//  Created by Laura Kirby on 10/25/17.
//  Copyright © 2017 LK. All rights reserved.
//



#ifndef BSTNode_h
#define BSTNode_h

#include "BinNode.h"
using namespace std;
// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include for access to the complete binary node
// template implementation


// Simple binary tree node implementation
template <typename Key, typename E>
class BSTNode : public BinNode<E> {
private:
    Key k;                          // The node's key
    E item;                         // The node's value
    BSTNode* leftChild;             // Pointer to left child
    BSTNode* rightChild;            // Pointer to right child

public:
    // Two constructors -- with and without initial values
    BSTNode() { leftChild = rightChild = NULL; }
    BSTNode(Key K, E e, BSTNode* l = NULL, BSTNode* r = NULL)
    { k = K; item = e; leftChild = l; rightChild = r; }
    ~BSTNode() {}             // Destructor

    // Functions to set and return the value and key
    E& element() { return item; }
    void setElement(const E& e) { item = e; }
    Key& key() { return k; }
    void setKey(const Key& K) { k = K; }

    // Functions to set and return the children
    inline BSTNode* left() const { return leftChild; }
    void setLeft(BinNode<E>* b) { leftChild = (BSTNode*)b; }

    inline BSTNode* right() const { return rightChild; }
    void setRight(BinNode<E>* b) { rightChild = (BSTNode*)b; }

    // Return true if it is a leaf, false otherwise
    bool isLeaf() { return (leftChild == NULL) && (rightChild == NULL); }
};


#endif /* BSTNode_h */
