#ifndef EVENING_STATE_H
#define EVENING_STATE_H
#include <iostream>

#include "state.h"

class EveningState : public State {
private:
    static State *m_state;
    EveningState() = default;

public:
    void WriteProgram();
    static State *GetInstance() {
        if (m_state == nullptr)
            m_state = new EveningState();
        return m_state;
    }
    ~EveningState() = default;
};

#endif