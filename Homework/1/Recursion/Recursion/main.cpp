//
//  main.cpp
//  Recursion
//
//  Created by Laura Kirby on 9/16/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
#include "time.h"

void printNums(int start){
    if (start == 10)
        return;

    // do math
    start += 2;

    std::cout << "moving up: " << start << std::endl;

    // repeat math
    printNums(start);

    std::cout << "moving down: " << start << std::endl;

}


int printNumbers(int startNum)
{
    std::cout << "recursive " << startNum << std::endl;
    if (startNum >= 18) {
        return 0;
    }

    return printNumbers(startNum+3);
}

int printNumbers_2(int a, int n, int d)
{
    std::cout << "recursive " << a << std::endl;
    if (n <= 0) {
        return 0;
    }

    return printNumbers_2((a+d), n-1, d);
}

int printNumbers_3(int a, int n, int d)
{
    // Recursive definition of an arithmetic sequence:
    // - aᵣ = a + rd
    // - aᵣ = aᵣ₋₁ + d
    // a₀ = a
    int list_value = (a+((n-1)*d));
    std::cout << "r2 " << a << std::endl;
    std::cout << "list value " << list_value << std::endl;
    if (n <= 0) {
        return 0;
    }

    return printNumbers_3(list_value, n-1, d);
}


void reverse(char *str)
{
    if (*str)
    {
        reverse(str+1);
        printf("%c", *str);
    }
}

int fibonacci(int end) {
    if (end <= 1)
        return end;

    return fibonacci(end-1) + fibonacci(end-2);
}



// exponential time growth because each return statement calls the "fibonacci
// dynmaic means storing some value to calculate the next value
int fibonacciDynamic(int end) {
    unsigned long long sequence[end+1];
    sequence[0] = 1;
    std::cout << "seq: " << sequence[0] << std::endl;
    sequence[1] = 1;
    std::cout << "seq: " << sequence[1] << std::endl;
    int i = 2;
    while (end - 2 >= i) {
        sequence[i] = sequence[i-1] + sequence[i-2];
        std::cout << "seq: " << sequence[i] << std::endl;
        i++;
    };
    return 0;
}

int fibonacciIterative(int end){
    int a = 0, b = 1, c, i;
    if (end == 0)
        return a;
    for (i = 2; i <= end; i ++) {
        c = a +b;
        a = b;
        c = c;
    }
    std::cout << b << std::endl;
    return b;
}


void timeFunction(){
    for (int i = 0; i < 1; i++) {
        clock_t t1, t2;
        t1 = clock();

        fibonacciDynamic(50);
        // we already knew the previous value, so now we are unnecessarily recalculate
        t2 = clock();
        float diff = ((float)t2-(float)t1);
        std::cout << "time: " << diff << std::endl;

    }
}

int main(int argc, const char * argv[]) {
    // list = 3, 6, 9, 12...
    /*
    int startingValueA = 3;
    int endingListLocationN = 6;
    int distanceBetweenNumbersD = 3;
    printNumbers(3);
    printNumbers_3(startingValueA, endingListLocationN, distanceBetweenNumbersD);
*/

    //int start = 1;
//    int end = 5;
    //fibonacci(end);
//    printf("%d", fibonacci(end));
//    std::cout << std::endl;

    // char a[] = "Geeks for Geeks";
    // reverse(a);

    for (int i = 0; i < 0; i++) {
        clock_t t1, t2;
        t1 = clock();

        fibonacciDynamic(50);
        // we already knew the previous value, so now we are unnecessarily recalculate
        t2 = clock();
        float diff = ((float)t2-(float)t1);
        std::cout << "time: " << diff << std::endl;

    }

    fibonacciIterative(50);
    timeFunction();

//    printNums(0);

//    fibonacci(end);

    return 0;
}
