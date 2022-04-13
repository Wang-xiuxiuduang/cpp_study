#ifndef BIRD_H
#define BIRD_H

#include <iostream>

#include "animal.h"

class Bird : public Animal {
public:
    Bird() { std::cout << "Bird constructor..." << std::endl; }
    ~Bird() { std::cout << "Bird deconstructor..." << std::endl; }
    void cry() override;
    void movement() override;
};

#endif