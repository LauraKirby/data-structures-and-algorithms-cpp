//
//  main.cpp
//  QuickSort
//
//  Created by Laura Kirby on 12/21/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
#include "book.h"
#include "compare.h"
#include "qsort1.h"

using namespace std;

int main(int argc, const char * argv[]) {
    int arr[] = {2,5,1,8,3,10};
    int size = 6;
    sort<int, minintCompare>(arr, size);

    for (int i = 0; i < 6; i++){
        cout << arr[i] << endl;
    }

    return 0;
}
