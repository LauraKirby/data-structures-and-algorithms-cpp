//
//  main.cpp
//  queues
//
//  Created by Laura Kirby on 10/19/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using namespace std;

/*

 Use the code template provided in Canvas, titled "queues.cpp", under the files directory and modify it accordingly.
 
 Given an integer array of numbers {5, 10, 15, 20, 25, 30}, demonstrate all the queue operations:
 - enqueue, 
 - dequeue, 
 - clear, 
 - length, 
 - frontValue

 Please upload your file here.

 Hint: start off with creating a queue with above set of numbers.

 */

// Assert: If "val" is false, print a message and terminate
// the program
void Assert(bool val, string s) {
    if (!val) { // Assertion failed -- close the program
        cout << "Assertion Failed: " << s << endl;
        exit(-1);
    }
}
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

// Abstract queue class
template <typename E> class Queue {
private:
    void operator =(const Queue&) {} // Protect assignment
    Queue(const Queue&) {} // Protect copy constructor
public:
    Queue() {} // Default
    virtual ~Queue() {} // Base destructor
    // Reinitialize the queue. The user is responsible for
    // reclaiming the storage used by the queue elements.
    virtual void clear() = 0;
    // Place an element at the rear of the queue.
    // it: The element being enqueued.
    virtual void enqueue(const E&) = 0;
    // Remove and return element at the front of the queue.
    // Return: The element at the front of the queue.
    virtual E dequeue() = 0;
    // Return: A copy of the front element.
    virtual const E& frontValue() const = 0;
    // Return: The number of elements in the queue.
    virtual int length() const = 0;
};

template <typename E> class LQueue: public Queue<E> {
private:
    Link<E>* front; // Pointer to front queue node
    Link<E>* rear; // Pointer to rear queue node
    int size; // Number of elements in queue
public:
    LQueue(int sz = 20) // Constructor
    { front = rear = new Link<E>(); size = 0; }
    ~LQueue() { clear(); delete front; } // Destructor
    void clear() {                 // Clear queue
        while(front->next != NULL) { // Delete each link node
            rear = front;
            front = front->next;
            delete rear;
        }
        rear = front;
        size = 0;
    }
    void enqueue(const E& it) { // Put element on rear
        rear->next = new Link<E>(it, NULL);
        rear = rear->next;
        size++;
    }
    E dequeue() { // Remove element from front
        Assert(size != 0, "Queue is empty");
        E it = front->next->element; // Store dequeued value
        Link<E>* ltemp = front->next; // Hold dequeued link
        front->next = ltemp->next; // Advance front
        if (rear == ltemp) rear = front; // Dequeue last element
        delete ltemp; // Delete link
        size --;
        return it; // Return element value
    }
    const E& frontValue() const { // Get front element
        Assert(size != 0, "Queue is empty");
        return front->next->element;
    }
    virtual int length() const { return size; }
};

//int main(int argc, const char * argv[]) {
//
//
//
//    // PART ONE:
//    // create a wait-list of 5 Students
//    int studentIds[5] = {1,2,3,4,5};
//    const int myInt = 3;
//
//    LQueue<int> waitlist;
//
//    waitlist.enqueue(myInt);
//
//
//    // PART TWO:
//    // demonstrate how a Student be entered into the wait-list
//    for(int i = 0; i < 5; i++) {
//        std::cout << "VALUE ADDED: " << studentIds[i] << std::endl;
//        waitlist.enqueue(studentIds[i]);
//    }
//
//
//
//    // PART THREE
//    // demonstrate how a wait-listed student gets an enrollment opportunity.
//    // remove student who has been waiting the longest
//    waitlist.dequeue();
//    // std::cout << "waitlist.dequeue(): " << (waitlist.dequeue()) << std::endl;
//    
//    return 0;
//}



int main() {
/* 
 You are given an integer array of numbers {5, 10, 15, 20, 25, 30}. 
 Use this sequence of numbers to demonstrate all the queue operations: 
 enqueue, dequeue, clear, length, frontValue.
*/

    int arr[6] = {5, 10, 15, 20, 25, 30};

    LQueue<int> lQue;
    LQueue<int> lQue2;

    // create a limit for when to stop iterating over "arr"
    const int numOfValues = sizeof(arr) / sizeof(arr[0]);

    // iterate over array of integers and add them to the queue
    for(int i = 0; i < numOfValues; i++){
        lQue.enqueue(arr[i]);
    }

    // store front value in variable "peek" and print to ensure new front value is 5
    const int peek = lQue.frontValue();
    cout << peek << endl;

    // remove item from queue
    lQue.dequeue();

    // store front value in variable "peek2" and print to ensure new front value is 10
    const int peek2 = lQue.frontValue();
    cout << peek2 << endl;

    // store length in variable "qLength" and print to ensure length returns 5
    // check lencth of queue
    const int qLength = lQue.length();
    cout << "qLength: " << qLength << endl;

    // remove all items from queue
    lQue.clear();

    return 0;
}


