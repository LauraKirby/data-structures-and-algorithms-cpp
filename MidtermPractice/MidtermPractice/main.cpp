//
//  main.cpp
//  MidtermPractice
//
//  Created by Laura Kirby on 10/18/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>
// using namespace std;

void countdown(int start){
    if (start <= 1)
        return;
    std::cout << start << std::endl;
    return countdown (start - 1);
}


/*
Notes:
if the two chars have different sizes then return false
   if (sizeof(str1) != sizeof(str2))
        return false;


 
 std::cout << "int value for char arr: " << std::atoi(str1) << std::endl;
 
 //    int sizeOfArray = sizeof(str1[1]);
 //    std::cout << "size of array: " << sizeOfArray << std::endl;
*/

/*
An anagram is a word or phrase formed by rearranging the letters of 
 a different word or phrase, typically using all the original letters exactly once. 
 Write a C++ algorithm (program) from scratch to check whether two given words are anagram pair. 
 Here you are not allowed to use any given algorithms or data structures given in any C++ libraries 
 including STL excluding strings.
*/

// Ex: dog & god

bool isAnagram(char *str1, char *str2){
    int numChars = 5;
    int countStr1[5] = {0};
    int countStr2[5] = {0};
    int i = 0;

    // For each character in input strings, increment count in
    // the corresponding count array
    for (i = 0; str1[i] && str2[i];  i++)
    {
        countStr1[str1[i]]++;
        countStr2[str2[i]]++;
        std::cout << "countStr1[i]: " << countStr1[i] << std::endl;

    }

    // Check if the strings are different lengths.
    // Return false if str1[i] or str2[i] is false
    if (str1[i] || str2[i]){
        std::cout << "false" << std::endl;
        return false;
    }

    // Compare count arrays
    for (int j = 0; j < numChars; j++)
        if (countStr1[j] != countStr2[j]) {
            std::cout << "false" << std::endl;
            return false;
        }

    std::cout << "true" << std::endl;
    return true;
}

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


int main(int argc, const char * argv[]) {
//    isAnagram(name, lastName);

    std::string str1 = "dig";
    std::string str2 = "gig";
    std::string str3 = "god";
    std::string str4 = "dog";
    anagram(str1, str2);
    anagram(str3, str4);

    return 0;
}
