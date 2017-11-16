//
//  main.cpp
//  intRecursive
//
//  Created by Laura Kirby on 9/21/17.
//  Copyright © 2017 LK. All rights reserved.
//
// Recursive, meaning "call to itself"

// Two parts of a recursive function
// 1. Contains a base case, a simple evaluation that will indicate
//    when the function should stop making recursive calls.
// 2. The parameters must be "closer" to the base case
//    than before the original call(s).

// 2,4,6...10
// start = 0
// n1 = start += 2
// n2 = start += 2
// n3 = start += 2

#include <iostream>

// std::cout << (start += 2) << std::endl;

void printListRecursive(int start){
    // base case
    if (start == 10)
        return;

    // update some value that will eventually case the base case to be true
    // simple functionality: to math and print
    std::cout << (start += 2) << std::endl;

    // call yourself to repeat the math and print functionality
    printListRecursive(start);
}

int printListRecursiveInt(int start){
    if (start == 10)
        return 0;
    std::cout << (start += 2) << std::endl;
    return printListRecursiveInt(start);

}

int main(int argc, const char * argv[]) {
    int start = 0;
    printListRecursiveInt(start);

    return 0;
}
