//
//  main.cpp
//  Bisection
//
//  Created by Laura Kirby on 10/26/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>


/*
 Get the root of the equation sin(n + (pi/4)) within the range 4 and 10.

 This uses the bisection method. The approximate positions of the two
 roots in this range are known from visually inspecting the graphical
 representation of the function.
 */
#include <cmath>
#include <iostream>

using namespace std;

//bisection aka root
double bisection(double rangeStart, double rangeEnd) {
    double midpoint = (rangeStart + rangeEnd) / 2;
    double result = sin(midpoint + (M_PI / 4));
    cout << "midpoint: " << midpoint << endl;
    if (result < 0.001 && result > -0.001) {
        cout << "midpoint: " << midpoint << endl;
        return midpoint;
    } else {
        if (result > 0) {
            cout << "midpoint: " << midpoint << endl;
            return bisection(midpoint, rangeEnd);
        } else {
            return bisection(midpoint, rangeEnd);
        }
    }
    return midpoint;
}


//float findRoot(float lowerBound, float upperBound){
//    if (lowerBound == .0001)
//        return lowerBound;
//
//    float mid = lowerBound + upperBound /2;
//    float fn = pow(mid, 3) - mid - 5;
//
//    if (fn  == 0) {
//        std::cout << fn;
//    } else if (fn > 0){
//        findRoot(mid, lowerBound);
//    }
//    else {
//        findRoot(upperBound, mid);
//    }
//
//    return lowerBound;
//};


int main() {
//    double root1 = root(6.0, 4.0);
//    double root2 = root(8.0, 10.0);
//
//    std::cout << "The roots of sin(n + (pi/4)) within the range 4 and 10 are: ";
//    std::cout << root1 << " and " << root2 << std::endl;
//
//
//    float lowerBound = -10;
//    float upperBound = 10;
//
//    findRoot(lowerBound, upperBound);
//    int input[8] = {35, 28, 22, 18, 13, 12, 8, 5};
//    findValue(input, 6);

    double rangeStart = 4;
    double rangeEnd = 10;
    bisection(rangeStart, rangeEnd);
}

