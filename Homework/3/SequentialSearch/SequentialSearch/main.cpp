//
//  main.cpp
//  SequentialSearch
//
//  Created by Laura Kirby on 10/26/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
#include "alist.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // Create an instance of AList (aka Array List)
    AList<int> list3;

    // Add 4,6,3 into the AList
    list3.insert(4);
    list3.insert(6);
    list3.insert(3);

    // Print the first value in the list to ensure that the list is being built
    cout << list3.getValue() << endl;


    // Find the value 6 and return it's index within the instance, called 'list3', of AList
    list3.ssearch(6);

    // Print the first value in the list to ensure that
    cout << list3.getValue() << endl;
    return 0;
}
