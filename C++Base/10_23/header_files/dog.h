#ifndef DOG_H
#define DOG_H

#include <iostream>

#include "animal.h"

class Dog : public Animal {
public:
    Dog() { std::cout << "Dog constructor..." << std::endl; }
    ~Dog() { std::cout << "Dog deconstructor..." << std::endl; }
    void cry() override;
    void movement() override;
};

#endif