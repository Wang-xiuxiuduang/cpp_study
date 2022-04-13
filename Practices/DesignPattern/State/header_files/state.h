#ifndef STATE_H
#define STATE_H

#include <iostream>

class State {
private:
    State *m_next_state_;

public:
    virtual void WriteProgram() = 0;
    virtual ~State() = default;
    void print() { std::cout << "hello world \n"; }
    State *GetNextState() { return m_next_state_; }
    void SetNextState(State *state) { m_next_state_ = state; }
};

#endif