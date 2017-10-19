//
//  main.cpp
//  Recursion3
//
//  Created by Laura Kirby on 9/20/17.
//  Copyright © 2017 LK. All rights reserved.
//


// Two parts of a recursive function
// 1. Contains a base case, a simple evaluation that will indicate
//    when the function should stop making recursive calls.
// 2. The parameters must be in some sense "closer" to the base
//    case than those of the original call(s).

// 2,4,6...10
// start = 0
// n1 = start += 2
// n2 = start += 2
// n3 = start += 2



#include <iostream>

void createListVerbose(int start) {
//    write out each math calculation and print
    std::cout << (start += 2) << std::endl;
    std::cout << (start += 2) << std::endl;
    std::cout << (start += 2) << std::endl;
    std::cout << (start += 2) << std::endl;
    std::cout << (start += 2) << std::endl;
}

void createListDynmaic(int start) {
    for (int i = 0; i < 5; i++) {
        std::cout << (start += 2) << std::endl;
    }
}

void createListRecursive(int start){
//    base case
    if(start == 10)
        return;

//    parameter must get closer to the base case
    std::cout << (start += 2) << std::endl;

//    recursion, a function that calls itself
    createListRecursive(start);

}


int main(int argc, const char * argv[]) {
    int start = 0;
//    createListVerbose(start);
    createListDynmaic(start);

    return 0;
}
