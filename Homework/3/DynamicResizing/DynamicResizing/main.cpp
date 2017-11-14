//
//  main.cpp
//  DynamicResizing
//
//  Created by Laura Kirby on 10/26/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>

/*
The objective of this question is to demonstrate the arrays inability to dynamic resizing. Please use the template file, linkedList.cpp file I posted to Canvas as your template. You should add the following to the above code:

1. Declare an integer array with length 3.
2. Declare an integer linked list.
3. In main, write a function that will take in 3 integer inputs from command line.
   - Add each received input to the array and the linked list.
4. Repeat step 3, this time with 5 integer inputs from the commland line.
6. Compare your observations.
7. Upload your file.
*/

#include <cstdlib>
using namespace std;

void Assert(bool val, string s) {
    if (!val) { // Assertion failed -- close the program
        cout << "Assertion Failed: " << s << endl;
        exit(-1);
    }
}

template <typename E> class List { // List ADT
private:
    void operator =(const List&) {} // Protect assignment
    List(const List&) {} // Protect copy constructor
public:
    List() {} // Default constructor
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


// Singly linked list node
template <typename E> class Link {
public:
    E element; // Value for this node
    Link *next; // Pointer to next node in list
    // Constructors
    Link(const E& elemval, Link* nextval =NULL)
    { element = elemval; next = nextval; }
    Link(Link* nextval =NULL) { next = nextval; }
};

// Linked list implementation
template <typename E> class LList: public List<E> {
private:
    Link<E>* head; // Pointer to list header
    Link<E>* tail; // Pointer to last element
    Link<E>* curr; // Access to current element
    int cnt; // Size of list
    void init() { // Intialization helper method
        curr = tail = head = new Link<E>;
        cnt = 0;
    }
    void removeall() { // Return link nodes to free store
        while(head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
public:
    LList(int size=100) { init(); } // Constructor
    ~LList() { removeall(); } // Destructor
    void print() const; // Print list contents
    void clear() { removeall(); init(); } // Clear list
    // Insert "it" at current position
    void insert(const E& it) {
        curr->next = new Link<E>(it, curr->next);
        if (tail == curr) tail = curr->next; // New tail
        cnt++;
    }
    void append(const E& it) { // Append "it" to list
        tail = tail->next = new Link<E>(it, NULL);
        cnt++;
    }
    // Remove and return current element
    E remove() {
        Assert(curr->next != NULL, "No element");
        E it = curr->next->element; // Remember value
        Link<E>* ltemp = curr->next; // Remember link node
        if (tail == curr->next) tail = curr; // Reset tail
        curr->next = curr->next->next; // Remove from list
        delete ltemp; // Reclaim space
        cnt--; // Decrement the count
        return it;
    }
    void moveToStart() // Place curr at list start
    { curr = head; }
    void moveToEnd() // Place curr at list end
    { curr = tail; }
    // Move curr one step left; no change if already at front
    void prev() {
        if (curr == head) return; // No previous element
        Link<E>* temp = head;
        // March down list until we find the previous element
        while (temp->next!=curr) temp=temp->next;
        curr = temp;
    }
    // Move curr one step right; no change if already at end
    void next()
    { if (curr != tail) curr = curr->next; }
    int length() const { return cnt; } // Return length
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
        Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
        curr = head;
        for(int i=0; i<pos; i++) curr = curr->next;
    }
    const E& getValue() const { // Return current element
        Assert(curr->next != NULL, "No value");
        return curr->next->element;
    }
};


int main(int argc, const char * argv[]) {
    /*
     The objective of this question is to demonstrate the arrays inability to dynamic resizing. Please use the template file, linkedList.cpp file I posted to Canvas as your template. You should add the following to the above code:

     1. Declare an integer array with length 3.
     2. Declare an integer linked list.
     3. In main, write a function that will take in 3 integer inputs from command line.
        - Add each received input to the array and the linked list.
     4. Repeat step 3, this time with 5 integer inputs from the commland line.
     5. Compare your observations.
     6. Upload your file.
     */

    // 1. Declare an integer array with length 3.
    int intArray[3] = {0,0,0};
    int value;
    int i = 0;


    // 2. Declare an integer linked list.
    LList<int> linkedList;


    // 3. In main, write a function that will take in 3 integer inputs from command line.
    // - Add each received input to the array and the linked list.
    while (i < 3){
        cin >> value;
        linkedList.insert(value);
        cout << "value added to Linked List: " << value << endl;
        i ++;
    }

    while (i < 3){
        cin >> value;
        intArray[i] = value;
        cout << "value added to Array List: " << value << endl;
        i ++;
    }


    // 4. Repeat step 3, this time with 5 integer inputs from the commland line.
    i = 0;
    while (i < 5){
        cin >> value;
        linkedList.insert(value);
        cout << "value added to Linked List: " << value << endl;
        i ++;
    }

    while (i < 5){
        cin >> value;
        intArray[i] = value;
        cout << "value added Array List:" << value << endl;
        i ++;
    }


    // 5. Compare your observations.
    // Linked list will allow you to continually add items to
    // a linked list instance as long as you don't run out of memory.
    // This shows that the list is dynamically resized.
    // as long as you don't run out of memory.
    // Array list does not allow you to dynamically resize, meaning the
    // an error will be thrown when you try to add a value that is out
    // of bounds.


    return 0;
}
