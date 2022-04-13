#ifndef CONTEXT_H
#define CONTEXT_H

#include "state.h"

class Context {
private:
    State *pState;

public:
    Context(State *state) : pState(state) {}
    void Work();
};

#endif