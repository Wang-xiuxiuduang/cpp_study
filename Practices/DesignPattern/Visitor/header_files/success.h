#ifndef SUCCESS_H_
#define SUCCESS_H_

#include <iostream>

#include "action.h"
#include "man.h"
#include "woman.h"

class Success : public Action {
public:
    void getConclusion(Man& man) override;
    void getConclusion(Woman& Woman) override;
};

#endif