//
//  main.cpp
//  DynamicResizing
//
//  Created by Laura Kirby on 10/26/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;

const int defaultSize = 10; // Default size

// Assert: If "val" is false, print a message and terminate
// the program
void Assert(bool val, string s) {
    if (!val) { // Assertion failed -- close the program
        cout << "Assertion Failed: " << s << endl;
        exit(-1);
    }
}

// Doubly linked list node with freelist support
template <typename E> class Link {
private:
    static Link<E>* freelist;       // Reference to freelist head

public:
    E element;      // Value for this node - 2
    Link* next;     // Pointer to next node in list
    Link* prev;     // Pointer to previous node

    // Constructors
    Link(const E& it, Link* prevp, Link* nextp) {
        element = it;
        prev = prevp;
        next = nextp;
    }

    Link(Link* prevp =NULL, Link* nextp =NULL) {
        prev = prevp;
        next = nextp;
    }

    void* operator new(size_t) {                    // Overloaded new operator
        if (freelist == NULL) return ::new Link;    // Create space
        Link<E>* temp = freelist;                   // Can take from freelist
        freelist = freelist->next;
        return temp;                                 // Return the link
    }

    // Overloaded delete operator
    void operator delete(void* ptr) {
        ((Link<E>*)ptr)->next = freelist;           // Put on freelist
        freelist = (Link<E>*)ptr;
    }
};

// The freelist head pointer is actually created here
template <typename E>
Link<E>* Link<E>::freelist = NULL;


template <typename E> class List { // List ADT
private:
    void operator =(const List&) {}      // Protect assignment
    List(const List&) {}           // Protect copy constructor
public:
    List() {}          // Default constructor
    virtual ~List() {} // Base destructor

    // Clear contents from the list, to make it empty.
    virtual void clear() = 0;

    // Insert an element at the current location.
    // item: The element to be inserted
    virtual void insert(const E& item) = 0;

    // Append an element at the end of the list.
    // item: The element to be appended.
    virtual void append(const E& item) = 0;

    // Remove and return the current element.
    // Return: the element that was removed.
    virtual E remove() = 0;

    // Set the current position to the start of the list
    virtual void moveToStart() = 0;

    // Set the current position to the end of the list
    virtual void moveToEnd() = 0;

    // Move the current position one step left. No change
    // if already at beginning.
    virtual void prev() = 0;

    // Move the current position one step right. No change
    // if already at end.
    virtual void next() = 0;

    // Print each item within the list, starting from the front.
    virtual void printList() = 0;

    // Print each item within the list, starting from the back.
    virtual void printListBackward() = 0;

    // Return: The number of elements in the list.
    virtual int length() const = 0;

    // Return: The position of the current element.
    virtual int currPos() const = 0;

    // Set current position.
    // pos: The position to make current.
    virtual void moveToPos(int pos) = 0;

    // Return: The current element.
    virtual const E& getValue() const = 0;
};

// This is the declaration for DList. It is broken up because the
// methods that appear in the book are in a separate file.
// Linked list implementation
template <typename E> class DoublyLinkedList: public List<E> {
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
    DoublyLinkedList(int size=defaultSize) { init(); }     // Constructor
    ~DoublyLinkedList() { removeall(); }                   // Destructor

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

// Main routine for array-based list driver class
int main(int argc, char** argv) {

    // Test DoublyLinkedList, accept input from console and add it to Doubly Linked List
    string input;
    DoublyLinkedList<string> doublyLinkedList;
    for (int i = 0; i < 3; i++ ) {
        cout << "\n\nenter preferred value into console." << endl;
        cin >> input;
        doublyLinkedList.insert(input);
        cout << "value added to Doubly Linked List: " << input << endl;
    }

    // Print Double Linked List forward and backward
    doublyLinkedList.printList();
    doublyLinkedList.printListBackward();

    return 0;
}

