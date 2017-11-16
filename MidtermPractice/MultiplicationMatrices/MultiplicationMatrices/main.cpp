//
//  main.cpp
//  MultiplicationMatrices
//
//  Created by Laura Kirby on 10/19/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
using namespace std;

/*

Pseudo code for multiplication of two n x n matrices, A and B is given below:

for i ⟵ 1 to n

 for j ⟵ 1 to n

    Cij ⟵ 0

    for k ⟵ 1 to n

        Cij ⟵ Cij +  aikbkj

- a and b represent elements in A and B respectively
- C is the resulting n x n matrix in which c represents an element in C. 
- refer to the pseudo code about to answer the following:
    1. what is the time complexity of this matrix multiplication in terms of Θ and n
    2. write a simple C++ method named "multiply(A, B, C)" where A, B and C are two dimensional arrays
    3. test your program in a driver with two 2 x 2 simple integer 2D arrays.
*/

// pass each array by using it's pointer
// pass in the row and height of each array so we know how many times to loop
void multiply2(double *A, double *B, double *C, int rows,int cols){
    // increment for each array in A {{2,4},{2,4}}
    for(int i = 0; i < rows; i++){


        // increment for items in each array ex: {2,4}
        for(int j = 0; j < cols; j++){
            *(C + i*rows + j) = *(A + i*rows + j);
//            *(A + i*rows + j)+=10.0;
            cout << *(A + i*rows + j) << "  ";

        }
    }
}

void printMatrix(double *C, int rows,int cols){
    cout<<"\n Printing C...\n";
    for(int i = 0;i < rows; i++){
        for(int j = 0; j<cols; j++){
            cout << *(C+ i*rows + j) << "  ";
        }
    }
}


int main(int argc, const char * argv[]) {

    // 1. Time complexity of this matrix multiplication in terms of Θ and n
    //    - T(n) = n^3
    //    - O(n^3)

    // 2.
    double A[2][2] = {{2,4},{1,3}};
    double B[2][2] = {{2,1},{10, 20}};
    double C[2][2] = {{0, 0},{0, 0}};

    // incomplete. i thought we were supposed to multiply values in an embeded array
    // then store the result in C

    multiply2(A[0], B[0], C[0], 2, 2);

    printMatrix(C[0], 2, 2);


    return 0;
}
