//
//  main.cpp
//  Pet
//
//  Created by Laura Kirby on 10/19/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include <iostream>


/*
 Write a C++ class to represent a Pet with the prospective usage based on the 
 interpretation  by a veterinary hospital. A pet is described by a name, age, owners name. 
 A pet involves the operations, eat, cry. 
 
 Note that all these operations involve a specific type of a pet.

 1. A Dog is a specific type of Pet.
 2. A dog is represented by:
    - name, age, owners name, breed.
 3. A dog involves the operations, eat, cry.
    - For eat operation you should output "dog food".
    - For cry operation you should output "BAW WOW".
 
 Please do the following:
  1. design an appropriate class hierarchy to represent Pet and Dog in C++
  2. write a driver program to create one dog object 
  3. perform eat and cry
  4. upload answers to both 1 and 2 in a single file here
  5. draw a sketch of your class hierarchy in the given paper as a UML class relation diagram. 
      - your individual class diagrams should be expressive.
  6. submit before you leave.
      - remember to write your name on your submission
 */

class Pet
{
public:
    // constructors
    Pet();
    ~Pet();

protected:
    // attributes/ data fields
    std::string name;
    int age;
    std::string ownersName;
};

class Dog : public Pet
{
public:
    // constructors
    Dog();
    ~Dog();

    // other methods
    void eat(){
        std::cout << "dog food" << std::endl;
        return;
    }

    void cry(){
        std::cout << "BAW WOW";
        return;
    }

protected:
    // attributes/ data fields
    std::string breed;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Dog kacey;
    kacey.eat();
    kacey.cry();

    return 0;
}
