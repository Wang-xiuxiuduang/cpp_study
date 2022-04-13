#ifndef PERSON_H
#define PERSON_H

#include <iostream>

#include "animal.h"

class Person : public Animal {
public:
    Person() { std::cout << "Person constructor..." << std::endl; }
    ~Person() { std::cout << "Person deconstructor..." << std::endl; }
    void cry() override;
    void movement() override;
};

#endif