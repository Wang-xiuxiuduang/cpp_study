#include "../header_files/morning_state.h"

State* MorningState::m_state = nullptr;

void MorningState::WriteProgram() {
    std::cout << "I like write program !\n";
    SetNextState(AfternoonState::GetInstance());
}