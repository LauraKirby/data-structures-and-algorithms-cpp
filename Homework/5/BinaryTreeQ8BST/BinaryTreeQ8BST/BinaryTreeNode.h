//
//  BinaryTreeNode.h
//  BinaryTreeQ8BST
//
//  Created by Laura Kirby on 12/3/17.
//  Copyright © 2017 LK. All rights reserved.
//

#ifndef BinaryTreeNode_h
#define BinaryTreeNode_h

#include "BinaryNode.h"
using namespace std;

// Binary tree node implementation
template <typename Key, typename E>
class BinaryTreeNode : public BinaryNode<E> {
private:
    Key k;                          // The node's key
    E item;                         // The node's value
    BinaryTreeNode* leftChild;             // Pointer to left child
    BinaryTreeNode* rightChild;            // Pointer to right child

public:
    // Two constructors -- with and without initial values
    BinaryTreeNode() { leftChild = rightChild = NULL; }
    BinaryTreeNode(Key K, E e, BinaryTreeNode* l = NULL, BinaryTreeNode* r = NULL)
    { k = K; item = e; leftChild = l; rightChild = r; }
    ~BinaryTreeNode() {}             // Destructor

    // Functions to set and return the value and key
    E& element() { return item; }
    void setElement(const E& e) { item = e; }
    Key& key() { return k; }
    void setKey(const Key& K) { k = K; }

    // Functions to set and return the children
    inline BinaryTreeNode* left() const { return leftChild; }
    void setLeft(BinaryNode<E>* b) { leftChild = (BinaryTreeNode*)b; }

    inline BinaryTreeNode* right() const { return rightChild; }
    void setRight(BinaryNode<E>* b) { rightChild = (BinaryTreeNode*)b; }

    // Return true if it is a leaf, false otherwise
    bool isLeaf() { return (leftChild == NULL) && (rightChild == NULL); }
};

#endif
