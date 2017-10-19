## Homework 2

1. Select the most suitable way we can represent an abstract class in UML:
  - normal class diagram with the class name in italic text

Extra credit question:

Test whether a given integer is a prime number is very crucial in many areas of computer science. Write a C++ recursive function to check whether a given integer is prime or not. In order to receive full credit, you must have two base cases and use the definition of prime numbers (Links to an external site.)Links to an external site. (linked inline) to figure them out. Sample result:

isPrime(2) -> true;

Please upload your file here.



## Quiz 7
1. Select all the all the steps that needed to fallow to solve a problem using divide and conquer paradigm.
- divide the problem into smaller sub-problems
- solve sub-problem
- combine the solutions of the sub problem

2. Often times we can use recursion to solve divide and conquer types problems. Select the best reason why?
- because we repeatedly solve same problems with smaller inputs

3. Implement a recursive bisection method to find the root of f(x) = x3 - x - 5. Use 0.001 as tolerance and enter your answer rounded to first decimal place.

if a === .0001
return a

-10, +10 boundaries


3. Implement a recursive bisection method to find the root of f(x) = x³ - x - 5. Use 0.001 as tolerance and enter your answer rounded to first decimal place.
- Answer: 1.9

```
#include <iostream>
#include <math.h>

float findRoot(float lowerBound, float upperBound){
    if (lowerBound == .0001)
        return lowerBound;

    float mid = lowerBound + upperBound /2;
    float fn = pow(mid, 3) - mid - 5;

    if (fn  == 0) {
      std::cout << fn;
    } else if (fn > 0){
      findRoot(mid, lowerBound);
    }
    else {
      findRoot(upperBound, mid);
    }

    return lowerBound;
};

int main(int argc, const char * argv[]) {
    float lowerBound = -10;
    float upperBound = 10;

    findRoot(lowerBound, upperBound);

    return 0;

}
```


4. Binary Search
You are given the following array of numbers {35, 28, 22, 18, 13, 12, 8, 5}. Write a C++ program using the divide and conquer method to search and return the index value of 12. Please enter the returned index here:
 - Answer: 5 or 6, (i think 5, since arrays are usually 0 based)
```
// since this is a sorted array, we can do binary search.


```



5. We use push operation to fill an empty stack. Push has O(1) running time. What would be the running time to fill a stack of size n?
 - O(n)

6. Please download the file "stringReverse.cpp" from Canvas to write a stack based program to reverse a string. Then use the same program to check whether a given string is a palindrome (Links to an external site.)Links to an external site.. Is the the word "Aibohphobia (Links to an external site.)Links to an external site."?. Use your program to find out.

7. In the same question above, what is the space complexity in terms of the size n ?





