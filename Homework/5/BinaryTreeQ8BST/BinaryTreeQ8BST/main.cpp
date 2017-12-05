//
//  main.cpp
//  BinaryTreeQ8BST
//
//  Created by Laura Kirby on 12/3/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
//// ADTs
//#include "dictionary.h"
//#include "BinaryNode.h"
//// Implementation
//#include "BinaryTree.h"
//#include "BinarySearchTree.h"
//#include "BinaryTreeNode.h"
//#include "BinarySearchTreeNode.h"

using namespace std;

/*
 Given a binary tree:
    1. write a method named "isBST" to check whether the given tree is a binary search tree.
    2. discuss the time complexity of your method as a comment in your program.
        - You may use any procedure to figure this out.
    3. Test your program:
        - Create a BST and Non BST created from the array, {4, 1, 5, 2, 9, 8, 7, 0, 3, 6} in a driver program
 
 SOLUTION: See line 530
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

// This is the file to include for access to the complete binary node
// template implementation


// Simple binary tree node implementation
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
class BinaryTree : public Dictionary<Key,E> {
private:
    BinaryTreeNode<Key,E>* root;   // Root of the BinaryTree
    int nodecount;          // Number of nodes in the BinaryTree

    // Private "helper" functions
    void clearHelper(BinaryTreeNode<Key, E>*);
    BinaryTreeNode<Key,E>* insertHelper(BinaryTreeNode<Key, E>*,
                                        const Key&, const E&);
    BinaryTreeNode<Key,E>* deleteMin(BinaryTreeNode<Key, E>*);
    BinaryTreeNode<Key,E>* getMin(BinaryTreeNode<Key, E>*);
    BinaryTreeNode<Key,E>* removeHelper(BinaryTreeNode<Key, E>*, const Key&);
    E findHelper(BinaryTreeNode<Key, E>*, const Key&) const;
    void printHelper(BinaryTreeNode<Key, E>*, int) const;


public:
    BinaryTree() { root = NULL; nodecount = 0; }    // Constructor
    ~BinaryTree() { clearHelper(root); }            // Destructor

    void clear()   // Reinitialize tree
    { clearHelper(root); root = NULL; nodecount = 0; }

    // Insert a record into the tree.
    // k Key value of the record.
    // e The record to insert.
    void insert(const Key& k, const E& e) {
        root = insertHelper(root, k, e);
        nodecount++;
    }

    // BinaryTreeNode<Key,E>* getroot() { return root; }
    BinaryTreeNode<Key,E>* getroot() {
        BinaryTreeNode<int,int>* node = root;
        return node;
    };

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

    void print() const {                            // Print the contents of the BinaryTree
        if (root == NULL) cout << "The BinaryTree is empty.\n";
        else printHelper(root, 0);
    }
};


// Clean up BinaryTree by releasing space back free store
template <typename Key, typename E>
void BinaryTree<Key, E>::
clearHelper(BinaryTreeNode<Key, E>* root) {
    if (root == NULL) return;
    clearHelper(root->left());
    clearHelper(root->right());
    delete root;
}

// Insert a node into the BinaryTree, returning the updated tree
template <typename Key, typename E>
BinaryTreeNode<Key, E>* BinaryTree<Key, E>::insertHelper(
                                                         BinaryTreeNode<Key, E>* root, const Key& k, const E& it ) {
    if (root == NULL)  // Empty tree: create node
        return new BinaryTreeNode<Key, E>(k, it, NULL, NULL);
    else {
        if ( nodecount % 2 == 1) // condition whether to go to left or right
            root->setLeft(insertHelper(root->left(), k, it));
        else
            root->setRight(insertHelper(root->right(), k, it));
        return root; // Return tree with node inserted
    }
}

// return BinaryTreeNode with the smallest value
template <typename Key, typename E>
BinaryTreeNode<Key, E>* BinaryTree<Key, E>::
getMin(BinaryTreeNode<Key, E>* rightTree) {
    if (rightTree->left() == NULL){
        return rightTree;
    } else return getMin(rightTree->left());
}

// Delete the minimum value from the BinaryTree, returning the revised BinaryTree
template <typename Key, typename E>
BinaryTreeNode<Key, E>* BinaryTree<Key, E>::
deleteMin(BinaryTreeNode<Key, E>* rightTree) {
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
BinaryTreeNode<Key, E>* BinaryTree<Key, E>::
removeHelper(BinaryTreeNode<Key, E>* rightTree, const Key& k) {
    if (rightTree == NULL) return NULL;             // k is not in tree
    else if (k < rightTree->key())
        rightTree->setLeft(removeHelper(rightTree->left(), k));
    else if (k > rightTree->key())
        rightTree->setRight(removeHelper(rightTree->right(), k));
    else {                                          // Found: remove it
        BinaryTreeNode<Key, E>* temp = rightTree;
        if (rightTree->left() == NULL) {            // Only a right child
            rightTree = rightTree->right();         //  so point to right
            delete temp;
        }
        else if (rightTree->right() == NULL) {      // Only a left child
            rightTree = rightTree->left();          //  so point to left
            delete temp;
        }
        else {                                      // Both children are non-empty
            BinaryTreeNode<Key, E>* temp = getMin(rightTree->right());
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
E BinaryTree<Key, E>::
findHelper(BinaryTreeNode<Key, E>* root, const Key& k) const {
    if (root == NULL) return NULL;                  // Return if empty tree
    if (k < root->key())
        return findHelper(root->left(), k);         // Check left
    else if (k > root->key())
        return findHelper(root->right(), k);        // Check right
    else return root->element();                    // Found it
}


// Print out a BinaryTree
template <typename Key, typename E>
void BinaryTree<Key, E>::
printHelper(BinaryTreeNode<Key, E>* root, int level) const {
    if (root == NULL) return;                       // Return if empty tree
    printHelper(root->left(), level+1);             // Move down left subtree
    cout << "level: " << level;
    for (int i=0; i<level; i++)                     // Indent to level
        cout << "  ";
    cout << root->key() << "\n";                    // Print node value
    printHelper(root->right(), level+1);            // Do right subtree
}

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

    // BinaryTreeNode<Key,E>* getroot() { return root; }
    BinaryNode<Key>* getroot() {
        BinaryNode<int>* node = root;
        return node;
    };

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


// --------------------------------
// SOLUTION IMPLEMENTATION
// --------------------------------

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
