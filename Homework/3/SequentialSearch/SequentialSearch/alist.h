//
//  alist.h
//  SequentialSearch
//
//  Created by Laura Kirby on 10/26/17.
//  Copyright © 2017 LK. All rights reserved.
//

#ifndef alist_h
#define alist_h



// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include in your code if you want access to the
// complete AList template class

// First, get the declaration for the base list class
#include "list.h"

using namespace std;

const int defaultSize = 10; // Default size
void Assert(bool val, string s) {
    if (!val) { // Assertion failed -- close the program
        cout << "Assertion Failed: " << s << endl;
        exit(-1);
    }
}

// This is the declaration for AList. It is split into two parts
// because it is too big to fit on one book page
template <typename E> // Array-based list implementation
class AList : public List<E> {
private:
    int maxSize;        // Maximum size of list
    int listSize;       // Number of list items now
    int curr;           // Position of current element
    E* listArray;    // Array holding list elements

public:
    AList(int size=defaultSize) { // Constructor
        maxSize = size;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }

    ~AList() { delete [] listArray; } // Destructor

    void clear() {                    // Reinitialize the list
        delete [] listArray;            // Remove the array
        listSize = curr = 0;            // Reset the size
        listArray = new E[maxSize];  // Recreate array
    }

    // Insert "it" at current position
    void insert(const E& it) {
        Assert(listSize < maxSize, "List capacity exceeded");
        for(int i=listSize; i>curr; i--)  // Shift elements up
            listArray[i] = listArray[i-1];  //   to make room
        listArray[curr] = it;
        listSize++;                       // Increment list size
    }

    void append(const E& it) {       // Append "it"
        Assert(listSize < maxSize, "List capacity exceeded");
        listArray[listSize++] = it;
    }

    // Remove and return the current element.
    E remove() {
        Assert((curr>=0) && (curr < listSize), "No element");
        E it = listArray[curr];           // Copy the element
        for(int i=curr; i<listSize-1; i++)  // Shift them down
            listArray[i] = listArray[i+1];
        listSize--;                          // Decrement size
        return it;
    }
    void moveToStart() { curr = 0; }        // Reset position
    void moveToEnd() { curr = listSize; }     // Set at end
    void prev() { if (curr != 0) curr--; }       // Back up
    void next() { if (curr < listSize) curr++; } // Next

    // Return list size
    int length() const  { return listSize; }

    // Return current position
    int currPos() const { return curr; }

    // Set current list position to "pos"
    void moveToPos(int pos) {
        Assert ((pos>=0)&&(pos<=listSize), "Pos out of range");
        curr = pos;
    }
    
    const E& getValue() const { // Return current element
        Assert((curr>=0)&&(curr<listSize),"No current element");
        return listArray[curr];
    }

    int ssearch(int findMe){
        // exit and return a message if list is empty
        Assert(0<listSize,"No current element");

        // interate over list,
        //    if value is found return index of where first value is located
        //    otherwise, keep iterating to find the "findMe" value within the array
        for (int i = 0; i < listSize; i++){
            if (listArray[i] == findMe){
                curr = i;
                cout << "found at index: " << curr << endl;
                return curr;
            }
        }
        cout << "not found: " << -1 << endl;
        return -1;
    }
};


#endif /* alist_h */
