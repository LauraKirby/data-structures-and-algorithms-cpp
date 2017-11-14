//
//  doublylinkedlist.cpp
//  DoublyLinkedList
//
//  Created by Laura Kirby on 11/13/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include "doublylinkedlist.h"


// Create freelist head pointer
template <typename E>
Link<E>* Link<E>::freelist = NULL;


class DoublyLinkedList {
    Link<E>* head; // Pointer to list header
    Link<E>* tail; // Pointer to last element
    Link<E>* curr; // Access to current element
    Link<E>* prev; // Pointer to previous node
    int count; // Size of list

    // Intialization helper method
    void init() {
        curr = tail = head = new Link<E>;
        count = 0;
    }
    
    void removeall() { // Return link nodes to free store
        while(head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

    void insert(const E& it) {
        curr->next = curr->next->prev =
        new Link<E>(it, curr, curr->next);
        count++;
    }

    void clear() { removeall(); init(); } // Clear list


    void print() const; // Print list contents


    // Append "it" to the end of the list.
    void append(const E& it) {
        tail->prev = tail->prev->next =
        new Link<E>(it, tail->prev, tail);
        count++;
    }

    // Remove and return current element
    E remove() {
        if (curr->next == tail) // Nothing to remove
            return NULL;
        E it = curr->next->element; // Remember value
        Link<E>* ltemp = curr->next; // Remember link node
        curr->next->next->prev = curr;
        curr->next = curr->next->next; // Remove from list
        delete ltemp; // Reclaim space
        count--; // Decrement count
        return it;
    }

    // Place curr at list start
    void moveToStart()
    {
        curr = head;
    }

    // Place curr at list end
    void moveToEnd()
    {
        curr = tail;
    }

    // Move fence one step left; no change if left is empty
    void prev() {
        if (curr != head) // Can’t back up from list head
            curr = curr->prev;
    }

    // Move curr one step right; no change if already at end
    void next()
    {
        if (curr != tail) curr = curr->next;
    }

    int length() const
    {
        // Return length
        return count;
    }

    // Return the position of the current element
    int currPos() const {
        Link<E>* temp = head;
        int i;
        for (i=0; curr != temp; i++)
            temp = temp->next;
        return i;
    }
    // Move down list to "pos" position
    void moveToPos(int pos) {
        Assert ((pos>=0)&&(pos<=count), "Position out of range");
        curr = head;
        for(int i=0; i<pos; i++) curr = curr->next;
    }
    const E& getValue() const { // Return current element
        Assert(curr->next != NULL, "No value");
        return curr->next->element;
    }
};



