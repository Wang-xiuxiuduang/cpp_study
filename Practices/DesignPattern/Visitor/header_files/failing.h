#ifndef FAILING_H_
#define FAILING_H_

#include <iostream>

#include "action.h"
#include "man.h"
#include "woman.h"

class Failing : public Action {
public:
    void getConclusion(Man& man);
    void getConclusion(Woman& Woman);
};

#endif