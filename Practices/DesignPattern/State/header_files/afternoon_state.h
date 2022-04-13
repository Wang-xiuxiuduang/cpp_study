#ifndef AFTERNOON_STATE_H
#define AFTERNOON_STATE_H

#include "evening_state.h"
#include "state.h"

class AfternoonState : public State {
private:
    static State *m_state;
    AfternoonState() = default;

public:
    void WriteProgram();
    static State *GetInstance() {
        if (m_state == nullptr)
            m_state = new AfternoonState();
        return m_state;
    }
    ~AfternoonState() = default;
};

#endif