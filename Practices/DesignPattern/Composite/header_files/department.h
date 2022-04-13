#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>

#include "company.h"

class Department : public Company {
public:
    void Display() override;
    Department(std::string);
};

#endif