//
//  linkFL.h
//  DynamicResizing
//
//  Created by Laura Kirby on 11/15/17.
//  Copyright © 2017 LK. All rights reserved.
//

#ifndef linkFL_h
#define linkFL_h

// Doubly linked list node with freelist support (doubly 2)
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

#endif /* linkFL_h */
