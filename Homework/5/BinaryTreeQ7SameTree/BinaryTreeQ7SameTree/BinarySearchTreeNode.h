//
//  BinarySearchTreeNode.h
//  BinaryTree
//
//  Created by Laura Kirby on 10/25/17.
//  Copyright © 2017 LK. All rights reserved.
//

#ifndef BinarySearchTreeNode_h
#define BinarySearchTreeNode_h

#include "BinaryNode.h"
using namespace std;

// This is the file to include for access to the complete binary node
// template implementation

// Simple binary tree node implementation
template <typename Key, typename E>
class BinarySearchTreeNode : public BinaryNode<E> {
private:
    Key k;                          // The node's key
    E item;                         // The node's value
    BinarySearchTreeNode* leftChild;             // Pointer to left child
    BinarySearchTreeNode* rightChild;            // Pointer to right child

public:
    // Two constructors -- with and without initial values
    BinarySearchTreeNode() { leftChild = rightChild = NULL; }
    BinarySearchTreeNode(Key K, E e, BinarySearchTreeNode* l = NULL, BinarySearchTreeNode* r = NULL)
    { k = K; item = e; leftChild = l; rightChild = r; }
    ~BinarySearchTreeNode() {}             // Destructor

    // Functions to set and return the value and key
    E& element() { return item; }
    void setElement(const E& e) { item = e; }
    Key& key() { return k; }
    void setKey(const Key& K) { k = K; }

    // Functions to set and return the children
    inline BinarySearchTreeNode* left() const { return leftChild; }
    void setLeft(BinaryNode<E>* b) { leftChild = (BinarySearchTreeNode*)b; }

    inline BinarySearchTreeNode* right() const { return rightChild; }
    void setRight(BinaryNode<E>* b) { rightChild = (BinarySearchTreeNode*)b; }

    // Return true if it is a leaf, false otherwise
    bool isLeaf() { return (leftChild == NULL) && (rightChild == NULL); }

};

#endif
