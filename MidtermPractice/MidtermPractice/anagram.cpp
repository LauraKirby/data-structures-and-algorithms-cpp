//
//  anagram.cpp
//  MidtermPractice
//
//  Created by Laura Kirby on 10/19/17.
//  Copyright © 2017 LK. All rights reserved.
//
#include <iostream>
#include "anagram.hpp"


bool anagram(std::string str1, std::string str2) {
    // store the int value for each char in an int variable
    int str1Sum = 0, str2Sum = 0, i = 0;
    while (str1[i] != '\0') {
        str1Sum += (int)str1[i];
        str2Sum += (int)str2[i];
        i++;
    }

    // if the int values for str1Sum and str2Sum are the same,
    // then the word is an anagram, otherwise it it not.
    // print whether or not string is an anagram
    if (str1Sum == str2Sum) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return str1Sum == str2Sum;
}
