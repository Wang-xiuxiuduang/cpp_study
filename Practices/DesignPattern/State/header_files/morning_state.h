#ifndef MORNING_STATE_H
#define MORNING_STATE_H

#include "afternoon_state.h"
#include "state.h"

class MorningState : public State {
private:
    static State *m_state;
    MorningState() = default;

public:
    void WriteProgram();
    static State *GetInstance() {
        if (m_state == nullptr)
            m_state = new MorningState();
        return m_state;
    };

    ~MorningState() = default;
};

#endif