//
//  llist.h
//  DynamicResizing
//
//  Created by Laura Kirby on 11/15/17.
//  Copyright © 2017 LK. All rights reserved.
//

#ifndef llist_h
#define llist_h

// This is the file to include in your code if you want access to the
// complete DList template class (update)

// First, get the declaration for the base list class
#include "list.h"

// This is the declaration for DList. It is broken up because the
// methods that appear in the book are in a separate file.
// Linked list implementation
template <typename E> class LList: public List<E> {
private:
    Link<E>* head;      // Pointer to list header
    Link<E>* tail;      // Pointer to list tailer
    Link<E>* curr;      // Pointer ahead of current element
    int cnt;            // Size of list

    void init() {       // Initialization helper method
        curr = head = new Link<E>;
        head->next = tail = new Link<E>(head, NULL);
        cnt = 0;
    }

    void removeall() {      // Return link nodes to free store
        while(head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    LList(int size=defaultSize) { init(); }     // Constructor
    ~LList() { removeall(); }                   // Destructor

    // Include those  methods that are different from singly linked list
    // Insert "it" at current position
    void insert(const E& it) {
        curr->next = curr->next->prev =
        new Link<E>(it, curr, curr->next);
        cnt++;
    }

    // Append "it" to the end of the list.
    void append(const E& it) {
        tail->prev = tail->prev->next =
        new Link<E>(it, tail->prev, tail);
        cnt++;
    }

    // Remove and return current element
    E remove() {
        if (curr->next == tail)        // Nothing to remove
            return NULL;
        E it = curr->next->element;    // Remember value
        Link<E>* ltemp = curr->next;   // Remember link node
        curr->next->next->prev = curr;
        curr->next = curr->next->next; // Remove from list
        delete ltemp;                  // Reclaim space
        cnt--;                         // Decrement cnt
        return it;
    }

    void moveToStart()      // Place curr at list start
    { curr = head; }

    void moveToEnd()        // Place curr at list end
    { curr = tail->prev; }

    // Move fence one step left; no change if left is empty
    void prev() {
        if (curr != head)  // Can't back up from list head
            curr = curr->prev;
    }

    void clear() { removeall(); init(); }       // Clear list

    // Move fence one step right; no change if right is empty
    void next()
    { if (curr != tail->prev) curr = curr->next; }

    int length() const  { return cnt; }  // Return length

    // Return the position of the current element
    int currPos() const {
        Link<E>* temp = head;
        int i;
        for (i=0; curr != temp; i++)
            temp = temp->next;
        return i;
    }

    // Move down list to position
    void moveToPos(int pos) {
        Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
        curr = head;
        for(int i=0; i<pos; i++) curr = curr->next;
    }

    // Return current element
    const E& getValue() const {
        if(curr->next == tail) return NULL;
        return curr->next->element;
    }

    // Print each element in list
    void printList() {
        Link<E>* temp;
        if (head->next) temp = head->next;
        while (temp->next){
            cout << "front to back: ";
            cout << temp->element << endl;

            temp = temp->next;
        };
    }

    // Print each element in list
    void printListBackward() {
        Link<E>* temp;
        if (tail->prev) temp = tail->prev;
        while (temp->prev){
            cout << "back to front: ";
            cout << temp->element << endl;

            temp = temp->prev;
        };
    }
};

#endif /* llist_h */
