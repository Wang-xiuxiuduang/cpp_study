#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "i_builder.h"

// 指挥者类
class Director {
public:
    void construct(IBuilder* iBuilder);
};

#endif