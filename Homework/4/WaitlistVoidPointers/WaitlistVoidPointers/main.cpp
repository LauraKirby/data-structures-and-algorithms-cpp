//
//  main.cpp
//  WaitlistVoidPointers
//
//  Created by Laura Kirby on 11/16/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
using namespace std;

/*

Hypothetical:
You are asked to create a waitlist for all employees at a company based on employee type. Each type employee is a subclass of Employee. Types/classes include: VP, Manager, Engineer, Technician, Clerk

 Approach 1: Use the most general of the type (i.e the Employee class) and create a queue of type Employee provided all of the above positions are children of Employee class. But, what if if we want to keep an object with its actual type in our queue as elements? This solution will not work because we can't have an array based queue. Arrays don't support multiple data types as elements.

 Approach 2: A linked list implementation of queue can store various types. An issue remains, how will we store each element on an item in the list when we don't the element type ahead of time?
        - Solution: Use "void" pointers. A void pointer is a pointer that has no type!
        - See section 9.7.1.1 of online eBook
        - Note: you cannot directly de-reference a void pointer for obvious reason that doesn't have a type. Rather, you must cast it to the type you think it is and then de-reference. Domain knowledge of the types involved in your problem is required.

To do:
- Create a queue that is capable of inserting types: char, int and double.
- Re-use your previously created linked list queue code or the code available in Canvas.
- You can simply copy the Queue adt/abstract class and the implementation.
- Create a driver program with a queue with 6 elements, 2 of each type, and then dequeue it to print all the values.
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
template <typename E>
    class Link {
        public:
            E element; // Value for this node
            Link *next; // Pointer to next node in list


            // Constructors
            Link(const E& elemval, Link* nextval = NULL) {
                element = elemval; next = nextval;
            }


            Link(Link* nextval =NULL) {
                next = nextval;
            }
    };

// Abstract queue class
template <typename E>
    class Queue {
        private:
            void operator =(const Queue&) {} // Protect assignment
            Queue(const Queue&) {} // Protect copy constructor

        public:
            // Constructor
            Queue() {}
            // Base destructor
            virtual ~Queue() {}

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

template <typename E>
    class LQueue: public Queue<E> {
        private:
            Link<E>* front;     // Pointer to front queue node
            Link<E>* rear;      // Pointer to rear queue node
            int size;           // Number of elements in queue

        public:
            // Constructor
            LQueue(int sz = 20)
            { front = rear = new Link<E>(); size = 0; }

            // Destructor
            ~LQueue() { clear(); delete front; }

            // Clear queue
            void clear() {
                // Delete each link node
                while(front->next != NULL) {
                    rear = front;
                    front = front->next;
                    delete rear;
                }
                rear = front;
                size = 0;
            }

            // Put element on rear
            void enqueue(const E& it) {
                rear->next = new Link<E>(it, NULL);
                rear = rear->next;
                size++;
            }

            // Remove element from front
            E dequeue() {
                Assert(size != 0, "Queue is empty");
                E it = front->next->element;            // Store dequeued value
                Link<E>* ltemp = front->next;           // Hold dequeued link
                front->next = ltemp->next;              // Advance front
                if (rear == ltemp) rear = front;        // Dequeue last element
                delete ltemp;                           // Delete link
                size --;
                return it;                              // Return element value
            }

            // Get front element
            const E& frontValue() const {
                Assert(size != 0, "Queue is empty");
                return front->next->element;
            }

            // Return number of nodes with an element value in list
            virtual int length() const {
                return size;
            }
    };


int main() {

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



