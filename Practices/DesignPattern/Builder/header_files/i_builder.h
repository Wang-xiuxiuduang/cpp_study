#ifndef I_BUILDER_H
#define I_BUILDER_H

#include "house.h"

class IBuilder {
public:
    House* house;
    House* getResult() { return house; }
    virtual void buildWindow() = 0;
    virtual void buildWall() = 0;
    virtual void buildCeiling() = 0;

    IBuilder() { house = new House(); }
    ~IBuilder() {}
};

#endif