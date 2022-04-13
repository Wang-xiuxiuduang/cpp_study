#ifndef BIRD_H_
#define BIRD_H_

#include <string>

#include "animal.h"
using std::cout;
using std::endl;
using std::string;

class Bird : public Animal {
private:
    float flightAltitude;  // 飞行高度
public:
    using Animal::getAge;
    Bird(float);
    Bird(float, bool);
    ~Bird();
    virtual void eatFood() override;
    virtual void sleep() override;
    void getSex();
    void getFA();
    void getAge(string);
};

#endif