//
//  BinaryNode.h
//  BinaryTree
//
//  Created by Laura Kirby on 10/25/17.
//  Copyright © 2017 LK. All rights reserved.
//

#ifndef BinaryNode_h
#define BinaryNode_h
using namespace std;

// Binary node abstract class
template <typename E> class BinaryNode {
public:
    virtual ~BinaryNode() {} // Base destructor

    // Return the node's value
    virtual E& element() = 0;

    // Set the node's value
    virtual void setElement(const E&) = 0;

    // Return the node's left child
    virtual BinaryNode* left() const = 0;

    // Set the node's left child
    virtual void setLeft(BinaryNode*) = 0;

    // Return the node's right child
    virtual BinaryNode* right() const = 0;

    // Set the node's right child
    virtual void setRight(BinaryNode*) = 0;

    // Return true if the node is a leaf, false otherwise
    virtual bool isLeaf() = 0;
};

#endif /* BinaryNode_h */
