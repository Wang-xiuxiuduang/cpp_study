#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>

class Company {
private:
    std::string company_name_;

public:
    std::string GetConcreteCompanyName();
    Company(std::string company_name);
    bool operator==(Company*);

    virtual ~Company() = default;
    virtual void Display() = 0;
};

#endif