//
//  BinaryTreeNode.h
//  BinaryTreeQ8BST
//
//  Created by Laura Kirby on 12/3/17.
//  Copyright © 2017 LK. All rights reserved.
//

// This file includes all of the pieces of the
// Binary Search Tree implementation

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

// Node implementation
#include "BinarySearchTreeNode.h"
// Dictionary ADT
#include "dictionary.h"
using namespace std;


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

#endif
