//
//  main.cpp
//  Homework1
//
//  Created by Laura Kirby on 9/16/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
#include<map>
using namespace std;
# define NO_OF_CHARS 256

// homework question 3
void createTable(int tableSize){
    for(int i = 1; i <= tableSize; i++){
        if(i == 1) {
            std::cout << i << " | 1 2 3 4" << std::endl;
            std::cout << "-------------" << std::endl;

        } else {
            std::cout << i << " | ";
            for (int j = 1; j <= tableSize; j++) {
                std::cout << i * j << " ";
            }
            std::cout << " " << std::endl;
        }
    }
}

// homework question 4
/*
 Write a C++ function to print out all unique letters of a given string. 
 You are free to use any C++ standard library function including STL and 
 your middle school math knowledge here. Extend your function to check 
 whether the word is an English pangram.
 */



void printUnique(char str[])
{
    std::map<char, int>  my_map;
    std::map<char,int>::iterator itr;

    // iterate over char array, store each letter as a key and
    // the number of times each character appears as the value.
    // use the 'find' member function to see if a key already exits.
    for (int i = 0; i <= strlen(str); i++){
        char my_char = str[i];

        itr = my_map.find(my_char);

        if (itr->second == 1)
            my_map[my_char]++;
        else
            my_map[my_char] = 1;
    }

    // print unique characters
    // iterate over map
    // if a key has a value of 1, then print the associated key
    // if a key has a value greater than 1,
    // then the char appears more than once, do not print
    // for each key with the value of 1, add to count
    int count = 0;
    for(itr = my_map.begin(); itr != my_map.end(); ++itr) {
        if(itr->second == 1)
            count += 1;
            cout << itr->first << ", ";
    }

    cout << "count " << (count - 1) << endl;

    // one higher (27) than the alphabet (26) due to the functionality of the initial iterator above
    // sotring an empty string or nil value as the first key in the map
    if (count == 27)
        cout << "char array entered is a Pangram" << endl;
}

// homework question 5
/* Shifting each element by given amount toward the left is called "left rotation" of an array.
   For example, if 2 left rotations are performed on the array [1, 2, 3, 4, 5], 
   then the array would become [3, 4, 5, 1, 2].

   Given an array of integers and a number, "r" (how many rotations), 
   perform "r" left rotations on the array. Then print the updated array as a single line of 
   space-separated integers.
*/

void leftRotatebyOne(int arr[], int n)
{
    int i, temp;
    temp = arr[0];
    for (i = 0; i < n-1; i++)
        arr[i] = arr[i+1];
    arr[i] = temp;
}

void leftRotation(int arr[], int d, int n)
{
    int i;
    for (i = 0; i < d; i++)
       leftRotatebyOne(arr, n);
}

void printArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

// homework question 6
/*
 The objective of this question is to learn about ADT (abstract data type) and base classes.

 Write a C++ an ADT to represent an Ellipse. In the Cartesian coordinate system, an ellipse can be uniquely identified by its x and y coordinates of the center, semi-major axis(a) and semi-minor axis (b). Other than getters and setters, an ellipse involves two operations, calculate area and calculate the perimeter. Above ADT should be an abstract class. Then write an Ellipse class to fully implement your ADT. The are of an ellipse is given by {\displaystyle A_{\text{ellipse}}=\pi ab} and perimeter, C of an ellipse is given by
 */
// the two classes are the 1) ADT Ellipse abstract class and 2) the implementation of Ellipse
int main(int argc, const char * argv[]) {

    std::cout << "\n--------------------" << std::endl;
    std::cout << "homework question 1" << std::endl;
    std::cout << "--------------------\n" << std::endl;
    int x, y, z;

    int * ptrx, * ptry, * ptrz;


    ptrx = &x;

    ptry = &y;
    
    ptrz = &z;


//    *ptrx = 10;
//    x = 10;

    std::cout << "one: " << *ptrx << std::endl;
    std::cout << "one: " << x << std::endl;

    std::cout << "two: " << *ptrx << std::endl;
    std::cout << "two: " << x << std::endl;

//    cin >> *ptrx;
//    cin >> x;

//    std::cout << "three: " << *ptrx << std::endl;
//    std::cout << "three: " << x << std::endl;

    std::cout << "four: " << (*ptrz = *ptrx + *ptry)  << std::endl;
    std::cout << "four: " << (z = x + y)  << std::endl;

    std::cout << "five: " << ptrx + 1 << std::endl;
    std::cout << "five: " << x + 1 << std::endl;


//    void* pointer_variable;

//    pointer_variable = ptrz;
//    std::cout << pointer_variable << std::endl;

    std::cout << "\n--------------------" << std::endl;
    std::cout << "homework question 3" << std::endl;
    std::cout << "--------------------\n" << std::endl;
    createTable(4);


    std::cout << "\n--------------------" << std::endl;
    std::cout << "homework question 4" << std::endl;
    std::cout << "--------------------\n" << std::endl;
    char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printUnique(str);

    std::cout << "\n--------------------" << std::endl;
    std::cout << "homework question 5" << std::endl;
    std::cout << "--------------------\n" << std::endl;

    int my_arr[] = {1,2,3,4,5};
    std::cout << "Array V.1:" << std::endl;
    std::cout << "\n";
    printArray(my_arr, 5);
    std::cout << "\n";
    leftRotation(my_arr, 2, 5);
    std::cout << "\n\nArray V.2:" << std::endl;
    std::cout << "\n";
    printArray(my_arr, 5);

    std::cout << "\n";
    return 0;
}
