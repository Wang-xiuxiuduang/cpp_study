#include "headerFile/test_10_12.h"

#include <iostream>

// constructors
Student::Student() { std::cout << "no parameters constructor" << std::endl; }

Student::Student(std::string name, int age, bool sex) : name(name), age(age), sex(sex) {
    std::cout << "have parameters constructor" << std::endl;
}

// class deconstructor
Student::~Student() { std::cout << "decontructor" << std::endl; }

// other method
void Student::getMsg() {
    std::cout << name << std::endl;
    std::cout << age << std::endl;
    std::cout << sex << std::endl;
}
