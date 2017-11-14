//
//  doublylinkedlist.hpp
//  DoublyLinkedList
//
//  Created by Laura Kirby on 11/13/17.
//  Copyright © 2017 LK. All rights reserved.
//

#ifndef doublylinkedlist_h
#define doublylinkedlist_h

#include <iostream>
#include <cstdlib>
#include "list.h"
#include "link.h"

using namespace std;

//template <typename E> class List { // List ADT
//template <typename E> class LList: public List<E> {

// DoublyLinkedList ADT
template <typename E> class DoublyLinkedList: public List<E>

{
public:
    DoublyLinkedList() {}          // Default constructor
    virtual ~DoublyLinkedList() {} // Base destructor

    // Return: The current element.
    virtual int print() const = 0;

    // get value of node/link
    virtual void getValue() const = 0;
};
#include "doublylinkedlist.cpp"

#endif /* doublylinkedlist_h */








/*
 Notes on ADTs:
 Source: "Data Abstraction & Problem Solving with C++, Walls and Mirrors"
 by Frank M. Carrano & Timothy Henry

 An ADT is a collection of data and a set of operations on the data. 
 In other words, a specification for a group of values and the operations on those values. 
 ADT is like a custom set of functions available to a given data type.

 Example 1:
 - We have a Date object. We want to make custom functions available to the Date object.
 - data: date = new Date()
 - custom function, check if data is a holiday: date.isHoliday?
 - "isHoliday" will be a function in the ADT

 Design an ADT by identifying data and choosing operations that are suitable to your problem.
 - data: Date object
 - operation: isHoliday

 Example 2:
 - Create an Appointment Book
 - data: appointments
 - Each appointment will be of class Appointment, containing, date, time and purpose fields
 - custom operations:
 - Ensure date and time are available
 - Get purpose of appointment for a given time
 - You can use ADT operations to design other operations on the appointments.
 - Ex: change the date or time of an appointment within an Appointment Book

 Example 3: ADTs that suggest other ADTs
 - We can use one ADT to implement another ADT
 - Receipe Database ADT
 - data: receipes
 - custom operations: insert, delete, get
 - Receipe Database ADT - Suggest another ADT
 - Suppose we want to offer ability to create custom measurements depending on how many people a user is cooking for.
 - data: measurement
 - custom operations: getMeasurement, setMeasurement, convertMeasurement
 */
