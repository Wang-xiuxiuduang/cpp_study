#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

// 基类：人
class Person {
private:
    std::string name;

public:
    Person(std::string);
    ~Person() { std::cout << "Person deconstruct..." << std::endl; }
    
    virtual void Show();
};

#endif