//
//  main.cpp
//  SwapVarNoTemp
//
//  Created by Laura Kirby on 11/12/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>

void swap(int a, int b){
    std::cout << "Goal, swap value of 'a' for the value of 'b'" << "\n";
    std::cout << "Note: this only works when we know the values for 'a' and 'b'" << "\n";
    std::cout << "first value for 'a': " << a << "\n";
    std::cout << "first value for 'b': " << b << "\n\n\n";


    std::cout << "1. Store (a + b) in 'a': " << "\n";
    a = a + b;
    std::cout << "second value for 'a': " << a << "\n\n";


    std::cout << "2. Replace the value of 'b' with substraction (a - b)" << "\n";
    b = a - b;
    std::cout << "second value for 'b': " << b << "\n\n";


    std::cout << "3. Find the original value for 'b' (which we now want to store in 'a') by subtracting the new values. Subtract the 'second' value for 'a' from the 'second' value for 'b'" << "\n";
    std::cout << "a = a - b;" << "\n" << "a = " << a << " - " << b << ";" << "\n";
    a = a - b;
    std::cout << "third value for 'a': " << a << "\n\n";

    std::cout << "Swapped value for 'a': " << a << "\n";
    std::cout << "Swapped value for 'b': " << b << "\n\n";

}

int main(int argc, const char * argv[]) {
    int one = 3;
    int two = 6;
    swap(one,two);

    return 0;
}


