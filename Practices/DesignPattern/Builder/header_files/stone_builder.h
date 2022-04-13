#ifndef STONE_BUILDER_H
#define STONE_BUILDER_H

#include "i_builder.h"

class StoneBuilder : public IBuilder {
public:
    void buildWindow() override;
    void buildWall() override;
    void buildCeiling() override;

    ~StoneBuilder(){};
};

#endif