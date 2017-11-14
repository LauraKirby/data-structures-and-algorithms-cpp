//
//  main.cpp
//  ReverseString
//
//  Created by Laura Kirby on 10/19/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <string>
#include <iostream>

using namespace std;

void reverse(char *strInput)
{
    // access the starting value of the char array
    // base case dereferences strInput and checks to make sure there is a value
    if (*strInput)
    {
        // if there is a value, then call "reverse" again
        // add one to the address, thus moving forward into the char array and making the problem smaller
        reverse(strInput+1);

        // "reverse" has been called for the last time,
        // start printing, starting from the last function that was envoked.
        std::cout << *strInput;
    }
}


string reverseString(string *strInput)
{
    // access the starting value of the char array
    // base case dereferences strInput and checks to make sure there is a value
    if (strInput.length() > 1) {
        char first = strInput[0];
        string reversed = reverseString( strInput->substr(1, strInput->length()-1)  );
        return strInput.insert(reversed.length(), 1, first);
    }
    return strInput;
}

int main(int argc, const char * argv[]) {
    char myName[] = "laura";

    reverse(myName);
    std::cout << std::endl;

    return 0;
}
