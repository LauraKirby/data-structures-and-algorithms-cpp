//
//  main.cpp
//  DoublyLinkedList
//
//  Created by Laura Kirby on 11/12/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
#include "link.h"
#include "list.h"
using namespace std;

/*
 The objective of this question is to extend our knowledge of linked lists to implement a doubly linked list: a linked list that allows convenient access from a list node to the next node and also to the preceding node on the list. Please read the section 4.1.5 (page 115) of PDF eBook to learn more. The do the following:

 1. Create an ADT and its implementation for a doubly linked list. See figures 4.13 and 4.14.
 2. Add a method named 'printList' to your ADT. 
 3. Build the 'printList' implementation. This method will print out the entire doubly linked list
 4. Write a driver program that contains the following to test out your ADT.
     A. A doubly linked list of strings. the value for each string should be received from standard input (cin). 
     B. Print out the list both forward and backward.
*/




// Create freelist head pointer
//template <typename E>
//Link<E>* Link<E>::freelist = NULL;



// Implementation for DoublyLinkedList
//template <typename E> class DoublyLinkedList: public List<E> {
//private:
//    Link<E>* head; // Pointer to list header
//    Link<E>* tail; // Pointer to last element
//    Link<E>* curr; // Access to current element
//    int cnt; // Size of list
//    void init() { // Intialization helper method
//        curr = tail = head = new Link<E>;
//        cnt = 0;
//    }
//    void removeall() { // Return link nodes to free store
//        while(head != NULL) {
//            curr = head;
//            head = head->next;
//            delete curr;
//        }
//    }
//public:
//    void insert(const E& it) {
//        curr->next = curr->next->prev =
//        new Link<E>(it, curr, curr->next);
//        cnt++;
//    }
//
//    void clear() { removeall(); init(); } // Clear list
//
//
//    void print() const; // Print list contents
//
//
//    // Append "it" to the end of the list.
//    void append(const E& it) {
//        tail->prev = tail->prev->next =
//        new Link<E>(it, tail->prev, tail);
//        cnt++;
//    }
//
//    // Remove and return current element
//    E remove() {
//        if (curr->next == tail) // Nothing to remove
//            return NULL;
//        E it = curr->next->element; // Remember value
//        Link<E>* ltemp = curr->next; // Remember link node
//        curr->next->next->prev = curr;
//        curr->next = curr->next->next; // Remove from list
//        delete ltemp; // Reclaim space
//        cnt--; // Decrement cnt
//        return it;
//    }
//
//    void moveToStart() // Place curr at list start
//    { curr = head; }
//
//    void moveToEnd() // Place curr at list end
//    { curr = tail; }
//
//    // Move fence one step left; no change if left is empty
//    void prev() {
//        if (curr != head) // Can’t back up from list head
//            curr = curr->prev;
//    }
//
//    // Move curr one step right; no change if already at end
//    void next()
//    { if (curr != tail) curr = curr->next; }
//
//    int length() const { return cnt; } // Return length
//
//    // Return the position of the current element
//    int currPos() const {
//        Link<E>* temp = head;
//        int i;
//        for (i=0; curr != temp; i++)
//            temp = temp->next;
//        return i;
//    }
//    // Move down list to "pos" position
//    void moveToPos(int pos) {
//        Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
//        curr = head;
//        for(int i=0; i<pos; i++) curr = curr->next;
//    }
//    const E& getValue() const { // Return current element
//        Assert(curr->next != NULL, "No value");
//        return curr->next->element;
//    }
//};

int main(int argc, const char * argv[]) {


    return 0;
}
