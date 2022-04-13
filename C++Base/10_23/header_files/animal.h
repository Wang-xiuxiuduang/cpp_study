#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
public:
    Animal() { std::cout << "Animal constructor..." << std::endl; }
    ~Animal() { std::cout << "Animal deconstructor..." << std::endl; }
    virtual void cry() = 0;
    virtual void movement() = 0;
    void hello() { std::cout << "Animal say hello..." << std::endl; }
};

#endif