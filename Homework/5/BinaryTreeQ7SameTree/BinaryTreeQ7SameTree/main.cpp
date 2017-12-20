//
//  main.cpp
//  BinaryTreeQ7SameTree
//
//  Created by Laura Kirby on 12/02/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
//// ADTs
//#include "dictionary.h"
//#include "BinaryNode.h"
//// Implementation
//#include "BinarySearchTree.h"
//#include "BinarySearchTreeNode.h"
using namespace std;

/*
 NOTE: This program does not comple. I am unsure how to resolve the issue. I did psuedo code a solution and then 
 tried my best to write it in C++. I am getting an error and I'm unsure how to resolve it. I have spent several 
 hours on this problem and need to move forward with the next question. (Upate: After completing the rest of the 
 assignment, I was able to resolve the error, however, i didn't have the time go back and fix the next items. 
 I didn't realize that the stanford resource provides a description on how to sove these problems)
 

 Given two binary trees, write a method named "isSameTree" that returns true if 
 the two trees are identical. An identical tree pair are made of nodes with the 
 same values arranged in the same way.

 Analyze the time complexity of your program for the best and worst cases in terms 
 of both number of element, n and the height, h of the tree and write it as a comment 
 in your method; you may use any procedure to figure this out including the procedures 
 we discussed in the class
 
 1. Test your program with two simple similar trees in a driver program
 2. Test your program with two simple dissimilar trees in the same driver program.

 */

// The Dictionary abstract class.
template <typename Key, typename E>
class  Dictionary {
private:
    void operator =(const Dictionary&) {}
    Dictionary(const Dictionary&) {}

public:
    Dictionary() {}          // Default constructor
    virtual ~Dictionary() {} // Base destructor

    // Reinitialize dictionary
    virtual void clear() = 0;

    // Insert a record
    // k: The key for the record being inserted.
    // e: The record being inserted.
    virtual void insert(const Key& k, const E& e) = 0;

    // Remove and return a record.
    // k: The key of the record to be removed.
    // Return: A maching record. If multiple records match
    // "k", remove an arbitrary one. Return NULL if no record
    // with key "k" exists.
    virtual E remove(const Key& k) = 0;

    // Remove and return an arbitrary record from dictionary.
    // Return: The record removed, or NULL if none exists.
    virtual E removeAny() = 0;

    // Return: A record matching "k" (NULL if none exists).
    // If multiple records match, return an arbitrary one.
    // k: The key of the record to find
    virtual E find(const Key& k) const = 0;

    // Return the number of records in the dictionary.
    virtual int size() = 0;
};

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

// Binary Search Tree implementation for the Dictionary ADT
template <typename Key, typename E>
class BST : public Dictionary<Key,E> {
private:
    BinarySearchTreeNode<Key,E>* root;   // Root of the BST
    int nodecount;          // Number of nodes in the BST

    // Private "helper" functions
    void clearHelper(BinarySearchTreeNode<Key, E>*);
    BinarySearchTreeNode<Key,E>* insertHelper(BinarySearchTreeNode<Key, E>*,
                                              const Key&, const E&);
    BinarySearchTreeNode<Key,E>* deleteMin(BinarySearchTreeNode<Key, E>*);
    BinarySearchTreeNode<Key,E>* getMin(BinarySearchTreeNode<Key, E>*);
    BinarySearchTreeNode<Key,E>* removeHelper(BinarySearchTreeNode<Key, E>*, const Key&);
    E findHelper(BinarySearchTreeNode<Key, E>*, const Key&) const;
    void printHelper(BinarySearchTreeNode<Key, E>*, int) const;


public:
    BST() { root = NULL; nodecount = 0; }  // Constructor
    ~BST() { clearHelper(root); }            // Destructor

    void clear()   // Reinitialize tree
    { clearHelper(root); root = NULL; nodecount = 0; }

    // Insert a record into the tree.
    // k Key value of the record.
    // e The record to insert.
    void insert(const Key& k, const E& e) {
        root = insertHelper(root, k, e);
        nodecount++;
    }

    // Get root of current tree
    BinaryNode<Key>* getroot() {
        BinaryNode<int>* node = root;
        return node;
    };

    void setRightElement(BinarySearchTreeNode<Key, E>* node, int value){
        node->right = value;
    }

    void setLeftElement(BinarySearchTreeNode<Key, E>* node, int value){
        node->left = value;
    }

    // Remove a record from the tree.
    // k Key value of record to remove.
    // Return: The record removed, or NULL if there is none.
    E remove(const Key& k) {
        E temp = findHelper(root, k);   // First find it
        if (temp != NULL) {
            root = removeHelper(root, k);
            nodecount--;
        }
        return temp;
    }

    // Remove and return the root node from the dictionary.
    // Return: The record removed, null if tree is empty.
    E removeAny() {  // Delete min value
        if (root != NULL) {
            E temp = root->element();
            root = removeHelper(root, root->key());
            nodecount--;
            return temp;
        }
        else return NULL;
    }

    // Return Record with key value k, NULL if none exist.
    // k: The key value to find. */
    // Return some record matching "k".
    // Return true if such exists, false otherwise. If
    // multiple records match "k", return an arbitrary one.
    E find(const Key& k) const { return findHelper(root, k); }

    // Return the number of records in the dictionary.
    int size() { return nodecount; }

    void print() const {                            // Print the contents of the BST
        if (root == NULL) cout << "The BST is empty.\n";
        else printHelper(root, 0);
    }
};

// Clean up BST by releasing space back free store
template <typename Key, typename E>
void BST<Key, E>::
clearHelper(BinarySearchTreeNode<Key, E>* root) {
    if (root == NULL) return;
    clearHelper(root->left());
    clearHelper(root->right());
    delete root;
}

// Insert a node into the BST, returning the updated tree
template <typename Key, typename E>
BinarySearchTreeNode<Key, E>* BST<Key, E>::
insertHelper( BinarySearchTreeNode<Key, E>* root, const Key& k, const E& it ) {
    if (root == NULL)  // Empty tree: create node
        return new BinarySearchTreeNode<Key, E>(k, it, NULL, NULL);
    if (k < root->key())
        root->setLeft(insertHelper(root->left(), k, it));
    else root->setRight(insertHelper(root->right(), k, it));
    return root;       // Return tree with node inserted
}

// Delete the minimum value from the BST, returning the revised BST
template <typename Key, typename E>
BinarySearchTreeNode<Key, E>* BST<Key, E>::
getMin(BinarySearchTreeNode<Key, E>* rightTree) {
    if (rightTree->left() == NULL)
        return rightTree;
    else return getMin(rightTree->left());
}

template <typename Key, typename E>
BinarySearchTreeNode<Key, E>* BST<Key, E>::
deleteMin(BinarySearchTreeNode<Key, E>* rightTree) {
    if (rightTree->left() == NULL)                     // Found min
        return rightTree->right();
    else {                                             // Continue left
        rightTree->setLeft(deleteMin(rightTree->left()));
        return rightTree;
    }
}

// Remove a node with key value k
// Return: The tree with the node removed
template <typename Key, typename E>
BinarySearchTreeNode<Key, E>* BST<Key, E>::
removeHelper(BinarySearchTreeNode<Key, E>* rightTree, const Key& k) {
    if (rightTree == NULL) return NULL;             // k is not in tree
    else if (k < rightTree->key())
        rightTree->setLeft(removeHelper(rightTree->left(), k));
    else if (k > rightTree->key())
        rightTree->setRight(removeHelper(rightTree->right(), k));
    else {                                          // Found: remove it
        BinarySearchTreeNode<Key, E>* temp = rightTree;
        if (rightTree->left() == NULL) {            // Only a right child
            rightTree = rightTree->right();         //  so point to right
            delete temp;
        }
        else if (rightTree->right() == NULL) {      // Only a left child
            rightTree = rightTree->left();          //  so point to left
            delete temp;
        }
        else {                                      // Both children are non-empty
            BinarySearchTreeNode<Key, E>* temp = getMin(rightTree->right());
            rightTree->setElement(temp->element());
            rightTree->setKey(temp->key());
            rightTree->setRight(deleteMin(rightTree->right()));
            delete temp;
        }
    }
    return rightTree;
}

// Find a node with the given key value
template <typename Key, typename E>
E BST<Key, E>::
findHelper(BinarySearchTreeNode<Key, E>* root, const Key& k) const {
    if (root == NULL) return NULL;                  // Return if empty tree
    if (k < root->key())
        return findHelper(root->left(), k);         // Check left
    else if (k > root->key())
        return findHelper(root->right(), k);        // Check right
    else return root->element();                    // Found it
}

// Print out a BST
template <typename Key, typename E>
void BST<Key, E>::
printHelper(BinarySearchTreeNode<Key, E>* root, int level) const {
    if (root == NULL) return;                       // Return if empty tree
    printHelper(root->left(), level+1);             // Move down left subtree
    cout << "level: " << level;
    for (int i=0; i<level; i++)                     // Indent to level
        cout << "  ";
    cout << root->key() << "\n";                    // Print node value
    printHelper(root->right(), level+1);            // Do right subtree
}


bool isSameTree(BinaryNode<int>* nodeA, BinaryNode<int>* nodeB){
    // both nodes are empty, return true
    if (nodeA == NULL && nodeB == NULL) return (true);
    // both nodes are not empty, compare them
    // this will never be the final return,
    else if (nodeA != NULL && nodeB != NULL) {
        return (
               nodeA->element() == nodeB->element() &&
               isSameTree(nodeA->left(), nodeB->left()) &&
               isSameTree(nodeA->right(), nodeB->right())
               );
    } // 3. one empty, one not -> false
    else return(false);
}

int main(int argc, const char * argv[]) {
    int nums[5] = {11,6,4,5,8};
    int nums2[5] = {10,7,13,3,1};

    BST<int, int>* tree1;
    BST<int, int>* tree2;
    BST<int, int>* tree3;

    // create same tree
    for(int i = 0; i < 5; i++){
        tree1->insert(nums[i], nums[i]);
        tree2->insert(nums[i], nums[i]);
    }

    // create different tree
    for(int i = 0; i < 5; i++){
        tree3->insert(nums2[i], nums2[i]);
    }

    cout << "\n\nSize: " << tree1->size() << "\n";
    tree1->clear();
    tree2->clear();
    tree3->clear();


    return 0;
}
