//
//  main.cpp
//  Registration
//
//  Created by Laura Kirby on 10/19/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>

/*

 Class "Student" to represent a student in a course registration software given by a class called Course. 
 
 Many courses have an enrollment cap due to resource limitations.
 Course
 
 
 If the course is full, a prospective student has to wait in a so called "wait-list". 
 
 Assuming you have access to Student and Course classes (you do not have to write these):
    - implement a wait-list using the most suitable data structure based on so far what we have learned in the class.
    - Write a driver program to:
        - create a wait-list of 5 Students
        - demonstrate how a Student be entered into the wait-list 
        - how wait-listed student gets an enrollment opportunity.
*/

// Abstract queue class
void Assert(bool val, std::string s) {
    if (!val) { // Assertion failed -- close the program
        std::cout << "Assertion Failed: " << s << std::endl;
        exit(-1);
    }
}

// Singly linked list node
template <typename E> class Link
{
public:
    E element; // Value for this node
    Link *next; // Pointer to next node in list

    // Constructors
    Link(const E& elemval, Link* nextval =NULL)
    {
        element = elemval; next = nextval;
    }

    Link(Link* nextval =NULL) {
        next = nextval;
    }
};

template <typename E> class Queue
{

private:
    void operator =(const Queue&) {} // Protect assignment
    Queue(const Queue&) {} // Protect copy constructor

public:
    Queue() {} // constructor
    virtual ~Queue() {} // destructor

    // remove all items from Queue
    virtual void clear() = 0;

    // add student to end of waitlist/Queue
    // it: The element being enqueued.
    virtual void enqueue(const E&) = 0;

    // remove and return student who has been waiting the longest from the waitlist/Queue
    virtual E dequeue() = 0;

    // return a copy of the first student in the waitlist/Queue
    virtual const E& frontValue() const = 0;

    // return the number of students in the waitlist/Queue.
    virtual int length() const = 0;
};

template <typename E> class LQueue: public Queue<E>
{
private:
    Link<E>* front; // pointer to front of waitlist/Queue
    Link<E>* rear; // pointer to rear waitlist/Queue, the last stundent in line
    int size; // number of students on the waitlist

public:
    LQueue(int sz = 20) // constructor
    { front = rear = new Link<E>(); size = 0; }
    ~LQueue() { clear(); delete front; } // destructor
    void clear() {                 // clear waitlist
        // while a "next" student is true
        while(front->next != NULL) {
            // assign "rear" to the very first value
            rear = front;

            // reassign front to be the "next" value
            front = front->next;

            // delete "rear", which is now storing the first value
            delete rear;
        }
        rear = front;
        size = 0;
    }

    void enqueue(const E& it) { // add student to end of waitlist/queue
        // create a new node in the waitlist/queue
        // store the new node in node located at "rear", in the old rear's "next" attribute
        rear->next = new Link<E>(it, NULL);
        // update "rear" to contain the new node
        rear = rear->next;
        // increment the size of the waitlist/queue
        size++;
    }

    // remove and return student from front
    // this will be the student who has been waiting the longest
    E dequeue() { // Remove element from front
        Assert(size != 0, "Queue is empty");
        E it = front->next->element; // store dequeued value
        Link<E>* ltemp = front->next; // create temporary variable to store dequeued value
        front->next = ltemp->next; // after removing
        if (rear == ltemp) rear = front; // dequeue last element
        delete ltemp; // delete link
        size --;
        return it; // return element value
    }

    const E& frontValue() const { // Get front element
        Assert(size != 0, "Queue is empty");
        return front->next->element;
    }

    virtual int length() const { return size; }
};

int main(int argc, const char * argv[]) {



    // PART ONE:
    // create a wait-list of 5 Students
    int studentIds[5] = {1,2,3,4,5};
    const int myInt = 3;

    LQueue<int> waitlist;

    waitlist.enqueue(myInt);


    // PART TWO:
    // demonstrate how a Student be entered into the wait-list
    for(int i = 0; i < 5; i++) {
        std::cout << "VALUE ADDED: " << studentIds[i] << std::endl;
        waitlist.enqueue(studentIds[i]);
    }



    // PART THREE
    // demonstrate how a wait-listed student gets an enrollment opportunity.
    // remove student who has been waiting the longest
    waitlist.dequeue();
    // std::cout << "waitlist.dequeue(): " << (waitlist.dequeue()) << std::endl;

    return 0;
}


