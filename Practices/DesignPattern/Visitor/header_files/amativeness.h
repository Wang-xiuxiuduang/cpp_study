#ifndef AMATIVENESS_H_
#define AMATIVENESS_H_

#include <iostream>

#include "action.h"
#include "man.h"
#include "woman.h"

class Amativeness : public Action {
public:
    void getConclusion(Man& man) override;
    void getConclusion(Woman& Woman) override;
};

#endif