// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This file includes all of the pieces of the BST implementation

// Include the node implementation
#include "BSTNode.h"

// Include the dictionary ADT
#include "dictionary.h"

// Binary Search Tree implementation for the Dictionary ADT
template <typename Key, typename E>
class BST : public Dictionary<Key,E> {
private:
    BSTNode<Key,E>* root;   // Root of the BST
    int nodecount;          // Number of nodes in the BST

    // Private "helper" functions
    void clearHelper(BSTNode<Key, E>*);
    BSTNode<Key,E>* insertHelper(BSTNode<Key, E>*,
                               const Key&, const E&);
    BSTNode<Key,E>* deleteMin(BSTNode<Key, E>*);
    BSTNode<Key,E>* getMin(BSTNode<Key, E>*);
    BSTNode<Key,E>* removeHelper(BSTNode<Key, E>*, const Key&);
    E findHelper(BSTNode<Key, E>*, const Key&) const;
    void printHelper(BSTNode<Key, E>*, int) const;
    void printLeftHelper(BSTNode<Key, E>*, int) const;
    void printRightHelper(BSTNode<Key, E>*, int) const;
    void printLeavesHelper(BSTNode<Key, E>*, int) const;


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

    void printLeft() const {                        // Print left side of tree
        cout << "\n\n-----------------" << "\n printLeft: \n" << "-----------------\n";
        if (root == NULL) cout << "The BST is empty.\n";
        else {
            cout << "root: " << root->key() << "\n" << "Left nodes: \n";
            if (root->left() == NULL) cout << "There are no nodes to the left\n";
            printLeftHelper(root->left(), 0);       // Move down and print left subtree
        }
        return;
    }

    void printRight() const {                       // Print right side of tree
        cout << "\n\n-----------------" << "\n printRight: \n" << "-----------------\n";
        if (root == NULL) cout << "The BST is empty.\n";
        else {
            cout << "root: " << root->key() << "\n" << "Right nodes: \n";
            if (root->right() == NULL) cout << "There are no nodes to the right\n";
            printRightHelper(root->right(), 0);     // Move down and print right subtree
        }
        return;
    }

    void printLeaves() const {
        cout << "\n\n-----------------" << "\n printLeaves: \n" << "-----------------\n";
        if (root == NULL) cout << "The BST is empty.\n";
        else if (root->left() != NULL || root->right() != NULL) printLeavesHelper(root, 0);
    }
};

// Clean up BST by releasing space back free store
template <typename Key, typename E>
void BST<Key, E>::
clearHelper(BSTNode<Key, E>* root) {
    if (root == NULL) return;
    clearHelper(root->left());
    clearHelper(root->right());
    delete root;
}

// Insert a node into the BST, returning the updated tree
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
insertHelper( BSTNode<Key, E>* root, const Key& k, const E& it ) {
    if (root == NULL)  // Empty tree: create node
        return new BSTNode<Key, E>(k, it, NULL, NULL);
    if (k < root->key())
        root->setLeft(insertHelper(root->left(), k, it));
    else root->setRight(insertHelper(root->right(), k, it));
    return root;       // Return tree with node inserted
}

// Delete the minimum value from the BST, returning the revised BST
template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
getMin(BSTNode<Key, E>* rightTree) {
    if (rightTree->left() == NULL)
        return rightTree;
    else return getMin(rightTree->left());
}

template <typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::
deleteMin(BSTNode<Key, E>* rightTree) {
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
BSTNode<Key, E>* BST<Key, E>::
removeHelper(BSTNode<Key, E>* rightTree, const Key& k) {
    if (rightTree == NULL) return NULL;             // k is not in tree
    else if (k < rightTree->key())
        rightTree->setLeft(removeHelper(rightTree->left(), k));
    else if (k > rightTree->key())
        rightTree->setRight(removeHelper(rightTree->right(), k));
    else {                                          // Found: remove it
        BSTNode<Key, E>* temp = rightTree;
        if (rightTree->left() == NULL) {            // Only a right child
            rightTree = rightTree->right();         //  so point to right
            delete temp;
        }
        else if (rightTree->right() == NULL) {      // Only a left child
            rightTree = rightTree->left();          //  so point to left
            delete temp;
        }
        else {                                      // Both children are non-empty
            BSTNode<Key, E>* temp = getMin(rightTree->right());
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
findHelper(BSTNode<Key, E>* root, const Key& k) const {
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
printHelper(BSTNode<Key, E>* root, int level) const {
    if (root == NULL) return;                       // Return if empty tree
    printHelper(root->left(), level+1);             // Move down left subtree
    cout << "level: " << level;
    for (int i=0; i<level; i++)                     // Indent to level
        cout << "  ";
    cout << root->key() << "\n";                    // Print node value
    printHelper(root->right(), level+1);            // Do right subtree
}

template <typename Key, typename E>
void BST<Key, E>::
printLeftHelper(BSTNode<Key, E>* root, int level) const {
    // as long as "root" holds a "truthy" value
    // continue to move down the the tree, with each call, pass in root->left
    if (root == NULL) return;
    printLeftHelper(root->left(), level+1);             // Move down the left subtree
    cout << "left: " << root->key() << "\n";            // Print node value
}

template <typename Key, typename E>
void BST<Key, E>::
printRightHelper(BSTNode<Key, E>* root, int level) const {
    // as long as "root" holds a "truthy" value
    // continue to move down the the tree, with each call, pass in root->right
    if (root == NULL) return;
    printRightHelper(root->right(), level+1);       // Move down the right subtree
    cout << "right: " << root->key() << "\n";       // Print node value
}

template <typename Key, typename E>
void BST<Key, E>::
printLeavesHelper(BSTNode<Key, E>* root, int level) const {
    if (root == NULL) {
        return;
    // if 1) root node is present, 2) left is "falsey", 3) right is falsey
    // then, we are at a leaf - print the key for this node
    } else if (root != NULL && !root->left() && !root->right()) {
        // Only print when a node does not have a left or a night value.
        if (root->key() != NULL) cout << "leaf: " << root->key() << endl;

    // if 1) left is "truthy" and 2) right is "truthy" - continue moving down/up the tree
    } else {
        printLeavesHelper(root->left(), level+1);          // Move to bottom of left subtree
        printLeavesHelper(root->right(), level+1);
    }
}
