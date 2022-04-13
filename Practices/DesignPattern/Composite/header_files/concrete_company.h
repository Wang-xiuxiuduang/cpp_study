#ifndef CNOCRETE_COMPANY_H
#define CNOCRETE_COMPANY_H

#include <iostream>
#include <list>

#include "company.h"

class ConcreteCompany : public Company {
private:
    std::list<Company*> department_list_;

public:
    ConcreteCompany(std::string);
    void Display() override;
    void Add(Company*);
    // void Remove(Company*);
};

#endif