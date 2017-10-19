//
//  main.cpp
//  Homework2
//
//  Created by Laura Kirby on 10/11/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>

// question 5
bool isPalindrome( const std::string &str ){
    std::string::const_iterator forward = str.begin();
    std::string::const_iterator reverse = str.end();
    if( reverse - forward <= 1 ) {
        std::cout << "true";
        return true;
    }
    if( *forward++ != *--reverse ) {
        std::cout << "false";
        return false;
    };
    return isPalindrome( std::string( forward, reverse ));
}

// question 6
int GCD(int x, int y) {
    if (x < 1 || y < 1) {
        return y;
    } else {
        std::cout << y;
        return GCD(y, x % y);
    }
}

// question 7
double powOfn(double num, double ogNum, int power){
    if (power <= 1) {
        std::cout << "power " << num << std::endl;
        return num;
    }
    double newTotal = ogNum * num;
    return powOfn(newTotal, ogNum, power - 1);
}

/*
Extra Credit question:

Test whether a given integer is a prime number is very crucial in many areas of computer science. Write a C++ recursive function to check whether a given integer is prime or not. In order to receive full credit, you must have two base cases and use the definition of prime numbers (Links to an external site.)Links to an external site. (linked inline) to figure them out. Sample result:

isPrime(2) -> true;

Please upload your file here.
*/

int main(int argc, const char * argv[]) {
    isPalindrome("hello");
    isPalindrome("racecar");

    GCD(18, 24);
    int pwr = 2;
    double n = 2;
    powOfn(n, n, pwr);
    return 0;
}


